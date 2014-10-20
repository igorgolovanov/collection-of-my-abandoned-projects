
namespace Zend\Code\Reflection;

/**
 * @todo       implement line numbers
 */
class PropertyReflection extends \ReflectionProperty implements \Reflector, ReflectionInterface
{
    const IS_STATIC = 1;

    const IS_PUBLIC = 256;

    const IS_PROTECTED = 512;

    const IS_PRIVATE = 1024;

    /**
     * @var AnnotationScanner
     */
    protected annotations;

    /**
     * Get declaring class reflection object
     *
     * @return ClassReflection
     */
    public function getDeclaringClass() -> <ClassReflection>
    {

    }

    /**
     * Get DocBlock comment
     *
     * @return string|false False if no DocBlock defined
     */
    public function getDocComment() -> string
    {

    }

    /**
     * @return false|DocBlockReflection
     */
    public function getDocBlock() -> <DocBlockReflection>
    {

    }

    /**
     * @param  AnnotationManager $annotationManager
     * @return AnnotationScanner
     */
    public function getAnnotations(annotationManager)
    {

    }

    public function toString()
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
     * @return CachingFileScanner
     */
    protected function createFileScanner(string filename)
    {

    }

}
