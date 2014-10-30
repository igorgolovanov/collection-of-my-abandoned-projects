/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Sql\Ddl\Constraint;

use Zend\Db\Sql\ExpressionInterface;

interface ConstraintInterface extends ExpressionInterface
{
    const TYPE_IDENTIFIER = "identifier";

    const TYPE_VALUE = "value";

    const TYPE_LITERAL = "literal";

    public function getColumns() -> array;

}
