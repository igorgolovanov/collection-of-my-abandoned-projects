
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
ZEPHIR_INIT_CLASS(ZendFramework_Mail_Storage_Writable_WritableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Mail\\Storage\\Writable, WritableInterface, zendframework, mail_storage_writable_writableinterface, zendframework_mail_storage_writable_writableinterface_method_entry);

	return SUCCESS;

}

/**
 * create a new folder
 *
 * This method also creates parent folders if necessary. Some mail storages may restrict, which folder
 * may be used as parent or which chars may be used in the folder name
 *
 * @param string                           $name         global name of folder, local name if $parentFolder is set
 * @param string|\Zend\Mail\Storage\Folder $parentFolder parent folder for new folder, else root folder is parent
 * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Writable_WritableInterface, createFolder);

/**
 * remove a folder
 *
 * @param string|\Zend\Mail\Storage\Folder $name name or instance of folder
 * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Writable_WritableInterface, removeFolder);

/**
 * rename and/or move folder
 *
 * The new name has the same restrictions as in createFolder()
 *
 * @param string|\Zend\Mail\Storage\Folder $oldName name or instance of folder
 * @param string                           $newName new global name of folder
 * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Writable_WritableInterface, renameFolder);

/**
 * append a new message to mail storage
 *
 * @param  string|\Zend\Mail\Message|\Zend\Mime\Message $message message as string or instance of message class
 * @param  null|string|\Zend\Mail\Storage\Folder        $folder  folder for new message, else current folder is taken
 * @param  null|array                                   $flags   set flags for new message, else a default set is used
 * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Writable_WritableInterface, appendMessage);

/**
 * copy an existing message
 *
 * @param  int                              $id     number of message
 * @param  string|\Zend\Mail\Storage\Folder $folder name or instance of target folder
 * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Writable_WritableInterface, copyMessage);

/**
 * move an existing message
 *
 * @param  int                              $id     number of message
 * @param  string|\Zend\Mail\Storage\Folder $folder name or instance of target folder
 * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Writable_WritableInterface, moveMessage);

/**
 * set flags for message
 *
 * NOTE: this method can't set the recent flag.
 *
 * @param  int   $id    number of message
 * @param  array $flags new flags for message
 * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_Mail_Storage_Writable_WritableInterface, setFlags);

