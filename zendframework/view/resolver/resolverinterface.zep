/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\View\Resolver;

interface ResolverInterface
{
    /**
     * Resolve a template/pattern name to a resource the renderer can consume
     *
     * @param  string $name
     * @param  null|Renderer $renderer
     * @return mixed
     */
    public function resolve(string name, var renderer = null);

}
