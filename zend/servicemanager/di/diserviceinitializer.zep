/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ServiceManager\Di;

use Zend\Di\Di;
use Zend\Di\InstanceManager;
use Zend\ServiceManager\Exception;
use Zend\ServiceManager\InitializerInterface;
use Zend\ServiceManager\ServiceLocatorInterface;

class DiServiceInitializer extends Di implements InitializerInterface
{
    /**
     * @var Di
     */
    protected di;

    /**
     * @var DiInstanceManagerProxy
     */
    protected diInstanceManagerProxy;

    /**
     * @var ServiceLocatorInterface
     */
    protected serviceLocator;

    /**
     * Constructor
     *
     * @param \Zend\Di\Di $di
     * @param \Zend\ServiceManager\ServiceLocatorInterface $serviceLocator
     * @param null|DiInstanceManagerProxy $diImProxy
     */
    public function __construct(<Di> di, <ServiceLocatorInterface> serviceLocator, <DiInstanceManagerProxy> diImProxy = null)
    {
        var instanceManager;

        let this->di = di;
        let this->serviceLocator = serviceLocator;

        if diImProxy === null {
            let instanceManager = <InstanceManager> di->instanceManager();
            let diImProxy = new DiInstanceManagerProxy(instanceManager, serviceLocator);
        }

        let this->diInstanceManagerProxy = diImProxy;
    }

    /**
     * Initialize
     *
     * @param $instance
     * @param ServiceLocatorInterface $serviceLocator
     * @throws \Exception
     */
    public function initialize(instance, <ServiceLocatorInterface> serviceLocator)
    {
        var instanceManager, e, di;

        let di = <Di> this->di;
        let instanceManager = <InstanceManager> di->instanceManager();
        let di->instanceManager = this->diInstanceManagerProxy;

        try {
            let di->injectDependencies(instance);
            let di->instanceManager = instanceManager;
        } catch (\Exception e)  {
            let di->instanceManager = instanceManager;
            throw e;
        }
    }

}
