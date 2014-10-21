/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

class LicenseTag implements TagInterface
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
        return "license";
    }

    /**
     * Initializer
     *
     * @param  string $tagDocblockLine
     */
    public function initialize(string tagDocblockLine)
    {
        array match = [];
        var url, licenseName;

        if !preg_match("#^([\S]*)(?:\s+(.*))?$#m", tagDocblockLine, match) {
            return;
        }

        if fetch url, match[1] {
            if url !== "" {
                let this->url = trim(url);
            }
        }

        if fetch licenseName, match[1] {
            if licenseName !== "" {
                let this->licenseName = licenseName;
            }
        }
    }

    /**
     * @return null|string
     */
    public function getUrl() -> string
    {
        return this->url;
    }

    /**
     * @return null|string
     */
    public function getLicenseName() -> string
    {
        return this->licenseName;
    }

    public function __toString()
    {
        string name, output;

        let name = this->getName();
        let output = "DocBlock Tag [ * @" . name . " ]" . PHP_EOL;

        return output;
    }

}
