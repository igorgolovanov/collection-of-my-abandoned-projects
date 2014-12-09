/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Json\Server\Exception;

use Zend\Json\Exception;

/**
 * Thrown by Zend\Json\Server\Client when a JSON-RPC fault response is returned.
 */
class ErrorException extends Exception\BadMethodCallException implements
    ExceptionInterface
{}
