/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Session\Storage;

// todo: types

/**
 * Session storage interface
 *
 * Defines the minimum requirements for handling userland, in-script session
 * storage (e.g., the $_SESSION superglobal array).
 */
interface StorageInterface extends \ArrayAccess, \Serializable, \Countable
{
    public function getRequestAccessTime();

    public function lock(key = null);

    public function isLocked(key = null);

    public function unlock(key = null);

    public function markImmutable();

    public function isImmutable();

    public function setMetadata(key, value, boolean overwriteArray = false);

    public function getMetadata(key = null);

    public function clear(key = null);

    public function fromArray(array! $array);

    public function toArray(boolean metaData = false);

}
