/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ModuleManager\Listener;

/**
 * Default listener aggregate
 */
class DefaultListenerAggregate extends AbstractListener implements \Zend\EventManager\ListenerAggregateInterface
{
    /**
     * @var array
     */
    protected listeners = [];

    /**
     * @var ConfigMergerInterface
     */
    protected configListener;

    /**
     * Attach one or more listeners
     *
     * @param  EventManagerInterface $events
     * @return DefaultListenerAggregate
     */
    public function attach(events) -> <DefaultListenerAggregate>
    {

    }

    /**
     * Detach all previously attached listeners
     *
     * @param  EventManagerInterface $events
     * @return void
     */
    public function detach(events) -> void
    {

    }

    /**
     * Get the config merger.
     *
     * @return ConfigMergerInterface
     */
    public function getConfigListener() -> <ConfigMergerInterface>
    {

    }

    /**
     * Set the config merger to use.
     *
     * @param  ConfigMergerInterface $configListener
     * @return DefaultListenerAggregate
     */
    public function setConfigListener(<ConfigMergerInterface> configListener) -> <DefaultListenerAggregate>
    {

    }

}
