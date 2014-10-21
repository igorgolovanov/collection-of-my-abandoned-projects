/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ModuleManager\Listener;

/**
 * Locator registration listener
 */
class LocatorRegistrationListener extends AbstractListener implements \Zend\EventManager\ListenerAggregateInterface
{
    /**
     * @var array
     */
    protected modules = [];

    /**
     * @var array
     */
    protected callbacks = [];

    /**
     * loadModule
     *
     * Check each loaded module to see if it implements LocatorRegistered. If it
     * does, we add it to an internal array for later.
     *
     * @param  ModuleEvent $e
     * @return void
     */
    public function onLoadModule(e) -> void
    {

    }

    /**
     * loadModules
     *
     * Once all the modules are loaded, loop
     *
     * @param  Event $e
     * @return void
     */
    public function onLoadModules(e) -> void
    {

    }

    /**
     * Bootstrap listener
     *
     * This is ran during the MVC bootstrap event because it requires access to
     * the DI container.
     *
     * @TODO: Check the application / locator / etc a bit better to make sure
     * the env looks how we're expecting it to?
     * @param Event $e
     * @return void
     */
    public function onBootstrap(e) -> void
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

}
