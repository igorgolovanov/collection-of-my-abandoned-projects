/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Aggregate;

use Zend\EventManager\AbstractListenerAggregate;
use Zend\EventManager\EventManagerInterface;
use Zend\Stdlib\Hydrator\HydratorInterface;
use Zend\Stdlib\CallbackHandler;

/**
 * Aggregate listener wrapping around a hydrator. Listens
 * to {@see \Zend\Stdlib\Hydrator\Aggregate::EVENT_HYDRATE} and
 * {@see \Zend\Stdlib\Hydrator\Aggregate::EVENT_EXTRACT}
 */
class HydratorListener extends AbstractListenerAggregate
{
    /**
     * @var \Zend\Stdlib\Hydrator\HydratorInterface
     */
    protected hydrator;

    /**
     * @param \Zend\Stdlib\Hydrator\HydratorInterface $hydrator
     */
    public function __construct(<HydratorInterface> hydrator)
    {
        let this->hydrator = hydrator;
    }

    /**
     * {@inheritDoc}
     */
    public function attach(<EventManagerInterface> events, int priority = 1)
    {
        array callbackOnHydrate, callbackOnExtract;
        var handlerOnHydrate, handlerOnExtract;

        let callbackOnHydrate = [this, "onHydrate"];
        let callbackOnExtract = [this, "onExtract"];

        let handlerOnHydrate = <CallbackHandler> events->attach(HydrateEvent::EVENT_HYDRATE, callbackOnHydrate, priority);
        let handlerOnExtract = <CallbackHandler> events->attach(ExtractEvent::EVENT_EXTRACT, callbackOnExtract, priority);

        let this->listeners[] = handlerOnHydrate;
        let this->listeners[] = handlerOnExtract;
    }

    /**
     * Callback to be used when {@see \Zend\Stdlib\Hydrator\Aggregate\HydrateEvent::EVENT_HYDRATE} is triggered
     *
     * @param \Zend\Stdlib\Hydrator\Aggregate\HydrateEvent $event
     *
     * @return object
     *
     * @internal
     */
    public function onHydrate(<HydrateEvent> event) -> object
    {
        var hydrator, $object, hydratedObject;
        array hydrationData;


        let hydrator = <HydratorInterface> this->hydrator;
        let hydrationData = event->getHydrationData();
        let hydratedObject = event->getHydratedObject();
        let $object = hydrator->hydrate(hydrationData, hydratedObject);

        event->setHydratedObject($object);

        return $object;
    }

    /**
     * Callback to be used when {@see \Zend\Stdlib\Hydrator\Aggregate\ExtractEvent::EVENT_EXTRACT} is triggered
     *
     * @param \Zend\Stdlib\Hydrator\Aggregate\ExtractEvent $event
     *
     * @return array
     *
     * @internal
     */
    public function onExtract(<ExtractEvent> event) -> array
    {
        var hydrator, extractionObject;
        array data;

        let hydrator = <HydratorInterface> this->hydrator;
        let extractionObject = event->getExtractionObject();
        let data = hydrator->extract(extractionObject);

        event->mergeExtractedData(data);

        return data;
    }

}
