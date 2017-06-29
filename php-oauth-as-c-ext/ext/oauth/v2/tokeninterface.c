
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(OAuth_V2_TokenInterface) {

	ZEPHIR_REGISTER_INTERFACE_EX(OAuth\\V2, TokenInterface, oauth, v2_tokeninterface, oauth_tokeninterface_ce, NULL);


	return SUCCESS;

}

