/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\EventManager;

use ArrayAccess;
use ArrayObject;
use Traversable;
use Zend\Stdlib\CallbackHandler;
use Zend\Stdlib\PriorityQueue;

/**
 * Event manager: notification system
 *
 * Use the EventManager when you want to create a per-instance notification
 * system for your objects.
 */
class EventManager implements EventManagerInterface, SharedEventManagerAwareInterface
{
    /**
     * Subscribed events and their listeners
     * @var array Array of PriorityQueue objects
     */
    protected events = [];

    /**
     * @var string Class representing the event being emitted
     */
    protected eventClass = "Zend\EventManager\Event";

    /**
     * Identifiers, used to pull shared signals from SharedEventManagerInterface instance
     * @var array
     */
    protected identifiers = [];

    /**
     * Shared event manager
     * @var false|null|SharedEventManagerInterface
     */
    protected sharedManager;

    /**
     * Constructor
     *
     * Allows optionally specifying identifier(s) to use to pull signals from a
     * SharedEventManagerInterface.
     *
     * @param  null|string|int|array|Traversable $identifiers
     */
    public function __construct(var identifiers = null)
    {
        this->setIdentifiers(identifiers);
    }

    /**
     * Set the event class to utilize
     *
     * @param  string $class
     * @return EventManager
     */
    public function setEventClass(string! $class) -> <EventManager>
    {
        let this->eventClass = $class;
        return this;
    }

    /**
     * Set shared event manager
     *
     * @param SharedEventManagerInterface $sharedEventManager
     * @return EventManager
     */
    public function setSharedManager(<SharedEventManagerInterface> sharedEventManager) -> <EventManager>
    {
        let this->sharedManager = sharedEventManager;
        StaticEventManager::setInstance(sharedEventManager);

        return this;
    }

    /**
     * Remove any shared event manager currently attached
     *
     * @return void
     */
    public function unsetSharedManager() -> void
    {
        let this->sharedManager = false;
    }

    /**
     * Get shared event manager
     *
     * If one is not defined, but we have a static instance in
     * StaticEventManager, that one will be used and set in this instance.
     *
     * If none is available in the StaticEventManager, a boolean false is
     * returned.
     *
     * @return false|SharedEventManagerInterface
     */
    public function getSharedManager() -> <SharedEventManagerInterface>|boolean
    {
        var sharedManager;

        let sharedManager = this->sharedManager;
        if sharedManager === false || sharedManager instanceof SharedEventManagerInterface {
            return sharedManager;
        }

        if !StaticEventManager::hasInstance() {
            return false;
        }
        let sharedManager = StaticEventManager::getInstance();
        let this->sharedManager = sharedManager;

        return sharedManager;
    }

    /**
     * Get the identifier(s) for this EventManager
     *
     * @return array
     */
    public function getIdentifiers() -> array
    {
        return this->identifiers;
    }

    /**
     * Set the identifiers (overrides any currently set identifiers)
     *
     * @param string|int|array|Traversable $identifiers
     * @return EventManager Provides a fluent interface
     */
    public function setIdentifiers(var identifiers) -> <EventManager>
    {
        if identifiers instanceof Traversable {
            let identifiers = iterator_to_array(identifiers);
        }
        if typeof identifiers != "array" {
            let identifiers = [identifiers];
        }
        let this->identifiers = identifiers;

        return this;
    }

    /**
     * Add some identifier(s) (appends to any currently set identifiers)
     *
     * @param string|int|array|Traversable $identifiers
     * @return EventManager Provides a fluent interface
     */
    public function addIdentifiers(var identifiers) -> <EventManager>
    {
        if typeof identifiers != "array" {
            if identifiers instanceof Traversable {
                let identifiers = iterator_to_array(identifiers);
            } else {
                let identifiers = [identifiers];
            }
        }
        let identifiers = array_merge(this->identifiers, identifiers);
        let identifiers = array_unique(identifiers);

        let this->identifiers = identifiers;

        return this;
    }   

