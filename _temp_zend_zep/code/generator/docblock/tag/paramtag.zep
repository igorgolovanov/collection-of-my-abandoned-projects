/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator\DocBlock\Tag;

use Zend\Code\Generator\DocBlock\TagManager;
use Zend\Code\Reflection\DocBlock\Tag\TagInterface as ReflectionTagInterface;

class ParamTag extends AbstractTypeableTag implements TagInterface
{
    /**
     * @var string
     */
    protected variableName;

    /**
     * @param string $variableName
     * @param array $types
     * @param string $description
     */
    public function __construct(string variableName = null, var types = [], string description = null)
    {
        if !empty variableName {
            this->setVariableName(variableName);
        }

        parent::__construct(types, description);
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
        return "param";
    }

    /**
     * @param string $variableName
     * @return ParamTag
     */
    public function setVariableName(string variableName) -> <ParamTag>
    {
        string name;

        let name = ltrim(variableName, "$");
        let this->variableName = name;

        return this;
    }

    /**
     * @return string
     */
    public function getVariableName() -> string
    {
        return this->variableName;
    }

    /**
     * @param string $datatype
     * @return ReturnTag
     * @deprecated Deprecated in 2.3. Use setTypes() instead
     */
    public function setDatatype(string datatype) -> <ParamTag>
    {
        let this->datatype = datatype;

        return this;
    }

    /**
     * @return string
     * @deprecated Deprecated in 2.3. Use getTypes() or getTypesAsString() instead
     */
    public function getDatatype() -> string
    {
        return this->datatype;
    }

    /**
     * @param  string $paramName
     * @return ParamTag
     * @deprecated Deprecated in 2.3. Use setVariableName() instead
     */
    public function setParamName(string paramName) -> <ParamTag>
    {
        let this->paramName = paramName;

        return this;
    }

    /**
     * @return string
     * @deprecated Deprecated in 2.3. Use getVariableName() instead
     */
    public function getParamName() -> string
    {
        return this->paramName;
    }

    /**
     * @return string
     */
    public function generate() -> string
    {
        string output = "@param", typesAsString;

        if !empty this->types {
            let typesAsString = this->getTypesAsString();
            let output = output . " " . typesAsString;
        }
        if !empty this->variableName {
            let output = output . " $" . this->variableName;
        }
        if !empty this->description {
            let output = output . " " . this->description;
        }

        return output;
    }

}
