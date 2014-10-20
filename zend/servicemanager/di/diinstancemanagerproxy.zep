/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ServiceManager\Di;

use Zend\Di\InstanceManager as DiInstanceManager;
use Zend\ServiceManager\ServiceLocatorInterface;

class DiInstanceManagerProxy extends DiInstanceManager
{
    /**
     * @var DiInstanceManager
     */
    protected diInstanceManager;

    /**
     * @var ServiceLocatorInterface
     */
    protected serviceLocator;

    /**
     * Constructor
     *
     * @param DiInstanceManager $diInstanceManager
     * @param ServiceLocatorInterface $serviceLocator
     */
    public function __construct(<DiInstanceManager> diInstanceManager, <ServiceLocatorInterface> serviceLocator)
    {
        let this->diInstanceManager = diInstanceManager;
        let this->serviceLocator = serviceLocator;

        // localize state
        let this->aliases = &diInstanceManager->aliases;
        let this->sharedInstances = &diInstanceManager->sharedInstances;
        let this->sharedInstancesWithParams = &diInstanceManager->sharedInstancesWithParams;
        let this->configurations = &diInstanceManager->configurations;
        let this->typePreferences = &diInstanceManager->typePreferences;
    }

    /**
     * Determine if we have a shared instance by class or alias
     *
     * @param $classOrAlias
     * @return bool
     */
    public function hasSharedInstance(string classOrAlias) -> boolean
    {
        var serviceLocator, diInstanceManager;

        let serviceLocator = <ServiceLocatorInterface> this->serviceLocator;
        let diInstanceManager = <DiInstanceManager> this->diInstanceManager;

        return serviceLocator->has(classOrAlias) || diInstanceManager->hasSharedInstance(classOrAlias);
    }

    /**
     * Get shared instance
     *
     * @param $classOrAlias
     * @return mixed
     */
    public function getSharedInstance(string classOrAlias)
    {
        var serviceLocator, diInstanceManager;

        let serviceLocator = <ServiceLocatorInterface> this->serviceLocator;
        if serviceLocator->has(classOrAlias) {
            return serviceLocator->get(classOrAlias);
        }

        let diInstanceManager = <DiInstanceManager> this->diInstanceManager;
        return diInstanceManager->getSharedInstance(classOrAlias);
    }

}
