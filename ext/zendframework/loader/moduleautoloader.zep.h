
extern zend_class_entry *zendframework_loader_moduleautoloader_ce;

ZEPHIR_INIT_CLASS(ZendFramework_Loader_ModuleAutoloader);

PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, __construct);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, setOptions);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, getModuleClassMap);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, setModuleClassMap);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, autoload);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, loadModuleFromDir);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, loadModuleFromPhar);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, register);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, unregister);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, registerPaths);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, registerPath);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, getPaths);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, pharFileToModuleName);
PHP_METHOD(ZendFramework_Loader_ModuleAutoloader, normalizePath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_moduleautoloader___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_moduleautoloader_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_moduleautoloader_setmoduleclassmap, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, classmap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_moduleautoloader_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_moduleautoloader_loadmodulefromdir, 0, 0, 2)
	ZEND_ARG_INFO(0, dirPath)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_moduleautoloader_loadmodulefromphar, 0, 0, 2)
	ZEND_ARG_INFO(0, pharPath)
	ZEND_ARG_INFO(0, class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_moduleautoloader_registerpaths, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_moduleautoloader_registerpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_moduleautoloader_pharfiletomodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, pharPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_zendframework_loader_moduleautoloader_normalizepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, trailingSlash)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(zendframework_loader_moduleautoloader_method_entry) {
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, __construct, arginfo_zendframework_loader_moduleautoloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, setOptions, arginfo_zendframework_loader_moduleautoloader_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, getModuleClassMap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, setModuleClassMap, arginfo_zendframework_loader_moduleautoloader_setmoduleclassmap, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, autoload, arginfo_zendframework_loader_moduleautoloader_autoload, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, loadModuleFromDir, arginfo_zendframework_loader_moduleautoloader_loadmodulefromdir, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, loadModuleFromPhar, arginfo_zendframework_loader_moduleautoloader_loadmodulefromphar, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, unregister, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, registerPaths, arginfo_zendframework_loader_moduleautoloader_registerpaths, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, registerPath, arginfo_zendframework_loader_moduleautoloader_registerpath, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, pharFileToModuleName, arginfo_zendframework_loader_moduleautoloader_pharfiletomodulename, ZEND_ACC_PROTECTED)
	PHP_ME(ZendFramework_Loader_ModuleAutoloader, normalizePath, arginfo_zendframework_loader_moduleautoloader_normalizepath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
