/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

class LicenseTag implements TagInterface, \Zend\Code\Generic\Prototype\PrototypeInterface
{
    /**
     * @var string
     */
    protected url;

    /**
     * @var string
     */
    protected licenseName;

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
     */
    public function getUrl() -> string
    {

    }

    /**
     * @return null|string
     */
    public function getLicenseName() -> string
    {

    }

    public function __toString()
    {

    }

}
