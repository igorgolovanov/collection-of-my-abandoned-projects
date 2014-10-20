/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ServiceManager\Di;

use Zend\Di\Di;
use Zend\Di\InstanceManager;
use Zend\Di\DefinitionList;
use Zend\ServiceManager\AbstractFactoryInterface;
use Zend\ServiceManager\ServiceLocatorInterface;

class DiAbstractServiceFactory extends DiServiceFactory implements AbstractFactoryInterface
{
    /**
     * Constructor
     *
     * @param \Zend\Di\Di $di
     * @param null|string|\Zend\Di\InstanceManager $useServiceLocator
     */
    public function __construct(<Di> di, var useServiceLocator = self::USE_SL_NONE)
    {
        array useSl = [self::USE_SL_BEFORE_DI, self::USE_SL_AFTER_DI, self::USE_SL_NONE];
        var definitions, instanceManager;

        let this->di = di;

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
     * {@inheritDoc}
     */
    public function createServiceWithName(<ServiceLocatorInterface> serviceLocator, string name, string requestedName)
    {
        let this->serviceLocator = serviceLocator;

        if !empty requestedName {
            let name = requestedName;
        }

        return this->get(name, []);
    }

    /**
     * {@inheritDoc}
     */
    public function canCreateServiceWithName(<ServiceLocatorInterface> serviceLocator, string name, string requestedName)
    {
        var im, definitions;

        let im = <InstanceManager> di->instanceManager;
        if im->hasSharedInstance(requestedName) || im->hasAlias(requestedName) || im->hasConfig(requestedName) || im->hasTypePreferences(requestedName) {
            return true;
        }

        let definitions = <DefinitionList> di->definitions;
        if !definitions->hasClass(requestedName) || interface_exists(requestedName) {
            return false;
        }

        return true;
    }

}
