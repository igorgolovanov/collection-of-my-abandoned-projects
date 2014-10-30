/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Cache\Storage\Plugin;

use Zend\EventManager\ListenerAggregateInterface;

interface PluginInterface extends ListenerAggregateInterface
{
    /**
     * Set options
     *
     * @param  PluginOptions $options
     * @return PluginInterface
     */
    public function setOptions(options) -> <PluginInterface>; // todo: <PatternOptions> options

    /**
     * Get options
     *
     * @return PluginOptions
     */
    public function getOptions() -> <PluginOptions>;

}
