
namespace Zend\Code\Reflection;

class MethodReflection extends \ReflectionMethod implements \Reflector, ReflectionInterface
{
    const PROTOTYPE_AS_ARRAY = "prototype_as_array";

    const PROTOTYPE_AS_STRING = "prototype_as_string";

    const IS_STATIC = 1;

    const IS_PUBLIC = 256;

    const IS_PROTECTED = 512;

    const IS_PRIVATE = 1024;

    const IS_ABSTRACT = 2;

    const IS_FINAL = 4;

    /**
     * @var AnnotationScanner
     */
    protected annotations;

    /**
     * Retrieve method DocBlock reflection
     *
     * @return DocBlockReflection|false
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

    /**
     * Get start line (position) of method
     *
     * @param  bool $includeDocComment
     * @return int
     */
    public function getStartLine(boolean includeDocComment = false) -> int
    {

    }

    /**
     * Get reflection of declaring class
     *
     * @return ClassReflection
     */
    public function getDeclaringClass() -> <ClassReflection>
    {

    }

    /**
     * Get method prototype
     *
     * @return array
     */
    public function getPrototype(format = Zend\Code\Reflection\MethodReflection::PROTOTYPE_AS_ARRAY) -> array
    {

    }

    /**
     * Get all method parameter reflection objects
     *
     * @return ParameterReflection[]
     */
    public function getParameters() -> array
    {

    }

    /**
     * Get method contents
     *
     * @param  bool $includeDocBlock
     * @return string|bool
     */
    public function getContents(boolean includeDocBlock = true) -> string|boolean
    {

    }

    /**
     * Get method body
     *
     * @return string|bool
     */
    public function getBody() -> string|boolean
    {

    }

    /**
     * Tokenize method string and return concatenated body
     *
     * @param bool $bodyOnly
     * @return string
     */
    protected function extractMethodContents(boolean bodyOnly = false) -> string
    {

    }

    /**
     * Take current position and find any whitespace
     *
     * @param $haystack
     * @param $position
     * @return string
     */
    protected function extractPrefixedWhitespace(haystack, position) -> string
    {

    }

    /**
     * Test for ending brace
     *
     * @param $haystack
     * @param $position
     * @return bool
     */
    protected function isEndingBrace(haystack, position) -> boolean
    {

    }

    /**
     * Test to see if current position is valid function or
     * closure.  Returns true if it's a function and NOT a closure
     *
     * @param $haystack
     * @param $position
     * @return bool
     */
    protected function isValidFunction(haystack, position, functionName = null) -> boolean
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
     * @return CachingFileScanner
     */
    protected function createFileScanner(string filename)
    {

    }

}
