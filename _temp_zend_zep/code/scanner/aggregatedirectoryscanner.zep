/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class AggregateDirectoryScanner extends DirectoryScanner implements ScannerInterface
{
    /**
     * @var bool
     */
    protected isScanned = false;

    /**
     * @param  bool $returnScannerClass
     * @todo not implemented
     */
    public function getNamespaces(boolean returnScannerClass = false)
    {

    }

    public function getIncludes(boolean returnScannerClass = false)
    {

    }

    public function getClasses(boolean returnScannerClass = false, boolean returnDerivedScannerClass = false)
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
     * @param  bool $returnScannerClass
     * @param  bool $returnDerivedScannerClass
     * @return ClassScanner|DerivedClassScanner
     * @throws Exception\RuntimeException
     */
    public function getClass(string $class, boolean returnScannerClass = true, boolean returnDerivedScannerClass = false) -> <ClassScanner>|<DerivedClassScanner>
    {

    }

    /**
     * @param bool $returnScannerClass
     */
    public function getFunctions(boolean returnScannerClass = false)
    {

    }

}
