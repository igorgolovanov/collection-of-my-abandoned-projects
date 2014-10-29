/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\EventManager;

use Zend\Stdlib\CallbackHandler;

/**
 * Interface for shared event listener collections
 */
interface SharedEventManagerInterface
{
    /**
     * Retrieve all listeners for a given identifier and event
     *
     * @param  string|int $id
     * @param  string|int $event
     * @return false|PriorityQueue
     */
    public function getListeners(var id, var event);

    /**
     * Attach a listener to an event
     *
     * @param  string|array $id Identifier(s) for event emitting component(s)
     * @param  string $event
     * @param  callable $callback PHP Callback
     * @param  int $priority Priority at which listener should execute
     * @return CallbackHandler|array Either CallbackHandler or array of CallbackHandlers
     */
    public function attach(var id, string event, var callback, int priority = 1) -> array|<CallbackHandler>;

    /**
     * Detach a listener from an event offered by a given resource
     *
     * @param  string|int $id
     * @param  CallbackHandler $listener
     * @return bool Returns true if event and listener found, and unsubscribed; returns false if either event or listener not found
     */
    public function detach(var id, <CallbackHandler> listener) -> boolean;

    /**
     * Retrieve all registered events for a given resource
     *
     * @param  string|int $id
     * @return array
     */
    public function getEvents(var id) -> array;

    /**
     * Clear all listeners for a given identifier, optionally for a specific event
     *
     * @param  string|int $id
     * @param  null|string $event
     * @return bool
     */
    public function clearListeners(var id, string event = null) -> boolean;

}
