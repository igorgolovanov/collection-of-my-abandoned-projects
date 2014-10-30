/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mvc;

use Zend\EventManager\EventInterface;

interface InjectApplicationEventInterface
{
    /**
     * Compose an Event
     *
     * @param  EventInterface $event
     * @return void
     */
    public function setEvent(<EventInterface> event) -> void;

    /**
     * Retrieve the composed event
     *
     * @return EventInterface
     */
    public function getEvent() -> <EventInterface>;

}
