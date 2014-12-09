/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Di\Exception;

use DomainException;

class CircularDependencyException extends DomainException implements ExceptionInterface
{
}

