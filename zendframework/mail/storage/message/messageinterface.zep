/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mail\Storage\Message;

interface MessageInterface
{
    /**
     * return toplines as found after headers
     *
     * @return string toplines
     */
    public function getTopLines() -> string;

    /**
     * check if flag is set
     *
     * @param mixed $flag a flag name, use constants defined in Zend\Mail\Storage
     * @return bool true if set, otherwise false
     */
    public function hasFlag(flag) -> boolean;

    /**
     * get all set flags
     *
     * @return array array with flags, key and value are the same for easy lookup
     */
    public function getFlags() -> array;

}
