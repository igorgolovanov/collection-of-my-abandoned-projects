/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

class PropertyTag implements TagInterface, PhpDocTypedTagInterface
{
    /**
     * @var array
     */
    protected types = [];

    /**
     * @var string
     */
    protected propertyName;

    /**
     * @var string
     */
    protected description;

    /**
     * @return string
     */
    public function getName() -> string
    {
        return "property";
    }

    /**
     * Initializer
     *
     * @param  string $tagDocBlockLine
     * @return void
     */
    public function initialize(string tagDocBlockLine) -> void
    {
        array matches = [], types;
        var description, type, propertyName;

        if !preg_match("#^(.+)?(\$[\S]+)[\s]*(.*)$#m", tagDocBlockLine, matches) {
            return;
        }

        if fetch type, matches[1] {
            let types = explode("|", type);
            let this->types = type;
        }
        if fetch propertyName, matches[2] {
            if !empty propertyName {
                let this->propertyName = propertyName;
            }
        } 

        if fetch description, matches[3] {
            if !empty description {
                let this->description = description;
            }
        }
    }

    /**
     * Get return variable type
     *
     * @return string
     * @deprecated 2.0.4 use getTypes instead
     */
    public function getType() -> string
    {
        array types;
        string type;

        let types = this->getTypes();
        let type = implode("|", types);

        return type;
    }

    /**
     * @return array
     */
    public function getTypes() -> array
    {
        return this->types;
    }

    /**
     * @return null|string
     */
    public function getDescription() -> string
    {
        return this->description;
    }

    public function __toString()
    {
        string output, name;

        let name = this->getName();
        let output = "DocBlock Tag [ * @" . name . " ]" . PHP_EOL;

        return output;
    }

}
