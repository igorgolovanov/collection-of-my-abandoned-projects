/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection;

use Zend\Code\Scanner\CachingFileScanner;

class FileReflection implements ReflectionInterface
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
    protected namespaces = [];

    /**
     * @var array
     */
    protected uses = [];

    /**
     * @var array
     */
    protected requiredFiles = [];

    /**
     * @var ClassReflection[]
     */
    protected classes = [];

    /**
     * @var FunctionReflection[]
     */
    protected functions = [];

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
        var fileRealPath;
        string exceptionMsg;
        array included;

        let fileRealPath = realpath(filename);
        if fileRealPath === false {
            let fileRealPath = stream_resolve_include_path(filename);
        }

        if unlikely !fileRealPath {
            let exceptionMsg = "No file for " . fileRealPath . " was found.";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let included = get_included_files();

        if !in_array(fileRealPath, included) {
            if !includeIfNotAlreadyIncluded {
                let exceptionMsg = "File " . filename . " must be required before it can be reflected";
                throw new Exception\RuntimeException(exceptionMsg);
            }
            require fileRealPath;
        }

        let this->filePath = fileRealPath;
        let this->reflect();
    }

    /**
     * Required by the Reflector interface.
     *
     * @todo   What should this do?
     * @return null
     */
    public static function export()
    {
        return null;
    }

    /**
     * Return the file name of the reflected file
     *
     * @return string
     */
    public function getFileName() -> string
    {
        // @todo get file name from path
        return this->filePath;
    }

    /**
     * Get the start line - Always 1, staying consistent with the Reflection API
     *
     * @return int
     */
    public function getStartLine() -> int
    {
        return this->startLine;
    }

    /**
     * Get the end line / number of lines
     *
     * @return int
     */
    public function getEndLine() -> int
    {
        return this->endLine;
    }

    /**
     * @return string
     */
    public function getDocComment() -> string
    {
        return this->docComment;
    }

    /**
     * @return DocBlockReflection
     */
    public function getDocBlock() -> <DocBlockReflection>|boolean
    {
        string docComment;
        var instance;

        let docComment = this->getDocComment();
        if !docComment {
            return false;
        }
        let instance = new DocBlockReflection(docComment);

        return instance;
    }

    /**
     * @return array
     */
    public function getNamespaces() -> array
    {
        return this->namespaces;
    }

    /**
     * @return string
     */
    public function getNamespace() -> string
    {
        var ns;

        if fetch ns, this->namespaces[0] {
            return ns;
        }

        return null;
    }

    /**
     * @return array
     */
    public function getUses() -> array
    {
        return this->uses;
    }

    /**
     * Return the reflection classes of the classes found inside this file
     *
     * @return ClassReflection[]
     */
    public function getClasses() -> array
    {
        var cl;
        array classes = [];

        for cl in this->classes {
            let classes[] = new ClassReflection(cl);
        }

        return classes;
    }

    /**
     * Return the reflection functions of the functions found inside this file
     *
     * @return FunctionReflection[]
     */
    public function getFunctions() -> array
    {
        var func;
        array functions = [];

        for func in this->functions {
            let functions[] = new FunctionReflection(func);
        }

        return functions;
    }

    /**
     * Retrieve the reflection class of a given class found in this file
     *
     * @param  null|string $name
     * @return ClassReflection
     * @throws Exception\InvalidArgumentException for invalid class name or invalid reflection class
     */
    public function getClass(var name = null) -> <ClassReflection>
    {
        var selected;
        string exceptionMsg;

        if name === null {
            reset(this->classes);
            let selected = current(this->classes);

            return new ClassReflection(selected);
        }

        if unlikely !in_array(name, this->classes) {
            let exceptionMsg = "Class by name " . name . " not found.";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        return new ClassReflection(name);
    }

    /**
     * Return the full contents of file
     *
     * @return string
     */
    public function getContents() -> string
    {
        var contents;

        let contents = file_get_contents(this->filePath);
        if contents === false {
            return "";
        }
        return contents;
    }

    public function toString() -> string
    {
        return ""; // @todo
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
        return "";  
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
        var scanner;

        let scanner = new CachingFileScanner(this->filePath);

        let this->docComment    = scanner->getDocComment();
        let this->requiredFiles = scanner->getIncludes();
        let this->classes       = scanner->getClassNames();
        let this->namespaces    = scanner->getNamespaces();
        let this->uses          = scanner->getUses();
    }

    /**
     * Validate / check a file level DocBlock
     *
     * @param  array $tokens Array of tokenizer tokens
     * @return void
     */
    protected function checkFileDocBlock(array tokens) -> void
    {
        var token, value;
        int type, lineNum;

        for token in tokens {
            let type = token[0];
            let value = token[1];
            let lineNum = token[2];

            if type == T_OPEN_TAG || type == T_WHITESPACE {
                continue;
            }
            if type == T_DOC_COMMENT {
                let this->docComment = value;
                let this->startLine = lineNum + substr_count(value, "\n") + 1;

                return;
            }
            return;
        }
    }

}
