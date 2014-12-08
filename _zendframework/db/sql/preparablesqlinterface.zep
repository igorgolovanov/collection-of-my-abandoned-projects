/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Sql;

use Zend\Db\Adapter\AdapterInterface;

interface PreparableSqlInterface
{
    /**
     * @param AdapterInterface $adapter
     * @param StatementContainerInterface $statementContainer
     * @return void
     */
    public function prepareStatement(<AdapterInterface> adapter, statementContainer) -> void;
    // todo: StatementContainerInterface
}
