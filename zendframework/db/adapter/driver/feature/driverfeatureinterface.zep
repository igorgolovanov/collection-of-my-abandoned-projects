/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Adapter\Driver\Feature;

interface DriverFeatureInterface
{
    /**
     * Setup the default features for Pdo
     *
     * @return DriverFeatureInterface
     */
    public function setupDefaultFeatures() -> <DriverFeatureInterface>;

    /**
     * Add feature
     *
     * @param string $name
     * @param mixed $feature
     * @return DriverFeatureInterface
     */
    public function addFeature(string name, var feature) -> <DriverFeatureInterface>;

    /**
     * Get feature
     *
     * @param $name
     * @return mixed|false
     */
    public function getFeature(var name);

}
