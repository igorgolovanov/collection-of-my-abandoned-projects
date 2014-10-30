/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Adapter\Driver;

interface StatementInterface // TODO: extends \Zend\Db\Adapter\StatementContainerInterface
{
    /**
     * Get resource
     *
     * @return resource
     */
    public function getResource() -> resource;

    /**
     * Prepare sql
     *
     * @param string $sql
     */
    public function prepare(string sql = null);

    /**
     * Check if is prepared
     *
     * @return bool
     */
    public function isPrepared() -> boolean;

    /**
     * Execute
     *
     * @param null $parameters
     * @return ResultInterface
     */
    public function execute(var parameters = null) -> <ResultInterface>;

}
