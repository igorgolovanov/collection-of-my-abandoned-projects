/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Log;

/**
 * Logger aware interface
 */
interface LoggerAwareInterface
{
    /**
     * Set logger instance
     *
     * @param LoggerInterface
     * @return void
     */
    public function setLogger(<LoggerInterface> logger) -> void;

}
