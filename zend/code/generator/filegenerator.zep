/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

class FileGenerator extends AbstractGenerator implements GeneratorInterface
{
    const LINE_FEED = "
";

    /**
     * @var string
     */
    protected filename;

    /**
     * @var DocBlockGenerator
     */
    protected docBlock;

    /**
     * @var array
     */
    protected requiredFiles; // []

    /**
     * @var string
     */
    protected $namespace;

    /**
     * @var array
     */
    protected uses; // []

    /**
     * @var array
     */
    protected classes; // []

    /**
     * @var string
     */
    protected body;

    /**
     * Passes $options to {@link setOptions()}.
     *
     * @param  array|\Traversable $options
     */
    public function __construct(var options = null)
    {

    }

    /**
     * Use this if you intend on generating code generation objects based on the same file.
     * This will keep previous changes to the file in tact during the same PHP process
     *
     * @param  string $filePath
     * @param  bool $includeIfNotAlreadyIncluded
     * @throws ReflectionException\InvalidArgumentException If file does not exists
     * @throws ReflectionException\RuntimeException If file exists but is not included or required
     * @return FileGenerator
     */
    public static function fromReflectedFileName(string filePath, boolean includeIfNotAlreadyIncluded = true) -> <FileGenerator>
    {

    }

    /**
     * @param  FileReflection $fileReflection
     * @return FileGenerator
     */
    public static function fromReflection(fileReflection) -> <FileGenerator>
    {

    }

    /**
     * @param  array $values
     * @return FileGenerator
     */
    public static function fromArray(array! values) -> <FileGenerator>
    {

    }

    /**
     * @param  DocBlockGenerator|string $docBlock
     * @throws Exception\InvalidArgumentException
     * @return FileGenerator
     */
    public function setDocBlock(var docBlock) -> <FileGenerator>
    {

    }

    /**
     * @return DocBlockGenerator
     */
    public function getDocBlock() -> <DocBlockGenerator>
    {

    }

    /**
     * @param  array $requiredFiles
     * @return FileGenerator
     */
    public function setRequiredFiles(array! requiredFiles) -> <FileGenerator>
    {

    }

    /**
     * @return array
     */
    public function getRequiredFiles() -> array
    {

    }

    /**
     * @return string
     */
    public function getNamespace() -> string
    {

    }

    /**
     * @param  string $namespace
     * @return FileGenerator
     */
    public function setNamespace(string $namespace) -> <FileGenerator>
    {

    }

    /**
     * Returns an array with the first element the use statement, second is the as part.
     * If $withResolvedAs is set to true, there will be a third element that is the
     * "resolved" as statement, as the second part is not required in use statements
     *
     * @param  bool $withResolvedAs
     * @return array
     */
    public function getUses(boolean withResolvedAs = false) -> array
    {

    }

    /**
     * @param  array $uses
     * @return FileGenerator
     */
    public function setUses(array! uses) -> <FileGenerator>
    {

    }

    /**
     * @param  string $use
     * @param  null|string $as
     * @return FileGenerator
     */
    public function setUse(string $use, string $as = null) -> <FileGenerator>
    {

    }

    /**
     * @param  array $classes
     * @return FileGenerator
     */
    public function setClasses(array! classes) -> <FileGenerator>
    {

    }

    /**
     * @param  string $name
     * @return ClassGenerator
     */
    public function getClass(string name = null) -> <ClassGenerator>
    {

    }

    /**
     * @param  array|string|ClassGenerator $class
     * @throws Exception\InvalidArgumentException
     * @return FileGenerator
     */
    public function setClass(var $class) -> <FileGenerator>
    {

    }

    /**
     * @param  string $filename
     * @return FileGenerator
     */
    public function setFilename(string filename) -> <FileGenerator>
    {

    }

    /**
     * @return string
     */
    public function getFilename() -> string
    {

    }

    /**
     * @return ClassGenerator[]
     */
    public function getClasses() -> array
    {

    }

    /**
     * @param  string $body
     * @return FileGenerator
     */
    public function setBody(string body) -> <FileGenerator>
    {

    }

    /**
     * @return string
     */
    public function getBody() -> string
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

    /**
     * @return FileGenerator
     * @throws Exception\RuntimeException
     */
    public function write() -> <FileGenerator>
    {

    }

}
