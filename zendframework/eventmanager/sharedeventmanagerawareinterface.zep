/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\EventManager;

/**
 * Interface to automate setter injection for a SharedEventManagerInterface instance
 */
interface SharedEventManagerAwareInterface
{
    /**
     * Inject a SharedEventManager instance
     *
     * @param  SharedEventManagerInterface $sharedEventManager
     * @return SharedEventManagerAwareInterface
     */
    public function setSharedManager(<SharedEventManagerInterface> sharedEventManager) -> <SharedEventManagerAwareInterface>;

    /**
     * Get shared collections container
     *
     * @return SharedEventManagerInterface
     */
    public function getSharedManager() -> <SharedEventManagerInterface>;

    /**
     * Remove any shared collections
     *
     * @return void
     */
    public function unsetSharedManager() -> void;

}
