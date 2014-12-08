/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\ModuleManager\Listener;

use Zend\EventManager\ListenerAggregateInterface;

interface ServiceListenerInterface extends ListenerAggregateInterface
{
    /**
     * @param  ServiceManager|string $serviceManager  Service Manager instance or name
     * @param  string                $key             Configuration key
     * @param  string                $moduleInterface FQCN as string
     * @param  string                $method          Method name
     * @return ServiceListenerInterface
     */
    public function addServiceManager(string serviceManager, string key, string moduleInterface, string method) -> <ServiceListenerInterface>;

    /**
     * @param  array $configuration
     * @return ServiceListenerInterface
     */
    public function setDefaultServiceConfig(array configuration) -> <ServiceListenerInterface>;

}