    /**
     * Trigger all listeners for a given event
     *
     * Can emulate triggerUntil() if the last argument provided is a callback.
     *
     * @param  string $event
     * @param  string|object $target Object calling emit, or symbol describing target (such as static method name)
     * @param  array|ArrayAccess $argv Array of arguments; typically, should be associative
     * @param  null|callable $callback
     * @return ResponseCollection All listener return values
     * @throws Exception\InvalidCallbackException
     */
    public function trigger(var event, var target = null, var argv = [], var callback = null) -> <ResponseCollection>
    {
        var e, callback;
        string eventClass;

        if event instanceof EventInterface {
            let e = <EventInterface> event;
            let event = e->getName();
            let callback = target;
        } else {
            if target instanceof EventInterface {
                let e = <EventInterface> target;
                let callback = argv;
                e->setName(event);
            } else {
                if argv instanceof EventInterface {
                    let e = <EventInterface> argv;
                    e->setName(event);
                    e->setTarget(target);
                } else {
                    let eventClass = this->eventClass();
                    let e = <EventInterface> new {eventClass}();
                    e->setName(event);
                    e->setTarget(target);
                    e->setParams(argv);
                }
            }
        }

        if !is_callable(callback) {
            throw new Exception\InvalidCallbackException("Invalid callback provided");
        }

        // Initial value of stop propagation flag should be false
        e->stopPropagation(false);

        return this->triggerListeners(event, e, callback);
    }

    /**
     * Trigger listeners until return value of one causes a callback to
     * evaluate to true
     *
     * Triggers listeners until the provided callback evaluates the return
     * value of one as true, or until all listeners have been executed.
     *
     * @param  string $event
     * @param  string|object $target Object calling emit, or symbol describing target (such as static method name)
     * @param  array|ArrayAccess $argv Array of arguments; typically, should be associative
     * @param  callable $callback
     * @return ResponseCollection
     * @throws Exception\InvalidCallbackException if invalid callable provided
     */
    public function triggerUntil(var event, var target, var argv = null, var callback = null) -> <ResponseCollection>
    {
        var e, callback;
        string eventClass;

        if event instanceof EventInterface {
            let e = <EventInterface> event;
            let event = e->getName();
            let callback = target;
        } else {
            if target instanceof EventInterface {
                let e = <EventInterface> target;
                let callback = argv;
                e->setName(event);
            } else {
                if argv instanceof EventInterface {
                    let e = <EventInterface> argv;
                    e->setName(event);
                    e->setTarget(target);
                } else {
                    let eventClass = this->eventClass();
                    let e = <EventInterface> new {eventClass}();
                    e->setName(event);
                    e->setTarget(target);
                    e->setParams(argv);
                }
            }
        }

        if !is_callable(callback) {
            throw new Exception\InvalidCallbackException("Invalid callback provided");
        }

        // Initial value of stop propagation flag should be false
        e->stopPropagation(false);

        return this->triggerListeners(event, e, callback);
    }

