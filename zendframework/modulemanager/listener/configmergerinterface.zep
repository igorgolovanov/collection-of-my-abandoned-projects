/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\ModuleManager\Listener;

/**
 * Config merger interface
 */
interface ConfigMergerInterface
{
    /**
     * getMergedConfig
     *
     * @param  bool $returnConfigAsObject
     * @return mixed
     */
    public function getMergedConfig(boolean returnConfigAsObject = true);

    /**
     * setMergedConfig
     *
     * @param  array $config
     * @return ConfigMergerInterface
     */
    public function setMergedConfig(array! config) -> <ConfigMergerInterface>;

}
