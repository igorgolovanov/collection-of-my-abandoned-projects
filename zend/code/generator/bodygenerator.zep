/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

class BodyGenerator extends AbstractGenerator
{
    /**
     * @var string
     */
    protected content;

    /**
     * @param  string $content
     * @return BodyGenerator
     */
    public function setContent(string content) -> <BodyGenerator>
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
        string content;

        let content = this->getContent();

        return content;
    }

}
