/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\TableGateway;

// todo:  types

interface TableGatewayInterface
{
    public function getTable();

    public function select(where = null);

    public function insert(set);

    public function update(set, where = null);

    public function delete(where);

}
