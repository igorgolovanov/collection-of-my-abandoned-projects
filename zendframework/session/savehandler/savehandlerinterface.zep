/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Session\SaveHandler;

/**
 * SaveHandler Interface
 *
 * @see        http://php.net/session_set_save_handler
 */
interface SaveHandlerInterface
{
    /**
     * Open Session - retrieve resources
     *
     * @param string $savePath
     * @param string $name
     */
    public function open(string savePath, string name);

    /**
     * Close Session - free resources
     *
     */
    public function close();

    /**
     * Read session data
     *
     * @param string $id
     */
    public function read(string id);

    /**
     * Write Session - commit data to resource
     *
     * @param string $id
     * @param mixed $data
     */
    public function write(string id, data);

    /**
     * Destroy Session - remove data from resource for
     * given session id
     *
     * @param string $id
     */
    public function destroy(string id);

    /**
     * Garbage Collection - remove old session data older
     * than $maxlifetime (in seconds)
     *
     * @param int $maxlifetime
     */
    public function gc(int maxlifetime);

}
