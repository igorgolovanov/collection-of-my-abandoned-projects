/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\ServiceManager;

/**
 * Service locator interface
 */
interface ServiceLocatorInterface
{
    /**
     * Retrieve a registered instance
     *
     * @param  string  $name
     * @throws Exception\ServiceNotFoundException
     * @return object|array
     */
    public function get(string name) -> object|array;

    /**
     * Check for a registered instance
     *
     * @param  string|array  $name
     * @return bool
     */
    public function has(var name) -> boolean;

}
