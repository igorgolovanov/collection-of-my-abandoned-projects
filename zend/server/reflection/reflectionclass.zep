/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Reflection;

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
    public function __construct(reflection, string $namespace = null, argv = false)
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
     * Return array of dispatchable {@link \Zend\Server\Reflection\ReflectionMethod}s.
     *
     * @access public
     * @return array
     */
    public function getMethods() -> array
    {

    }

    /**
     * Get namespace for this class
     *
     * @return string
     */
    public function getNamespace() -> string
    {

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
