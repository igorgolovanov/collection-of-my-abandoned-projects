/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Server;

/**
 * Client Interface
 */
interface Client
{
    /**
     * Executes remote call
     *
     * Unified interface for calling custom remote methods.
     *
     * @param  string $method Remote call name.
     * @param  array $params Call parameters.
     * @return mixed Remote call results.
     */
    public function call(string method, array params = []);

}
