/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\EventManager;

/**
 * Interface to automate setter injection for an EventManager instance
 */
interface EventManagerAwareInterface extends EventsCapableInterface
{
    /**
     * Inject an EventManager instance
     *
     * @param  EventManagerInterface $eventManager
     * @return void
     */
    public function setEventManager(<EventManagerInterface> eventManager) -> void;

}
