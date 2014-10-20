/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Loader;

abstract class AutoloaderFactory
{
    const STANDARD_AUTOLOADER = "Zend\Loader\StandardAutoloader";

    /**
     * @var array All autoloaders registered using the factory
     */
    protected static loaders; // []

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
        var autoloader, autoloaderOptions;
        string className, exceptionMsg, standardAutoloader = static::STANDARD_AUTOLOADER;

        if options === null {
            if !isset static::loaders[standardAutoloader] {
                let autoloader = <SplAutoloader> static::getStandardAutoloader();
                autoloader->register();
                let static::loaders[standardAutoloader] = autoloader;
            }
            // Return so we don't hit the next check's exception (we're done here anyway)
            return;
        }

        if unlikely typeof options != "array" && !(options instanceof Traversable) {
            throw new Exception\InvalidArgumentException(
                "Options provided must be an array or Traversable"
            );
        }

        for autoloaderOptions, className in options {
            if !isset static::loaders[className] {
                let autoloader = <SplAutoloader> static::getStandardAutoloader();

                if unlikely !class_exists(className) && !autoloader->autoload(className) {
                    let exceptionMsg = "Autoloader class \"" . className . "\" not loaded";
                    throw new Exception\InvalidArgumentException(exceptionMsg);
                }
                if unlikely !static::isSubclassOf(className, "Zend\Loader\SplAutoloader") {
                    let exceptionMsg = "Autoloader class " . className . " must implement Zend\\Loader\\SplAutoloader";
                    throw new Exception\InvalidArgumentException(exceptionMsg);
                }

                if className === standardAutoloader {
                    autoloader->setOptions(autoloaderOptions);
                } else {
                    let autoloader = <SplAutoloader> new {className}(autoloaderOptions);
                }
                autoloader->register();
                let static::loaders[className] = autoloader;
            } else {
                let autoloader = static::loaders[className];
                autoloader->setOptions(autoloaderOptions);
            }
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
        // todo: change self->static
        return self::loaders;
    }

    /**
     * Retrieves an autoloader by class name
     *
     * @param  string $class
     * @return SplAutoloader
     * @throws Exception\InvalidArgumentException for non-registered class
     */
    public static function getRegisteredAutoloader(string $class) -> <SplAutoloader>
    {
        string exceptionMsg;

        if unlikely !isset static::loaders[$class] {
            let exceptionMsg = "Autoloader class \"" . $class . "\" not loaded";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        return static::loaders[$class];
    }

    /**
     * Unregisters all autoloaders that have been registered via the factory.
     * This will NOT unregister autoloaders registered outside of the fctory.
     *
     * @return void
     */
    public static function unregisterAutoloaders() -> void
    {
        array autoloaders, callback;
        var autoloader;
        string className;

        let autoloaders = static::getRegisteredAutoloaders();
        for autoloader, className in autoloaders {
            let callback = [autoloader, "autoload"];
            spl_autoload_unregister(callback);
            unset static::loaders[className];
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
        var autoloader;
        boolean status = false;
        array callback;

        if fetch autoloader, static::loaders[autoloaderClass] {
            let callback = [autoloader, "autoload"];
            spl_autoload_unregister(callback);
            unset static::loaders[autoloaderClass];
            let status = true;
        }
        return status;
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
        var loader;

        if static::standardAutoloader !== null {
            return static::standardAutoloader;
        }

        let loader = new StandardAutoloader();
        let static::standardAutoloader = loader;

        return loader;
    }

    /**
     * Checks if the object has this class as one of its parents
     *
     * @see https://bugs.php.net/bug.php?id=53727
     * @see https://github.com/zendframework/zf2/pull/1807
     *
     * @param  string $className
     * @param  string $type
     * @return bool
     */
    protected static function isSubclassOf(string className, string type) -> boolean
    {
        boolean is = false;
        var ref;

        if is_subclass_of(className, type) {
            let is = true;
        } else {
            if PHP_VERSION_ID < 50307 && interface_exists(type) {
                let ref = new ReflectionClass(className);
                let is = ref->implementsInterface(type);
            }
        }
        return is;
    }
}
