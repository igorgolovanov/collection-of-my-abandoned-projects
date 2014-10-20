/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class PropertyScanner implements ScannerInterface
{
    const T_BOOLEAN = "boolean";

    const T_INTEGER = "int";

    const T_STRING = "string";

    const T_ARRAY = "array";

    const T_UNKNOWN = "unknown";

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
     * @var bool
     */
    protected isProtected = false;

    /**
     * @var bool
     */
    protected isPublic = true;

    /**
     * @var bool
     */
    protected isPrivate = false;

    /**
     * @var bool
     */
    protected isStatic = false;

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
     * @var string
     */
    protected valueType;

    /**
     * Constructor
     *
     * @param array $propertyTokens
     * @param NameInformation $nameInformation
     */
    public function __construct(array! propertyTokens, nameInformation = null)
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
    public function getValueType() -> string
    {

    }

    /**
     * @return bool
     */
    public function isPublic() -> boolean
    {

    }

    /**
     * @return bool
     */
    public function isPrivate() -> boolean
    {

    }

    /**
     * @return bool
     */
    public function isProtected() -> boolean
    {

    }

    /**
     * @return bool
     */
    public function isStatic() -> boolean
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
     * @throws \Zend\Code\Exception\RuntimeException
     */
    protected function scan()
    {

    }

}
