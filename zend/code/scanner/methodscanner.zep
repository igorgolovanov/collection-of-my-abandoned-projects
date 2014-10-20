/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class MethodScanner implements ScannerInterface
{
    /**
     * @var bool
     */
    protected isScanned = false;

    /**
     * @var string
     */
    protected docComment;

    /**
     * @var ClassScanner
     */
    protected scannerClass;

    /**
     * @var string
     */
    protected $class;

    /**
     * @var string
     */
    protected name;

    /**
     * @var int
     */
    protected lineStart;

    /**
     * @var int
     */
    protected lineEnd;

    /**
     * @var bool
     */
    protected isFinal = false;

    /**
     * @var bool
     */
    protected isAbstract = false;

    /**
     * @var bool
     */
    protected isPublic = true;

    /**
     * @var bool
     */
    protected isProtected = false;

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
    protected body = "";

    /**
     * @var array
     */
    protected tokens; // []

    /**
     * @var NameInformation
     */
    protected nameInformation;

    /**
     * @var array
     */
    protected infos; // []

    /**
     * @param  array $methodTokens
     * @param NameInformation $nameInformation
     */
    public function __construct(array! methodTokens, nameInformation = null)
    {

    }

    /**
     * @param  string $class
     * @return MethodScanner
     */
    public function setClass(string $class) -> <MethodScanner>
    {

    }

    /**
     * @param  ClassScanner  $scannerClass
     * @return MethodScanner
     */
    public function setScannerClass(<ClassScanner> scannerClass) -> <MethodScanner>
    {

    }

    /**
     * @return MethodScanner
     */
    public function getClassScanner() -> <MethodScanner>
    {

    }

    /**
     * @return string
     */
    public function getName() -> string
    {

    }

    /**
     * @return int
     */
    public function getLineStart() -> int
    {

    }

    /**
     * @return int
     */
    public function getLineEnd() -> int
    {

    }

    /**
     * @return string
     */
    public function getDocComment() -> string
    {

    }

    /**
     * @param  AnnotationManager $annotationManager
     * @return AnnotationScanner
     */
    public function getAnnotations(annotationManager) -> <AnnotationScanner>
    {

    }

    /**
     * @return bool
     */
    public function isFinal() -> boolean
    {

    }

    /**
     * @return bool
     */
    public function isAbstract() -> boolean
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
    public function isProtected() -> boolean
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
    public function isStatic() -> boolean
    {

    }

    /**
     * @return int
     */
    public function getNumberOfParameters() -> int
    {

    }

    /**
     * @param  bool $returnScanner
     * @return array
     */
    public function getParameters(boolean returnScanner = false) -> array
    {

    }

    /**
     * @param  int|string $parameterNameOrInfoIndex
     * @return ParameterScanner
     * @throws Exception\InvalidArgumentException
     */
    public function getParameter(var parameterNameOrInfoIndex) -> <ParameterScanner>
    {

    }

    /**
     * @return string
     */
    public function getBody() -> string
    {

    }

    public static function export()
    {

    }

    public function __toString()
    {

    }

    protected function scan()
    {

    }

}
