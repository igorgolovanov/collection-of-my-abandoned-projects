/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Crypt\Symmetric\Exception;

use Zend\Crypt\Exception;

/**
 * Runtime argument exception
 */
class RuntimeException extends Exception\RuntimeException implements
    ExceptionInterface
{
}