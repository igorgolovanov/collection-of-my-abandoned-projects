/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator;

use Zend\Stdlib\Exception;
use Zend\Stdlib\Hydrator\Filter\FilterInterface;

class ObjectProperty extends AbstractHydrator
{
    /**
     * Extract values from an object
     *
     * Extracts the accessible non-static properties of the given $object.
     *
     * @param  object $object
     * @return array
     * @throws Exception\BadMethodCallException for a non-object $object
     */
    public function extract(object! $object) -> array
    {
        string exceptionMsg;
        array data;
        var name, value, filter, extracted;

        if unlikely typeof $object != "object" {
            let exceptionMsg = __METHOD__ . " expects the provided $object to be a PHP object";
            throw new Exception\BadMethodCallException(exceptionMsg);
        }

        let data = get_object_vars($object);
        let filter = <FilterInterface> this->getFilter();

        for name, value in data {
            if !filter->filter(name) {
                unset data[name];
                continue;
            }
            // Replace name if extracted differ
            let extracted = this->extractName(name, $object);

            if extracted !== name {
                unset data[name];
                let name = extracted;
            }
            let data[name] = this->extractValue(name, value, $object);
        }

        return data;
    }

    /**
     * Hydrate an object by populating public properties
     *
     * Hydrates an object by setting public properties of the object.
     *
     * @param  array $data
     * @param  object $object
     * @return object
     * @throws Exception\BadMethodCallException for a non-object $object
     */
    public function hydrate(array! data, object! $object) -> object
    {
        string exceptionMsg;
        var name, value, property;

        if unlikely typeof $object != "object" {
           let exceptionMsg = __METHOD__ . " expects the provided $object to be a PHP object";
            throw new Exception\BadMethodCallException(exceptionMsg);
        }

        for name, value in data {
            let property = this->hydrateName(name, data);
            let $object->{property} = this->hydrateValue(property, value, data);
        }

        return $object;
    }

}
