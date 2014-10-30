/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Adapter\Driver;

interface ConnectionInterface
{
    /**
     * Get current schema
     *
     * @return string
     */
    public function getCurrentSchema() -> string;

    /**
     * Get resource
     *
     * @return mixed
     */
    public function getResource();

    /**
     * Connect
     *
     * @return ConnectionInterface
     */
    public function connect() -> <ConnectionInterface>;

    /**
     * Is connected
     *
     * @return bool
     */
    public function isConnected() -> boolean;

    /**
     * Disconnect
     *
     * @return ConnectionInterface
     */
    public function disconnect() -> <ConnectionInterface>;

    /**
     * Begin transaction
     *
     * @return ConnectionInterface
     */
    public function beginTransaction() -> <ConnectionInterface>;

    /**
     * Commit
     *
     * @return ConnectionInterface
     */
    public function commit() -> <ConnectionInterface>;

    /**
     * Rollback
     *
     * @return ConnectionInterface
     */
    public function rollback() -> <ConnectionInterface>;

    /**
     * Execute
     *
     * @param  string $sql
     * @return ResultInterface
     */
    public function execute(string sql) -> <ResultInterface>;

    /**
     * Get last generated id
     *
     * @param  null $name Ignored
     * @return int
     */
    public function getLastGeneratedValue(var name = null) -> int;

}
