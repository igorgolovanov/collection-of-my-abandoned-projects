
namespace Zend\Code\Reflection;

class ClassReflection extends \ReflectionClass implements \Reflector, ReflectionInterface
{
    const IS_IMPLICIT_ABSTRACT = 16;

    const IS_EXPLICIT_ABSTRACT = 32;

    const IS_FINAL = 64;

    /**
     * @var AnnotationScanner
     */
    protected annotations;

    /**
     * @var DocBlockReflection
     */
    protected docBlock;

    /**
     * Return the reflection file of the declaring file.
     *
     * @return FileReflection
     */
    public function getDeclaringFile() -> <FileReflection>
    {

    }

    /**
     * Return the classes DocBlock reflection object
     *
     * @return DocBlockReflection
     * @throws Exception\ExceptionInterface for missing DocBock or invalid reflection class
     */
    public function getDocBlock() -> <DocBlockReflection>
    {

    }

    /**
     * @param  AnnotationManager $annotationManager
     * @return AnnotationCollection
     */
    public function getAnnotations(annotationManager)
    {

    }

    /**
     * Return the start line of the class
     *
     * @param  bool $includeDocComment
     * @return int
     */
    public function getStartLine(boolean includeDocComment = false) -> int
    {

    }

    /**
     * Return the contents of the class
     *
     * @param  bool $includeDocBlock
     * @return string
     */
    public function getContents(boolean includeDocBlock = true) -> string
    {

    }

    /**
     * Get all reflection objects of implemented interfaces
     *
     * @return ClassReflection[]
     */
    public function getInterfaces() -> array
    {

    }

    /**
     * Return method reflection by name
     *
     * @param  string $name
     * @return MethodReflection
     */
    public function getMethod(string name) -> <MethodReflection>
    {

    }

    /**
     * Get reflection objects of all methods
     *
     * @param  int $filter
     * @return MethodReflection[]
     */
    public function getMethods(int filter = -1) -> array
    {

    }

    /**
     * Get parent reflection class of reflected class
     *
     * @return ClassReflection|bool
     */
    public function getParentClass() -> <ClassReflection>|boolean
    {

    }

    /**
     * Return reflection property of this class by name
     *
     * @param  string $name
     * @return PropertyReflection
     */
    public function getProperty(string name) -> <PropertyReflection>
    {

    }

    /**
     * Return reflection properties of this class
     *
     * @param  int $filter
     * @return PropertyReflection[]
     */
    public function getProperties(int filter = -1) -> array
    {

    }

    public function toString()
    {

    }

    public function __toString()
    {

    }

    /**
     * Creates a new FileScanner instance.
     *
     * By having this as a seperate method it allows the method to be overridden
     * if a different FileScanner is needed.
     *
     * @param  string $filename
     *
     * @return FileScanner
     */
    protected function createFileScanner(string filename)
    {

    }

}
