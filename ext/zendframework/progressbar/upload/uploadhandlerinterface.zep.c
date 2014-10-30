
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
/**
 * Interface for Upload Progress Handlers
 */
ZEPHIR_INIT_CLASS(ZendFramework_ProgressBar_Upload_UploadHandlerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\ProgressBar\\Upload, UploadHandlerInterface, zendframework, progressbar_upload_uploadhandlerinterface, zendframework_progressbar_upload_uploadhandlerinterface_method_entry);

	return SUCCESS;

}

/**
 * @param  string $id
 * @return array
 */
ZEPHIR_DOC_METHOD(ZendFramework_ProgressBar_Upload_UploadHandlerInterface, getProgress);

