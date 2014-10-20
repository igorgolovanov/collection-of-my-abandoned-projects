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
    public function extract(object $object) -> array
    {
        if unlikely typeof $object != "object" {

        }
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
    public function hydrate(array! data, object $object) -> object
    {

    }

}
