/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Loader;

/**
 * PSR-0 compliant autoloader
 *
 * Allows autoloading both namespaced and vendor-prefixed classes. Class
 * lookups are performed on the filesystem. If a class file for the referenced
 * class is not found, a PHP warning will be raised by include().
 */
class StandardAutoloader implements SplAutoloader
{
    const NS_SEPARATOR = "\\\\";
    const PREFIX_SEPARATOR = "_";
    const LOAD_NS = "namespaces";
    const LOAD_PREFIX = "prefixes";
    const ACT_AS_FALLBACK = "fallback_autoloader";
    const AUTOREGISTER_ZF = "autoregister_zf";

    /**
     * @var array Namespace/directory pairs to search; ZF library added by default
     */
    protected namespaces = [];

    /**
     * @var array Prefix/directory pairs to search
     */
    protected prefixes = [];

    /**
     * @var bool Whether or not the autoloader should also act as a fallback autoloader
     */
    protected fallbackAutoloaderFlag = false;

    /**
     * Constructor
     *
     * @param  null|array|\Traversable $options
     */
    public function __construct(var options = null)
    {
        if options !== null {
            this->setOptions(options);
        }
    }

    /**
     * Configure autoloader
     *
     * Allows specifying both "namespace" and "prefix" pairs, using the
     * following structure:
     * <code>
     * array(
     *     'namespaces' => array(
     *         'Zend'     => '/path/to/Zend/library',
     *         'Doctrine' => '/path/to/Doctrine/library',
     *     ),
     *     'prefixes' => array(
     *         'Phly_'     => '/path/to/Phly/library',
     *     ),
     *     'fallback_autoloader' => true,
     * )
     * </code>
     *
     * @param  array|\Traversable $options
     * @throws Exception\InvalidArgumentException
     * @return StandardAutoloader
     */
    public function setOptions(var options) -> <StandardAutoloader>
    {
        string type, dirname;
        var pairs;

        if unlikely typeof options != "array" || !(options instanceof \Traversable) {
            throw new Exception\InvalidArgumentException("Options must be either an array or Traversable");
        }

        for pairs, type in options {
            switch type {
                case self::AUTOREGISTER_ZF:
                    if !empty pairs {
                        let dirname = dirname(__DIR__);
                        // todo: what do with ZF?
                    }
                    break;

                case self::LOAD_NS:
                    if typeof pairs == "array" || pairs instanceof \Traversable {
                        this->registerNamespaces(pairs);
                    }
                    break;

                case self::LOAD_PREFIX:
                    if typeof pairs == "array" || pairs instanceof \Traversable {
                        this->registerPrefixes(pairs);
                    }
                    break;  

                case self::ACT_AS_FALLBACK:
                    this->setFallbackAutoloader(pairs);
                    break;    
            }
        }
        return this;
    }

    /**
     * Set flag indicating fallback autoloader status
     *
     * @param  bool $flag
     * @return StandardAutoloader
     */
    public function setFallbackAutoloader(boolean flag) -> <StandardAutoloader>
    {
        let this->fallbackAutoloaderFlag = flag;
    }

    /**
     * Is this autoloader acting as a fallback autoloader?
     *
     * @return bool
     */
    public function isFallbackAutoloader() -> boolean
    {
        return this->fallbackAutoloaderFlag;
    }

    /**
     * Register a namespace/directory pair
     *
     * @param  string $namespace
     * @param  string $directory
     * @return StandardAutoloader
     */
    public function registerNamespace(string $namespace, string directory) -> <StandardAutoloader>
    {
        string normilized;

        let $namespace = rtrim($namespace, self::NS_SEPARATOR) + self::NS_SEPARATOR;
        let normilized = this->normalizeDirectory(directory);

        let this->namespaces[$namespaces] = normilized;

        return this;
    }

    /**
     * Register many namespace/directory pairs at once
     *
     * @param  array $namespaces
     * @throws Exception\InvalidArgumentException
     * @return StandardAutoloader
     */
    public function registerNamespaces(var namespaces) -> <StandardAutoloader>
    {
        string ns, dir;

        if unlikely typeof namespaces != "array" || !namespaces instanceof \Traversable {
            throw new Exception\InvalidArgumentException("Namespace pairs must be either an array or Traversable");
        }
        for dir, ns in namespaces {
            this->registerNamespace(ns, dir);
        }
        return this;
    }

    /**
     * Register a prefix/directory pair
     *
     * @param  string $prefix
     * @param  string $directory
     * @return StandardAutoloader
     */
    public function registerPrefix(string prefix, string directory) -> <StandardAutoloader>
    {
        string normilized;

        let prefix = rtrim(prefix, self::PREFIX_SEPARATOR) + self::PREFIX_SEPARATOR;
        let normilized = this->normalizeDirectory(directory);

        let this->prefixes[prefix] = normilized;

        return this;
    }

    /**
     * Register many namespace/directory pairs at once
     *
     * @param  array $prefixes
     * @throws Exception\InvalidArgumentException
     * @return StandardAutoloader
     */
    public function registerPrefixes(var prefixes) -> <StandardAutoloader>
    {
        string prefix, dir;

        if unlikely typeof prefixes != "array" || !prefixes instanceof \Traversable {
            throw new Exception\InvalidArgumentException("Prefix pairs must be either an array or Traversable");
        }
        for dir, prefix in prefixes {
            this->registerPrefix(prefix, dir);
        }
        return this;
    }

    /**
     * Defined by Autoloadable; autoload a class
     *
     * @param  string $class
     * @return false|string
     */
    public function autoload(string $class) -> string
    {

    }

    /**
     * Register the autoloader with spl_autoload
     *
     * @return void
     */
    public function register() -> void
    {
        array autoload = [this, "autoload"];

        spl_autoload_register(autoload);
    }

    /**
     * Transform the class name to a filename
     *
     * @param  string $class
     * @param  string $directory
     * @return string
     */
    protected function transformClassNameToFilename(string $class, string directory) -> string
    {

    }

    /**
     * Load a class, based on its type (namespaced or prefixed)
     *
     * @param  string $class
     * @param  string $type
     * @return bool|string
     * @throws Exception\InvalidArgumentException
     */
    protected function loadClass(string $class, string type) -> boolean|string
    {

    }

    /**
     * Normalize the directory to include a trailing directory separator
     *
     * @param  string $directory
     * @return string
     */
    protected function normalizeDirectory(string directory) -> string
    {

    }

}
