/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Validator;

interface ValidatorPluginManagerAwareInterface
{
    /**
     * Set validator plugin manager
     *
     * @param ValidatorPluginManager $pluginManager
     */
    public function setValidatorPluginManager(<ValidatorPluginManager> pluginManager);

    /**
     * Get validator plugin manager
     *
     * @return ValidatorPluginManager
     */
    public function getValidatorPluginManager() -> <ValidatorPluginManager>;

}
