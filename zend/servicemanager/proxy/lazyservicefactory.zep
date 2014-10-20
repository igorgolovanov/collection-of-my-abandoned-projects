/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ServiceManager\Proxy;

/**
 * Delegator factory responsible of instantiating lazy loading value holder proxies of
 * given services at runtime
 *
 * @link https://github.com/Ocramius/ProxyManager/blob/master/docs/lazy-loading-value-holder.md
 */
class LazyServiceFactory implements \Zend\ServiceManager\DelegatorFactoryInterface
{
    /**
     * @var \ProxyManager\Factory\LazyLoadingValueHolderFactory
     */
    protected proxyFactory;

    /**
     * @var string[] map of service names to class names
     */
    protected servicesMap;

    /**
     * @param LazyLoadingValueHolderFactory $proxyFactory
     * @param string[]                      $servicesMap  a map of service names to class names of their
     *                                                    respective classes
     */
    public function __construct(proxyFactory, array! servicesMap)
    {

    }

    /**
     * {@inheritDoc}
     *
     * @return object|\ProxyManager\Proxy\LazyLoadingInterface|\ProxyManager\Proxy\ValueHolderInterface
     */
    public function createDelegatorWithName(serviceLocator, name, requestedName, callback) -> object
    {

    }

}
