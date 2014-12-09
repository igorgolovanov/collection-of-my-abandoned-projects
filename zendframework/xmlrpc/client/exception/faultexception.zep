/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\XmlRpc\Client\Exception;

use Zend\XmlRpc\Exception;

/**
 * Thrown by Zend\XmlRpc\Client when an XML-RPC fault response is returned.
 */
class FaultException extends Exception\BadMethodCallException implements ExceptionInterface
{
}
