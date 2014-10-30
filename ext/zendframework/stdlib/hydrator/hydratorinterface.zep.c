
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_Hydrator_HydratorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib\\Hydrator, HydratorInterface, zendframework, stdlib_hydrator_hydratorinterface, NULL);

	zend_class_implements(zendframework_stdlib_hydrator_hydratorinterface_ce TSRMLS_CC, 1, zendframework_stdlib_hydrator_hydrationinterface_ce);
	zend_class_implements(zendframework_stdlib_hydrator_hydratorinterface_ce TSRMLS_CC, 1, zendframework_stdlib_extractor_extractioninterface_ce);
	return SUCCESS;

}

