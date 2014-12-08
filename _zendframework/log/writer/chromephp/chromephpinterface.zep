/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Log\Writer\ChromePhp;

interface ChromePhpInterface
{
    /**
     * Log an error message
     *
     * @param string $line
     */
    public function error(string line);

    /**
     * Log a warning
     *
     * @param string $line
     */
    public function warn(string line);

    /**
     * Log informational message
     *
     * @param string $line
     */
    public function info(string line);

    /**
     * Log a trace
     *
     * @param string $line
     */
    public function trace(string line);

    /**
     * Log a message
     *
     * @param string $line
     */
    public function log(string line);

}
