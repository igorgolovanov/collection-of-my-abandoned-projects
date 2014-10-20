/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator\DocBlock\Tag;

use Zend\Code\Generator\AbstractGenerator;
use Zend\Code\Generator\DocBlock\TagManager;
use Zend\Code\Reflection\DocBlock\Tag\TagInterface as ReflectionTagInterface;

class AuthorTag extends AbstractGenerator implements TagInterface
{
    /**
     * @var string
     */
    protected authorName;

    /**
     * @var string
     */
    protected authorEmail;

    /**
     * @param string $authorName
     * @param string $authorEmail
     */
    public function __construct(string authorName = null, string authorEmail = null)
    {
        if !empty authorName {
            this->setAuthorName(authorName);
        }
        if !empty authorEmail {
            this->setAuthorEmail(authorEmail);
        }
    }

    /**
     * @param ReflectionTagInterface $reflectionTag
     * @return ReturnTag
     * @deprecated Deprecated in 2.3. Use TagManager::createTagFromReflection() instead
     */
    public static function fromReflection(<ReflectionTagInterface> reflectionTag) -> <TagInterface>
    {
        var manager, tag;

        let manager = new TagManager();
        manager->initializeDefaultTags();

        let tag = <TagInterface> manager->createTagFromReflection(reflectionTag);

        return tag;
    }

    /**
     * @return string
     */
    public function getName() -> string
    {
        return "author";
    }

    /**
     * @param string $authorEmail
     * @return AuthorTag
     */
    public function setAuthorEmail(string authorEmail) -> self
    {
        let this->authorEmail = authorEmail;

        return this;
    }

    /**
     * @return string
     */
    public function getAuthorEmail() -> string
    {
        return this->authorEmail;
    }

    /**
     * @param string $authorName
     * @return AuthorTag
     */
    public function setAuthorName(string authorName) -> self
    {
        let this->authorName = authorName;

        return this;
    }

    /**
     * @return string
     */
    public function getAuthorName() -> string
    {
        return this->authorName;
    }

    /**
     * @return string
     */
    public function generate() -> string
    {
        string output = "@author";

        if !empty this->authorName {
            let output = output . " " . this->authorName;
        }
        if !empty this->authorEmail {
            let output = output . " <" . this->authorEmail . ">";
        }

        return output;
    }

}
