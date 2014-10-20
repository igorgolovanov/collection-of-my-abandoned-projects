/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Permissions\Acl\Assertion;

use Zend\ServiceManager\AbstractPluginManager;
use Zend\Permissions\Acl\Exception\InvalidArgumentException;

class AssertionManager extends AbstractPluginManager
{
    protected sharedByDefault = true;

    /**
     * Validate the plugin
     *
     * Checks that the element is an instance of AssertionInterface
     *
     * @param mixed $plugin
     *
     * @throws InvalidArgumentException
     * @return bool
     */
    public function validatePlugin(var plugin) -> boolean
    {
        string type, exceptionMsg;

        let type = typeof plugin;

        if unlikely type != "object" || !(plugin instanceof AssertionInterface) {
            if type == "object" {
                let type = get_class(plugin);
            }
            let exceptionMsg = "Plugin of type " . type . " is invalid; must implement Zend\Permissions\Acl\Assertion\AssertionInterface";
            throw new InvalidArgumentException(exceptionMsg);
        }
        return true;
    }

}
