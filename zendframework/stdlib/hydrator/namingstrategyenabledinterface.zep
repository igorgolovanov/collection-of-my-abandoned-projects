/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib\Hydrator;

use Zend\Stdlib\Hydrator\NamingStrategy\NamingStrategyInterface;

interface NamingStrategyEnabledInterface
{
    /**
     * Adds the given naming strategy
     *
     * @param NamingStrategyInterface $strategy The naming to register.
     * @return NamingStrategyEnabledInterface
     */
    public function setNamingStrategy(<NamingStrategyInterface> strategy) -> <NamingStrategyEnabledInterface>;

    /**
     * Gets the naming strategy.
     *
     * @return NamingStrategyInterface
     */
    public function getNamingStrategy() -> <NamingStrategyInterface>;

    /**
     * Checks if a naming strategy exists.
     *
     * @return bool
     */
    public function hasNamingStrategy() -> boolean;

    /**
     * Removes the naming with the given name.
     *
     * @return NamingStrategyEnabledInterface
     */
    public function removeNamingStrategy() -> <NamingStrategyEnabledInterface>;

}
