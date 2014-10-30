/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\EventManager;

use Zend\Stdlib\CallbackHandler;
use Zend\Stdlib\PriorityQueue;

/**
 * Shared/contextual EventManager
 *
 * Allows attaching to EMs composed by other classes without having an instance first.
 * The assumption is that the SharedEventManager will be injected into EventManager
 * instances, and then queried for additional listeners when triggering an event.
 */
class SharedEventManager implements SharedEventAggregateAwareInterface, SharedEventManagerInterface
{
    /**
     * Identifiers with event connections
     * @var array
     */
    protected identifiers = [];

    /**
     * Attach a listener to an event
     *
     * Allows attaching a callback to an event offered by one or more
     * identifying components. As an example, the following connects to the
     * "getAll" event of both an AbstractResource and EntityResource:
     *
     * <code>
     * $sharedEventManager = new SharedEventManager();
     * $sharedEventManager->attach(
     *     array('My\Resource\AbstractResource', 'My\Resource\EntityResource'),
     *     'getAll',
     *     function ($e) use ($cache) {
     *         if (!$id = $e->getParam('id', false)) {
     *             return;
     *         }
     *         if (!$data = $cache->load(get_class($resource) . '::getOne::' . $id )) {
     *             return;
     *         }
     *         return $data;
     *     }
     * );
     * </code>
     *
     * @param  string|array $id Identifier(s) for event emitting component(s)
     * @param  string $event
     * @param  callable $callback PHP Callback
     * @param  int $priority Priority at which listener should execute
     * @return CallbackHandler|array Either CallbackHandler or array of CallbackHandlers
     */
    public function attach(var id, string event, var callback, int priority = 1) -> array|<CallbackHandler>
    {
        var i, identifiers, eventManager, ids, listeners = [];

        let ids = typeof id == "array" ? id : [id];
        let identifiers = this->identifiers;

        for i in ids {
            if unlikely fetch eventManager, identifiers[i] {
                let eventManager = new EventManager(i);
                let this->identifiers[i] = eventManager;
            }
            let listeners[] = eventManager->attach(event, callback, priority);
        }

        if count(listeners) > 1 {
            return listeners;
        }
        return listeners[0];
    }

    /**
     * Attach a listener aggregate
     *
     * Listener aggregates accept an EventManagerInterface instance, and call attachShared()
     * one or more times, typically to attach to multiple events using local
     * methods.
     *
     * @param  SharedListenerAggregateInterface $aggregate
     * @param  int $priority If provided, a suggested priority for the aggregate to use
     * @return mixed return value of {@link ListenerAggregateInterface::attachShared()}
     */
    public function attachAggregate(<SharedListenerAggregateInterface> aggregate, int priority = 1)
    {
        return aggregate->attachShared(this, priority);
    }

    /**
     * Detach a listener from an event offered by a given resource
     *
     * @param  string|int $id
     * @param  CallbackHandler $listener
     * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
     */
    public function detach(var id, <CallbackHandler> listener) -> boolean
    {
        var eventManager;

        if fetch eventManager, this->identifiers[id] {
            return eventManager->detach(listener);
        }
        return false;
    }

    /**
     * Detach a listener aggregate
     *
     * Listener aggregates accept a SharedEventManagerInterface instance, and call detachShared()
     * of all previously attached listeners.
     *
     * @param  SharedListenerAggregateInterface $aggregate
     * @return mixed return value of {@link SharedListenerAggregateInterface::detachShared()}
     */
    public function detachAggregate(<SharedListenerAggregateInterface> aggregate)
    {
        return aggregate->detachShared(this);
    }

    /**
     * Retrieve all registered events for a given resource
     *
     * @param  string|int $id
     * @return array
     */
    public function getEvents(var id) -> array|boolean // todo: check boolean
    {
        var eventManager;
        string wildcard = "*";

        if fetch eventManager, this->identifiers[id] {
            return eventManager->getEvents();
        }
        if id != wildcard && fetch eventManager, this->identifiers[wildcard] {
            return eventManager->getEvents();
        }
        return false; // maybe empty array?
    }

    /**
     * Retrieve all listeners for a given identifier and event
     *
     * @param  string|int $id
     * @param  string|int $event
     * @return false|PriorityQueue
     */
    public function getListeners(var id, var event) -> boolean|<PriorityQueue>
    {
        var eventManager, listeners;

        if fetch eventManager, this->identifiers[id] {
            let listeners = eventManager->getListeners(event);
            return listeners;
        }
        return false;
    }

    /**
     * Clear all listeners for a given identifier, optionally for a specific event
     *
     * @param  string|int $id
     * @param  null|string $event
     * @return bool
     */
    public function clearListeners(var id, string event = null) -> boolean
    {
        var eventManager;

        if fetch eventManager, this->identifiers[id] {
            if event !== null {
                return eventManager->clearListeners(event);
            }
            unset this->identifiers[id];
            return true;
        }
        return false;
    }

}
