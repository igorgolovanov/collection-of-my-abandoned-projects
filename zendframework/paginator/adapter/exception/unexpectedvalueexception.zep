/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Paginator\Adapter\Exception;

use Zend\Paginator\Exception;

class UnexpectedValueException extends Exception\UnexpectedValueException implements
    ExceptionInterface
{}
