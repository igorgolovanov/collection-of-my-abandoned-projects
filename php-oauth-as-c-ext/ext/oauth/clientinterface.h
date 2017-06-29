
extern zend_class_entry *oauth_clientinterface_ce;

ZEPHIR_INIT_CLASS(OAuth_ClientInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_oauth_clientinterface_retrieve, 0, 0, 2)
	ZEND_ARG_INFO(0, endpoint)
	ZEND_ARG_INFO(0, requestBody)
	ZEND_ARG_INFO(0, headers)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(oauth_clientinterface_method_entry) {
	PHP_ABSTRACT_ME(OAuth_ClientInterface, retrieve, arginfo_oauth_clientinterface_retrieve)
	PHP_FE_END
};
