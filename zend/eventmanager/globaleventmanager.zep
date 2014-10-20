/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
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
        let self::events = events; // todo: change self -> static
    }

    /**
     * Get event collection on which this operates
     *
     * @return EventManagerInterface
     */
    public static function getEventCollection() -> <EventManagerInterface>
    {
        // todo: change self -> static
        var events;
        let events = self::events;

        if events === null {
            let events = new EventManager();
            self::setEventCollection(events);
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
        // todo: change self -> static
        var events;
        let events = <EventManagerInterface> self::getEventCollection();

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
    public static function triggerUntil(string event, var context, var argv, callback) -> <ResponseCollection>
    {
        // todo: change self -> static
        var events;
        let events = <EventManagerInterface> self::getEventCollection();

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
        // todo: change self -> static
        var events;
        let events = <EventManagerInterface> self::getEventCollection();

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
        // todo: change self -> static
        let events = <EventManagerInterface> self::getEventCollection();

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
        // todo: change self -> static
        let events = <EventManagerInterface> self::getEventCollection();

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
        // todo: change self -> static
        let events = <EventManagerInterface> self::getEventCollection();

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
        // todo: change self -> static
        let events = <EventManagerInterface> self::getEventCollection();

        events->clearListeners(event);
    }

}
