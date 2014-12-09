/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Console\Exception;

class RuntimeException extends \RuntimeException implements ExceptionInterface
{
    /**
     * Usage
     *
     * @var string
     */
    protected usage = "";

    /**
     * Constructor
     *
     * @param string $message
     * @param string $usage
     */
    public function __construct(string message, string usage = "")
    {

    }

    /**
     * Returns the usage
     *
     * @return string
     */
    public function getUsageMessage() -> string
    {

    }

}
