/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Aggregate;

use Zend\EventManager\Event;

/**
 * Event triggered when the {@see \Zend\Stdlib\Hydrator\Aggregate\AggregateHydrator} hydrates
 * data into an object
 */
class HydrateEvent extends Event
{
    const EVENT_HYDRATE = "hydrate";

    /**
     * {@inheritDoc}
     */
    protected name = self::EVENT_HYDRATE;

    /**
     * @var object
     */
    protected hydratedObject;

    /**
     * @var array
     */
    protected hydrationData;

    /**
     * @param object $target
     * @param object $hydratedObject
     * @param array  $hydrationData
     */
    public function __construct(object! target, object! hydratedObject, array! hydrationData)
    {
        let this->target = target;
        let this->hydrationData = hydrationData;
        let this->hydratedObject = hydratedObject;
    }

    /**
     * Retrieves the object that is being hydrated
     *
     * @return object
     */
    public function getHydratedObject() -> object
    {
        return this->hydratedObject;
    }

    /**
     * @param object $hydratedObject
     */
    public function setHydratedObject(object! hydratedObject)
    {
        let this->hydratedObject = hydratedObject;
    }

    /**
     * Retrieves the data that is being used for hydration
     *
     * @return array
     */
    public function getHydrationData() -> array
    {
        return this->hydrationData;
    }

    /**
     * @param array $hydrationData
     */
    public function setHydrationData(array! hydrationData)
    {
        let this->hydrationData = hydrationData;
    }
}
