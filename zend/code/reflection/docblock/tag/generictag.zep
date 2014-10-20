/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

class GenericTag implements TagInterface, \Zend\Code\Generic\Prototype\PrototypeInterface, \Zend\Code\Generic\Prototype\PrototypeGenericInterface
{
    /**
     * @var string
     */
    protected name;

    /**
     * @var string
     */
    protected content;

    /**
     * @var null|string
     */
    protected contentSplitCharacter;

    /**
     * @var array
     */
    protected values; // []

    /**
     * @param  string $contentSplitCharacter
     */
    public function __construct(string contentSplitCharacter = " ")
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
     * Get annotation tag name
     *
     * @return string
     */
    public function getName() -> string
    {

    }

    /**
     * @param  string $name
     */
    public function setName(string name)
    {

    }

    /**
     * @return string
     */
    public function getContent() -> string
    {

    }

    /**
     * @param  int $position
     * @return string
     */
    public function returnValue(int position) -> string
    {

    }

    /**
     * Serialize to string
     *
     * Required by Reflector
     *
     * @todo   What should this do?
     * @return string
     */
    public function __toString() -> string
    {

    }

    /**
     * @param  string $docBlockLine
     */
    protected function parse(string docBlockLine)
    {

    }

}
