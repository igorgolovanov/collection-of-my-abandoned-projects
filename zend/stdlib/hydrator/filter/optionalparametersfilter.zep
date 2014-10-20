/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Filter;

use InvalidArgumentException;
use ReflectionException;
use ReflectionMethod;
use ReflectionParameter;

/**
 * Filter that includes methods which have no parameters or only optional parameters
 */
class OptionalParametersFilter implements FilterInterface
{
    /**
     * Map of methods already analyzed
     * by {@see \Zend\Stdlib\Hydrator\Filter\OptionalParametersFilter::filter()},
     * cached for performance reasons
     *
     * @var bool[]
     */
    protected static propertiesCache; // [] // todo: add array

    /**
     * {@inheritDoc}
     */
    public function filter(string property) -> boolean
    {
        var exception, reflectionMethod;
        array mandatoryParameters, callback, parameters;

        // todo: change self -> static
        if isset self::propertiesCache[property] {
            return self::propertiesCache[property];
        }

        try {
            let reflectionMethod = new ReflectionMethod(property);
        } catch (ReflectionException exception) {
            let exceptionMsg = sprintf("Method %s doesn't exist", property);
            throw new InvalidArgumentException(exceptionMsg);
        }

        let parameters = reflectionMethod->getParameters();
        let callback = [this, "filterParameters"];
        let mandatoryParameters = array_filter(parameters, callback);

        let self::propertiesCache[property] = empty mandatoryParameters;

        return self::propertiesCache[property];
    }

    private function filterParameters(<ReflectionParameter> parameter) -> boolean
    {
        return !parameter->isOptional();
    }
}
