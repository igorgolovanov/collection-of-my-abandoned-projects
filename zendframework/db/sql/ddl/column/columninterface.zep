/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Sql\Ddl\Column;

use Zend\Db\Sql\ExpressionInterface;

interface ColumnInterface extends ExpressionInterface
{
    const TYPE_IDENTIFIER = "identifier";

    const TYPE_VALUE = "value";

    const TYPE_LITERAL = "literal";

    public function getName() -> string;

    public function isNullable() -> boolean;

    public function getDefault();

    public function getOptions() -> array;

}
