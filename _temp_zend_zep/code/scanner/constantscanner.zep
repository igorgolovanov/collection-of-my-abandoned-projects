/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class ConstantScanner implements ScannerInterface
{
    /**
     * @var bool
     */
    protected isScanned = false;

    /**
     * @var array
     */
    protected tokens;

    /**
     * @var NameInformation
     */
    protected nameInformation;

    /**
     * @var string
     */
    protected $class;

    /**
     * @var ClassScanner
     */
    protected scannerClass;

    /**
     * @var int
     */
    protected lineStart;

    /**
     * @var string
     */
    protected docComment;

    /**
     * @var string
     */
    protected name;

    /**
     * @var string
     */
    protected value;

    /**
     * Constructor
     *
     * @param array $constantTokens
     * @param NameInformation $nameInformation
     */
    public function __construct(array! constantTokens, nameInformation = null)
    {

    }

    /**
     * @param string $class
     */
    public function setClass(string $class)
    {

    }

    /**
     * @param ClassScanner $scannerClass
     */
    public function setScannerClass(<ClassScanner> scannerClass)
    {

    }

    /**
     * @return ClassScanner
     */
    public function getClassScanner() -> <ClassScanner>
    {

    }

    /**
     * @return string
     */
    public function getName() -> string
    {

    }

    /**
     * @return string
     */
    public function getValue() -> string
    {

    }

    /**
     * @return string
     */
    public function getDocComment() -> string
    {

    }

    /**
     * @param Annotation\AnnotationManager $annotationManager
     * @return AnnotationScanner
     */
    public function getAnnotations(annotationManager) -> <AnnotationScanner>
    {

    }

    /**
     * @return string
     */
    public function __toString() -> string
    {

    }

    /**
     * Scan tokens
     *
     * @throws Exception\RuntimeException
     */
    protected function scan()
    {

    }

}
