/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Console\RouteMatcher;

interface RouteMatcherInterface
{
    /**
     * Match parameters against route passed to constructor
     *
     * @param array $params
     * @return array|null
     */
    public function match(array params) -> array;

}
