/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator\DocBlock\Tag;

class MethodTag extends AbstractTypeableTag implements TagInterface
{

    /**
     * @var string
     */
    protected methodName;

    /**
     * @var bool
     */
    protected isStatic = false;

    /**
     * @param string $methodName
     * @param array $types
     * @param string $description
     * @param bool $isStatic
     */
    public function __construct(string methodName = null, var types = [], string description = null, boolean isStatic = false)
    {
        if !empty methodName {
            this->setMethodName(methodName);
        }
        this->setIsStatic(isStatic);

        parent::__construct(types, description);
    }

    /**
     * @return string
     */
    public function getName() -> string
    {
        return "method";
    }

    /**
     * @param boolean $isStatic
     * @return MethodTag
     */
    public function setIsStatic(boolean isStatic) -> <MethodTag>
    {
        let this->isStatic = isStatic;

        return this;
    }

    /**
     * @return boolean
     */
    public function isStatic() -> boolean
    {
        return this->isStatic;
    }

    /**
     * @param string $methodName
     * @return MethodTag
     */
    public function setMethodName(string methodName) -> <MethodTag>
    {
        let this->methodName = methodName;

        return this;
    }

    /**
     * @return string
     */
    public function getMethodName() -> string
    {
        return this->methodName;
    }

    /**
     * @return string
     */
    public function generate() -> string
    {
        string output = "@method", typesAsString;

        if this->isStatic {
            let output = output . " static";
        }
        if !empty this->types {
            let typesAsString = this->getTypesAsString();
            let output = output . " " . typesAsString;
        }
        if !empty this->methodName {
            let output = output . " " . this->methodName . "()";
        }
        if !empty this->description {
            let output = output . " " . this->description;
        }

        return output;
    }

}
