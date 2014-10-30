/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Cache\Storage;

interface IteratorInterface extends \Iterator
{
    const CURRENT_AS_SELF = 0;

    const CURRENT_AS_KEY = 1;

    const CURRENT_AS_VALUE = 2;

    const CURRENT_AS_METADATA = 3;

    /**
     * Get storage instance
     *
     * @return StorageInterface
     */
    public function getStorage() -> <StorageInterface>;

    /**
     * Get iterator mode
     *
     * @return int Value of IteratorInterface::CURRENT_AS_*
     */
    public function getMode() -> int;

    /**
     * Set iterator mode
     *
     * @param int $mode Value of IteratorInterface::CURRENT_AS_*
     * @return IteratorInterface Fluent interface
     */
    public function setMode(int mode) -> <IteratorInterface>;

}
