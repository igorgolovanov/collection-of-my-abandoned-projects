/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

class ClassGenerator extends AbstractGenerator implements GeneratorInterface
{
    const FLAG_ABSTRACT = 1;

    const FLAG_FINAL = 2;

    const LINE_FEED = "
";

    /**
     * @var FileGenerator
     */
    protected containingFileGenerator;

    /**
     * @var string
     */
    protected namespaceName;

    /**
     * @var DocBlockGenerator
     */
    protected docBlock;

    /**
     * @var string
     */
    protected name;

    /**
     * @var bool
     */
    protected flags = 0;

    /**
     * @var string
     */
    protected extendedClass;

    /**
     * @var array Array of string names
     */
    protected implementedInterfaces; // []

    /**
     * @var PropertyGenerator[] Array of properties
     */
    protected properties; // []

    /**
     * @var MethodGenerator[] Array of methods
     */
    protected methods; // []

    /**
     * @var array Array of string names
     */
    protected uses; // []

    /**
     * Build a Code Generation Php Object from a Class Reflection
     *
     * @param  ClassReflection $classReflection
     * @return ClassGenerator
     */
    public static function fromReflection(classReflection) -> <ClassGenerator>
    {

    }

    /**
     * Generate from array
     *
     * @configkey name           string        [required] Class Name
     * @configkey filegenerator  FileGenerator File generator that holds this class
     * @configkey namespacename  string        The namespace for this class
     * @configkey docblock       string        The docblock information
     * @configkey flags          int           Flags, one of ClassGenerator::FLAG_ABSTRACT ClassGenerator::FLAG_FINAL
     * @configkey extendedclass  string        Class which this class is extending
     * @configkey implementedinterfaces
     * @configkey properties
     * @configkey methods
     *
     * @throws Exception\InvalidArgumentException
     * @param  array $array
     * @return ClassGenerator
     */
    public static function fromArray(array! $array) -> <ClassGenerator>
    {

    }

    /**
     * @param  string $name
     * @param  string $namespaceName
     * @param  array|string $flags
     * @param  string $extends
     * @param  array $interfaces
     * @param  array $properties
     * @param  array $methods
     * @param  DocBlockGenerator $docBlock
     */
    public function __construct(string name = null, string namespaceName = null, var flags = null, string extends = null, array interfaces = [], array properties = [], array methods = [], <DocBlockGenerator> docBlock = null)
    {

    }

    /**
     * @param  string $name
     * @return ClassGenerator
     */
    public function setName(string name) -> <ClassGenerator>
    {

    }

    /**
     * @return string
     */
    public function getName() -> string
    {

    }

    /**
     * @param  string $namespaceName
     * @return ClassGenerator
     */
    public function setNamespaceName(string namespaceName) -> <ClassGenerator>
    {

    }

    /**
     * @return string
     */
    public function getNamespaceName() -> string
    {

    }

    /**
     * @param  FileGenerator $fileGenerator
     * @return ClassGenerator
     */
    public function setContainingFileGenerator(<FileGenerator> fileGenerator) -> <ClassGenerator>
    {

    }

    /**
     * @return FileGenerator
     */
    public function getContainingFileGenerator() -> <FileGenerator>
    {

    }

    /**
     * @param  DocBlockGenerator $docBlock
     * @return ClassGenerator
     */
    public function setDocBlock(<DocBlockGenerator> docBlock) -> <ClassGenerator>
    {

    }

    /**
     * @return DocBlockGenerator
     */
    public function getDocBlock() -> <DocBlockGenerator>
    {

    }

    /**
     * @param  array|string $flags
     * @return ClassGenerator
     */
    public function setFlags(var flags) -> <ClassGenerator>
    {

    }

    /**
     * @param  string $flag
     * @return ClassGenerator
     */
    public function addFlag(string flag) -> <ClassGenerator>
    {

    }

    /**
     * @param  string $flag
     * @return ClassGenerator
     */
    public function removeFlag(string flag) -> <ClassGenerator>
    {

    }

    /**
     * @param  bool $isAbstract
     * @return ClassGenerator
     */
    public function setAbstract(boolean isAbstract) -> <ClassGenerator>
    {

    }

