/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator\DocBlock\Tag;

use Zend\Code\Generator\DocBlock\TagManager;
use Zend\Code\Reflection\DocBlock\Tag\TagInterface as ReflectionTagInterface;

class ReturnTag extends AbstractTypeableTag implements TagInterface
{

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
        return "return";
    }

    /**
     * @param string $datatype
     * @return ReturnTag
     * @deprecated Deprecated in 2.3. Use setTypes() instead
     */
    public function setDatatype(string datatype) -> <ReturnTag>
    {
        return this->setTypes(datatype);
    }

    /**
     * @return string
     * @deprecated Deprecated in 2.3. Use getTypes() or getTypesAsString() instead
     */
    public function getDatatype() -> string
    {
        return this->getTypesAsString();
    }

    /**
     * @return string
     */
    public function generate() -> string
    {
        string output = "@return", typesAsString;

        if !empty this->types {
            let typesAsString = this->getTypesAsString();
            let output = output . " " . typesAsString;
        }
        if !empty this->description {
            let output = output . " " . this->description;
        }

        return output;
    }

}
