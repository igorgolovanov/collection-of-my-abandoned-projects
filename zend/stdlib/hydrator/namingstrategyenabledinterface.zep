/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator;

interface NamingStrategyEnabledInterface
{
    /**
     * Adds the given naming strategy
     *
     * @param NamingStrategyInterface $strategy The naming to register.
     * @return NamingStrategyEnabledInterface
     */
    public function setNamingStrategy(strategy) -> <NamingStrategyEnabledInterface>;

    /**
     * Gets the naming strategy.
     *
     * @return NamingStrategyInterface
     */
    public function getNamingStrategy();

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
