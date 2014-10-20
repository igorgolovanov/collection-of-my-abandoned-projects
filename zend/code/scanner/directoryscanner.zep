/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
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

    }

    /**
     * @param  DirectoryScanner|string $directory
     * @return void
     * @throws Exception\InvalidArgumentException
     */
    public function addDirectory(var directory) -> void
    {

    }

    /**
     * @param  DirectoryScanner $directoryScanner
     * @return void
     */
    public function addDirectoryScanner(<DirectoryScanner> directoryScanner) -> void
    {

    }

    /**
     * @param  FileScanner $fileScanner
     * @return void
     */
    public function addFileScanner(<FileScanner> fileScanner) -> void
    {

    }

    /**
     * @return void
     */
    protected function scan() -> void
    {

    }

    /**
     * @todo implement method
     */
    public function getNamespaces()
    {

    }

    /**
     * @param  bool $returnFileScanners
     * @return array
     */
    public function getFiles(boolean returnFileScanners = false) -> array
    {

    }

    /**
     * @return array
     */
    public function getClassNames() -> array
    {

    }

    /**
     * @param  bool  $returnDerivedScannerClass
     * @return array
     */
    public function getClasses(boolean returnDerivedScannerClass = false) -> array
    {

    }

    /**
     * @param  string $class
     * @return bool
     */
    public function hasClass(string $class) -> boolean
    {

    }

    /**
     * @param  string $class
     * @param  bool $returnDerivedScannerClass
     * @return ClassScanner|DerivedClassScanner
     * @throws Exception\InvalidArgumentException
     */
    public function getClass(string $class, boolean returnDerivedScannerClass = false) -> <ClassScanner>|<DerivedClassScanner>
    {

    }

    /**
     * Create class to file scanner cache
     *
     * @return void
     */
    protected function createClassToFileScannerCache() -> void
    {

    }

    /**
     * Export
     *
     * @todo implement method
     */
    public static function export()
    {

    }

    /**
     * __ToString
     *
     * @todo implement method
     */
    public function __toString()
    {

    }

}
