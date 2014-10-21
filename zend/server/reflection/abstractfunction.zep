/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Reflection;

use ReflectionClass as PhpReflectionClass;
use ReflectionFunction as PhpReflectionFunction;
use ReflectionFunctionAbstract;
use ReflectionMethod as PhpReflectionMethod;
use Zend\Code\Reflection\DocBlockReflection;
use Zend\Code\Reflection\DocBlock\Tag\ReturnTag;
use Zend\Code\Reflection\DocBlock\Tag\ParamTag;

/**
 * Function/Method Reflection
 *
 * Decorates a ReflectionFunction. Allows setting and retrieving an alternate
 * 'service' name (i.e., the name to be used when calling via a service),
 * setting and retrieving the description (originally set using the docblock
 * contents), retrieving the callback and callback type, retrieving additional
 * method invocation arguments, and retrieving the
 * method {@link \Zend\Server\Reflection\Prototype prototypes}.
 */
abstract class AbstractFunction
{
    /**
     * @var ReflectionFunctionAbstract
     */
    protected reflection;

    /**
     * Additional arguments to pass to method on invocation
     * @var array
     */
    protected argv = [];

    /**
     * Used to store extra configuration for the method (typically done by the
     * server class, e.g., to indicate whether or not to instantiate a class).
     * Associative array; access is as properties via {@link __get()} and
     * {@link __set()}
     * @var array
     */
    protected config = [];

    /**
     * Declaring class (needed for when serialization occurs)
     * @var string
     */
    protected $class;

    /**
     * Function/method description
     * @var string
     */
    protected description = "";

    /**
     * Namespace with which to prefix function/method name
     * @var string
     */
    protected $namespace;

    /**
     * Prototypes
     * @var array
     */
    protected prototypes = [];

    private $return;

    private returnDesc;

    private paramDesc;

    private sigParams;

    private sigParamsDepth;

    /**
     * Constructor
     *
     * @param ReflectionFunctionAbstract $r
     * @param null|string $namespace
     * @param null|array $argv
     * @throws Exception\InvalidArgumentException
     * @throws Exception\RuntimeException
     */
    public function __construct(<\ReflectionFunctionAbstract> r, var $namespace = null, var argv = [])
    {
        var declaringClass;
        string name;

        let this->reflection = r;

        // Determine namespace
        if !empty $namespace {
            this->setNamespace($namespace);
        }

        // Determine arguments
        if typeof argv {
            let this->argv = argv;
        }

        // If method call, need to store some info on the class
        if r instanceof PhpReflectionMethod {
            let declaringClass = <> r->getDeclaringClass();
        }
    }

    /**
     * Create signature node tree
     *
     * Recursive method to build the signature node tree. Increments through
     * each array in {@link $sigParams}, adding every value of the next level
     * to the current value (unless the current value is null).
     *
     * @param \Zend\Server\Reflection\Node $parent
     * @param int $level
     * @return void
     */
    protected function addTree(<\Zend\Server\Reflection\Node> parent, int level = 0) -> void
    {
        var sigParams, node, value;
        int level2;

        if level >= this->sigParamsDepth {
            return;
        }

        if fetch sigParams, this->sigParams[level] {
            for value in sigParams {
                let node = new Node(value, parent);
                let level2 = level + 1;
                if value !== null && this->sigParamsDepth > level2 {
                    this->addTree(node, level2);
                }
            }
        }
    }

    /**
     * Build the signature tree
     *
     * Builds a signature tree starting at the return values and descending
     * through each method argument. Returns an array of
     * {@link \Zend\Server\Reflection\Node}s.
     *
     * @return array
     */
    protected function buildTree() -> array
    {
        array tree = [];
        var value, node;

        for value in this->return {
            let node = new Node(value);
            this->addTree(node);
            let tree[] = node;
        }

        return tree;
    }

