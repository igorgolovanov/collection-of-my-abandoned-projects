/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Loader;

use Traversable;

abstract class AutoloaderFactory
{
    const STANDARD_AUTOLOADER = "Zend\\Loader\\StandardAutoloader";

    /**
     * @var array All autoloaders registered using the factory
     */
    protected static loaders; // todo: []

    /**
     * @var StandardAutoloader StandardAutoloader instance for resolving
     * autoloader classes via the include_path
     */
    protected static standardAutoloader;

    /**
     * Factory for autoloaders
     *
     * Options should be an array or Traversable object of the following structure:
     * <code>
     * array(
     *     '<autoloader class name>' => $autoloaderOptions,
     * )
     * </code>
     *
     * The factory will then loop through and instantiate each autoloader with
     * the specified options, and register each with the spl_autoloader.
     *
     * You may retrieve the concrete autoloader instances later using
     * {@link getRegisteredAutoloaders()}.
     *
     * Note that the class names must be resolvable on the include_path or via
     * the Zend library, using PSR-0 rules (unless the class has already been
     * loaded).
     *
     * @param  array|Traversable $options (optional) options to use. Defaults to Zend\Loader\StandardAutoloader
     * @return void
     * @throws Exception\InvalidArgumentException for invalid options
     * @throws Exception\InvalidArgumentException for unloadable autoloader classes
     * @throws Exception\DomainException for autoloader classes not implementing SplAutoloader
     */
    public static function factory(var options = null) -> void
    {
        var className, loaders = null, autoloaderClass, autoloader,
            autoloaderOptions, autoloaderClassDefault;
        string exceptionMsg;

        let className = get_called_class();

        if options === null {
            // todo: static::$loaders
            %{
                zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
            }%
            if typeof loaders != "array" {
                let loaders = [];
            }
            // todo: static::STANDARD_AUTOLOADER
            let autoloaderClass = constant(className . "::STANDARD_AUTOLOADER");
            if !isset loaders[autoloaderClass] {
                let autoloader = static::getStandardAutoloader();

                autoloader->register();

                let loaders[autoloaderClass] = autoloader;
                // todo: static::$loaders
                %{
                    zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders"), &loaders TSRMLS_CC);
                }%
            }
            // Return so we don't hit the next check's exception (we're done here anyway)
            return;
        }

        if typeof options != "array" {
            if unlikely !is_subclass_of(options, "Traversable") { // todo: options instanceof Traversable
                throw new Exception\InvalidArgumentException("Options provided must be an array or Traversable");
            }
            let options = iterator_to_array(options);
        }

        for autoloaderClass, autoloaderOptions in options {
            // todo: static::$loaders
            %{
                zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
            }%
            if typeof loaders != "array" {
                let loaders = [];
            }
            if fetch autoloader, loaders[autoloaderClass] {
                autoloader->setOptions(autoloaderOptions);
                continue;
            }
            let autoloader = static::getStandardAutoloader();
            if unlikely !class_exists(autoloaderClass) && !autoloader->autoload(autoloaderClass) {
                let exceptionMsg = "Autoloader class \"" . autoloaderClass . "\" not loaded";
                throw new Exception\InvalidArgumentException(exceptionMsg);
            }

            if unlikely !is_subclass_of(autoloaderClass, "Zend\\Loader\\SplAutoloader") {
                let exceptionMsg = "Autoloader class " . autoloaderClass . " must implement Zend\\Loader\\SplAutoloader";
                throw new Exception\InvalidArgumentException(exceptionMsg);
            }

            // todo: static::STANDARD_AUTOLOADER
            let autoloaderClassDefault = constant(className . "::STANDARD_AUTOLOADER");
            if autoloaderClassDefault === autoloaderClass {
                autoloader->setOptions(autoloaderOptions);
            } else {
                let autoloader = new {autoloaderClass}(autoloaderOptions);
            }
            autoloader->register();
            let loaders[autoloaderClass] = autoloader;
            // todo: static::$loaders
            %{
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders"), &loaders TSRMLS_CC);
            }%
        }
    }

