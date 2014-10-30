
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Db_Adapter_Driver_Feature_DriverFeatureInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Db\\Adapter\\Driver\\Feature, DriverFeatureInterface, zendframework, db_adapter_driver_feature_driverfeatureinterface, zendframework_db_adapter_driver_feature_driverfeatureinterface_method_entry);

	return SUCCESS;

}

/**
 * Setup the default features for Pdo
 *
 * @return DriverFeatureInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_Feature_DriverFeatureInterface, setupDefaultFeatures);

/**
 * Add feature
 *
 * @param string $name
 * @param mixed $feature
 * @return DriverFeatureInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_Feature_DriverFeatureInterface, addFeature);

/**
 * Get feature
 *
 * @param $name
 * @return mixed|false
 */
ZEPHIR_DOC_METHOD(ZendFramework_Db_Adapter_Driver_Feature_DriverFeatureInterface, getFeature);

