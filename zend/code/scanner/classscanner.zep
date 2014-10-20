/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class ClassScanner implements ScannerInterface
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
     * @var string
     */
    protected name;

    /**
     * @var string
     */
    protected shortName;

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
    protected isInterface = false;

    /**
     * @var string
     */
    protected parentClass;

    /**
     * @var string
     */
    protected shortParentClass;

    /**
     * @var array
     */
    protected interfaces; // []

    /**
     * @var array
     */
    protected shortInterfaces; // []

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
     * @param  array $classTokens
     * @param  NameInformation|null $nameInformation
     * @return ClassScanner
     */
    public function __construct(array! classTokens, nameInformation = null) -> <ClassScanner>
    {

    }

    /**
     * Get annotations
     *
     * @param  Annotation\AnnotationManager $annotationManager
     * @return Annotation\AnnotationCollection
     */
    public function getAnnotations(annotationManager)
    {

    }

    /**
     * Return documentation comment
     *
     * @return null|string
     */
    public function getDocComment() -> string
    {

    }

    /**
     * Return documentation block
     *
     * @return false|DocBlockScanner
     */
    public function getDocBlock() -> <DocBlockScanner>
    {

    }

    /**
     * Return a name of class
     *
     * @return null|string
     */
    public function getName() -> string
    {

    }

    /**
     * Return short name of class
     *
     * @return null|string
     */
    public function getShortName() -> string
    {

    }

    /**
     * Return number of first line
     *
     * @return int|null
     */
    public function getLineStart() -> int
    {

    }

    /**
     * Return number of last line
     *
     * @return int|null
     */
    public function getLineEnd() -> int
    {

    }

    /**
     * Verify if class is final
     *
     * @return bool
     */
    public function isFinal() -> boolean
    {

    }

    /**
     * Verify if class is instantiable
     *
     * @return bool
     */
    public function isInstantiable() -> boolean
    {

    }

    /**
     * Verify if class is an abstract class
     *
     * @return bool
     */
    public function isAbstract() -> boolean
    {

    }

    /**
     * Verify if class is an interface
     *
     * @return bool
     */
    public function isInterface() -> boolean
    {

    }

    /**
     * Verify if class has parent
     *
     * @return bool
     */
    public function hasParentClass() -> boolean
    {

    }

    /**
     * Return a name of parent class
     *
     * @return null|string
     */
    public function getParentClass() -> string
    {

    }

    /**
     * Return a list of interface names
     *
     * @return array
     */
    public function getInterfaces() -> array
    {

    }

    /**
     * Return a list of constant names
     *
     * @return array
     */
    public function getConstantNames() -> array
    {

    }

    /**
     * Return a list of constants
     *
     * @param  bool $namesOnly Set false to return instances of ConstantScanner
     * @return array|ConstantScanner[]
     */
    public function getConstants(boolean namesOnly = true) -> array
    {

    }

    /**
     * Return a single constant by given name or index of info
     *
     * @param  string|int $constantNameOrInfoIndex
     * @throws Exception\InvalidArgumentException
     * @return bool|ConstantScanner
     */
    public function getConstant(var constantNameOrInfoIndex) -> boolean|<ConstantScanner>
    {

    }

    /**
     * Verify if class has constant
     *
     * @param  string $name
     * @return bool
     */
    public function hasConstant(string name) -> boolean
    {

    }

    /**
     * Return a list of property names
     *
     * @return array
     */
    public function getPropertyNames() -> array
    {

    }

    /**
     * Return a list of properties
     *
     * @return PropertyScanner
     */
    public function getProperties() -> <PropertyScanner>
    {

    }

    /**
     * Return a single property by given name or index of info
     *
     * @param  string|int $propertyNameOrInfoIndex
     * @throws Exception\InvalidArgumentException
     * @return bool|PropertyScanner
     */
    public function getProperty(var propertyNameOrInfoIndex) -> boolean|<PropertyScanner>
    {

    }

    /**
     * Verify if class has property
     *
     * @param  string $name
     * @return bool
     */
    public function hasProperty(string name) -> boolean
    {

    }

    /**
     * Return a list of method names
     *
     * @return array
     */
    public function getMethodNames() -> array
    {

    }

    /**
     * Return a list of methods
     *
     * @return MethodScanner[]
     */
    public function getMethods() -> array
    {

    }

    /**
     * Return a single method by given name or index of info
     *
     * @param  string|int $methodNameOrInfoIndex
     * @throws Exception\InvalidArgumentException
     * @return MethodScanner
     */
    public function getMethod(var methodNameOrInfoIndex) -> <MethodScanner>
    {

    }

    /**
     * Verify if class has method by given name
     *
     * @param  string $name
     * @return bool
     */
    public function hasMethod(string name) -> boolean
    {

    }

    public static function export()
    {

    }

    public function __toString()
    {

    }

    /**
     * Scan tokens
     *
     * @return void
     * @throws Exception\RuntimeException
     */
    protected function scan() -> void
    {

    }

}
