/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mvc\Router;

use Zend\Stdlib\RequestInterface;

/**
 * RouteInterface interface.
 */
interface RouteInterface
{
    /**
     * Create a new route with given options.
     *
     * @param  array|\Traversable $options
     * @return void
     */
    public static function factory(var options = []) -> void;

    /**
     * Match a given request.
     *
     * @param  RequestInterface $request
     * @return RouteMatch|null
     */
    public function match(<RequestInterface> request); // todo: -> <RouteMatch>|null;

    /**
     * Assemble the route.
     *
     * @param  array $params
     * @param  array $options
     * @return mixed
     */
    public function assemble(array! params = [], array! options = []);

}
