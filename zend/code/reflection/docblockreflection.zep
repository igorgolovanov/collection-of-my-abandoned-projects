
namespace Zend\Code\Reflection;

class DocBlockReflection implements ReflectionInterface, \Reflector
{
    /**
     * @var Reflector
     */
    protected reflector;

    /**
     * @var string
     */
    protected docComment;

    /**
     * @var DocBlockTagManager
     */
    protected tagManager;

    protected startLine;

    protected endLine;

    /**
     * @var string
     */
    protected cleanDocComment;

    /**
     * @var string
     */
    protected longDescription;

    /**
     * @var string
     */
    protected shortDescription;

    /**
     * @var array
     */
    protected tags; // []

    /**
     * @var bool
     */
    protected isReflected = false;

    /**
     * Export reflection
     *
     * Required by the Reflector interface.
     *
     * @todo   What should this do?
     * @return void
     */
    public static function export() -> void
    {

    }

    /**
     * @param  Reflector|string $commentOrReflector
     * @param  null|DocBlockTagManager $tagManager
     * @throws Exception\InvalidArgumentException
     * @return DocBlockReflection
     */
    public function __construct(var commentOrReflector, tagManager = null) -> <DocBlockReflection>
    {

    }

    /**
     * Retrieve contents of DocBlock
     *
     * @return string
     */
    public function getContents() -> string
    {

    }

    /**
     * Get start line (position) of DocBlock
     *
     * @return int
     */
    public function getStartLine() -> int
    {

    }

    /**
     * Get last line (position) of DocBlock
     *
     * @return int
     */
    public function getEndLine() -> int
    {

    }

    /**
     * Get DocBlock short description
     *
     * @return string
     */
    public function getShortDescription() -> string
    {

    }

    /**
     * Get DocBlock long description
     *
     * @return string
     */
    public function getLongDescription() -> string
    {

    }

    /**
     * Does the DocBlock contain the given annotation tag?
     *
     * @param  string $name
     * @return bool
     */
    public function hasTag(string name) -> boolean
    {

    }

    /**
     * Retrieve the given DocBlock tag
     *
     * @param  string $name
     * @return DocBlockTagInterface|false
     */
    public function getTag(string name)
    {

    }

    /**
     * Get all DocBlock annotation tags
     *
     * @param  string $filter
     * @return DocBlockTagInterface[]
     */
    public function getTags(string filter = null) -> array
    {

    }

    /**
     * Parse the DocBlock
     *
     * @return void
     */
    protected function reflect() -> void
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
     * @return string
     */
    public function __toString() -> string
    {

    }

}
