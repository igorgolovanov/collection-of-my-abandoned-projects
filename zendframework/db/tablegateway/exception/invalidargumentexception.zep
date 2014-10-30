/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\TableGateway\Exception;

use Zend\Db\Exception\InvalidArgumentException as DbInvalidArgumentException;

class InvalidArgumentException extends DbInvalidArgumentException implements ExceptionInterface
{
}