    /**
     * Attach a listener to an event
     *
     * The first argument is the event, and the next argument describes a
     * callback that will respond to that event. A CallbackHandler instance
     * describing the event listener combination will be returned.
     *
     * The last argument indicates a priority at which the event should be
     * executed. By default, this value is 1; however, you may set it for any
     * integer value. Higher values have higher priority (i.e., execute first).
     *
     * You can specify "*" for the event name. In such cases, the listener will
     * be triggered for every event.
     *
     * @param  string|array|ListenerAggregateInterface $event An event or array of event names. If a ListenerAggregateInterface, proxies to {@link attachAggregate()}.
     * @param  callable|int $callback If string $event provided, expects PHP callback; for a ListenerAggregateInterface $event, this will be the priority
     * @param  int $priority If provided, the priority at which to register the callable
     * @return CallbackHandler|mixed CallbackHandler if attaching callable (to allow later unsubscribe); mixed if attaching aggregate
     * @throws Exception\InvalidArgumentException
     */
    public function attach(var event, var callback = null, int priority = 1)
    {
        string expected, exceptionMsg;
        var event, returns, name, listener;
        array listeners, metadata;

        // Proxy ListenerAggregateInterface arguments to attachAggregate()
        if event instanceof ListenerAggregateInterface {
            return this->attachAggregate(event, callback);
        }

        // Null callback is invalid
        if callback === null {
            let exceptionMsg = __METHOD__ . ": expects a callback; none provided"ж
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        // Array of events should be registered individually, and return an array of all listeners
        if typeof event == "array" {
            let listeners = [];

            for name in event {
                let listeners[] = this->attach(name, callback, priority);
            }
            return listeners;
        }

        // If we don't have a priority queue for the event yet, create one
        if empty this->events[event] {
            let this->events[event] = new PriorityQueue();
        }

        // Create a callback handler, setting the event and priority in its metadata
        let metadata = ["event" : event, "priority" : priority];
        let listener = new CallbackHandler(callback, metadata);

        this->events[event]->insert(listener, priority);

        return listener;
    }

    /**
     * Attach a listener aggregate
     *
     * Listener aggregates accept an EventManagerInterface instance, and call attach()
     * one or more times, typically to attach to multiple events using local
     * methods.
     *
     * @param  ListenerAggregateInterface $aggregate
     * @param  int $priority If provided, a suggested priority for the aggregate to use
     * @return mixed return value of {@link ListenerAggregateInterface::attach()}
     */
    public function attachAggregate(<ListenerAggregateInterface> aggregate, int priority = 1)
    {
        return aggregate->attach(this, priority);
    }

    /**
     * Unsubscribe a listener from an event
     *
     * @param  CallbackHandler|ListenerAggregateInterface $listener
     * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
     * @throws Exception\InvalidArgumentException if invalid listener provided
     */
    public function detach(<ListenerAggregateInterface> listener) -> boolean
    {
        string expected, exceptionMsg;
        var event, events, returns;

        if listener instanceof ListenerAggregateInterface {
            return this->detachAggregate(listener);
        }

        if !listener instanceof CallbackHandler {
            if typeof listener == "object" {
                let expected = get_class(listener);
            } else {
                let expected = typeof listener;
            }
            let exceptionMsg = __METHOD__ . ": expected a ListenerAggregateInterface or CallbackHandler; received \"" . expected . "\"";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }
        
        let events = this->events;
        let event = listener->getMetadatum("event");

        if !event || empty events[event] {
            return false;
        }

        let returns = events[event]->remove(listener);
        if !returns {
            return false;
        }

        if !count(events[event]) {
            unset(this->events[event]);
        }
        return true;
    }

    /**
     * Detach a listener aggregate
     *
     * Listener aggregates accept an EventManagerInterface instance, and call detach()
     * of all previously attached listeners.
     *
     * @param  ListenerAggregateInterface $aggregate
     * @return mixed return value of {@link ListenerAggregateInterface::detach()}
     */
    public function detachAggregate(<ListenerAggregateInterface> aggregate)
    {
        return aggregate->detach(this);
    }

    /**
     * Retrieve all registered events
     *
     * @return array
     */
    public function getEvents() -> array
    {
        var events;
        array keys;

        let events = this->events;
        let keys = array_keys(events);

        return keys;
    }

    /**
     * Retrieve all listeners for a given event
     *
     * @param  string $event
     * @return PriorityQueue
     */
    public function getListeners(string event) -> <PriorityQueue>
    {
        var events;
        boolean exists;

        let events = this->events;
        let exists = array_key_exists(event, events);

        if !exists {
            return new PriorityQueue();
        }

        return events[event];
    }

    /**
     * Clear all listeners for a given event
     *
     * @param  string $event
     * @return void
     */
    public function clearListeners(string event) -> void
    {
        if isset this->events[event] {
            unset this->events[event];
        }
    }

    /**
     * Prepare arguments
     *
     * Use this method if you want to be able to modify arguments from within a
     * listener. It returns an ArrayObject of the arguments, which may then be
     * passed to trigger() or triggerUntil().
     *
     * @param  array $args
     * @return ArrayObject
     */
    public function prepareArgs(array! args) -> <ArrayObject>
    {
        return new ArrayObject(args);
    }

    /**
     * Trigger listeners
     *
     * Actual functionality for triggering listeners, to which both trigger() and triggerUntil()
     * delegate.
     *
     * @param  string           $event Event name
     * @param  EventInterface $e
     * @param  null|callable    $callback
     * @return ResponseCollection
     */
    protected function triggerListeners(string event, <EventInterface> e, callback = null) -> <ResponseCollection>
    {
        var responses, listeners, wildcardListeners, listener, last,
            listenerCallback, listenerCallbackResponse, callbackResponse;
        array sharedListeners, sharedWildcardListeners;

        let responses = new ResponseCollection();
        let listeners = <PriorityQueue> this->getListeners(event);

        // Add shared/wildcard listeners to the list of listeners,
        // but don't modify the listeners object
        let sharedListeners = this->getSharedListeners(event);
        let sharedWildcardListeners = this->getSharedListeners("*");
        let wildcardListeners = <PriorityQueue> this->getListeners("*");

        if count(sharedListeners) || count(sharedWildcardListeners) || count(wildcardListeners) {
            let listeners = clone listeners;
            // Shared listeners on this specific event
            this->insertListeners(listeners, sharedListeners);
            // Shared wildcard listeners
            this->insertListeners(listeners, sharedWildcardListeners);
            // Add wildcard listeners
            this->insertListeners(listeners, wildcardListeners);
        }

        for listener in listeners {
            let listenerCallback = listener->getCallback();

            // Trigger the listener's callback, and push its result onto the
            // response collection
            let listenerCallbackResponse = call_user_func(listenerCallback, e);
            responses->push(listenerCallbackResponse);

            // If the event was asked to stop propagating, do so
            if e->propagationIsStopped() {
                responses->setStopped(true);
                break;
            }

            // If the result causes our validation callback to return true,
            // stop propagation
            if callback {
                let last = responses->last();
                let callbackResponse = call_user_func(callback, last);
                if callbackResponse {
                    responses->setStopped(true);
                    break;
                }
            }
        }

        return responses;
    }

    /**
     * Get list of all listeners attached to the shared event manager for
     * identifiers registered by this instance
     *
     * @param  string $event
     * @return array
     */
    protected function getSharedListeners(string event) -> array
    {
        var sharedManager, id, listeners, listener;
        array identifiers, sharedListeners = [];

        let sharedManager = this->getSharedManager();
        if !sharedManager {
            return [];
        }

        let identifiers = this->getIdentifiers();
        if !in_array("*", identifiers) {
            let identifiers[] = "*";
        }

        for id in identifiers {
            let listeners = sharedManager->getListeners(id, event);
            if !listeners {
                continue;
            }
            if typeof listeners != "array" && !listeners instanceof Traversable {
                continue;
            }
            for listener in listeners {
                if !listener instanceof CallbackHandler {
                    continue;
                }
                let sharedListeners[] = listener;
            }
        }

        return sharedListeners;
    }

    /**
     * Add listeners to the master queue of listeners
     *
     * Used to inject shared listeners and wildcard listeners.
     *
     * @param  PriorityQueue $masterListeners
     * @param  PriorityQueue $listeners
     * @return void
     */
    protected function insertListeners(<PriorityQueue> masterListeners, <PriorityQueue> listeners) -> void
    {
        var listener, priority;

        for listener in listeners {
            let priority = listener->getMetadatum("priority");
            if priority === null {
                let priority = 1;
            } else {
                if typeof priority == "array" {
                    // If we have an array, likely using PriorityQueue. Grab first
                    // element of the array, as that's the actual priority.
                    let priority = array_shift(priority);
                }
            }
            masterListeners->insert(listener, priority);
        }
    }

}
