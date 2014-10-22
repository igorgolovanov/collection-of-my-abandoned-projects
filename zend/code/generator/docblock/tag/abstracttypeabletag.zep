/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator\DocBlock\Tag;

use Zend\Code\Generator\AbstractGenerator;

/**
 * This abstract class can be used as parent for all tags
 * that use a type part in their content.
 * @see http://www.phpdoc.org/docs/latest/for-users/phpdoc/types.html
 */
abstract class AbstractTypeableTag extends AbstractGenerator
{
    const LINE_FEED = "\n";

    /**
     * @var string
     */
    protected description;

    /**
     * @var array
     */
    protected types = [];

    /**
     * @param array $types
     * @param string $description
     */
    public function __construct(var types = [], string description = null)
    {
        if !empty types {
            this->setTypes(types);
        }
        if !empty description {
            this->setDescription(description);
        }
    }

    /**
     * @param string $description
     * @return AbstractTypeableTag
     */
    public function setDescription(string description) -> <AbstractTypeableTag>
    {
        let this->description = description;

        return this;
    }

    /**
     * @return string
     */
    public function getDescription() -> string
    {
        return this->description;
    }

    /**
     * Array of types or string with types delimited by pipe (|)
     * e.g. array('int', 'null') or "int|null"
     *
     * @param array|string $types
     * @return AbstractTypeableTag
     */
    public function setTypes(var types) -> <AbstractTypeableTag>
    {
        if typeof types == "string" {
            let types = explode("|", types);
        }
        let this->types = types;

        return this;
    }

    /**
     * @return array
     */
    public function getTypes() -> array
    {
        return this->types;
    }

    /**
     * @param string $delimiter
     * @return string
     */
    public function getTypesAsString(string delimiter = "|") -> string
    {
        return implode(delimiter, this->types);
    }

}
