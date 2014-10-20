/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Loader;

class ModuleAutoloader implements SplAutoloader
{
    /**
     * @var array An array of module paths to scan
     */
    protected paths = [];

    /**
     * @var array An array of modulename => path
     */
    protected explicitPaths = [];

    /**
     * @var array An array of namespaceName => namespacePath
     */
    protected namespacedPaths = [];

    /**
     * @var array An array of supported phar extensions (filled on constructor)
     */
    protected pharExtensions = [];

    /**
     * @var array An array of module classes to their containing files
     */
    protected moduleClassMap = [];

    /**
     * Constructor
     *
     * Allow configuration of the autoloader via the constructor.
     *
     * @param  null|array|Traversable $options
     */
    public function __construct(var options = null)
    {
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
        var str, classLoaded, pos, basePath, entry, glob;
        string moduleClassFile, moduleName, ns, path, moduleNameBuffer, 
            moduleClassPath, pharSuffixPattern;
        array namespacedPaths, exts;

        // Limit scope of this autoloader
        let str = substr($class, -7);
        if str !== "\\Module" {
            return false;
        }

        if fetch moduleClassFile, this->moduleClassMap[$class] {
            require moduleClassFile;
            return moduleClassFile;
        }

        let moduleName = substr($class, 0, -7);
        if fetch moduleClassFile, this->explicitPaths[moduleName] {
            let classLoaded = this->loadModuleFromDir(moduleClassFile, $class);
            if classLoaded {
                return classLoaded;
            }

            let classLoaded = this->loadModuleFromPhar(moduleClassFile, $class);
            if classLoaded {
                return classLoaded;
            }
        }

        let namespacedPaths = this->namespacedPaths;
        if count(namespacedPaths) >= 1 {
            for path, ns in namespacedPaths {
                let pos = strpos(moduleName, ns);
                if pos === false {
                    continue;
                }
                let moduleNameBuffer = str_replace(ns + "\\", "", moduleName);
                let path = path . DIRECTORY_SEPARATOR . moduleNameBuffer . DIRECTORY_SEPARATOR;

                let classLoaded = this->loadModuleFromDir(path, $class);
                if classLoaded {
                    return classLoaded;
                }

                let classLoaded = this->loadModuleFromPhar(path, $class);
                if classLoaded {
                    return classLoaded;
                }
            }
        }

        let moduleClassPath = str_replace("\\", DIRECTORY_SEPARATOR, moduleName);
        if !empty this->pharExtensions {
            let exts = array_map('preg_quote', this->pharExtensions);
            let pharSuffixPattern = "(" + implode("|", exts) + ")";
            let pharSuffixPattern = "#.+\." + pharSuffixPattern + "$#";
        }

        for path in this->paths {
            let path = path +  moduleClassPath;
            let str = substr(path, 0, 2);

            if path == "." || str == "./" || str == ".\\" {
                let basePath = realpath(".");
                if basePath === false {
                    let basePath = getcwd();
                }
                let path = rtrim(basePath, "\/\\") + substr(path, 1);
            }

            let classLoaded = this->loadModuleFromDir(path, $class);
            if classLoaded {
                return classLoaded;
            }

            // No directory with Module.php, searching for phars
            if !empty pharSuffixPattern {
                let glob = new GlobIterator(path + ".*");
                for entry in glob {
                    if entry->isDir() {
                        continue;
                    }

                    if !preg_math(pharSuffixPattern, entry->getPathname()) {
                        continue;
                    }

                    let classLoaded = this->loadModuleFromPhar(entry->getPathname(), $class);
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
        var file;
        string filePath;

        let filePath = dirPath + "/Module.php";
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
        // todo: change self->static

        var file, pos, moduleFile;
        string fileRealPath, moduleClassFile, pharBaseName;

        let pharPath = self::normalizePath(pharPath, false);
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
        let moduleClassFile = "phar://" + fileRealPath + "/Module.php";
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
        let moduleClassFile = "phar://" + fileRealPath + "/" + pharBaseName + "/Module.php";
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
        array callback = [this, "autoload"];

        spl_autoload_register(callback);
    }

    /**
     * Unregister the autoloader with spl_autoload registry
     *
     * @return void
     */
    public function unregister() -> void
    {
        array callback = [this, "autoload"];
        
        spl_autoload_unregister(callback);
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
        var module;
        string path;

        if unlikely typeof paths != "array" && !paths instanceof Traversable {
            throw new Exception\InvalidArgumentException(
                "Parameter to \\Zend\\Loader\\ModuleAutoloader's registerPaths method must be an array or implement the Traversable interface"
            );
        }

        for path, module in paths {
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
        // todo: change self -> static
        string type, exceptionMsg, moduleNamePart;

        let type = typeof path;
        if unlikely typeof path != "string" {
            let exceptionMsg = "Invalid path provided; must be a string, received " + type;
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        if moduleName {
            let moduleNamePart = substr(moduleName, -2);
            if in_array(moduleNamePart, ["\\\\*", "\\\\%"]) {
                let this->namespacedPaths[moduleNamePart] = self::normalizePath(path);
            } else {
                let this->explicitPaths[moduleName] = self::normalizePath(path);
            }
        } else {
            let this->paths[] = self::normalizePath(path);
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
        array pathInfo;

        do {
            let pathInfo = pathinfo(pharPath);
            let pharPath = pathinfo["filename"];
        } while isset pathInfo["extension"];

        return pathInfo["filename"];
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
        let path = rtrim(path, "\\\\");
        
        if trailingSlash {
            let path = path + DIRECTORY_SEPARATOR;
        }

        return path;
    }

}
