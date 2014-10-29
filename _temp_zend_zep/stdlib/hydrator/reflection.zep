/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator;


use ReflectionClass;
use Zend\Stdlib\Exception;
use Zend\Stdlib\Hydrator\Filter\FilterComposite;

class Reflection extends AbstractHydrator
{
    /**
     * Simple in-memory array cache of ReflectionProperties used.
     * @var array
     */
    protected static reflProperties; // todo: []

    /**
     * Extract values from an object
     *
     * @param  object $object
     * @return array
     */
    public function extract(object! $object) -> array
    {
        array result = [], reflProperties;
        var property, filter, value, extractValue;
        string propertyName, name;

        let reflProperties = self::getReflProperties($object);

        for property in reflProperties {
            let name = property->getName();
            let propertyName = this->extractName(name, $object);
            let filter = <FilterComposite> this->filterComposite;

            if !filter->filter(propertyName) {
                continue;
            }

            let value = property->getValue($object);
            let extractValue = this->extractValue(propertyName, value, $object)

            let result[propertyName] = extractValue;
        }

        return result;
    }

    /**
     * Hydrate $object with the provided $data.
     *
     * @param  array $data
     * @param  object $object
     * @return object
     */
    public function hydrate(array! data, object! $object) -> object
    {
        array reflProperties;
        var key, value, hydrateValue;
        string name;

        let reflProperties = self::getReflProperties($object);

        for key, value in reflProperties {
            let name = this->hydrateName(key, data);
            if isset reflProperties[name] {
                let hydrateValue = this->hydrateValue(name, value, data);
                let reflProperties[name]->setValue($object, hydrateValue);
            }
        }

        return $object;
    }

    /**
     * Get a reflection properties from in-memory cache and lazy-load if
     * class has not been loaded.
     *
     * @param  string|object $input
     * @throws Exception\InvalidArgumentException
     * @return array
     */
    protected static function getReflProperties(var input) -> array
    {
        string type, propertyName;
        var property, refClass;
        array reflProperties;

        let type = typeof input;
        if type == "object" {
            let input = get_class(input);
        } else {
            if unlikely type != "string" {
                throw new Exception\InvalidArgumentException("Input must be a string or an object.");
            }
        }

       if fetch property, static::reflProperties[input] {
            return property;
       }

       let static::reflProperties[input] = [];
       let refClass = new ReflectionClass(input);
       let reflProperties = refClass->getProperties();

       for property in reflProperties {
            property->setAccessible(true);
            let propertyName = property->getName();
            let static::reflProperties[input][propertyName] = property;
       }

       return static::reflProperties[input];
    }

}
