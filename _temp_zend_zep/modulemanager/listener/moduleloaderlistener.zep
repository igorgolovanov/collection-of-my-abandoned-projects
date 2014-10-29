/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ModuleManager\Listener;

/**
 * Module loader listener
 */
class ModuleLoaderListener extends AbstractListener implements \Zend\EventManager\ListenerAggregateInterface
{
    /**
     * @var array
     */
    protected moduleLoader;

    /**
     * @var bool
     */
    protected generateCache;

    /**
     * @var array
     */
    protected callbacks = [];

    /**
     * Constructor.
     *
     * Creates an instance of the ModuleAutoloader and injects the module paths
     * into it.
     *
     * @param  ListenerOptions $options
     */
    public function __construct(<ListenerOptions> options = null)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function attach(events)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function detach(events)
    {

    }

    /**
     * @return bool
     */
    protected function hasCachedClassMap() -> boolean
    {

    }

    /**
     * @return array
     */
    protected function getCachedConfig() -> array
    {

    }

    /**
     * loadModulesPost
     *
     * Unregisters the ModuleLoader and generates the module class map cache.
     *
     * @param  ModuleEvent $event
     */
    public function onLoadModulesPost(event)
    {

    }

}
