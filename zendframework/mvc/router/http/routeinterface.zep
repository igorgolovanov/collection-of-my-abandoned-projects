/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mvc\Router\Http;

use Zend\Mvc\Router\RouteInterface as MvcRouteInterface;

/**
 * Tree specific route interface.
 */
interface RouteInterface extends MvcRouteInterface
{
    /**
     * Get a list of parameters used while assembling.
     *
     * @return array
     */
    public function getAssembledParams() -> array;

}
