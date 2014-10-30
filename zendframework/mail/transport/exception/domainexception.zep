/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mail\Transport\Exception;

use Zend\Mail\Exception\DomainException as MailDomainException;

/**
 * Exception for Zend\Mail\Transport component.
 */
class DomainException extends MailDomainException implements ExceptionInterface
{
}
