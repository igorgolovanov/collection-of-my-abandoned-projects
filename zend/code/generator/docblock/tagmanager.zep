/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator\DocBlock;

use Zend\Code\Generator\DocBlock\Tag\TagInterface;
use Zend\Code\Generic\Prototype\PrototypeClassFactory;
use Zend\Code\Reflection\DocBlock\Tag\TagInterface as ReflectionTagInterface;

/**
 * This class is used in DocBlockGenerator and creates the needed
 * Tag classes depending on the tag. So for example an @author tag
 * will trigger the creation of an AuthorTag class.
 *
 * If none of the classes is applicable, the GenericTag class will be
 * created
 */
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
     * @param ReflectionTagInterface $reflectionTag
     * @return TagInterface
     */
    public function createTagFromReflection(<ReflectionTagInterface> reflectionTag) -> <TagInterface>
    {
        string tagName, methodName, propertyName, methodNameTag;
        var tag, reflectionClass, method, value;
        array methods;

        let tagName = reflectionTag->getName();
        let tag = <TagInterface> this->getClonedPrototype(tagName);
        let reflectionClass = new \ReflectionClass(reflectionTag);

        let methods = reflectionClass->getMethods(\ReflectionMethod::IS_PUBLIC);
        for method in methods {
            let methodName = method->getName();

            if substr(methodName, 0, 3) == "get" {
                let propertyName = substr(methodName, 3);
                let methodNameTag = "set" . propertyName;
                if method_exists(tag, methodNameTag) {
                    let value = reflectionTag->{methodName}();
                    tag->{methodNameTag}(value);
                }
            } else {
                if substr(methodName, 0, 2) == "is" {
                    let propertyName = ucfirst(methodName);
                    let methodNameTag = "set" . propertyName;
                    if method_exists(tag, methodNameTag) {
                        let value = reflectionTag->{methodName}();
                        tag->{methodNameTag}(value);
                    }
                }
            }
        }

        return tag;
    }

}
