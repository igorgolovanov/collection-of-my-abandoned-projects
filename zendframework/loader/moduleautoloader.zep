/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Loader;

use SplFileInfo;
use GlobIterator;

class ModuleAutoloader implements SplAutoloader
{
    /**
     * @var array An array of module paths to scan
     */
    protected paths; // todo: []

    /**
     * @var array An array of modulename => path
     */
    protected explicitPaths; // todo: []

    /**
     * @var array An array of namespaceName => namespacePath
     */
    protected namespacedPaths; // todo: []

    /**
     * @var array An array of supported phar extensions (filled on constructor)
     */
    protected pharExtensions; // todo: []

    /**
     * @var array An array of module classes to their containing files
     */
    protected moduleClassMap; // todo: []

    /**
     * Constructor
     *
     * Allow configuration of the autoloader via the constructor.
     *
     * @param  null|array|Traversable $options
     */
    public function __construct(var options = null)
    {
        if typeof this->paths != "array" {
            let this->paths = [];
        }
        if typeof this->explicitPaths != "array" {
            let this->explicitPaths = [];
        }
        if typeof this->namespacedPaths != "array" {
            let this->namespacedPaths = [];
        }
        if typeof this->pharExtensions != "array" {
            let this->pharExtensions = [];
        }
        if typeof this->moduleClassMap != "array" {
            let this->moduleClassMap = [];
        }

        if extension_loaded("phar") {
            let this->pharExtensions = ["phar", "phar.tar", "tar"];

            // ext/zlib enabled -> phar can read gzip & zip compressed files
            if extension_loaded("zlib") {
                let this->pharExtensions[] = "phar.gz";
                let this->pharExtensions[] = "phar.tar.gz";
                let this->pharExtensions[] = "tar.gz";
                let this->pharExtensions[] = "phar.zip";
                let this->pharExtensions[] = "zip";
            }

           // ext/bzip2 enabled -> phar can read bz2 compressed files
           if extension_loaded("bzip2") {
                let this->pharExtensions[] = "phar.bz2";
                let this->pharExtensions[] = "phar.tar.bz2";
                let this->pharExtensions[] = "tar.bz2";
            }
        }

        if options !== null {
            this->setOptions(options);
        }
    }

    /**
     * Configure the autoloader
     *
     * In most cases, $options should be either an associative array or
     * Traversable object.
     *
     * @param  array|Traversable $options
     * @return ModuleAutoloader
     */
    public function setOptions(var options) -> <ModuleAutoloader>
    {
        this->registerPaths(options);
        return this;
    }

    /**
     * Retrieves the class map for all loaded modules.
     *
     * @return array
     */
    public function getModuleClassMap() -> array
    {
        return this->moduleClassMap;
    }

    /**
     * Sets the class map used to speed up the module autoloading.
     *
     * @param  array $classmap
     * @return ModuleAutoloader
     */
    public function setModuleClassMap(array! classmap) -> <ModuleAutoloader>
    {
        let this->moduleClassMap = classmap;
        return this;
    }

