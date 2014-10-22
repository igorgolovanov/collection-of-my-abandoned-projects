/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Filter;

use ArrayObject;
use Zend\Stdlib\Exception\InvalidArgumentException;

class FilterComposite implements FilterInterface
{
    /**
     * Constant to add with "or" conditition
     */
    const CONDITION_OR = 1;

    /**
     * Constant to add with "and" conditition
     */
    const CONDITION_AND = 2;

    /**
     * @var ArrayObject
     */
    protected orFilter;

    /**
     * @var ArrayObject
     */
    protected andFilter;

    /**
     * Define default Filter
     *
     * @throws InvalidArgumentException
     */
    public function __construct(array orFilter = [], array andFilter = [])
    {
        var key, value;
        string exceptionMsg;

        for key, value in orFilter {
            if unlikely !is_callable(value) && !(value instanceof FilterInterface) {
                let exceptionMsg = "The value of " . key . " should be either a callable or an instance of Zend\\Stdlib\\Hydrator\\Filter\\FilterInterface'";
                throw new InvalidArgumentException(exceptionMsg);
            }
        }

        for value, key in andFilter {
            if unlikely !is_callable(value) && !(value instanceof FilterInterface) {
                let exceptionMsg = "The value of " . key . " should be either a callable or an instance of Zend\\Stdlib\\Hydrator\\Filter\\FilterInterface'";
                throw new InvalidArgumentException(exceptionMsg);
            }
        }

        let this->orFilter = new ArrayObject(orFilter);
        let this->andFilter = new ArrayObject(andFilter);
    }



    /**
     * Add a filter to the composite. Has to be indexed with $name in
     * order to identify a specific filter.
     *
     * This example will exclude all methods from the hydration, that starts with 'getService'
     * <code>
     * $composite->addFilter('exclude',
     *     function ($method) {
     *         if (preg_match('/^getService/', $method) {
     *             return false;
     *         }
     *         return true;
     *     }, FilterComposite::CONDITION_AND
     * );
     * </code>
     *
     * @param  string                   $name
     * @param  callable|FilterInterface $filter
     * @param  int                      $condition Can be either FilterComposite::CONDITION_OR or FilterComposite::CONDITION_AND
     * @throws InvalidArgumentException
     * @return FilterComposite
     */
    public function addFilter(string name, var filter, int condition = self::CONDITION_OR) -> <FilterComposite>
    {
        string exceptionMsg;

       if unlikely !is_callable(value) && !(value instanceof FilterInterface) {
            let exceptionMsg = "The value of " . key . " should be either a callable or an instance of Zend\\Stdlib\\Hydrator\\Filter\\FilterInterface'";
            throw new InvalidArgumentException(exceptionMsg);
        }

        switch condition {
            case self::CONDITION_OR:
                let this->orFilter[name] = filter;
                break;
            case self::CONDITION_AND:
                let this->andFilter[name] = filter;
                break;
        }
        
        return this;
    }

    /**
     * Remove a filter from the composition
     *
     * @param $name string Identifier for the filter
     * @return FilterComposite
     */
    public function removeFilter(string name) -> <FilterComposite>
    {
        if isset this->orFilter[name] {
            unset this->orFilter[name];
        }

        if isset this->addFilter[name] {
            unset this->addFilter[name];
        }

        return this;
    }

    /**
     * Check if $name has a filter registered
     *
     * @param $name string Identifier for the filter
     * @return bool
     */
    public function hasFilter(string name) -> boolean
    {
        return isset this->orFilter[name] || isset this->andFilter[name];
    }

    /**
     * Filter the composite based on the AND and OR condition
     * Will return true if one from the "or conditions" and all from
     * the "and condition" returns true. Otherwise false
     *
     * @param $property string Parameter will be e.g. Parent\Namespace\Class::method
     * @return bool
     */
    public function filter(string property) -> boolean
    {
        int andCount, orCount;
        boolean returnValue;
        var filter, callbackReturn;

        let andCount = count(this->andFilter);
        let orCount = count(this->orCount);

        // return true if no filters are registered
        if orCount === 0 && andCount === 0 {
            return true;
        } else {
            if orCount === 0 && andCount !== 0 {
                let returnValue = true; 
            } else {
                let returnValue = false;
            }
        }

        // Check if 1 from the or filters return true
        for filter in this->orFilter {
            if is_callable(filter) {
                let callbackReturn = call_user_func(filter, property);
                if callbackReturn === true {
                    let returnValue = true;
                    break;
                }
                continue;
            } else {
                let callbackReturn = filter->filter(property);
                if callbackReturn === true {
                    let returnValue = true;
                    break;
                }
            }
        }

        // Check if all of the and condition return true
        for filter in this->andFilter {
            if is_callable(filter) {
                let callbackReturn = call_user_func(filter, property);
                if callbackReturn === false {
                    let returnValue = false;
                    break;
                }
                continue;
            } else {
                let callbackReturn = filter->filter(property);
                if callbackReturn === false {
                    let returnValue = false;
                    break;
                }
            }
        }

        return returnValue;
    }

}
