/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

class MethodTag implements TagInterface, \Zend\Code\Generic\Prototype\PrototypeInterface, PhpDocTypedTagInterface
{
    /**
     * Return value type
     *
     * @var array
     */
    protected types; // []

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

    }

    /**
     * Initializer
     *
     * @param  string $tagDocblockLine
     */
    public function initialize(string tagDocblockLine)
    {

    }

    /**
     * Get return value type
     *
     * @return null|string
     * @deprecated 2.0.4 use getTypes instead
     */
    public function getReturnType() -> string
    {

    }

    public function getTypes()
    {

    }

    /**
     * @return string
     */
    public function getMethodName() -> string
    {

    }

    /**
     * @return null|string
     */
    public function getDescription() -> string
    {

    }

    /**
     * @return bool
     */
    public function isStatic() -> boolean
    {

    }

    public function __toString()
    {

    }

}
