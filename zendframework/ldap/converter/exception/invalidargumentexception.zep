/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Ldap\Converter\Exception;

use Zend\Ldap\Exception\InvalidArgumentException as LdapInvalidArgumentException;

class InvalidArgumentException extends LdapInvalidArgumentException implements ExceptionInterface
{
}