    /**
     * Build method signatures
     *
     * Builds method signatures using the array of return types and the array of
     * parameters types
     *
     * @param array $return Array of return types
     * @param string $returnDesc Return value description
     * @param array $paramTypes Array of arguments (each an array of types)
     * @param array $paramDesc Array of parameter descriptions
     * @return array
     */
    protected function buildSignatures(array $return, string returnDesc, array paramTypes, array paramDesc) -> array
    {
        array signatureTrees, signatures = [], 
            signature = [], endPoints = [], params, tpmArray;
        var root, tmp, node, val, reflection, sign, 
            returnRefl, type, key, param;
        string paramDesc;

        let this->$return = $return;
        let this->returnDesc = returnDesc;
        let this->paramDesc = paramDesc;
        let this->sigParams = paramTypes;
        let this->sigParamsDepth = count(paramTypes);

        let signatureTrees = this->buildTree();

        for root in signatureTrees {
            let tmp = root->getEndPoints();
            if empty tmp {
                let tmp = [root];
            }
            let endPoints = array_merge(endPoints, tmp);
        }

        for node in endPoints {
            if !(node instanceof Node) {
                continue;
            }
            let signature = [];
            do {
                let val = node->getValue();
                array_unshift(signature, val);
                let node = node->getParent();
            } while node instanceof Node;

            let signatures[] = signature;
        }
        // Build prototypes
        let reflection = <ReflectionFunctionAbstract> this->reflection;
        let params = reflection->getParameters();

        for sign in signatures {
            let val = array_shift(sign);
            let returnRefl = new ReflectionReturnValue(val, this->returnDesc);
            let tpmArray = [];
            for key, type in sign {
                let tmp = params[key];
                let paramDesc = null;
                if isset this->paramDesc[key] {
                    let paramDesc = this->paramDesc[key];
                }
                let param = new ReflectionParameter(tmp, type, paramDesc);
                param->setPosition(key);
                let tpmArray[] = param;
            }
            let this->prototypes[] = new Prototype(returnRefl, tmpArray);
        }
    }

    /**
     * Use code reflection to create method signatures
     *
     * Determines the method help/description text from the function DocBlock
     * comment. Determines method signatures using a combination of
     * ReflectionFunction and parsing of DocBlock @param and @return values.
     *
     * @throws Exception\RuntimeException
     * @return array
     */
    protected function reflect() -> array
    {
        var func, scanner, returnTag, type, param, key, paramTag;
        int paramCount, paramTypesTmpCount, i;
        array parameters, paramTags, returnVal, types,
            paramTypesTmp = [], paramDesc = [], paramTypes = [];
        string docComment, helpText, returnDesc, description;

        let func = <ReflectionFunctionAbstract> this->reflection;
        let paramCount = func->getNumberOfParameters();
        let parameters = func->getParameters();
        let docComment = func->getDocComment();

        if !docComment {
            let docComment = "/***/";
        }

        let scanner = new DocBlockReflection(docComment);
        let paramTags = scanner->getTags("param");
        let returnTag = <ReturnTag> scanner->getTag("return");
        let helpText = scanner->getLongDescription();

        if empty helpText {
            let helpText = scanner->getShortDescription();
            if empty helpText {
                let helpText = func->getName()
            }
        }

        this->setDescription(helpText);

        if returnTag {
            let returnVal = [];
            let returnDesc = returnTag->getDescription();
            let types = returnTag->getTypes();

            for type in types {
                let returnVal[] = type;
            }
        } else {
            let returnVal = ["void"];
            let returnDesc = "";
        }

        if empty paramTags {
            for param in parameters {
                if param->isArray() {
                    let paramTypesTmp[] = ["array"];
                } else {
                    let paramTypesTmp[] = ["mixed"];
                }
                let paramDesc[] = "";
            }
        } else {
            for param in paramTags {
                let paramTypesTmp[] = param->getTypes();
                let description = param->getDescription();

                if description {
                    let paramDesc[] = description;
                } else {
                    let paramDesc[] = "";
                }
            }
        }

        // Get all param types as arrays
        let paramTypesTmpCount = count(paramTypesTmp);

        if paramTypesTmpCount < paramCount {
            let i = paramCount - paramTypesTmpCount;
            while i < paramCount {
                let i++;
                let paramTypesTmp[i] = ["mixed"];
                let paramDesc[i] = "";
            }
        } else {
            if unlikely paramTypesTmpCount != paramCount {
                throw new Exception\RuntimeException("Variable number of arguments is not supported for services (except optional parameters). Number of function arguments must correspond to actual number of arguments described in a docblock.");
            }
        }

        for key, param in paramTypesTmp {
            let paramTag = <ParamTag> parameters[key];
            if paramTag->isOptional() {
                 array_unshift(param, null);
            }
            let paramTypes[] = param;
        }

        this->buildSignatures(returnVal, returnDesc, paramTypes, paramDesc);
    }

