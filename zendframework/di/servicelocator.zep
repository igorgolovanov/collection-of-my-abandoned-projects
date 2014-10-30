/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Di;

use Closure;

/**
 * Simple service locator implementation capable of using closures to generate instances
 */
class ServiceLocator implements ServiceLocatorInterface
{
    /**
     * Map of service names to methods
     *
     * As an example, you might define a getter method "getFoo", and map it to
     * the service name "foo":
     *
     * <code>
     * protected $map = array('foo' => 'getFoo');
     * </code>
     *
     * When encountered, the return value of that method will be used.
     *
     * Methods mapped in this way may expect a single, array argument, the
     * $params passed to {@link get()}, if any.
     *
     * @var array
     */
    protected map = [];

    /**
     * Registered services and cached values
     *
     * @var array
     */
    protected services = [];

    /**
     * {@inheritDoc}
     */
    public function set(string name, var service) -> <ServiceLocator>
    {
        let this->services[name] = service;

        return this;
    }

    /**
     * Retrieve a registered service
     *
     * Tests first if a value is registered for the service, and, if so,
     * returns it.
     *
     * If the value returned is a non-object callback or closure, the return
     * value is retrieved, stored, and returned. Parameters passed to the method
     * are passed to the callback, but only on the first retrieval.
     *
     * If the service requested matches a method in the method map, the return
     * value of that method is returned. Parameters are passed to the matching
     * method.
     *
     * @param  string $name
     * @param  array  $params
     * @return mixed
     */
    public function get(string name, array! params = [])
    {
        var service, method;

        if fetch service, this->services[name] {
            if service instanceof Closure || (typeof service != "object" && is_callable(service)) {
                let service = call_user_func_array(service, params);
                let this->services[name] = service;
            }
            return service;
        }

        if fetch method, this->map[name] {
            return this->{method}(params);
        }

        return null;
    }

}
