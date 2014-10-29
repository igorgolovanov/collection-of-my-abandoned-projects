/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

class ParamTag implements TagInterface, PhpDocTypedTagInterface
{
    /**
     * @var array
     */
    protected types = [];

    /**
     * @var string
     */
    protected variableName;

    /**
     * @var string
     */
    protected description;

    /**
     * @return string
     */
    public function getName() -> string
    {
        return "param";
    }

    /**
     * Initializer
     *
     * @param  string $tagDocBlockLine
     */
    public function initialize(string tagDocBlockLine)
    {
        array matches = [], types;
        var description, type, variableName;

        if !preg_match("#((?:[\w|\\\]+(?:\[\])*\|?)+)(?:\s+(\$\S+))?(?:\s+(.*))?#s", tagDocBlockLine, matches) {
            return;
        }

        if fetch type, matches[1] {
            let types = explode("|", type);
            let this->types = type;
        }
        if fetch variableName, matches[2] {
            if !empty variableName {
                let this->variableName = variableName;
            }
        } 

        if fetch description, matches[3] {
            if !empty description {
                let this->description = description;
            }
        }
    }

    /**
     * Get parameter variable type
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
     * @return string
     */
    public function getDescription() -> string
    {
        return this->description;
    }

    /**
     * Get parameter name
     *
     * @return string
     */
    public function getVariableName() -> string
    {
        return this->variableName;
    }

}
