/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

class PropertyTag implements TagInterface, \Zend\Code\Generic\Prototype\PrototypeInterface, PhpDocTypedTagInterface
{
    /**
     * @var array
     */
    protected types; // []

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
     * @return null|string
     * @deprecated 2.0.4 use getTypes instead
     */
    public function getType() -> string
    {

    }

    public function getTypes()
    {

    }

    /**
     * @return null|string
     */
    public function getPropertyName() -> string
    {

    }

    /**
     * @return null|string
     */
    public function getDescription() -> string
    {

    }

    public function __toString()
    {

    }

}
