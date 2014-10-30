/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Session\Storage;

/**
 * Session storage interface
 *
 * Defines the minimum requirements for handling userland, in-script session
 * storage (e.g., the $_SESSION superglobal array).
 */
interface StorageInitializationInterface
{
    /**
     * Initialize Session Storage
     *
     * @param  array $input
     * @return void
     */
    public function init(array input = null) -> void;

}
