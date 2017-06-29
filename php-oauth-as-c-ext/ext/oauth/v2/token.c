
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(OAuth_V2_Token) {

	ZEPHIR_REGISTER_CLASS_EX(OAuth\\V2, Token, oauth, v2_token, oauth_token_ce, NULL, 0);

	zend_class_implements(oauth_v2_token_ce TSRMLS_CC, 1, oauth_v2_tokeninterface_ce);

	return SUCCESS;

}

