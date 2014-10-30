
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/
ZEPHIR_INIT_CLASS(ZendFramework_Mail_Storage_Folder_FolderInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mail\\Storage\\Folder, FolderInterface, zendframework, mail_storage_folder_folderinterface, zendframework_mail_storage_folder_folderinterface_method_entry);

	return SUCCESS;

}

/**
 * get root folder or given folder
 *
 * @param string $rootFolder get folder structure for given folder, else root
 * @return FolderInterface root or wanted folder
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Folder_FolderInterface, getFolders);

/**
 * select given folder
 *
 * folder must be selectable!
 *
 * @param FolderInterface|string $globalName global name of folder or instance for subfolder
 * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Folder_FolderInterface, selectFolder);

/**
 * get Zend\Mail\Storage\Folder instance for current folder
 *
 * @return FolderInterface instance of current folder
 * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Folder_FolderInterface, getCurrentFolder);