    /**
     * Autoload a class
     *
     * @param   $class
     * @return  mixed
     *          False [if unable to load $class]
     *          get_class($class) [if $class is successfully loaded]
     */
    public function autoload(string $class) -> string|boolean
    {
        var str, classLoaded, className, pos, basePath, entry, glob,
            moduleClassFile, moduleName, ns, path, moduleNameBuffer,
            moduleClassPath, pharSuffixPattern = null, namespacedPaths, exts, paths,
            pharExtensions;

        let className = $class;
        // Limit scope of this autoloader
        let str = substr(className, -7);
        if str !== "\\Module" {
            return false;
        }

        if fetch moduleClassFile, this->moduleClassMap[className] {
            require moduleClassFile;
            return moduleClassFile;
        }

        let moduleName = substr(className, 0, -7);
        if fetch moduleClassFile, this->explicitPaths[moduleName] {
            let classLoaded = this->loadModuleFromDir(moduleClassFile, className);
            if classLoaded {
                return classLoaded;
            }

            let classLoaded = this->loadModuleFromPhar(moduleClassFile, className);
            if classLoaded {
                return classLoaded;
            }
        }

        let namespacedPaths = this->namespacedPaths;
        if typeof namespacedPaths != "array" {
            let namespacedPaths = [];
            let this->namespacedPaths = namespacedPaths;
        }
        if count(namespacedPaths) >= 1 {
            for ns, path in namespacedPaths {
                let pos = strpos(moduleName, ns);
                if pos === false {
                    continue;
                }
                let moduleNameBuffer = str_replace(ns . "\\", "", moduleName);
                let path = path . DIRECTORY_SEPARATOR . moduleNameBuffer . DIRECTORY_SEPARATOR;

                let classLoaded = this->loadModuleFromDir(path, className);
                if classLoaded {
                    return classLoaded;
                }

                let classLoaded = this->loadModuleFromPhar(path, className);
                if classLoaded {
                    return classLoaded;
                }
            }
        }

        let moduleClassPath = str_replace("\\", DIRECTORY_SEPARATOR, moduleName);
        let pharExtensions = this->pharExtensions;
        if typeof pharExtensions != "array" {
            let pharExtensions = [];
            let this->pharExtensions = pharExtensions;
        }
        if count(pharExtensions) > 0 {
            let exts = array_map("preg_quote", this->pharExtensions);
            let pharSuffixPattern = "(" . implode("|", exts) . ")";
            let pharSuffixPattern = "#.+\\." . pharSuffixPattern . "$#";
        }
        let paths = this->paths;
        if typeof paths != "array" {
            let paths = [];
            let this->paths = paths;
        }

        for path in paths {
            let path = path .  moduleClassPath;
            let str = substr(path, 0, 2);

            if path == "." || str == "./" || str == ".\\" {
                let basePath = realpath(".");
                if basePath === false {
                    let basePath = getcwd();
                }
                let path = rtrim(basePath, "\\/\\") . substr(path, 1);
            }

            let classLoaded = this->loadModuleFromDir(path, className);
            if classLoaded {
                return classLoaded;
            }

            // No directory with Module.php, searching for phars
            if pharSuffixPattern !== null {
                let glob = new GlobIterator(path . ".*");
                for entry in iterator(glob) {
                    if entry->isDir() {
                        continue;
                    }

                    if !preg_match(pharSuffixPattern, entry->getPathname()) {
                        continue;
                    }

                    let classLoaded = this->loadModuleFromPhar(entry->getPathname(), className);
                    if classLoaded {
                        return classLoaded;
                    }
                }
            }
        }
        return false;
    }

    /**
     * loadModuleFromDir
     *
     * @param  string $dirPath
     * @param  string $class
     * @return  mixed
     *          False [if unable to load $class]
     *          get_class($class) [if $class is successfully loaded]
     */
    protected function loadModuleFromDir(string dirPath, string $class) -> string|boolean
    {
        var file, filePath;

        let filePath = dirPath . "/Module.php";
        let file = new SplFileInfo(filePath);

        if file->isReadable() && file->isFile() {
            // Found directory with Module.php in it
            let filePath = file->getRealPath();
            require filePath;

            if class_exists($class) {
                let this->moduleClassMap[$class] = filePath;
                return $class;
            }
        }
        return false;
    }

