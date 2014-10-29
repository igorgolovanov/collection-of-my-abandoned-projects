/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\EventManager;

use Traversable;
use Zend\Stdlib\CallbackHandler;

/**
* Interface for messengers
*/
interface EventManagerInterface extends SharedEventManagerAwareInterface
{
    /**
     * Trigger an event
     *
     * Should allow handling the following scenarios:
     * - Passing Event object only
     * - Passing event name and Event object only
     * - Passing event name, target, and Event object
     * - Passing event name, target, and array|ArrayAccess of arguments
     *
     * Can emulate triggerUntil() if the last argument provided is a callback.
     *
     * @param  string $event
     * @param  object|string $target
     * @param  array|object $argv
     * @param  null|callable $callback
     * @return ResponseCollection
     */
    public function trigger(string event, var target = null, var argv = [], var callback = null) -> <ResponseCollection>;

    /**
     * Trigger an event until the given callback returns a boolean false
     *
     * Should allow handling the following scenarios:
     * - Passing Event object and callback only
     * - Passing event name, Event object, and callback only
     * - Passing event name, target, Event object, and callback
     * - Passing event name, target, array|ArrayAccess of arguments, and callback
     *
     * @param  string $event
     * @param  object|string $target
     * @param  array|object $argv
     * @param  callable $callback
     * @return ResponseCollection
     */
    public function triggerUntil(string event, var target, var argv = null, var callback = null) -> <ResponseCollection>;

    /**
     * Attach a listener to an event
     *
     * @param  string $event
     * @param  callable $callback
     * @param  int $priority Priority at which to register listener
     * @return CallbackHandler
     */
    public function attach(string event, callback = null, int priority = 1);

    /**
     * Detach an event listener
     *
     * @param  CallbackHandler|ListenerAggregateInterface $listener
     * @return bool
     */
    public function detach(<ListenerAggregateInterface> listener) -> boolean;

    /**
     * Get a list of events for which this collection has listeners
     *
     * @return array
     */
    public function getEvents() -> array;

    /**
     * Retrieve a list of listeners registered to a given event
     *
     * @param  string $event
     * @return array|object
     */
    public function getListeners(string event) -> array|object;

    /**
     * Clear all listeners for a given event
     *
     * @param  string $event
     * @return void
     */
    public function clearListeners(string event) -> void;

    /**
     * Set the event class to utilize
     *
     * @param  string $class
     * @return EventManagerInterface
     */
    public function setEventClass(string $class) -> <EventManagerInterface>;

    /**
     * Get the identifier(s) for this EventManager
     *
     * @return array
     */
    public function getIdentifiers() -> array;

    /**
     * Set the identifiers (overrides any currently set identifiers)
     *
     * @param string|int|array|Traversable $identifiers
     * @return EventManagerInterface
     */
    public function setIdentifiers(var identifiers) -> <EventManagerInterface>;

    /**
     * Add some identifier(s) (appends to any currently set identifiers)
     *
     * @param string|int|array|Traversable $identifiers
     * @return EventManagerInterface
     */
    public function addIdentifiers(var identifiers) -> <EventManagerInterface>;

    /**
     * Attach a listener aggregate
     *
     * @param  ListenerAggregateInterface $aggregate
     * @param  int $priority If provided, a suggested priority for the aggregate to use
     * @return mixed return value of {@link ListenerAggregateInterface::attach()}
     */
    public function attachAggregate(<ListenerAggregateInterface> aggregate, int priority = 1);

    /**
     * Detach a listener aggregate
     *
     * @param  ListenerAggregateInterface $aggregate
     * @return mixed return value of {@link ListenerAggregateInterface::detach()}
     */
    public function detachAggregate(<ListenerAggregateInterface> aggregate);

}
