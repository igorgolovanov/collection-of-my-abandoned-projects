/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di;

interface ServiceLocatorInterface extends LocatorInterface
{
    /**
     * Register a service with the locator
     *
     * @abstract
     * @param  string                  $name
     * @param  mixed                   $service
     * @return ServiceLocatorInterface
     */
    public function set(string name, var service) -> <ServiceLocatorInterface>;

}
