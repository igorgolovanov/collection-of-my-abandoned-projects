
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
/**
 * Server Interface
 */
ZEPHIR_INIT_CLASS(ZendFramework_Server_Server) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Server, Server, zendframework, server_server, zendframework_server_server_method_entry);

	return SUCCESS;

}

/**
 * Attach a function as a server method
 *
 * Namespacing is primarily for xmlrpc, but may be used with other
 * implementations to prevent naming collisions.
 *
 * @param  string $function
 * @param  string $namespace
 * @param  null|array Optional array of arguments to pass to callback at
 *                    dispatch.
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Server, addFunction);

/**
 * Attach a class to a server
 *
 * The individual implementations should probably allow passing a variable
 * number of arguments in, so that developers may define custom runtime
 * arguments to pass to server methods.
 *
 * Namespacing is primarily for xmlrpc, but could be used for other
 * implementations as well.
 *
 * @param  mixed $class Class name or object instance to examine and attach
 *                      to the server.
 * @param  string $namespace Optional namespace with which to prepend method
 *                           names in the dispatch table.
 *                           methods in the class will be valid callbacks.
 * @param  null|array Optional array of arguments to pass to callbacks at
 *                    dispatch.
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Server, setClass);

/**
 * Generate a server fault
 *
 * @param  mixed $fault
 * @param  int $code
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Server, fault);

/**
 * Handle a request
 *
 * Requests may be passed in, or the server may automatically determine the
 * request based on defaults. Dispatches server request to appropriate
 * method and returns a response
 *
 * @param  mixed $request
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Server, handle);

/**
 * Return a server definition array
 *
 * Returns a server definition array as created using
 * {@link Reflection}. Can be used for server introspection,
 * documentation, or persistence.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Server, getFunctions);

/**
 * Load server definition
 *
 * Used for persistence; loads a construct as returned by {@link getFunctions()}.
 *
 * @param  array $definition
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Server, loadFunctions);

/**
 * Set server persistence
 *
 * @todo Determine how to implement this
 * @param  int $mode
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Server, setPersistence);

/**
 * Sets auto-response flag for the server.
 *
 * To unify all servers, default behavior should be to auto-emit response.
 *
 * @param  bool $flag
 * @return Server Self instance.
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Server, setReturnResponse);

/**
 * Returns auto-response flag of the server.
 *
 * @return bool $flag Current status.
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Server, getReturnResponse);

/**
 * Returns last produced response.
 *
 * @return string|object Content of last response, or response object that
 *                       implements __toString() methods.
 */
ZEPHIR_DOC_METHOD(ZendFramework_Server_Server, getResponse);

