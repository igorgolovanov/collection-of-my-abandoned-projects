/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ServiceManager\Di;

use Zend\Di\Di;
use Zend\Di\DefinitionList;
use Zend\Di\InstanceManager;
use Zend\Di\Exception\ClassNotFoundException as DiClassNotFoundException;
use Zend\ServiceManager\Exception;
use Zend\ServiceManager\FactoryInterface;
use Zend\ServiceManager\ServiceLocatorInterface;

class DiServiceFactory extends Di implements FactoryInterface
{
    const USE_SL_BEFORE_DI = "before";
    const USE_SL_AFTER_DI = "after";
    const USE_SL_NONE = "none";

    /**
     * @var \Zend\Di\Di
     */
    protected di;

    /**
     * @var \Zend\Di\InstanceManager
     */
    protected name;

    /**
     * @var array
     */
    protected parameters; // []

    /**
     * @var string
     */
    protected useServiceLocator = self::USE_SL_AFTER_DI;

    /**
     * @var ServiceLocatorInterface
     */
    protected serviceLocator;

    /**
     * Constructor
     *
     * @param \Zend\Di\Di $di
     * @param null|\Zend\Di\InstanceManager $name
     * @param array $parameters
     * @param string $useServiceLocator
     */
    public function __construct(<Di> di, <InstanceManager> name, array! parameters = [], string useServiceLocator = self::USE_SL_NONE)
    {
        array useSl = [self::USE_SL_BEFORE_DI, self::USE_SL_AFTER_DI, self::USE_SL_NONE];
        var definitions, instanceManager;

        let this->di = di;
        let this->name = name;
        let this->parameters = parameters;

        if in_array(useServiceLocator, useSl) {
            let this->useServiceLocator = useServiceLocator;
        }

        // since we are using this in a proxy-fashion, localize state
        let definitions = <DefinitionList> di->definitions;
        let instanceManager = <InstanceManager> di->instanceManager;
        let this->definitions = definitions;
        let this->instanceManager = instanceManager;
    }

    /**
     * Create service
     *
     * @param ServiceLocatorInterface $serviceLocator
     * @return object
     */
    public function createService(<ServiceLocatorInterface> serviceLocator) -> object
    {
        var name;
        array parameters;

        let this->serviceLocator = serviceLocator;
        let name = <InstanceManager> this->name;
        let parameters = this->parameters;

        return this->get(name, parameters);
    }

    /**
     * Override, as we want it to use the functionality defined in the proxy
     *
     * @param string $name
     * @param array $params
     * @return object
     * @throws Exception\ServiceNotFoundException
     */
    public function get(string name, array! params = []) -> object
    {
        var serviceLocator, e, service;
        int useServiceLocator;
        string exceptionMsg;

        let serviceLocator = <ServiceLocatorInterface> this->serviceLocator;
        let useServiceLocator = this->useServiceLocator;
        // allow this di service to get dependencies from the service locator BEFORE trying di
        if useServiceLocator == self::USE_SL_BEFORE_DI && serviceLocator->has(name) {
            let service = serviceLocator->get(name);
            return service;
        }

        try {
            let service = parent::get(name, params);
            return service;
        } catch(DiClassNotFoundException e) {
            // allow this di service to get dependencies from the service locator AFTER trying di
            if useServiceLocator == self::USE_SL_AFTER_DI && serviceLocator->has(name) {
                let service = serviceLocator->get(name);
                return service;
            }
            let exceptionMsg = "Service %s was not found in this DI instance";
            let exceptionMsg = sprintf(exceptionMsg, name);

            throw new Exception\ServiceNotFoundException(exceptionMsg, null, e);
        }
    }

}
