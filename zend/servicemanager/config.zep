/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ServiceManager;

class Config implements ConfigInterface
{
    /**
     * @var array
     */
    protected config; // []

    /**
     * Constructor
     *
     * @param array $config
     */
    public function __construct(array config = [])
    {
        let this->config = config;
    }

    /**
     * Get allow override
     *
     * @return null|bool
     */
    public function getAllowOverride() -> boolean|null
    {
        boolean allow;

        if fetch allow, this->config["allow_override"] {
            return allow;
        }
        return null;
    }

    /**
     * Get factories
     *
     * @return array
     */
    public function getFactories() -> array
    {
        array factories;

        if fetch factories, this->config["factories"] {
            return factories;
        }

        return [];
    }

    /**
     * Get abstract factories
     *
     * @return array
     */
    public function getAbstractFactories() -> array
    {
        array factories;

        if fetch factories, this->config["abstract_factories"] {
            return factories;
        }

        return [];
    }

    /**
     * Get invokables
     *
     * @return array
     */
    public function getInvokables() -> array
    {
        array invokables;

        if fetch invokables, this->config["invokables"] {
            return invokables;
        }

        return [];
    }

    /**
     * Get services
     *
     * @return array
     */
    public function getServices() -> array
    {
        array services;

        if fetch services, this->config["services"] {
            return services;
        }

        return [];
    }

    /**
     * Get aliases
     *
     * @return array
     */
    public function getAliases() -> array
    {
        array aliases;

        if fetch aliases, this->config["aliases"] {
            return aliases;
        }

        return [];
    }

    /**
     * Get initializers
     *
     * @return array
     */
    public function getInitializers() -> array
    {
        array initializers;

        if fetch initializers, this->config["initializers"] {
            return initializers;
        }

        return [];
    }

    /**
     * Get shared
     *
     * @return array
     */
    public function getShared() -> array
    {
        array shared;

        if fetch shared, this->config["shared"] {
            return shared;
        }

        return [];
    }

    /**
     * Get the delegator services map, with keys being the services acting as delegates,
     * and values being the delegator factories names
     *
     * @return array
     */
    public function getDelegators() -> array
    {
        array delegators;

        if fetch delegators, this->config["delegators"] {
            return delegators;
        }

        return [];
    }

    /**
     * Configure service manager
     *
     * @param ServiceManager $serviceManager
     * @return void
     */
    public function configureServiceManager(<ServiceManager> serviceManager) -> void
    {
        var name, allowOverride, factory, invokable, originalServiceName, service,
            nameOrAlias, alias, initializer, isShared, delegator, delegators;

        array factories, invokables, services, aliases, initializers, shared, delegatorsPerService;    

        let allowOverride = this->getAllowOverride();
        if allowOverride !== null {
            serviceManager->setAllowOverride(allowOverride);
        }

        let factories = this->getFactories();
        for factory, name in factories {
            serviceManager->setFactory(name, factory);
        }

        let factories = this->getAbstractFactories();
        for factory in factories {
            serviceManager->addAbstractFactory(factory);
        }

        let invokables = this->getInvokables();
        for invokable, name in invokables {
            serviceManager->setInvokableClass(name, invokable);
        }

        let services = this->getServices();
        for service, name in services {
            serviceManager->setService(name, service);
        }

        let aliases = this->getAliases();
        for nameOrAlias, alias in aliases {
            serviceManager->setAlias(alias, nameOrAlias);
        }

        let initializers = this->getInitializers();
        for initializer in initializers {
            serviceManager->addInitializer(initializer);
        }

        let shared = this->getShared();
        for isShared, name in shared {
            serviceManager->setShared(name, isShared);
        }

        let delegatorsPerService = this->getDelegators();
        for delegators, originalServiceName in delegatorsPerService {
            for delegator in delegators {
                serviceManager->addDelegator(originalServiceName, delegator);
            }
        }
    }

}
