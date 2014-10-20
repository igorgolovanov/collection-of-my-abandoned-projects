/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator;


use Zend\ServiceManager\AbstractPluginManager;
use Zend\Stdlib\Exception;

/**
 * Plugin manager implementation for hydrators.
 *
 * Enforces that adapters retrieved are instances of HydratorInterface
 */
class HydratorPluginManager extends AbstractPluginManager
{
    /**
     * Whether or not to share by default
     *
     * @var bool
     */
    protected shareByDefault = false;

    /**
     * Default set of adapters
     *
     * @var array
     */
    protected invokableClasses; // ["arrayserializable": "Zend\Stdlib\Hydrator\ArraySerializable", "classmethods": "Zend\Stdlib\Hydrator\ClassMethods", "objectproperty": "Zend\Stdlib\Hydrator\ObjectProperty", "reflection": "Zend\Stdlib\Hydrator\Reflection"]

    /**
     * {@inheritDoc}
     */
    public function validatePlugin(plugin)
    {
        string exceptionMsg, type;

        if plugin instanceof HydratorInterface {
            return;
        }

        let type = typeof plugin;
        if type == "object" {
            let type = get_class(plugin);
        }

        let exceptionMsg = "Plugin of type %s is invalid; must implement Zend\Stdlib\Hydrator\HydratorInterface";
        let exceptionMsg = sprintf(exceptionMsg, type);

        throw new Exception\RuntimeException(exceptionMsg);
    }

}
