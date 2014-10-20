/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ServiceManager\Proxy;

/**
 * Service factory responsible of instantiating {@see \Zend\ServiceManager\Proxy\LazyServiceFactory}
 * and configuring it starting from application configuration
 */
class LazyServiceFactoryFactory implements \Zend\ServiceManager\FactoryInterface
{
    /**
     * {@inheritDoc}
     *
     * @return \Zend\ServiceManager\Proxy\LazyServiceFactory
     */
    public function createService(serviceLocator) -> <LazyServiceFactory>
    {

    }

}
