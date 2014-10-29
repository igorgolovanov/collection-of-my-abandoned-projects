/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\View\Helper;

use Zend\View\Renderer\RendererInterface;

interface HelperInterface
{
    /**
     * Set the View object
     *
     * @param  Renderer $view
     * @return HelperInterface
     */
    public function setView(<RendererInterface> view) -> <HelperInterface>;

    /**
     * Get the View object
     *
     * @return Renderer
     */
    public function getView() -> <RendererInterface>;

}
