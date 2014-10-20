
namespace Zend\Code\Reflection;

class FileReflection implements ReflectionInterface, \Reflector
{
    /**
     * @var string
     */
    protected filePath;

    /**
     * @var string
     */
    protected docComment;

    /**
     * @var int
     */
    protected startLine = 1;

    /**
     * @var int
     */
    protected endLine;

    /**
     * @var string
     */
    protected namespaces; // []

    /**
     * @var array
     */
    protected uses; // []

    /**
     * @var array
     */
    protected requiredFiles; // []

    /**
     * @var ClassReflection[]
     */
    protected classes; // []

    /**
     * @var FunctionReflection[]
     */
    protected functions; // []

    /**
     * @var string
     */
    protected contents;

    /**
     * @param  string $filename
     * @param  bool $includeIfNotAlreadyIncluded
     * @throws Exception\InvalidArgumentException If file does not exists
     * @throws Exception\RuntimeException If file exists but is not included or required
     */
    public function __construct(string filename, boolean includeIfNotAlreadyIncluded = false)
    {

    }

    /**
     * Required by the Reflector interface.
     *
     * @todo   What should this do?
     * @return null
     */
    public static function export()
    {

    }

    /**
     * Return the file name of the reflected file
     *
     * @return string
     */
    public function getFileName() -> string
    {

    }

    /**
     * Get the start line - Always 1, staying consistent with the Reflection API
     *
     * @return int
     */
    public function getStartLine() -> int
    {

    }

    /**
     * Get the end line / number of lines
     *
     * @return int
     */
    public function getEndLine() -> int
    {

    }

    /**
     * @return string
     */
    public function getDocComment() -> string
    {

    }

    /**
     * @return DocBlockReflection
     */
    public function getDocBlock() -> <DocBlockReflection>
    {

    }

    /**
     * @return array
     */
    public function getNamespaces() -> array
    {

    }

    /**
     * @return string
     */
    public function getNamespace() -> string
    {

    }

    /**
     * @return array
     */
    public function getUses() -> array
    {

    }

    /**
     * Return the reflection classes of the classes found inside this file
     *
     * @return ClassReflection[]
     */
    public function getClasses() -> array
    {

    }

    /**
     * Return the reflection functions of the functions found inside this file
     *
     * @return FunctionReflection[]
     */
    public function getFunctions() -> array
    {

    }

    /**
     * Retrieve the reflection class of a given class found in this file
     *
     * @param  null|string $name
     * @return ClassReflection
     * @throws Exception\InvalidArgumentException for invalid class name or invalid reflection class
     */
    public function getClass(string name = null) -> <ClassReflection>
    {

    }

    /**
     * Return the full contents of file
     *
     * @return string
     */
    public function getContents() -> string
    {

    }

    public function toString()
    {

    }

    /**
     * Serialize to string
     *
     * Required by the Reflector interface
     *
     * @todo   What should this serialization look like?
     * @return string
     */
    public function __toString() -> string
    {

    }

    /**
     * This method does the work of "reflecting" the file
     *
     * Uses Zend\Code\Scanner\FileScanner to gather file information
     *
     * @return void
     */
    protected function reflect() -> void
    {

    }

    /**
     * Validate / check a file level DocBlock
     *
     * @param  array $tokens Array of tokenizer tokens
     * @return void
     */
    protected function checkFileDocBlock(array tokens) -> void
    {

    }

}
