/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection;

use Reflector;
use Zend\Code\Reflection\DocBlock\Tag\TagInterface as DocBlockTagInterface;
use Zend\Code\Reflection\DocBlock\TagManager as DocBlockTagManager;
use Zend\Code\Scanner\DocBlockScanner;

class DocBlockReflection implements ReflectionInterface
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
    public function __construct(var commentOrReflector, <DocBlockTagManager> tagManager = null) -> <DocBlockReflection>
    {
        string exceptionMsg, className;
        int lineCount;

        if tagManager === null {
            let tagManager = new DocBlockTagManager();
            tagManager->initializeDefaultTags();
        }
        let this->tagManager = tagManager;

        if commentOrReflector instanceof Reflector {
            let this->reflector = commentOrReflector;
            if unlikely !method_exists(commentOrReflector, "getDocComment") {
                throw new Exception\InvalidArgumentException("Reflector must contain method \"getDocComment\"");
            }
            let this->docComment = commentOrReflector->getDocComment();

            // determine line numbers
            let lineCount = substr_count(this->docComment, "\n");
            let this->startLine = commentOrReflector->getStartLine() - lineCount - 1;
            let this->endLine = commentOrReflector->getStartLine() - 1;
        } else {
            if unlikely typeof commentOrReflector != "string" {
                let className = get_class(this);
                let exceptionMsg = className . " must have a (string) DocComment or a Reflector in the constructor";

                throw new Exception\InvalidArgumentException(exceptionMsg);
            }
            let this->docComment = commentOrReflector;
        }

        if unlikely this->docComment == "" {
            throw new Exception\InvalidArgumentException("DocComment cannot be empty");
        }

        this->reflect();
    }

    /**
     * Retrieve contents of DocBlock
     *
     * @return string
     */
    public function getContents() -> string
    {
        this->reflect();

        return this->cleanDocComment;
    }

    /**
     * Get start line (position) of DocBlock
     *
     * @return int
     */
    public function getStartLine() -> int
    {
        this->reflect();

        return this->startLine;
    }

    /**
     * Get last line (position) of DocBlock
     *
     * @return int
     */
    public function getEndLine() -> int
    {
        this->reflect();

        return this->endLine;
    }

    /**
     * Get DocBlock short description
     *
     * @return string
     */
    public function getShortDescription() -> string
    {
        this->reflect();

        return this->shortDescription;
    }

    /**
     * Get DocBlock long description
     *
     * @return string
     */
    public function getLongDescription() -> string
    {
        this->reflect();

        return this->longDescription;
    }

    /**
     * Does the DocBlock contain the given annotation tag?
     *
     * @param  string $name
     * @return bool
     */
    public function hasTag(string name) -> boolean
    {
        var tag;
        string tagName;

        this->reflect();

        for tag in this->tags {
            let tagName = tag->getName();
            if tagName == name {
                return true;
            }
        }

        return false;
    }

    /**
     * Retrieve the given DocBlock tag
     *
     * @param  string $name
     * @return DocBlockTagInterface|false
     */
    public function getTag(string name) -> <DocBlockTagInterface>|boolean
    {
        var tag;
        string tagName;

        this->reflect();

        for tag in this->tags {
            let tagName = tag->getName();
            if tagName == name {
                return tag;
            }
        }

        return false;
    }

    /**
     * Get all DocBlock annotation tags
     *
     * @param  string $filter
     * @return DocBlockTagInterface[]
     */
    public function getTags(var filter = null) -> array
    {
        array returnTags = [];
        var tag;
        string name;

        this->reflect();
        if filter === null || typeof filter == "string" {
            return this->tags;
        }

        for tag in this->tags {
            let name = tag->getName();
            if name == filter {
                let returnTags[] = tag;
            }
        }

        return returnTags;
    }

    /**
     * Parse the DocBlock
     *
     * @return void
     */
    protected function reflect() -> void
    {
        string docComment, shortDescription, longDescription, tagName, tagContent;
        var scanner, tagData, tagManager, tag;
        array tags;

        if this->isReflected {
            return;
        }
        let docComment = this->docComment;
        // create a clean docComment
        let this->cleanDocComment = preg_replace("#[ \t]*(?:/\*\*|\*/|\*)[ ]{0,1}(.*)?#", "$1", docComment);
        let this->cleanDocComment = ltrim(this->cleanDocComment, "\r\n"); // @todo should be changed to remove first and last empty line

        let scanner = new DocBlockScanner(docComment);
        let shortDescription = scanner->getShortDescription();
        let longDescription = scanner->getLongDescription();

        let this->shortDescription = ltrim(shortDescription);
        let this->longDescription = ltrim(longDescription);

        let tagManager = <DocBlockTagManager> this->tagManager;
        let tags = scanner->getTags();
        for tagData in tags {
            let tagName = ltrim(tagData["name"], "@");
            let tagContent = ltrim(tagData["value"]);

            let tag = tagManager->createTag(tagName, tagContent);

            let this->tags[] = tag;
        }
        let this->isReflected = true;
    }

    public function toString()
    {
        string output, tagStr;
        var count, tag;

        let count = count(this->tags);
        let output = "DocBlock [ /* DocBlock */ ] {" . PHP_EOL . PHP_EOL;
        let output = output . "  - Tags [" . count . "] {" . PHP_EOL;

        for tag in this->tags {
            let tagStr = strval(tag);
            let output = output . "    " . tagStr;
        }

        let output = output . "  }" . PHP_EOL;
        let output = output . "}" . PHP_EOL;

        return output;
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
        return this->toString();
    }

}
