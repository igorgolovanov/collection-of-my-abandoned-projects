/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Adapter\Exception;

class InvalidConnectionParametersException extends RuntimeException
{
    /**
     * @var int
     */
    protected parameters;

    /**
     * @param string $message
     * @param int $parameters
     */
    public function __construct(string message, int parameters)
    {
        parent::__construct(message);
        let this->parameters = parameters;
    }

}
