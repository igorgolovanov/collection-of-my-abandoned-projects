/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Reflection;

use ReflectionClass as PhpReflectionClass;

/**
 * Class/Object reflection
 *
 * Proxies calls to a ReflectionClass object, and decorates getMethods() by
 * creating its own list of {@link Zend\Server\Reflection\ReflectionMethod}s.
 */
class ReflectionClass
{
    /**
     * Optional configuration parameters; accessible via {@link __get} and
     * {@link __set()}
     * @var array
     */
    protected config = [];

    /**
     * Array of {@link \Zend\Server\Reflection\Method}s
     * @var array
     */
    protected methods = [];

    /**
     * Namespace
     * @var string
     */
    protected $namespace;

    /**
     * ReflectionClass object
     * @var PhpReflectionClass
     */
    protected reflection;

    /**
     * Constructor
     *
     * Create array of dispatchable methods, each a
     * {@link Zend\Server\Reflection\ReflectionMethod}. Sets reflection object property.
     *
     * @param PhpReflectionClass $reflection
     * @param string $namespace
     * @param mixed $argv
     */
    public function __construct(<PhpReflectionClass> reflection, string $namespace = null, var argv = false)
    {
        var method, methodRefl;
        array methods;
        string ns, name;

        let this->reflection = reflection;
        this->setNamespace($namespace);

        let methods = reflection->getMethods();
        for method in methods {

            // Don't aggregate magic methods
            let name = method->getName();
            if substr(name, 0, 2) == "__" {
                continue;
            }

            if method->isPublic() {
                let ns = this->getNamespace();
                // Get signatures and description
                let methodRefl = new ReflectionMethod(this, method, ns, argv);
                let this->methods[] = methodRefl;
            }
        }
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
        array callback;

        let reflection = <PhpReflectionClass> this->reflection;

        if unlikely !method_exists(reflection, method) {
             throw new Exception\BadMethodCallException("Invalid reflection method");
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
     * Return array of dispatchable {@link \Zend\Server\Reflection\ReflectionMethod}s.
     *
     * @access public
     * @return array
     */
    public function getMethods() -> array
    {
        return this->methods;
    }

    /**
     * Get namespace for this class
     *
     * @return string
     */
    public function getNamespace() -> string
    {
        return this->$namespace;
    }

    /**
     * Set namespace for this class
     *
     * @param string $namespace
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public function setNamespace(string $namespace) -> void
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
     * Wakeup from serialization
     *
     * Reflection needs explicit instantiation to work correctly. Re-instantiate
     * reflection object on wakeup.
     *
     * @return void
     */
    public function __wakeup() -> void
    {
        string name;

        let name = this->getName();
        let this->reflection = new PhpReflectionClass(name);
    }
}
