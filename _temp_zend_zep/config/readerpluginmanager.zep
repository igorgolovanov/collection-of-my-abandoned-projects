/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Config;

use Zend\ServiceManager\AbstractPluginManager;

class ReaderPluginManager extends AbstractPluginManager
{
    /**
     * Default set of readers
     *
     * @var array
     */
    protected invokableClasses = [
        "ini": "Zend\Config\Reader\Ini", 
        "json": "Zend\Config\Reader\Json", 
        "xml": "Zend\Config\Reader\Xml", 
        "yaml": "Zend\Config\Reader\Yaml"
    ];

    /**
     * Validate the plugin
     * Checks that the reader loaded is an instance of Reader\ReaderInterface.
     *
     * @param  Reader\ReaderInterface $plugin
     * @return void
     * @throws Exception\InvalidArgumentException if invalid
     */
    public function validatePlugin(var plugin) -> void
    {
        string exceptionMsg, type;

        if unlikely !(plugin instanceof Reader\ReaderInterface) {
            let type = typeof type;
            if type == "object" {
                let type = get_class(type);
            }
            let exceptionMsg = "Plugin of type " . type . " is invalid; must implement " . __NAMESPACE__ . "\Reader\ReaderInterface";
            throws new throw new Exception\InvalidArgumentException(exceptionMsg);
        }
    }

}
