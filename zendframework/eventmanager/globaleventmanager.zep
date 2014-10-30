/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\EventManager;

use Zend\Stdlib\CallbackHandler;
use Zend\Stdlib\PriorityQueue;

/**
 * Event manager: notification system
 *
 * Use the EventManager when you want to create a per-instance notification
 * system for your objects.
 */
class GlobalEventManager
{
    /**
     * @var EventManagerInterface
     */
    protected static events;

    /**
     * Set the event collection on which this will operate
     *
     * @param  null|EventManagerInterface $events
     * @return void
     */
    public static function setEventCollection(<EventManagerInterface> events = null) -> void
    {
        var className;

        let className = get_called_class();
        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("events"), &events TSRMLS_CC);
        }%
    }

    /**
     * Get event collection on which this operates
     *
     * @return EventManagerInterface
     */
    public static function getEventCollection() -> <EventManagerInterface>
    {
        var className, events = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&events, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("events") TSRMLS_CC);
        }%
        if events === null {
            let events = new EventManager();
            static::setEventCollection(events);
        }
        return events;
    }

    /**
     * Trigger an event
     *
     * @param  string $event
     * @param  object|string $context
     * @param  array|object $argv
     * @return ResponseCollection
     */
    public static function trigger(string event, var context, var argv = []) -> <ResponseCollection>
    {
        var events;
        let events = <EventManagerInterface> static::getEventCollection();

        return events->trigger(event, context, argv);
    }

    /**
     * Trigger listeners until return value of one causes a callback to evaluate
     * to true.
     *
     * @param  string $event
     * @param  string|object $context
     * @param  array|object $argv
     * @param  callable $callback
     * @return ResponseCollection
     */
    public static function triggerUntil(string event, var context, var argv, var callback) -> <ResponseCollection>
    {
        var events;
        let events = <EventManagerInterface> static::getEventCollection();

        return events->triggerUntil(event, context, argv, callback);
    }

    /**
     * Attach a listener to an event
     *
     * @param  string $event
     * @param  callable $callback
     * @param  int $priority
     * @return CallbackHandler
     */
    public static function attach(string event, callback, int priority = 1) -> <CallbackHandler>
    {
        var events;
        let events = <EventManagerInterface> static::getEventCollection();

        return events->attach(event, callback, priority);
    }

    /**
     * Detach a callback from a listener
     *
     * @param  CallbackHandler $listener
     * @return bool
     */
    public static function detach(<CallbackHandler> listener) -> boolean
    {
        var events;
        let events = <EventManagerInterface> static::getEventCollection();

        return events->detach(listener);
    }

    /**
     * Retrieve list of events this object manages
     *
     * @return array
     */
    public static function getEvents() -> array
    {
        var events;
        let events = <EventManagerInterface> static::getEventCollection();

        return events->getEvents();
    }

    /**
     * Retrieve all listeners for a given event
     *
     * @param  string $event
     * @return PriorityQueue|array
     */
    public static function getListeners(string event) -> array|<PriorityQueue>
    {
        var events;
        let events = <EventManagerInterface> static::getEventCollection();

        return events->getListeners(event);
    }

    /**
     * Clear all listeners for a given event
     *
     * @param  string $event
     * @return void
     */
    public static function clearListeners(string event) -> void
    {
        var events;
        let events = <EventManagerInterface> static::getEventCollection();

        events->clearListeners(event);
    }

}
