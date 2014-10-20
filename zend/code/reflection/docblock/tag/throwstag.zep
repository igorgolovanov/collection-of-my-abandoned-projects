/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

class ThrowsTag implements TagInterface, \Zend\Code\Generic\Prototype\PrototypeInterface, PhpDocTypedTagInterface
{
    /**
     * @var array
     */
    protected types; // []

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
     * @param  string $tagDocBlockLine
     * @return void
     */
    public function initialize(string tagDocBlockLine) -> void
    {

    }

    /**
     * Get return variable type
     *
     * @return string
     * @deprecated 2.0.4 use getTypes instead
     */
    public function getType() -> string
    {

    }

    /**
     * @return array
     */
    public function getTypes() -> array
    {

    }

    /**
     * @return string
     */
    public function getDescription() -> string
    {

    }

}
