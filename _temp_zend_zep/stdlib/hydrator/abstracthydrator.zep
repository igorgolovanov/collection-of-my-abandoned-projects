/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator;

use ArrayObject;
use Zend\Stdlib\Exception;
use Zend\Stdlib\Hydrator\Filter\FilterComposite;
use Zend\Stdlib\Hydrator\NamingStrategy\NamingStrategyInterface;
use Zend\Stdlib\Hydrator\Strategy\StrategyInterface;

abstract class AbstractHydrator implements HydratorInterface, StrategyEnabledInterface, FilterEnabledInterface, NamingStrategyEnabledInterface
{
    /**
     * The list with strategies that this hydrator has.
     *
     * @var ArrayObject
     */
    protected strategies;

    /**
     * An instance of NamingStrategyInterface
     *
     * @var NamingStrategyInterface
     */
    protected namingStrategy;

    /**
     * Composite to filter the methods, that need to be hydrated
     *
     * @var Filter\FilterComposite
     */
    protected filterComposite;

    /**
     * Initializes a new instance of this class.
     */
    public function __construct()
    {
        let this->strategies = new ArrayObject();
        let this->filterComposite = new FilterComposite();
    }

    /**
     * Gets the strategy with the given name.
     *
     * @param string $name The name of the strategy to get.
     *
     * @throws \Zend\Stdlib\Exception\InvalidArgumentException
     * @return StrategyInterface
     */
    public function getStrategy(string name) -> <StrategyInterface>
    {
        var strategy;
        string exceptionMsg;

        if fetch strategy, this->strategies[name] {
            return strategy;
        }

        if fetch strategy, this->strategies["*"] {
            return strategy;
        }

        let exceptionMsg = __METHOD__ . ": no strategy by name of \"" . name . "\", and no wildcard strategy present";
        throw new Exception\InvalidArgumentException(exceptionMsg);
    }

    /**
     * Checks if the strategy with the given name exists.
     *
     * @param string $name The name of the strategy to check for.
     * @return bool
     */
    public function hasStrategy(string name) -> boolean
    {
        return isset this->strategies[name] || isset this->strategies["*"];
    }

    /**
     * Adds the given strategy under the given name.
     *
     * @param string $name The name of the strategy to register.
     * @param StrategyInterface $strategy The strategy to register.
     * @return HydratorInterface
     */
    public function addStrategy(string name, <StrategyInterface> strategy) -> <HydratorInterface>
    {
        let this->strategies[name] = strategy;

        return this;
    }

    /**
     * Removes the strategy with the given name.
     *
     * @param string $name The name of the strategy to remove.
     * @return HydratorInterface
     */
    public function removeStrategy(string name) -> <HydratorInterface>
    {
        if isset this->strategies[name] {
            unset this->strategies[name];
        }
        return this;
    }

    /**
     * Converts a value for extraction. If no strategy exists the plain value is returned.
     *
     * @param  string $name  The name of the strategy to use.
     * @param  mixed  $value  The value that should be converted.
     * @param  mixed  $object The object is optionally provided as context.
     * @return mixed
     */
    public function extractValue(string name, var value, object $object = null)
    {
        var strategy;

        if this->hasStrategy(name) {
            let strategy = <StrategyInterface> this->getStrategy();
            let value = strategy->extract(value, $object);
        }
        return value;
    }

    /**
     * Converts a value for hydration. If no strategy exists the plain value is returned.
     *
     * @param string $name The name of the strategy to use.
     * @param mixed $value The value that should be converted.
     * @param array $data The whole data is optionally provided as context.
     * @return mixed
     */
    public function hydrateValue(string name, var value, array data = null)
    {
        var strategy;

        if this->hasStrategy(name) {
            let strategy = <StrategyInterface> this->getStrategy();
            let value = strategy->hydrate(value, data);
        }
        return value;
    }

    /**
     * Convert a name for extraction. If no naming strategy exists, the plain value is returned.
     *
     * @param string $name    The name to convert.
     * @param null   $object  The object is optionally provided as context.
     * @return mixed
     */
    public function extractName(string name, object $object = null)
    {
        var strategy;

        if this->hasNamingStrategy(name) {
            let strategy = <NamingStrategyInterface> this->getNamingStrategy();
            let value = strategy->extract(value, $object);
        }
        return value;
    }

    /**
     * Converts a value for hydration. If no naming strategy exists, the plain value is returned.
     *
     * @param string $name  The name to convert.
     * @param array  $data  The whole data is optionally provided as context.
     * @return mixed
     */
    public function hydrateName(string name, array data = null)
    {
        var strategy;

        if this->hasNamingStrategy(name) {
            let strategy = <NamingStrategyInterface> this->getNamingStrategy();
            let value = strategy->hydrate(value, data);
        }
        return value;
    }

    /**
     * Get the filter instance
     *
     * @return Filter\FilterComposite
     */
    public function getFilter() -> <FilterComposite>
    {
        return this->filterComposite;
    }

    /**
     * Add a new filter to take care of what needs to be hydrated.
     * To exclude e.g. the method getServiceLocator:
     *
     * <code>
     * $composite->addFilter("servicelocator",
     *     function ($property) {
     *         list($class, $method) = explode('::', $property);
     *         if ($method === 'getServiceLocator') {
     *             return false;
     *         }
     *         return true;
     *     }, FilterComposite::CONDITION_AND
     * );
     * </code>
     *
     * @param string $name Index in the composite
     * @param callable|Filter\FilterInterface $filter
     * @param int $condition
     * @return Filter\FilterComposite
     */
    public function addFilter(string name, var filter, int condition = FilterComposite::CONDITION_OR) -> <FilterComposite>
    {
        var filterComposite;
        let filterComposite = <FilterComposite> this->filterComposite;

        return filterComposite>addFilter(name, filter, condition);
    }

    /**
     * Check whether a specific filter exists at key $name or not
     *
     * @param string $name Index in the composite
     * @return bool
     */
    public function hasFilter(string name) -> boolean
    {
        var filterComposite;
        let filterComposite = <FilterComposite> this->filterComposite;

        return filterComposite->hasFilter(name);
    }

    /**
     * Remove a filter from the composition.
     * To not extract "has" methods, you simply need to unregister it
     *
     * <code>
     * $filterComposite->removeFilter('has');
     * </code>
     *
     * @param $name
     * @return Filter\FilterComposite
     */
    public function removeFilter(string name) -> <FilterComposite>
    {
        var filterComposite;
        let filterComposite = <FilterComposite> this->filterComposite;

        return filterComposite->removeFilter(name);
    }

    /**
     * Adds the given naming strategy
     *
     * @param NamingStrategyInterface $strategy The naming to register.
     * @return self
     */
    public function setNamingStrategy(<NamingStrategyInterface> strategy) -> <AbstractHydrator>
    {
        let this->namingStrategy = namingStrategy;

        return this;
    }

    /**
     * Gets the naming strategy.
     *
     * @return NamingStrategyInterface
     */
    public function getNamingStrategy() -> <NamingStrategyInterface>|null
    {
        return this->namingStrategy;
    }

    /**
     * Checks if a naming strategy exists.
     *
     * @return bool
     */
    public function hasNamingStrategy() -> boolean
    {
        return isset this->namingStrategy;
    }

    /**
     * Removes the naming strategy
     *
     * @return self
     */
    public function removeNamingStrategy() -> <AbstractHydrator>
    {
        let this->namingStrategy = null;
        return this;
    }

}
