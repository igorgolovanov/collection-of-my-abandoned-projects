srcdir = /home/igor/projects/OAuth/ext
builddir = /home/igor/projects/OAuth/ext
top_srcdir = /home/igor/projects/OAuth/ext
top_builddir = /home/igor/projects/OAuth/ext
EGREP = /bin/grep -E
SED = /bin/sed
CONFIGURE_COMMAND = './configure' '--enable-oauth'
CONFIGURE_OPTIONS = '--enable-oauth'
SHLIB_SUFFIX_NAME = so
SHLIB_DL_SUFFIX_NAME = so
ZEND_EXT_TYPE = zend_extension
RE2C = re2c
AWK = nawk
shared_objects_oauth = oauth.lo kernel/main.lo kernel/memory.lo kernel/exception.lo kernel/hash.lo kernel/debug.lo kernel/backtrace.lo kernel/object.lo kernel/array.lo kernel/extended/array.lo kernel/string.lo kernel/fcall.lo kernel/require.lo kernel/alternative/fcall.lo kernel/file.lo kernel/operators.lo kernel/concat.lo kernel/variables.lo oauth/client.lo oauth/clientinterface.lo oauth/credentials.lo oauth/credentialsinterface.lo oauth/exceptioninterface.lo oauth/service.lo oauth/serviceinterface.lo oauth/token.lo oauth/tokenexpiredexception.lo oauth/tokeninterface.lo oauth/tokennotfoundexception.lo oauth/tokenstorage/memory.lo oauth/tokenstorageinterface.lo oauth/uri.lo oauth/uriinterface.lo oauth/v1/service.lo oauth/v1/serviceinterface.lo oauth/v1/signature.lo oauth/v1/signatureinterface.lo oauth/v1/token.lo oauth/v1/tokeninterface.lo oauth/v1/unsupportedhashalgorithmexception.lo oauth/v2/service.lo oauth/v2/serviceinterface.lo oauth/v2/token.lo oauth/v2/tokeninterface.lo
PHP_PECL_EXTENSION = oauth
PHP_MODULES = $(phplibdir)/oauth.la
PHP_ZEND_EX =
all_targets = $(PHP_MODULES) $(PHP_ZEND_EX)
install_targets = install-modules install-headers
prefix = /usr
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /usr
phplibdir = /home/igor/projects/OAuth/ext/modules
phpincludedir = /usr/include/php5
CC = gcc
CFLAGS = -O2
CFLAGS_CLEAN = $(CFLAGS)
CPP = gcc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX =
CXXFLAGS =
CXXFLAGS_CLEAN = $(CXXFLAGS)
EXTENSION_DIR = /usr/lib/php5/20100525
PHP_EXECUTABLE = /usr/bin/php
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/usr/include/php5 -I/usr/include/php5/main -I/usr/include/php5/TSRM -I/usr/include/php5/Zend -I/usr/include/php5/ext -I/usr/include/php5/ext/date/lib
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/bash
INSTALL_HEADERS =
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -DPHP_ATOM_INC -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)

all: $(all_targets) 
	@echo
	@echo "Build complete."
	@echo "Don't forget to run 'make test'."
	@echo
	
build-modules: $(PHP_MODULES) $(PHP_ZEND_EX)

build-binaries: $(PHP_BINARIES)

libphp$(PHP_MAJOR_VERSION).la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp $@ $(phptempdir)/$@ >/dev/null 2>&1

