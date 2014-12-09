/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Loader;

use Traversable;

/**
 * PSR-0 compliant autoloader
 *
 * Allows autoloading both namespaced and vendor-prefixed classes. Class
 * lookups are performed on the filesystem. If a class file for the referenced
 * class is not found, a PHP warning will be raised by include().
 */
class StandardAutoloader implements SplAutoloader
{
    const NS_SEPARATOR     = "\\";
    const PREFIX_SEPARATOR = "_";
    const LOAD_NS          = "namespaces";
    const LOAD_PREFIX      = "prefixes";
    const ACT_AS_FALLBACK  = "fallback_autoloader";
    const AUTOREGISTER_ZF  = "autoregister_zf";

    /**
     * @var array Namespace/directory pairs to search; ZF library added by default
     */
    protected namespaces; // todo: []

    /**
     * @var array Prefix/directory pairs to search
     */
    protected prefixes; // todo: []

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
        if typeof this->namespaces != "array" {
            let this->namespaces = [];
        }
        if typeof this->prefixes != "array" {
            let this->prefixes = [];
        }

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
        var type, pairs;

        if typeof options != "array" {
            if unlikely !is_subclass_of(options, "Traversable") { // todo: options instanceof Traversable
                throw new Exception\InvalidArgumentException("Options must be either an array or Traversable");
            }
            let options = iterator_to_array(options);
        }

        for type, pairs in options {
            switch type {
                case self::AUTOREGISTER_ZF:
                    // skip, already loaded
                    break;
                case self::LOAD_NS:
                    if typeof pairs == "array" || is_subclass_of(pairs, "Traversable") { // todo: pairs instanceof Traversable
                        this->registerNamespaces(pairs);
                    }
                    break;
                case self::LOAD_PREFIX:
                    if typeof pairs == "array" || is_subclass_of(pairs, "Traversable") { // todo: pairs instanceof Traversable
                        this->registerPrefixes(pairs);
                    }
                    break;
                case self::ACT_AS_FALLBACK:
                    this->setFallbackAutoloader(pairs);
                    break;
                default:
                    // ignore
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

        return $this;
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
        var normalized;

        let normalized = this->normalizeDirectory(directory);
        let $namespace = $namespace->trimright(self::NS_SEPARATOR);
        let $namespace .= self::NS_SEPARATOR;

        let this->namespaces[$namespace] = normalized;

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
        var ns, dir;

        if typeof namespaces != "array" {
            if unlikely !is_subclass_of(namespaces, "Traversable") { // todo: namespaces instanceof Traversable
                throw new Exception\InvalidArgumentException("Namespace pairs must be either an array or Traversable");
            }
            let namespaces = iterator_to_array(namespaces);
        }
        for ns, dir in namespaces {
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
        var normalized;

        let normalized = this->normalizeDirectory(directory);
        let prefix = prefix->trimright(self::PREFIX_SEPARATOR);
        let prefix .= self::PREFIX_SEPARATOR;

        let this->prefixes[prefix] = normalized;

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
        var prefix, dir;

        if typeof prefixes != "array" {
            if unlikely !is_subclass_of(prefixes, "Traversable") { // todo: prefixes instanceof Traversable
                throw new Exception\InvalidArgumentException("Prefix pairs must be either an array or Traversable");
            }
            let prefixes = iterator_to_array(prefixes);
        }
        for prefix, dir in prefixes {
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
    public function autoload(string $class) -> boolean|string
    {
        boolean isFallback;
        var pos;

        let isFallback = (boolean) this->isFallbackAutoloader();
        let pos = $class->index(self::NS_SEPARATOR);

        if pos !== false {
            if this->loadClass($class, self::LOAD_NS) {
                return $class;
            } elseif isFallback {
                return this->loadClass($class, self::ACT_AS_FALLBACK);
            }
            return false;
        }
        let pos = $class->index(self::PREFIX_SEPARATOR);
        if pos !== false {
            if this->loadClass($class, self::LOAD_PREFIX) {
                return $class;
            } elseif isFallback {
                return this->loadClass($class, self::ACT_AS_FALLBACK);
            }
            return false;
        }
        if isFallback {
            return this->loadClass($class, self::ACT_AS_FALLBACK);
        }
        return false;
    }

    /**
     * Register the autoloader with spl_autoload
     *
     * @return void
     */
    public function register() -> void
    {
        spl_autoload_register([this, "autoload"]);
    }

    /**
     * Transform the class name to a filename
     *
     * @param  string $class
     * @param  string $directory
     * @return string
     */
    protected function transformClassNameToFilename(string $class, string directory)
    {
        var matches = [], cl, ns;
        string fileName;

        // $class may contain a namespace portion, in  which case we need
        // to preserve any underscores in that portion.
        preg_match("/(?P<namespace>.+\\\)?(?P<class>[^\\\]+$)/", $class, matches);

        if fetch cl, matches["class"] {
            let cl = str_replace(self::PREFIX_SEPARATOR, "/", cl);
        } else {
            let cl = "";
        }

        if fetch ns, matches["namespace"] {
            let ns = str_replace(self::NS_SEPARATOR, "/", ns);
        } else {
            let ns = "";
        }

        let fileName = directory . ns . cl . ".php";

        return fileName;
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
        var fileName, resolvedName, paths, leader, path, trimmedClass;

        if unlikely !in_array(type, [self::LOAD_NS, self::LOAD_PREFIX, self::ACT_AS_FALLBACK]) {
            throw new Exception\InvalidArgumentException();
        }

        // Fallback autoloading
        if type === self::ACT_AS_FALLBACK {
            // create filename
            let fileName = this->transformClassNameToFilename($class, "");
            let resolvedName = stream_resolve_include_path(fileName);

            if resolvedName !== false {
                require resolvedName;
                return $class;
            }
            return false;
        }

        switch type {
            case self::LOAD_NS:
                let paths = this->namespaces;
                break;
            case self::LOAD_PREFIX:
                let paths = this->prefixes;
                break;
        }
        if typeof paths != "array" {
            let paths = [];
        }

        for leader, path in paths {

            if 0 === $class->index(leader) {
                // Trim off leader (namespace or prefix)
                let trimmedClass = substr($class, strlen(leader));
                let fileName = this->transformClassNameToFilename(trimmedClass, path);

                if file_exists(fileName) {
                    require fileName;
                    return $class;
                }
            }
        }
        return false;
    }

    /**
     * Normalize the directory to include a trailing directory separator
     *
     * @param  string $directory
     * @return string
     */
    protected function normalizeDirectory(string directory) -> string
    {
        return directory->trimright("/\\") . DIRECTORY_SEPARATOR;
    }
}
