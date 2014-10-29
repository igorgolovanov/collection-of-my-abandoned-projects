/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock;

use Zend\Code\Generic\Prototype\PrototypeClassFactory;
use Zend\Code\Reflection\DocBlock\Tag\TagInterface;

class TagManager extends PrototypeClassFactory
{
    /**
     * @return void
     */
    public function initializeDefaultTags() -> void
    {
        this->addPrototype(new Tag\ParamTag());
        this->addPrototype(new Tag\ReturnTag());
        this->addPrototype(new Tag\MethodTag());
        this->addPrototype(new Tag\PropertyTag());
        this->addPrototype(new Tag\AuthorTag());
        this->addPrototype(new Tag\LicenseTag());
        this->addPrototype(new Tag\ThrowsTag());
        this->setGenericPrototype(new Tag\GenericTag());
    }

    /**
     * @param string $tagName
     * @param string $content
     * @return TagInterface
     */
    public function createTag(string tagName, string content = null) -> <TagInterface>
    {
        var tag;

        let tag = <TagInterface> this->getClonedPrototype(tagName);

        if !empty content {
            tag->initialize(content);
        }

        return tag;
    }

}
