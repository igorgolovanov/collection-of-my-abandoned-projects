/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

class MethodTag implements TagInterface, PhpDocTypedTagInterface
{
    /**
     * Return value type
     *
     * @var array
     */
    protected types = [];

    /**
     * @var string
     */
    protected methodName;

    /**
     * @var string
     */
    protected description;

    /**
     * Is static method
     *
     * @var bool
     */
    protected isStatic = false;

    /**
     * @return string
     */
    public function getName() -> string
    {
        return "method";
    }

    /**
     * Initializer
     *
     * @param  string $tagDocblockLine
     */
    public function initialize(string tagDocblockLine)
    {
        array matches = [], types;
        var description, type, methodName, isStatic;

        if !preg_match("#^(static[\s]+)?(.+[\s]+)?(.+\(\))[\s]*(.*)$#m", tagDocBlockLine, matches) {
            return;
        }

        if fetch isStatic, matches[1] {
            if isStatic {
                let this->isStatic = true;
            }
        }
        if fetch type, matches[2] {
            let type = rtrim(type);
            let types = explode("|", type);
            let this->types = type;
        }

        if fetch methodName, matches[3] {
            let this->methodName = methodName;
        } 

        if fetch description, matches[4] {
            if !empty description {
                let this->description = description;
            }
        }
    }

    /**
     * Get return value type
     *
     * @return null|string
     * @deprecated 2.0.4 use getTypes instead
     */
    public function getReturnType() -> string
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
     * @return string
     */
    public function getMethodName() -> string
    {
        return this->methodName;
    }

    /**
     * @return bool
     */
    public function isStatic() -> boolean
    {
        return this->isStatic;
    }

    public function __toString()
    {
        string name, output;

        let name = this->getName();
        let output = "DocBlock Tag [ * @" . name . " ]" . PHP_EOL;

        return output;
    }

}
