/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Code\Scanner;

use Zend\Code\Annotation\AnnotationManager;
use Zend\Code\Exception;
use Zend\Code\NameInformation;

class TokenArrayScanner implements ScannerInterface
{
    /**
     * @var bool
     */
    protected isScanned = false;

    /**
     * @var array
     */
    protected tokens = [];

    /**
     * @var null
     */
    protected docComment;

    /**
     * @var NameInformation
     */
    protected nameInformation;

    /**
     * @var array
     */
    protected infos = [];

    /**
     * @var AnnotationManager
     */
    protected annotationManager;

    /**
     * @param null|array $tokens
     * @param null|AnnotationManager $annotationManager
     */
    public function __construct(array tokens, <AnnotationManager> annotationManager = null)
    {
        let this->tokens = tokens;
        let this->annotationManager = annotationManager;
    }

    /**
     * @return AnnotationManager
     */
    public function getAnnotationManager() -> <AnnotationManager>|null
    {
        return this->annotationManager;
    }

    /**
     * Get doc comment
     *
     * @todo Assignment of $this->docComment should probably be done in scan()
     *       and then $this->getDocComment() just retrieves it.
     *
     * @return string
     */
    public function getDocComment() -> string
    {
        var token, type, value;

        for token in this->tokens {
            let type = token[0];
            let value = token[1];

            if type == T_OPEN_TAG || type == T_WHITESPACE {
                continue;
            } elseif type == T_DOC_COMMENT {
                let this->docComment = value;
            }
            // Only whitespace is allowed before file docblocks
            break;
        }
        return this->docComment;
    }

    /**
     * @return array
     */
    public function getNamespaces() -> array
    {
        var namespaces = [], info;

        this->scan();

        for info in this->infos {
            let info["type"] == "namespace" {
                let namespaces[] = info["namespace"];
            }
        }
        return namespaces;
    }

    /**
     * @param  null|string $namespace
     * @return array|null
     */
    public function getUses(string $namespace = null) -> array
    {
        this->scan();

        return this->getUsesNoScan($namespace);
    }

    /**
     * @return array
     */
    public function getIncludes() -> array
    {
        this->scan();
        // @todo Implement getIncludes() in TokenArrayScanner
    }

    /**
     * @return array
     */
    public function getClassNames() -> array
    {
        var classNames = [], info;

        this->scan();

        for info in this->infos {
            if info["type"] != "class" {
                continue;
            }
            let classNames[] = info["name"];
        }
        return classNames;
    }

    /**
     * @return ClassScanner[]
     */
    public function getClasses() -> array
    {
        var classes = [], info;

        this->scan();

        for info in this->infos {
            if info["type"] != "class" {
                continue;
            }
            let classes[] = this->getClass(info["name"]);
        }
        return classes;
    }

    /**
     * Return the class object from this scanner
     *
     * @param  string|int $name
     * @throws Exception\InvalidArgumentException
     * @return ClassScanner
     */
    public function getClass(var name) -> <ClassScanner>|boolean
    {
        var info, nameInfo, scanner, tokenStart, tokenEnd, classTokens;
        boolean classFound = false;
        int tokenLength;

        this->scan();

        if typeof name == "integer" {
            let info = this->infos[name];
            if unlikely info["type"] != "class" {
                throw new Exception\InvalidArgumentException("Index of info offset is not about a class");
            }
        } elseif typeof name == "string" {
            for info in this->infos {
                if info["type"] === "class" && info["name"] === name {
                    let classFound = true;
                    break;
                }
            }

            if !classFound {
                return false;
            }
        } else {
            return false;
        }

        let tokenStart = info["tokenStart"];
        let tokenEnd = info["tokenEnd"];
        let tokenLength = tokenEnd - tokenStart + 1;
        let classTokens = array_slice(this->tokens, tokenStart, tokenLength);
        let nameInfo = new NameInformation(info["namespace"], info["uses"]);
        let scanner = new ClassScanner(classTokens, nameInfo);

        return scanner;
    }

    /**
     * @param  string $className
     * @return bool|null|NameInformation
     */
    public function getClassNameInformation(string className) -> boolean|null|<NameInformation>
    {
        var info = null;
        boolean classFound = false;

        this->scan();

        for info in this->infos {
            if info["type"] === "class" && info["name"] === className {
                let classFound = true;
                break;
            }
        }

        if !classFound {
            return false;
        }

        if info === null {
            return null;
        }

        return new NameInformation(info["namespace"], info["uses"]);
    }

    /**
     * @return array
     */
    public function getFunctionNames() -> array
    {
        var functionNames = [], info;

        this->scan();
        for info in this->infos {
            if info["type"] == "function" {
                let functionNames[] = info["name"];
            }
        }

        return functionNames;
    }

    /**
     * @return array
     */
    public function getFunctions() -> array
    {
        var functions = [], info;

        this->scan();
        for info in this->infos {
            if info["type"] == "function" {
                // @todo let functions[] = new FunctionScanner(info["name"]);
            }
        }

        return functions;
    }

    /**
     * Export
     *
     * @param $tokens
     */
    public static function export(tokens)
    {
        // @todo
    }

    public function __toString()
    {
        // @todo
        return "";
    }

    /**
     * Scan
     *
     * @todo: $this->docComment should be assigned for valid docblock during
     *        the scan instead of $this->getDocComment() (starting with
     *        T_DOC_COMMENT case)
     *
     * @throws Exception\RuntimeException
     */
    protected function scan()
    {

    }

    /**
     * Check for namespace
     *
     * @param string $namespace
     * @return bool
     */
    public function hasNamespace(string $namespace) -> boolean
    {

    }

    /**
     * @param  string $namespace
     * @return null|array
     * @throws Exception\InvalidArgumentException
     */
    protected function getUsesNoScan(string $namespace) -> array
    {

    }

}
