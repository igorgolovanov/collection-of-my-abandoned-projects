/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection\DocBlock\Tag;

class AuthorTag implements TagInterface, \Zend\Code\Generic\Prototype\PrototypeInterface
{
    /**
     * @var string
     */
    protected authorName;

    /**
     * @var string
     */
    protected authorEmail;

    /**
     * @return string
     */
    public function getName() -> string
    {
        return "author";
    }

    /**
     * Initializer
     *
     * @param  string $tagDocblockLine
     */
    public function initialize(string tagDocblockLine) -> void
    {
        array match = [];
        var val;

        if preg_match("/^([^\<]*)(\<([^\>]*)\>)?(.*)$/u", tagDocblockLine, match) {
            return;
        }

        if fetch val, match[1] {
            if val !== "" {
                let this->authorName = val;
            }
        }

        if fetch val, match[3] {
            if val !== "" {
                let this->authorEmail = val;
            }
        }
    }

    /**
     * @return null|string
     */
    public function getAuthorName() -> string
    {
        return this->authorName;
    }

    /**
     * @return null|string
     */
    public function getAuthorEmail() -> string
    {
        return this->authorEmail;
    }

    public function __toString() -> string
    {
        string msg, name;

        let name = this->getName();
        let msg = "DocBlock Tag [ * @" . name . " ]" . PHP_EOL;

        return msg;
    }

}