    /**
     * Proxy reflection calls
     *
     * @param string $method
     * @param array $args
     * @throws Exception\BadMethodCallException
     * @return mixed
     */
    public function __call(string method, array args)
    {
        var reflection, result;
        string exceptionMsg;
        array callback;

        let reflection = <ReflectionFunctionAbstract> this->reflection;

        if unlikely !method_exists(reflection, method) {
            let exceptionMsg = "Invalid reflection method (\"" . method . "\")";
            throw new Exception\BadMethodCallException(exceptionMsg);
        }

        let callback = [reflection, method];
        let result = call_user_func_array(callback, args);

        return result;
    }

    /**
     * Retrieve configuration parameters
     *
     * Values are retrieved by key from {@link $config}. Returns null if no
     * value found.
     *
     * @param string $key
     * @return mixed
     */
    public function __get(string key)
    {
        var value;

        if fetch value, this->config[key] {
            return value;
        }

        return null;
    }

    /**
     * Set configuration parameters
     *
     * Values are stored by $key in {@link $config}.
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function __set(string key, var value) -> void
    {
        let this->config[key] = value;
    }

    /**
     * Set method's namespace
     *
     * @param string $namespace
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public function setNamespace(var $namespace) -> void
    {
        if empty $namespace {
            let this->$namespace = "";
            return;
        }

        if unlikely typeof $namespace != "string" || !preg_match("/[a-z0-9_\.]+/i", $namespace) {
            throw new Exception\InvalidArgumentException("Invalid namespace");
        }

        let this->$namespace = $namespace;
    }

    /**
     * Return method's namespace
     *
     * @return string
     */
    public function getNamespace() -> string
    {
        return this->$namespace;
    }

    /**
     * Set the description
     *
     * @param string $string
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public function setDescription(var $string) -> void
    {
        if unlikely typeof $string == "string" {
            throw new Exception\InvalidArgumentException("Invalid description");
        }

        let this->description = $string;
    }

    /**
     * Retrieve the description
     *
     * @return string
     */
    public function getDescription() -> string
    {
        return this->description;
    }

    /**
     * Retrieve all prototypes as array of
     * {@link \Zend\Server\Reflection\Prototype}s
     *
     * @return Prototype[]
     */
    public function getPrototypes() -> array
    {
        return this->prototypes;
    }

    /**
     * Retrieve additional invocation arguments
     *
     * @return array
     */
    public function getInvokeArguments() -> array
    {
        return this->argv;
    }

    /**
     * Wakeup from serialization
     *
     * Reflection needs explicit instantiation to work correctly. Re-instantiate
     * reflection object on wakeup.
     *
     * @return void
     */
    public function __wakeup() -> void
    {
        var reflectionClass, reflection, instance;
        string name;

        let name = this->getName();

        if this->reflection instanceof PhpReflectionMethod {
            let reflectionClass = new PhpReflectionClass(this->$class);
            let instance = reflectionClass->newInstance();
            let reflection = new PhpReflectionMethod(instance, name); 
        } else {
            let reflection = new PhpReflectionFunction(name);
        }
        let this->reflection = reflection;
    }

}
