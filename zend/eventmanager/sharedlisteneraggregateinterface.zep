/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\EventManager;

/**
 * Interface for self-registering event listeners.
 *
 * Classes implementing this interface may be registered by name or instance
 * with a SharedEventManager, without an event name. The {@link attach()} method will
 * then be called with the current SharedEventManager instance, allowing the class to
 * wire up one or more listeners.
 */
interface SharedListenerAggregateInterface
{
    /**
     * Attach one or more listeners
     *
     * Implementors may add an optional $priority argument; the SharedEventManager
     * implementation will pass this to the aggregate.
     *
     * @param SharedEventManagerInterface $events
     */
    public function attachShared(<SharedEventManagerInterface> events);

    /**
     * Detach all previously attached listeners
     *
     * @param SharedEventManagerInterface $events
     */
    public function detachShared(<SharedEventManagerInterface> events);

}
