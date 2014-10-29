/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator;

use Traversable;
use Zend\Stdlib\Exception;
use Zend\Stdlib\ArrayUtils;
use Zend\Stdlib\Hydrator\Filter\FilterComposite;
use Zend\Stdlib\Hydrator\Filter\FilterProviderInterface;
use Zend\Stdlib\Hydrator\Filter\GetFilter;
use Zend\Stdlib\Hydrator\Filter\HasFilter;
use Zend\Stdlib\Hydrator\Filter\IsFilter;
use Zend\Stdlib\Hydrator\Filter\MethodMatchFilter;
use Zend\Stdlib\Hydrator\Filter\OptionalParametersFilter;
use Zend\Stdlib\Hydrator\NamingStrategy\UnderscoreNamingStrategy;

class ClassMethods extends AbstractHydrator implements HydratorOptionsInterface
{
    /**
     * Flag defining whether array keys are underscore-separated (true) or camel case (false)
     * @var bool
     */
    protected underscoreSeparatedKeys = true;

    /**
     * @var \Zend\Stdlib\Hydrator\Filter\FilterInterface
     */
    private callableMethodFilter;

    /**
     * Define if extract values will use camel case or name with underscore
     * @param bool|array $underscoreSeparatedKeys
     */
    public function __construct(var underscoreSeparatedKeys = true)
    {
        var filter;

        parent::__construct();

        this->setUnderscoreSeparatedKeys(underscoreSeparatedKeys);

        let this->callableMethodFilter = new OptionalParametersFilter();
        let filter = <FilterComposite> this->FilterComposite;

        filter->addFilter("is", new IsFilter());
        filter->addFilter("has", new HasFilter());
        filter->addFilter("get", new GetFilter());
        filter->addFilter("parameter", new OptionalParametersFilter(), FilterComposite::CONDITION_AND);
    }

    /**
     * @param  array|Traversable                 $options
     * @return ClassMethods
     * @throws Exception\InvalidArgumentException
     */
    public function setOptions(var options) -> <ClassMethods>
    {
        var underscoreSeparatedKeys;

        if options instanceof Traversable {
            let options = ArrayUtils::iteratorToArray(options);
        } else {
            if unlikely typeof options != "array" {
                throw new Exception\InvalidArgumentException(
                    "The options parameter must be an array or a Traversable"
                ); 
            }
        }

        if fetch underscoreSeparatedKeys, options["underscoreSeparatedKeys"] {
            this->setUnderscoreSeparatedKeys(underscoreSeparatedKeys);
        }

        return this;
    }

    /**
     * @param  bool      $underscoreSeparatedKeys
     * @return ClassMethods
     */
    public function setUnderscoreSeparatedKeys(boolean underscoreSeparatedKeys) -> <ClassMethods>
    {
        var namingStrategy;

        let this->underscoreSeparatedKeys = underscoreSeparatedKeys;

        if underscoreSeparatedKeys {
            let namingStrategy = new UnderscoreNamingStrategy();
            this->setNamingStrategy(namingStrategy);
        } else {
            let namingStrategy = this->getNamingStrategy();
            if namingStrategy instanceof UnderscoreNamingStrategy {
                this->removeNamingStrategy();
            }
        }
        return this;
    }

    /**
     * @return bool
     */
    public function getUnderscoreSeparatedKeys() -> boolean
    {
        return this->underscoreSeparatedKeys;
    }

    /**
     * Extract values from an object with class methods
     *
     * Extracts the getter/setter of the given $object.
     *
     * @param  object                           $object
     * @return array
     * @throws Exception\BadMethodCallException for a non-object $object
     */
    public function extract(object! $object) -> array
    {
        string exceptionMsg, methodPath;
        var filter, objectFilter, method, callableMethodFilter, attribute, 
            value, extractedValue;
        array attributes = [], methods;

        if unlikely typeof $object != "object" {
            let exceptionMsg = __METHOD__ . " expects the provided $object to be a PHP object";
            throw new Exception\BadMethodCallException(exceptionMsg);
        }

        if $object instanceof FilterProviderInterface {
            let objectFilter = <FilterInterface> $object->getFilter();
            let filter = new FilterComposite([objectFilter], [new MethodMatchFilter("getFilter")]);
        } else {
            let filter = <FilterComposite> this->filterComposite;
        }

        let methods = get_class_methods($object);
        let callableMethodFilter = <FilterInterface> this->callableMethodFilter;

        for method in methods {
            let methodPath = get_class($object) . "::" . method;
            if !filter->filter(methodPath) {
                continue;
            }
            if !callableMethodFilter->filter(methodPath) {
                continue;
            }
            let attribute = method;

            if preg_match("/^get/", method) {
                let attribute = substr(method, 3);
                if !property_exists($object, attribute) {
                    let attribute = lcfirst(attribute);
                }
            }

            let attribute = this->extractName(attribute, $object);
            let value = $object->{method}();
            let extractedValue = this->extractValue(attribute, value, $object);

            let attributes[attribute] = extractedValue;
        }

         return attributes;
    }

    /**
     * Hydrate an object by populating getter/setter methods
     *
     * Hydrates an object by getter/setter methods of the object.
     *
     * @param  array                            $data
     * @param  object                           $object
     * @return object
     * @throws Exception\BadMethodCallException for a non-object $object
     */
    public function hydrate(array! data, object! $object) -> object
    {
        var property, value, hydratedValue;
        array callback;
        string methodName;

        if unlikely typeof $object != "object" {
            let exceptionMsg = __METHOD__ . " expects the provided $object to be a PHP object";
            throw new Exception\BadMethodCallException(exceptionMsg);
        }

        for property, value in data {
            let methodName = "set" . ucfirst(this->hydrateName(property, data));
            let callback = [$object, methodName];

            if is_callable(callback) {
                let hydratedValue = this->hydrateValue(property, value, data);
                $object->{method}(hydratedValue);
            }
        }

        return $object;
    }

}