    /**
     * Get a list of all autoloaders registered with the factory
     *
     * Returns an array of autoloader instances.
     *
     * @return array
     */
    public static function getRegisteredAutoloaders() -> array
    {
        var loaders = null, className;

        let className = get_called_class();
        // todo: static::$loaders
        %{
            zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
        }%
        if typeof loaders != "array" {
            let loaders = [];
        }
        return loaders;
    }

    /**
     * Retrieves an autoloader by class name
     *
     * @param  string $class
     * @return SplAutoloader
     * @throws Exception\InvalidArgumentException for non-registered class
     */
    public static function getRegisteredAutoloader($class) -> <SplAutoloader>
    {
        var loaders = null, className, autoloader;
        string exceptionMsg;

        let className = get_called_class();
        // todo: static::$loaders
        %{
            zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
        }%
        if typeof loaders != "array" {
            let loaders = [];
        }

        if likely fetch autoloader, loaders[$class] {
            return autoloader;
        }

        let exceptionMsg = "Autoloader class \"" . $class . "\" not loaded";
        throw new Exception\InvalidArgumentException(exceptionMsg);
    }

    /**
     * Unregisters all autoloaders that have been registered via the factory.
     * This will NOT unregister autoloaders registered outside of the fctory.
     *
     * @return void
     */
    public static function unregisterAutoloaders() -> void
    {
        var autoloaders, className, autoloader, loaders = null, autoloaderClass;

        let autoloaders = static::getRegisteredAutoloaders();
        let className = get_called_class();

        for autoloaderClass, autoloader in autoloaders {
            spl_autoload_unregister([autoloader, "autoload"]);
            // todo: static::$loaders
            %{
                zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
            }%
            unset loaders[autoloaderClass];
            // todo: static::$loaders
            %{
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders"), &loaders TSRMLS_CC);
            }%
        }
    }

    /**
     * Unregister a single autoloader by class name
     *
     * @param  string $autoloaderClass
     * @return bool
     */
    public static function unregisterAutoloader(string autoloaderClass) -> boolean
    {
        var className, loaders = null, autoloader;

        let className = get_called_class();
        // todo: static::$loaders
        %{
            zephir_read_static_property(&loaders, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders") TSRMLS_CC);
        }%

        if typeof loaders != "array" || !fetch autoloader, loaders[autoloaderClass] {
            return false;
        }

        spl_autoload_unregister([autoloader, "autoload"]);

        unset loaders[autoloaderClass];
        // todo: static::$loaders
        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("loaders"), &loaders TSRMLS_CC);
        }%
        return true;
    }

    /**
     * Get an instance of the standard autoloader
     *
     * Used to attempt to resolve autoloader classes, using the
     * StandardAutoloader. The instance is marked as a fallback autoloader, to
     * allow resolving autoloaders not under the "Zend" namespace.
     *
     * @return SplAutoloader
     */
    protected static function getStandardAutoloader() -> <SplAutoloader>
    {
        var className, standardAutoloader = null, autoloaderClass;

        let className = get_called_class();
        // todo: static::$standardAutoloader
        %{
            zephir_read_static_property(&standardAutoloader, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("standardAutoloader") TSRMLS_CC);
        }%
        if null !== standardAutoloader {
            return standardAutoloader;
        }

        // todo: static::STANDARD_AUTOLOADER
        let autoloaderClass = constant(className . "::STANDARD_AUTOLOADER");
        let standardAutoloader = new {autoloaderClass}();
        // todo: static::$standardAutoloader
        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("standardAutoloader"), &standardAutoloader TSRMLS_CC);
        }%

        return standardAutoloader;
    }

    /**
     * Checks if the object has this class as one of its parents
     *
     * @see https://bugs.php.net/bug.php?id=53727
     * @see https://github.com/zendframework/zf2/pull/1807
     *
     * @deprecated since zf 2.3 requires PHP >= 5.3.23
     *
     * @param  string $className
     * @param  string $type
     * @return bool
     */
    protected static function isSubclassOf(string className, string type)
    {
        return is_subclass_of(className, type);
    }
}