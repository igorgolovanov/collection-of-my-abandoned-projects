/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

use Zend\Code\Generic\Prototype\PrototypeGenericInterface;

class GenericTag implements TagInterface, PrototypeGenericInterface
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
    protected values = [];

    /**
     * @param  string $contentSplitCharacter
     */
    public function __construct(string contentSplitCharacter = " ")
    {
        let this->contentSplitCharacter = contentSplitCharacter;
    }

    /**
     * @param  string $tagDocBlockLine
     * @return void
     */
    public function initialize(string tagDocBlockLine) -> void
    {
        this->parse(tagDocBlockLine);
    }

    /**
     * Get annotation tag name
     *
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * @param  string $name
     */
    public function setName(string name)
    {
        let this->name = name;
    }

    /**
     * @return string
     */
    public function getContent() -> string
    {
        return this->content;
    }

    /**
     * @param  int $position
     * @return string
     */
    public function returnValue(int position) -> string
    {
        var value;
        if fetch value, this->values[position] {
            return value;
        }
        return "";
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
        string output;

        let output = "DocBlock Tag [ * @" . this->name . " ]" . PHP_EOL;

        return output;
    }

    /**
     * @param  string $docBlockLine
     */
    protected function parse(string docBlockLine)
    {
        array values;

        let values = explode(this->contentSplitCharacter, docBlockLine);

        let this->content = docBlockLine->trim();
        let this->values = values;
    }

}