    /**
     * loadModuleFromPhar
     *
     * @param  string $pharPath
     * @param  string $class
     * @return  mixed
     *          False [if unable to load $class]
     *          get_class($class) [if $class is successfully loaded]
     */
    protected function loadModuleFromPhar(string pharPath, string $class) -> string|boolean
    {
        var file, pos, moduleFile, fileRealPath, moduleClassFile, pharBaseName;

        let pharPath = static::normalizePath(pharPath, false);
        let file = new SplFileInfo(pharPath);

        if !file->isReadable() || !file->isFile() {
            return false;
        }

        let fileRealPath = file->getRealPath();
        let pos = strpos(fileRealPath, ".phar");

        // Phase 0: Check for executable phar with Module class in stub
        if pos !== false {
            // First see if the stub makes the Module class available
            require fileRealPath;
            if class_exists($class) {
                let this->moduleClassMap[$class] = fileRealPath;
                return $class;
            }
        }

        // Phase 1: Not executable phar, no stub, or stub did not provide Module class; try Module.php directly
        let moduleClassFile = "phar://" . fileRealPath . "/Module.php";
        let moduleFile = new SplFileInfo(moduleClassFile);

        if moduleFile->isReadable() && moduleFile->isFile() {
            require moduleClassFile;
            if class_exists($class) {
                let this->moduleClassMap[$class] = fileRealPath;
                return $class;
            }
        }

        // Phase 2: Check for nested module directory within archive
        // Checks for /path/to/MyModule.tar/MyModule/Module.php
        // (shell-integrated zip/tar utilities wrap directories like this)
        let pharBaseName = this->pharFileToModuleName(fileRealPath);
        let moduleClassFile = "phar://" . fileRealPath . "/" . pharBaseName . "/Module.php";
        let moduleFile = new SplFileInfo(moduleClassFile);

        if moduleFile->isReadable() && moduleFile->isFile() {
            require moduleClassFile;
            if class_exists($class) {
                let this->moduleClassMap[$class] = fileRealPath;
                return $class;
            }
        }

        return false;
    }

    /**
     * Register the autoloader with spl_autoload registry
     *
     * @return void
     */
    public function register() -> void
    {
        spl_autoload_register([this, "autoload"]);
    }

    /**
     * Unregister the autoloader with spl_autoload registry
     *
     * @return void
     */
    public function unregister() -> void
    {
        spl_autoload_unregister([this, "autoload"]);
    }

    /**
     * registerPaths
     *
     * @param  array|Traversable $paths
     * @throws \InvalidArgumentException
     * @return ModuleAutoloader
     */
    public function registerPaths(var paths) -> <ModuleAutoloader>
    {
        var module, path;

        if typeof paths != "array" {
            if unlikely !is_subclass_of(paths, "Traversable") { // todo: paths instanceof Traversable
                throw new Exception\InvalidArgumentException(
                    "Parameter to \\Zend\\Loader\\ModuleAutoloader's registerPaths method must be an array or implement the Traversable interface"
                );
            }
            let paths = iterator_to_array(paths);
        }

        for module, path in paths {
            if typeof module == "string" {
                this->registerPath(path, module);
            } else {
                this->registerPath(path);
            }
        }

        return this;
    }

    /**
     * registerPath
     *
     * @param  string $path
     * @param  bool|string $moduleName
     * @throws \InvalidArgumentException
     * @return ModuleAutoloader
     */
    public function registerPath(var path, var moduleName = false) -> <ModuleAutoloader>
    {
        string exceptionMsg;
        var moduleNamePart, normalizedPath, patterns = ["\\*", "\\%"];

        if unlikely typeof path != "string" {
            let exceptionMsg = "Invalid path provided; must be a string, received " . typeof path;
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let normalizedPath = static::normalizePath(path);

        if moduleName {
            let moduleNamePart = substr(moduleName, -2);
            if in_array(moduleNamePart, patterns) {
                let moduleNamePart = substr(moduleName, 0, -2);
                let this->namespacedPaths[moduleNamePart] = normalizedPath;
            } else {
                let this->explicitPaths[moduleName] = normalizedPath;
            }
        } else {
            let this->paths[] = normalizedPath;
        }

        return this;
    }

    /**
     * getPaths
     *
     * This is primarily for unit testing, but could have other uses.
     *
     * @return array
     */
    public function getPaths() -> array
    {
        return this->paths;
    }

    /**
     * Returns the base module name from the path to a phar
     *
     * @param  string $pharPath
     * @return string
     */
    protected function pharFileToModuleName(string pharPath) -> string
    {
        var info, path;

        let path = pharPath;
        do {
            let info = pathinfo(path);
            let path = info["filename"];
        } while isset info["extension"];

        return info["filename"];
    }

    /**
     * Normalize a path for insertion in the stack
     *
     * @param  string $path
     * @param  bool   $trailingSlash Whether trailing slash should be included
     * @return string
     */
    public static function normalizePath(string path, boolean trailingSlash = true) -> string
    {
        let path = rtrim(path, "/");
        let path = rtrim(path, "\\");
        
        if trailingSlash {
            let path = path . DIRECTORY_SEPARATOR;
        }

        return path;
    }

}