libs/libphp$(PHP_MAJOR_VERSION).bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp$(PHP_MAJOR_VERSION).so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-binaries: build-binaries $(install_binary_targets)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-headers:
	-@if test "$(INSTALL_HEADERS)"; then \
		for i in `echo $(INSTALL_HEADERS)`; do \
			i=`$(top_srcdir)/build/shtool path -d $$i`; \
			paths="$$paths $(INSTALL_ROOT)$(phpincludedir)/$$i"; \
		done; \
		$(mkinstalldirs) $$paths && \
		echo "Installing header files:          $(INSTALL_ROOT)$(phpincludedir)/" && \
		for i in `echo $(INSTALL_HEADERS)`; do \
			if test "$(PHP_PECL_EXTENSION)"; then \
				src=`echo $$i | $(SED) -e "s#ext/$(PHP_PECL_EXTENSION)/##g"`; \
			else \
				src=$$i; \
			fi; \
			if test -f "$(top_srcdir)/$$src"; then \
				$(INSTALL_DATA) $(top_srcdir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			elif test -f "$(top_builddir)/$$src"; then \
				$(INSTALL_DATA) $(top_builddir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			else \
				(cd $(top_srcdir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i; \
				cd $(top_builddir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i) 2>/dev/null || true; \
			fi \
		done; \
	fi

PHP_TEST_SETTINGS = -d 'open_basedir=' -d 'output_buffering=0' -d 'memory_limit=-1'
PHP_TEST_SHARED_EXTENSIONS =  ` \
	if test "x$(PHP_MODULES)" != "x"; then \
		for i in $(PHP_MODULES)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d extension=$$dlname"; \
		done; \
	fi; \
	if test "x$(PHP_ZEND_EX)" != "x"; then \
		for i in $(PHP_ZEND_EX)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d $(ZEND_EXT_TYPE)=$(top_builddir)/modules/$$dlname"; \
		done; \
	fi`
PHP_DEPRECATED_DIRECTIVES_REGEX = '^(magic_quotes_(gpc|runtime|sybase)?|(zend_)?extension(_debug)?(_ts)?)[\t\ ]*='

test: all
	-@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		INI_FILE=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r 'echo php_ini_loaded_file();' 2> /dev/null`; \
		if test "$$INI_FILE"; then \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_FILE" > $(top_builddir)/tmp-php.ini; \
		else \
			echo > $(top_builddir)/tmp-php.ini; \
		fi; \
		INI_SCANNED_PATH=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r '$$a = explode(",\n", trim(php_ini_scanned_files())); echo $$a[0];' 2> /dev/null`; \
		if test "$$INI_SCANNED_PATH"; then \
			INI_SCANNED_PATH=`$(top_srcdir)/build/shtool path -d $$INI_SCANNED_PATH`; \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_SCANNED_PATH"/*.ini >> $(top_builddir)/tmp-php.ini; \
		fi; \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(PHP_EXECUTABLE) -n -c $(top_builddir)/tmp-php.ini $(PHP_TEST_SETTINGS) $(top_srcdir)/run-tests.php -n -c $(top_builddir)/tmp-php.ini -d extension_dir=$(top_builddir)/modules/ $(PHP_TEST_SHARED_EXTENSIONS) $(TESTS); \
		rm $(top_builddir)/tmp-php.ini; \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.gcno -o -name \*.gcda | xargs rm -f
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	rm -f libphp$(PHP_MAJOR_VERSION).la $(SAPI_CLI_PATH) $(OVERALL_TARGET) modules/* libs/*

distclean: clean
	rm -f Makefile config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h stamp-h sapi/apache/libphp$(PHP_MAJOR_VERSION).module buildmk.stamp
	$(EGREP) define'.*include/php' $(top_srcdir)/configure | $(SED) 's/.*>//'|xargs rm -f

.PHONY: all clean install distclean test
.NOEXPORT:
oauth.lo: /home/igor/projects/OAuth/ext/oauth.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth.c -o oauth.lo 
kernel/main.lo: /home/igor/projects/OAuth/ext/kernel/main.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/main.c -o kernel/main.lo 
kernel/memory.lo: /home/igor/projects/OAuth/ext/kernel/memory.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/memory.c -o kernel/memory.lo 
kernel/exception.lo: /home/igor/projects/OAuth/ext/kernel/exception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/exception.c -o kernel/exception.lo 
kernel/hash.lo: /home/igor/projects/OAuth/ext/kernel/hash.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/hash.c -o kernel/hash.lo 
kernel/debug.lo: /home/igor/projects/OAuth/ext/kernel/debug.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/debug.c -o kernel/debug.lo 
kernel/backtrace.lo: /home/igor/projects/OAuth/ext/kernel/backtrace.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/backtrace.c -o kernel/backtrace.lo 
kernel/object.lo: /home/igor/projects/OAuth/ext/kernel/object.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/object.c -o kernel/object.lo 
kernel/array.lo: /home/igor/projects/OAuth/ext/kernel/array.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/array.c -o kernel/array.lo 
kernel/extended/array.lo: /home/igor/projects/OAuth/ext/kernel/extended/array.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/extended/array.c -o kernel/extended/array.lo 
kernel/string.lo: /home/igor/projects/OAuth/ext/kernel/string.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/string.c -o kernel/string.lo 
kernel/fcall.lo: /home/igor/projects/OAuth/ext/kernel/fcall.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/fcall.c -o kernel/fcall.lo 
kernel/require.lo: /home/igor/projects/OAuth/ext/kernel/require.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/require.c -o kernel/require.lo 
kernel/alternative/fcall.lo: /home/igor/projects/OAuth/ext/kernel/alternative/fcall.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/alternative/fcall.c -o kernel/alternative/fcall.lo 
kernel/file.lo: /home/igor/projects/OAuth/ext/kernel/file.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/file.c -o kernel/file.lo 
kernel/operators.lo: /home/igor/projects/OAuth/ext/kernel/operators.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/operators.c -o kernel/operators.lo 
kernel/concat.lo: /home/igor/projects/OAuth/ext/kernel/concat.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/concat.c -o kernel/concat.lo 
kernel/variables.lo: /home/igor/projects/OAuth/ext/kernel/variables.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/kernel/variables.c -o kernel/variables.lo 
oauth/client.lo: /home/igor/projects/OAuth/ext/oauth/client.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/client.c -o oauth/client.lo 
oauth/clientinterface.lo: /home/igor/projects/OAuth/ext/oauth/clientinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/clientinterface.c -o oauth/clientinterface.lo 
oauth/credentials.lo: /home/igor/projects/OAuth/ext/oauth/credentials.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/credentials.c -o oauth/credentials.lo 
oauth/credentialsinterface.lo: /home/igor/projects/OAuth/ext/oauth/credentialsinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/credentialsinterface.c -o oauth/credentialsinterface.lo 
oauth/exceptioninterface.lo: /home/igor/projects/OAuth/ext/oauth/exceptioninterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/exceptioninterface.c -o oauth/exceptioninterface.lo 
oauth/service.lo: /home/igor/projects/OAuth/ext/oauth/service.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/service.c -o oauth/service.lo 
oauth/serviceinterface.lo: /home/igor/projects/OAuth/ext/oauth/serviceinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/serviceinterface.c -o oauth/serviceinterface.lo 
oauth/token.lo: /home/igor/projects/OAuth/ext/oauth/token.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/token.c -o oauth/token.lo 
oauth/tokenexpiredexception.lo: /home/igor/projects/OAuth/ext/oauth/tokenexpiredexception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/tokenexpiredexception.c -o oauth/tokenexpiredexception.lo 
oauth/tokeninterface.lo: /home/igor/projects/OAuth/ext/oauth/tokeninterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/tokeninterface.c -o oauth/tokeninterface.lo 
oauth/tokennotfoundexception.lo: /home/igor/projects/OAuth/ext/oauth/tokennotfoundexception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/tokennotfoundexception.c -o oauth/tokennotfoundexception.lo 
oauth/tokenstorage/memory.lo: /home/igor/projects/OAuth/ext/oauth/tokenstorage/memory.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/tokenstorage/memory.c -o oauth/tokenstorage/memory.lo 
oauth/tokenstorageinterface.lo: /home/igor/projects/OAuth/ext/oauth/tokenstorageinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/tokenstorageinterface.c -o oauth/tokenstorageinterface.lo 
oauth/uri.lo: /home/igor/projects/OAuth/ext/oauth/uri.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/uri.c -o oauth/uri.lo 
oauth/uriinterface.lo: /home/igor/projects/OAuth/ext/oauth/uriinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/uriinterface.c -o oauth/uriinterface.lo 
oauth/v1/service.lo: /home/igor/projects/OAuth/ext/oauth/v1/service.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v1/service.c -o oauth/v1/service.lo 
oauth/v1/serviceinterface.lo: /home/igor/projects/OAuth/ext/oauth/v1/serviceinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v1/serviceinterface.c -o oauth/v1/serviceinterface.lo 
oauth/v1/signature.lo: /home/igor/projects/OAuth/ext/oauth/v1/signature.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v1/signature.c -o oauth/v1/signature.lo 
oauth/v1/signatureinterface.lo: /home/igor/projects/OAuth/ext/oauth/v1/signatureinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v1/signatureinterface.c -o oauth/v1/signatureinterface.lo 
oauth/v1/token.lo: /home/igor/projects/OAuth/ext/oauth/v1/token.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v1/token.c -o oauth/v1/token.lo 
oauth/v1/tokeninterface.lo: /home/igor/projects/OAuth/ext/oauth/v1/tokeninterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v1/tokeninterface.c -o oauth/v1/tokeninterface.lo 
oauth/v1/unsupportedhashalgorithmexception.lo: /home/igor/projects/OAuth/ext/oauth/v1/unsupportedhashalgorithmexception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v1/unsupportedhashalgorithmexception.c -o oauth/v1/unsupportedhashalgorithmexception.lo 
oauth/v2/service.lo: /home/igor/projects/OAuth/ext/oauth/v2/service.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v2/service.c -o oauth/v2/service.lo 
oauth/v2/serviceinterface.lo: /home/igor/projects/OAuth/ext/oauth/v2/serviceinterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v2/serviceinterface.c -o oauth/v2/serviceinterface.lo 
oauth/v2/token.lo: /home/igor/projects/OAuth/ext/oauth/v2/token.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v2/token.c -o oauth/v2/token.lo 
oauth/v2/tokeninterface.lo: /home/igor/projects/OAuth/ext/oauth/v2/tokeninterface.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/home/igor/projects/OAuth/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /home/igor/projects/OAuth/ext/oauth/v2/tokeninterface.c -o oauth/v2/tokeninterface.lo 
$(phplibdir)/oauth.la: ./oauth.la
	$(LIBTOOL) --mode=install cp ./oauth.la $(phplibdir)

./oauth.la: $(shared_objects_oauth) $(OAUTH_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(EXTRA_LDFLAGS) $(shared_objects_oauth) $(OAUTH_SHARED_LIBADD)

