/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Adapter\Driver;

interface ResultInterface extends \Countable, \Iterator
{
    /**
     * Force buffering
     *
     * @return void
     */
    public function buffer() -> void;

    /**
     * Check if is buffered
     *
     * @return bool|null
     */
    public function isBuffered() -> boolean;

    /**
     * Is query result?
     *
     * @return bool
     */
    public function isQueryResult() -> boolean;

    /**
     * Get affected rows
     *
     * @return int
     */
    public function getAffectedRows() -> int;

    /**
     * Get generated value
     *
     * @return mixed|null
     */
    public function getGeneratedValue();

    /**
     * Get the resource
     *
     * @return mixed
     */
    public function getResource();

    /**
     * Get field count
     *
     * @return int
     */
    public function getFieldCount() -> int;

}
