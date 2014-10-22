/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Aggregate;

use Zend\EventManager\EventManager;
use Zend\EventManager\EventManagerAwareInterface;
use Zend\EventManager\EventManagerInterface;
use Zend\Stdlib\Hydrator\HydratorInterface;

/**
* Aggregate hydrator that composes multiple hydrators via events
*/
class AggregateHydrator implements HydratorInterface, EventManagerAwareInterface
{
    const DEFAULT_PRIORITY = 1;

    /**
     * @var \Zend\EventManager\EventManagerInterface|null
     */
    protected eventManager;

    /**
     * Attaches the provided hydrator to the list of hydrators to be used while hydrating/extracting data
     *
     * @param \Zend\Stdlib\Hydrator\HydratorInterface $hydrator
     * @param int                                     $priority
     */
    public function add(<HydratorInterface> hydrator, int priority = self::DEFAULT_PRIORITY) -> <AggregateHydrator>
    {
        var eventManager, hydratorListener;

        let eventManager = <EventManagerInterface> this->getEventManager();
        let hydratorListener = new HydratorListener(hydrator);

        eventManager->attachAggregate(hydratorListener, priority);

        return this;
    }

    /**
     * {@inheritDoc}
     */
    public function extract(object! $object) -> array
    {
        var event, eventManager;
        array data;

        let event = new ExtractEvent(this, $object);
        let eventManager = <EventManagerInterface> this->getEventManager();

        eventManager->trigger(event);

        let data = event->getExtractedData();

        return data;
    }

    /**
     * {@inheritDoc}
     */
    public function hydrate(array! data, object! $object) -> object
    {
        var event, eventManager, hydratedObject;

        let event = new HydrateEvent(this, $object, data);
        let eventManager = <EventManagerInterface> this->getEventManager();

        eventManager->trigger(event);

        let hydratedObject = event->getHydratedObject();

        return hydratedObject;
    }

    /**
     * {@inheritDoc}
     */
    public function setEventManager(<EventManagerInterface> eventManager) -> <AggregateHydrator>
    {
        string className;
        array identifiers;

        let className = get_class(this);
        let identifiers = [__CLASS__, className];

        eventManager->setIdentifiers(identifiers);

        let this->eventManager = eventManager;

        return this;
    }

    /**
     * {@inheritDoc}
     */
    public function getEventManager() -> <EventManagerInterface>
    {
        var eventManager;

        let eventManager = this->eventManager;
        if eventManager === null {
            let eventManager = new EventManager();
            this->setEventManager(eventManager);
        }
        return eventManager;
    }

}
