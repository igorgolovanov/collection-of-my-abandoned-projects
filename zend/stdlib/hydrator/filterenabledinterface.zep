/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator;

use Zend\Stdlib\Hydrator\Filter\FilterInterface;
use Zend\Stdlib\Hydrator\Filter\FilterComposite;
use Zend\Stdlib\Hydrator\Filter\FilterProviderInterface;

interface FilterEnabledInterface extends FilterProviderInterface
{
    /**
     * Add a new filter to take care of what needs to be hydrated.
     * To exclude e.g. the method getServiceLocator:
     *
     * <code>
     * $composite->addFilter(
     *     "servicelocator",
     *     function ($property) {
     *         list($class, $method) = explode('::', $property);
     *         if ($method === 'getServiceLocator') {
     *             return false;
     *         }
     *         return true;
     *     },
     *     FilterComposite::CONDITION_AND
     * );
     * </code>
     *
     * @param string $name Index in the composite
     * @param callable|FilterInterface $filter
     * @param int $condition
     * @return FilterComposite
     */
    public function addFilter(string name, var filter, int condition = FilterComposite::CONDITION_OR) -> <FilterComposite>;

    /**
     * Check whether a specific filter exists at key $name or not
     *
     * @param string $name Index in the composite
     * @return bool
     */
    public function hasFilter(string name) -> boolean;

    /**
     * Remove a filter from the composition.
     * To not extract "has" methods, you simply need to unregister it
     *
     * <code>
     * $filterComposite->removeFilter('has');
     * </code>
     *
     * @param $name
     * @return FilterComposite
     */
    public function removeFilter(string name) -> <FilterComposite>;

}
