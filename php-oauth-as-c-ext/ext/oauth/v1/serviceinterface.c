
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(OAuth_V1_ServiceInterface) {

	ZEPHIR_REGISTER_INTERFACE_EX(OAuth\\V1, ServiceInterface, oauth, v1_serviceinterface, oauth_serviceinterface_ce, NULL);


	return SUCCESS;

}

