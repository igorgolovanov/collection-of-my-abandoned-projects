
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
ZEPHIR_INIT_CLASS(ZendFramework_Console_Prompt_PromptInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Console\\Prompt, PromptInterface, zendframework, console_prompt_promptinterface, zendframework_console_prompt_promptinterface_method_entry);

	return SUCCESS;

}

/**
 * Show the prompt to user and return the answer.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Prompt_PromptInterface, show);

/**
 * Return last answer to this prompt.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Prompt_PromptInterface, getLastResponse);

/**
 * Return console adapter to use when showing prompt.
 *
 * @return ConsoleAdapter
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Prompt_PromptInterface, getConsole);

/**
 * Set console adapter to use when showing prompt.
 *
 * @param ConsoleAdapter $adapter
 * @return void
 */
ZEPHIR_DOC_METHOD(ZendFramework_Console_Prompt_PromptInterface, setConsole);

