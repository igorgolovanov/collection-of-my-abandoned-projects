/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Loader;

/**
 * Plugin class locator interface
 */
interface PluginClassLocator extends ShortNameLocator, \IteratorAggregate, \Traversable
{
    /**
     * Register a class to a given short name
     *
     * @param  string $shortName
     * @param  string $className
     * @return PluginClassLocator
     */
    public function registerPlugin(string shortName, string className) -> <PluginClassLocator>;

    /**
     * Unregister a short name lookup
     *
     * @param  mixed $shortName
     * @return void
     */
    public function unregisterPlugin(var shortName) -> void;

    /**
     * Get a list of all registered plugins
     *
     * @return array|Traversable
     */
    public function getRegisteredPlugins() -> array|<\Traversable>;

}
