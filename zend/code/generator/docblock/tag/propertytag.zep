/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator\DocBlock\Tag;

class PropertyTag extends AbstractTypeableTag implements TagInterface
{
    /**
     * @var string
     */
    protected propertyName;

    /**
     * @param string $propertyName
     * @param array $types
     * @param string $description
     */
    public function __construct(string propertyName = null, var types = [], string description = null)
    {
        if !empty propertyName {
            this->setPropertyName(propertyName);
        }

        parent::__construct(types, description);
    }

    /**
     * @return string
     */
    public function getName() -> string
    {
        return "property";
    }

    /**
     * @param string $propertyName
     * @return self
     */
    public function setPropertyName(string propertyName) -> self
    {
        string name;

        let name = ltrim(propertyName, "$");
        let this->propertyName = name;

        return this;
    }

    /**
     * @return string
     */
    public function getPropertyName() -> string
    {
        return propertyName;
    }

    /**
     * @return string
     */
    public function generate() -> string
    {
        string output = "@property", typesAsString;

        if !empty this->types {
            let typesAsString = this->getTypesAsString();
            let output = output . " " . typesAsString;
        }
        if !empty this->propertyName {
            let output = output . " $" . this->propertyName;
        }
        if !empty this->description {
            let output = output . " " . this->description;
        }

        return output;
    }

}
