/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

class DocBlockGenerator extends AbstractGenerator implements GeneratorInterface
{
    const LINE_FEED = "
";

    /**
     * @var string
     */
    protected shortDescription;

    /**
     * @var string
     */
    protected longDescription;

    /**
     * @var array
     */
    protected tags; // []

    /**
     * @var string
     */
    protected indentation = "";

    /**
     * @var bool
     */
    protected wordwrap = true;

    protected static tagManager;

    /**
     * Build a DocBlock generator object from a reflection object
     *
     * @param  DocBlockReflection $reflectionDocBlock
     * @return DocBlockGenerator
     */
    public static function fromReflection(reflectionDocBlock) -> <DocBlockGenerator>
    {

    }

    /**
     * Generate from array
     *
     * @configkey shortdescription string The short description for this doc block
     * @configkey longdescription  string The long description for this doc block
     * @configkey tags             array
     *
     * @throws Exception\InvalidArgumentException
     * @param  array $array
     * @return DocBlockGenerator
     */
    public static function fromArray(array! $array) -> <DocBlockGenerator>
    {

    }

    protected static function getTagManager()
    {

    }

    /**
     * @param  string $shortDescription
     * @param  string $longDescription
     * @param  array $tags
     */
    public function __construct(string shortDescription = null, string longDescription = null, array! tags = [])
    {

    }

    /**
     * @param  string $shortDescription
     * @return DocBlockGenerator
     */
    public function setShortDescription(string shortDescription) -> <DocBlockGenerator>
    {

    }

    /**
     * @return string
     */
    public function getShortDescription() -> string
    {

    }

    /**
     * @param  string $longDescription
     * @return DocBlockGenerator
     */
    public function setLongDescription(string longDescription) -> <DocBlockGenerator>
    {

    }

    /**
     * @return string
     */
    public function getLongDescription() -> string
    {

    }

    /**
     * @param  array $tags
     * @return DocBlockGenerator
     */
    public function setTags(array! tags) -> <DocBlockGenerator>
    {

    }

    /**
     * @param array|TagInterface $tag
     * @throws Exception\InvalidArgumentException
     * @return DocBlockGenerator
     */
    public function setTag(array tag) -> <DocBlockGenerator>
    {

    }

    /**
     * @return TagInterface[]
     */
    public function getTags() -> array
    {

    }

    /**
     * @param bool $value
     * @return DocBlockGenerator
     */
    public function setWordWrap(boolean value) -> <DocBlockGenerator>
    {

    }

    /**
     * @return bool
     */
    public function getWordWrap() -> boolean
    {

    }

    /**
     * @return string
     */
    public function generate() -> string
    {

    }

    /**
     * @param  string $content
     * @return string
     */
    protected function docCommentize(string content) -> string
    {

    }

}
