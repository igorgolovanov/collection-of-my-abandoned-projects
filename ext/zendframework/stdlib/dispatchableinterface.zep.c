
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Stdlib_DispatchableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Stdlib, DispatchableInterface, zendframework, stdlib_dispatchableinterface, zendframework_stdlib_dispatchableinterface_method_entry);

	return SUCCESS;

}

/**
 * Dispatch a request
 *
 * @param RequestInterface $request
 * @param null|ResponseInterface $response
 * @return Response|mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Stdlib_DispatchableInterface, dispatch);

