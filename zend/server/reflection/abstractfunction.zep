/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Reflection;

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

    private return;

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
    public function __construct(<\ReflectionFunctionAbstract> r, string $namespace = null, array argv = [])
    {

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
    protected function buildSignatures(array return, string returnDesc, array paramTypes, array paramDesc) -> array
    {

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
    public function __set(string key, value) -> void
    {

    }

    /**
     * Set method's namespace
     *
     * @param string $namespace
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public function setNamespace(string $namespace) -> void
    {

    }

    /**
     * Return method's namespace
     *
     * @return string
     */
    public function getNamespace() -> string
    {

    }

    /**
     * Set the description
     *
     * @param string $string
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public function setDescription(string $string) -> void
    {

    }

    /**
     * Retrieve the description
     *
     * @return string
     */
    public function getDescription() -> string
    {

    }

    /**
     * Retrieve all prototypes as array of
     * {@link \Zend\Server\Reflection\Prototype}s
     *
     * @return Prototype[]
     */
    public function getPrototypes() -> array
    {

    }

    /**
     * Retrieve additional invocation arguments
     *
     * @return array
     */
    public function getInvokeArguments() -> array
    {

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

    }

}
