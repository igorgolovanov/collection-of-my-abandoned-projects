/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator\DocBlock\Tag;

use Zend\Code\Generator\AbstractGenerator;
use Zend\Code\Generic\Prototype\PrototypeGenericInterface;

class GenericTag extends AbstractGenerator implements TagInterface, PrototypeGenericInterface
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
     * @param string $name
     * @param string $content
     */
    public function __construct(string name = null, string content = null)
    {
        if !empty name {
            this->setName(name);
        }
        if !empty content {
            this->setContent(content);
        }
    }

    /**
     * @param  string $name
     * @return GenericTag
     */
    public function setName(string name) -> <GenericTag>
    {
        let this->name = name;

        return this;
    }

    /**
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * @param string $content
     * @return GenericTag
     */
    public function setContent(string content) -> <GenericTag>
    {
        let this->content = content;

        return this;
    }

    /**
     * @return string
     */
    public function getContent() -> string
    {
        return this->content;
    }

    /**
     * @return string
     */
    public function generate() -> string
    {
        string output = "@" . this->name;

        if !empty this->content {
            let output = output . " " . this->content;
        }

        return output;
    }

}
