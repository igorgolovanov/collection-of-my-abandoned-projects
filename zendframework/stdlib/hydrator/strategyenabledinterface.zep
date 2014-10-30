/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib\Hydrator;

use Zend\Stdlib\Hydrator\Strategy\StrategyInterface;

interface StrategyEnabledInterface
{
    /**
     * Adds the given strategy under the given name.
     *
     * @param string $name The name of the strategy to register.
     * @param StrategyInterface $strategy The strategy to register.
     * @return StrategyEnabledInterface
     */
    public function addStrategy(string name, <StrategyInterface> strategy) -> <StrategyEnabledInterface>;

    /**
     * Gets the strategy with the given name.
     *
     * @param string $name The name of the strategy to get.
     * @return StrategyInterface
     */
    public function getStrategy(string name) -> <StrategyInterface>;

    /**
     * Checks if the strategy with the given name exists.
     *
     * @param string $name The name of the strategy to check for.
     * @return bool
     */
    public function hasStrategy(string name) -> boolean;

    /**
     * Removes the strategy with the given name.
     *
     * @param string $name The name of the strategy to remove.
     * @return StrategyEnabledInterface
     */
    public function removeStrategy(string name) -> <StrategyEnabledInterface>;

}
