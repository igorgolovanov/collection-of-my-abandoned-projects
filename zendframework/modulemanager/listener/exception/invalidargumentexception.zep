/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\ModuleManager\Listener\Exception;

use Zend\ModuleManager\Exception\InvalidArgumentException as ModuleManagerInvalidArgumentException;

/**
 * Invalid Argument Exception
 */
class InvalidArgumentException extends ModuleManagerInvalidArgumentException implements ExceptionInterface
{
}
