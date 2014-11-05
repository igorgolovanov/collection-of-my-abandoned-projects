/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Code\Scanner;

class DirectoryScanner implements ScannerInterface
{
    /**
     * @var bool
     */
    protected isScanned = false;

    /**
     * @var string[]|DirectoryScanner[]
     */
    protected directories; // []

    /**
     * @var FileScanner[]
     */
    protected fileScanners; // []

    /**
     * @var array
     */
    protected classToFileScanner;

    /**
     * @param null|string|array $directory
     */
    public function __construct(var directory = null)
    {
        var d;

        if typeof directory == "string" {
            this->addDirectory(directory);
        } elseif typeof directory == "array" {
            for d in directory {
                this->addDirectory(d);
            }
        }
    }

    /**
     * @param  DirectoryScanner|string $directory
     * @return void
     * @throws Exception\InvalidArgumentException
     */
    public function addDirectory(var directory) -> void
    {
        var realDir;
        string exceptionMsg;

        if directory instanceof DirectoryScanner {
            let this->directories[] = directory;
        } elseif typeof directory == "string" {
            let realDir = realpath(directory);
            if unlikely !realDir || !is_dir(realDir) {
                let exceptionMsg = "Directory \"" . realDir . "\" does not exist";
                throw new Exception\InvalidArgumentException(exceptionMsg);
            }
            let this->directories[] = realDir;
        } else {
            throw new Exception\InvalidArgumentException("The argument provided was neither a DirectoryScanner or directory path");
        }
    }

    /**
     * @param  DirectoryScanner $directoryScanner
     * @return void
     */
    public function addDirectoryScanner(<DirectoryScanner> directoryScanner) -> void
    {
        this->addDirectory(directoryScanner);
    }

    /**
     * @param  FileScanner $fileScanner
     * @return void
     */
    public function addFileScanner(<FileScanner> fileScanner) -> void
    {
        this->fileScanners[] = fileScanner;
    }

    /**
     * @return void
     */
    protected function scan() -> void
    {
        var directory, fileScanner, rdi, rii, item, realPath;

        if this->isScanned {
            return;
        }

        // iterate directories creating file scanners
        for directory in this->directories {
            if directory instanceof DirectoryScanner {
                directory->scan();
                if directory->fileScanners {
                    let fileScanners = this->fileScanners;
                    let fileScanners = array_merge(fileScanners, directory->fileScanners);
                    let this->fileScanners = fileScanners;
                }
            } else {
                let rdi = new RecursiveDirectoryIterator(directory);
                let rii = new RecursiveIteratorIterator(rdi);

                for item in iterator(rii) {
                    if item->isFile() {
                        let realPath = item->getRealPath();
                        if pathinfo(realPath, PATHINFO_EXTENSION) == "php" {
                            let this->fileScanners[] = new FileScanner(realPath);
                        }
                    }
                }
            }
        }
        let this->isScanned = true;
    }

    /**
     * @todo implement method
     */
    public function getNamespaces()
    {
        // @todo
    }

    /**
     * @param  bool $returnFileScanners
     * @return array
     */
    public function getFiles(boolean returnFileScanners = false) -> array
    {
        var files, fileScanner;

        this->scan();

        if returnFileScanners {
            return this->fileScanners;
        }

        let files = [];
        for fileScanner in this->fileScanners {
            let files[] = fileScanner->getFile();
        }
        return files;
    }

    /**
     * @return array
     */
    public function getClassNames() -> array
    {
        this->scan();

        if this->classToFileScanner === null {
            this->createClassToFileScannerCache();
        }
        return array_keys(this->classToFileScanner);
    }

    /**
     * @param  bool  $returnDerivedScannerClass
     * @return array
     */
    public function getClasses(boolean returnDerivedScannerClass = false) -> array
    {
        var classes = [], className, fsIndex, classScanner, fileScanner;

        this->scan();

        if this->classToFileScanner === null {
            this->createClassToFileScannerCache();
        }

        for className, fsIndex in this->classToFileScanner {
            let fileScanner = <FileScanner> this->fileScanners[fsIndex];
            let classScanner = <ClassScanner> fileScanner->getClass(className);

            if returnDerivedScannerClass {
                let classScanner = new DerivedClassScanner(classScanner, this);
            }
            let classes[] = classScanner;
        }

        return classes;
    }

    /**
     * @param  string $class
     * @return bool
     */
    public function hasClass(string $class) -> boolean
    {
        this->scan();

        if this->classToFileScanner === null {
            this->createClassToFileScannerCache();
        }

        return isset this->classToFileScanner[$class];
    }

    /**
     * @param  string $class
     * @param  bool $returnDerivedScannerClass
     * @return ClassScanner|DerivedClassScanner
     * @throws Exception\InvalidArgumentException
     */
    public function getClass(string $class, boolean returnDerivedScannerClass = false) -> <ClassScanner>|<DerivedClassScanner>
    {
        var fs, cfs, classReturn;

        this->scan();

        if this->classToFileScanner === null {
            this->createClassToFileScannerCache();
        }

        if unlikely !isset this->classToFileScanner[$class] {
            throw new Exception\InvalidArgumentException("Class not found.");
        }

        let cfs = this->classToFileScanner[$class];
        let fs = <FileScanner> this->fileScanners[cfs];
        let classReturn = <ClassScanner> fs->getClass($class);

        if classReturn instanceof ClassScanner && returnDerivedScannerClass {
            return new DerivedClassScanner(classReturn, this);
        }
        return classReturn;
    }

    /**
     * Create class to file scanner cache
     *
     * @return void
     */
    protected function createClassToFileScannerCache() -> void
    {
        var fsIndex, fileScanner, fsClasses, fsClassName;

        if this->classToFileScanner === null {
            return;
        }

        let this->classToFileScanner = [];
        for fsIndex, fileScanner in this->fileScanners {
            let fsClasses = fileScanner->getClassNames();
            for fsClassName in fsClasses {
                let this->classToFileScanner[fsClassName] = fsIndex;
            }
        }
    }

    /**
     * Export
     *
     * @todo implement method
     */
    public static function export()
    {
        // @todo
    }

    /**
     * __ToString
     *
     * @todo implement method
     */
    public function __toString()
    {
        // @todo
    }

}
