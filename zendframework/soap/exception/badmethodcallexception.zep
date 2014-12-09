/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Soap\Exception;

/**
 * Exception thrown when unrecognized method is called via overloading
 */
class BadMethodCallException extends \BadMethodCallException implements ExceptionInterface
{
}
