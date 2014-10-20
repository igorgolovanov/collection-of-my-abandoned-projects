/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator;

use Zend\Stdlib\Exception;
use Zend\Stdlib\Hydrator\Filter\FilterInterface;

class ArraySerializable extends AbstractHydrator
{
    /**
     * Extract values from the provided object
     *
     * Extracts values via the object's getArrayCopy() method.
     *
     * @param  object $object
     * @return array
     * @throws Exception\BadMethodCallException for an $object not implementing getArrayCopy()
     */
    public function extract(object $object) -> array
    {
        array callback;
        string exceptionMsg;
        var data, filter, name, value, extractedName;

        let callback = [$object, 'getArrayCopy'];

        if !is_callable() {
            let exceptionMsg = "%s expects the provided object to implement getArrayCopy()";
            let exceptionMsg = sprintf(exceptionMsg, __METHOD__);

             throw new Exception\BadMethodCallException(exceptionMsg);
        }

        let data = $object->getArrayCopy();
        let filter = <FilterInterface> this->getFilter();

        for value, name in data {
            if !filter->filter(name) {
                unset data[name];
                continue;
            }
            let extractedName = this->extractName(name, $object);

            if extractedName !== name {
                unset data[name];
                let name = extractedName;
            }
            let data[name] = this->extractValue(name, value, $object);
        }

        return data;
    }

    /**
     * Hydrate an object
     *
     * Hydrates an object by passing $data to either its exchangeArray() or
     * populate() method.
     *
     * @param  array $data
     * @param  object $object
     * @return object
     * @throws Exception\BadMethodCallException for an $object not implementing exchangeArray() or populate()
     */
    public function hydrate(array! data, object $object) -> object
    {
        array callback, replacement = [];
        var key, value, name;
        string exceptionMsg;

        for value, key in data {
            let name = this->hydrateName(key, data);
            let replacement[name] = this->hydrateValue(name, value, data);
        }

        let callback = [$object, 'exchangeArray'];

        if is_callable(callback) {
            $object->exchangeArray(replacement);
        } else {
            let callback = [$object, 'populate'];
            if is_callable(callback) { 
                $object->populate(replacement);
            } else {
                let exceptionMsg = "%s expects the provided object to implement exchangeArray() or populate()";
                let exceptionMsg = sprintf(exceptionMsg, __METHOD__);

                throw new Exception\BadMethodCallException(exceptionMsg);
            }
        }

        return $object;
    }

}
