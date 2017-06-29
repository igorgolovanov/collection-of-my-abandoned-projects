PHP_ARG_ENABLE(oauth, whether to enable oauth, [ --enable-oauth   Enable Oauth])

if test "$PHP_OAUTH" = "yes"; then
	AC_DEFINE(HAVE_OAUTH, 1, [Whether you have Oauth])
	oauth_sources="oauth.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/alternative/fcall.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c oauth/client.c oauth/clientinterface.c oauth/credentials.c oauth/credentialsinterface.c oauth/exceptioninterface.c oauth/service.c oauth/serviceinterface.c oauth/token.c oauth/tokenexpiredexception.c oauth/tokeninterface.c oauth/tokennotfoundexception.c oauth/tokenstorage/memory.c oauth/tokenstorageinterface.c oauth/uri.c oauth/uriinterface.c oauth/v1/service.c oauth/v1/serviceinterface.c oauth/v1/signature.c oauth/v1/signatureinterface.c oauth/v1/token.c oauth/v1/tokeninterface.c oauth/v1/unsupportedhashalgorithmexception.c oauth/v2/service.c oauth/v2/serviceinterface.c oauth/v2/token.c oauth/v2/tokeninterface.c "
	PHP_NEW_EXTENSION(oauth, $oauth_sources, $ext_shared)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([oauth], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([oauth], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS
fi
