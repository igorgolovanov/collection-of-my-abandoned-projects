/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Config;

use Zend\ServiceManager\AbstractPluginManager;

class WriterPluginManager extends AbstractPluginManager
{

    protected invokableClasses = [
	    "ini": "Zend\Config\Writer\Ini", 
	    "json": "Zend\Config\Writer\Json", 
	    "php": "Zend\Config\Writer\PhpArray", 
	    "yaml": "Zend\Config\Writer\Yaml", 
	    "xml": "Zend\Config\Writer\Xml"
    ];

    public function validatePlugin(var plugin)
    {
    	string exceptionMsg, type;

        if unlikely !(plugin instanceof Writer\WriterInterface) {
            let type = typeof type;
            if type == "object" {
                let type = get_class(type);
            }
            let exceptionMsg = "Plugin of type " . type . " is invalid; must implement " . __NAMESPACE__ . "\Writer\WriterInterface";
            throws new throw new Exception\InvalidArgumentException(exceptionMsg);
        }
    }

}
