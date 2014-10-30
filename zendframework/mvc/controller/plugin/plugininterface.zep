/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mvc\Controller\Plugin;

use Zend\Stdlib\DispatchableInterface;

interface PluginInterface
{
    /**
     * Set the current controller instance
     *
     * @param  Dispatchable $controller
     * @return void
     */
    public function setController(<DispatchableInterface> controller) -> void;

    /**
     * Get the current controller instance
     *
     * @return null|DispatchableInterface
     */
    public function getController() -> <DispatchableInterface>|null;

}
