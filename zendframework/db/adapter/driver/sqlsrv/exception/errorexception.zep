/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Adapter\Driver\Sqlsrv\Exception;

use Zend\Db\Adapter\Exception;

class ErrorException extends Exception\ErrorException implements ExceptionInterface
{

    /**
     * Errors
     *
     * @var array
     */
    protected errors = [];

    /**
     * Construct
     *
     * @param  bool $errors
     */
    public function __construct(var errors = false)
    {
        if errors === false {
            let errors = sqlsrv_errors();
        }
        let this->errors = errors;
    }
}