    /**
     * @return bool
     */
    public function isAbstract() -> boolean
    {

    }

    /**
     * @param  bool $isFinal
     * @return ClassGenerator
     */
    public function setFinal(boolean isFinal) -> <ClassGenerator>
    {

    }

    /**
     * @return bool
     */
    public function isFinal() -> boolean
    {

    }

    /**
     * @param  string $extendedClass
     * @return ClassGenerator
     */
    public function setExtendedClass(string extendedClass) -> <ClassGenerator>
    {

    }

    /**
     * @return string
     */
    public function getExtendedClass() -> string
    {

    }

    /**
     * @param  array $implementedInterfaces
     * @return ClassGenerator
     */
    public function setImplementedInterfaces(array! implementedInterfaces) -> <ClassGenerator>
    {

    }

    /**
     * @return array
     */
    public function getImplementedInterfaces() -> array
    {

    }

    /**
     * @param  array $properties
     * @return ClassGenerator
     */
    public function addProperties(array! properties) -> <ClassGenerator>
    {

    }

    /**
     * Add Property from scalars
     *
     * @param  string $name
     * @param  string|array $defaultValue
     * @param  int $flags
     * @throws Exception\InvalidArgumentException
     * @return ClassGenerator
     */
    public function addProperty(string name, var defaultValue = null, int flags = Zend\Code\Generator\PropertyGenerator::FLAG_PUBLIC) -> <ClassGenerator>
    {

    }

    /**
     * Add property from PropertyGenerator
     *
     * @param  PropertyGenerator           $property
     * @throws Exception\InvalidArgumentException
     * @return ClassGenerator
     */
    public function addPropertyFromGenerator(<PropertyGenerator> property) -> <ClassGenerator>
    {

    }

    /**
     * Add a class to "use" classes
     *
     * @param  string $use
     * @param  string|null $useAlias
     * @return ClassGenerator
     */
    public function addUse(string $use, string useAlias = null) -> <ClassGenerator>
    {

    }

    /**
     * @return PropertyGenerator[]
     */
    public function getProperties() -> array
    {

    }

    /**
     * @param  string $propertyName
     * @return PropertyGenerator|false
     */
    public function getProperty(string propertyName) -> <PropertyGenerator>
    {

    }

    /**
     * Returns the "use" classes
     *
     * @return array
     */
    public function getUses() -> array
    {

    }

    /**
     * @param  string $propertyName
     * @return bool
     */
    public function hasProperty(string propertyName) -> boolean
    {

    }

    /**
     * @param  array $methods
     * @return ClassGenerator
     */
    public function addMethods(array! methods) -> <ClassGenerator>
    {

    }

    /**
     * Add Method from scalars
     *
     * @param  string $name
     * @param  array $parameters
     * @param  int $flags
     * @param  string $body
     * @param  string $docBlock
     * @throws Exception\InvalidArgumentException
     * @return ClassGenerator
     */
    public function addMethod(string name = null, array! parameters = [], int flags = Zend\Code\Generator\MethodGenerator::FLAG_PUBLIC, string body = null, string docBlock = null) -> <ClassGenerator>
    {

    }

    /**
     * Add Method from MethodGenerator
     *
     * @param  MethodGenerator                    $method
     * @throws Exception\InvalidArgumentException
     * @return ClassGenerator
     */
    public function addMethodFromGenerator(<MethodGenerator> method) -> <ClassGenerator>
    {

    }

    /**
     * @return MethodGenerator[]
     */
    public function getMethods() -> array
    {

    }

    /**
     * @param  string $methodName
     * @return MethodGenerator|false
     */
    public function getMethod(string methodName) -> <MethodGenerator>
    {

    }

    /**
     * @param  string $methodName
     * @return ClassGenerator
     */
    public function removeMethod(string methodName) -> <ClassGenerator>
    {

    }

    /**
     * @param  string $methodName
     * @return bool
     */
    public function hasMethod(string methodName) -> boolean
    {

    }

    /**
     * @return bool
     */
    public function isSourceDirty() -> boolean
    {

    }

    /**
     * @return string
     */
    public function generate() -> string
    {

    }

}
