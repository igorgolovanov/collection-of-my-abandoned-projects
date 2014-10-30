
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
/**
 * Interface for navigational helpers
 */
ZEPHIR_INIT_CLASS(ZendFramework_View_Helper_Navigation_HelperInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\View\\Helper\\Navigation, HelperInterface, zendframework, view_helper_navigation_helperinterface, zendframework_view_helper_navigation_helperinterface_method_entry);

	zend_class_implements(zendframework_view_helper_navigation_helperinterface_ce TSRMLS_CC, 1, zendframework_view_helper_helperinterface_ce);
	return SUCCESS;

}

/**
 * Magic overload: Should proxy to {@link render()}.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, __toString);

/**
 * Renders helper
 *
 * @param  string|Navigation\AbstractContainer $container [optional] container to render.
 *                                         Default is null, which indicates
 *                                         that the helper should render
 *                                         the container returned by {@link
 *                                         getContainer()}.
 * @return string helper output
 * @throws \Zend\View\Exception\ExceptionInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, render);

/**
 * Sets ACL to use when iterating pages
 *
 * @param  Acl\AclInterface $acl [optional] ACL instance
 * @return HelperInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, setAcl);

/**
 * Returns ACL or null if it isn't set using {@link setAcl()} or
 * {@link setDefaultAcl()}
 *
 * @return Acl\AclInterface|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, getAcl);

/**
 * Checks if the helper has an ACL instance
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, hasAcl);

/**
 * Sets navigation container the helper should operate on by default
 *
 * @param  string|Navigation\AbstractContainer $container [optional] container to operate
 *                                         on. Default is null, which
 *                                         indicates that the container
 *                                         should be reset.
 * @return HelperInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, setContainer);

/**
 * Returns the navigation container the helper operates on by default
 *
 * @return Navigation\AbstractContainer  navigation container
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, getContainer);

/**
 * Checks if the helper has a container
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, hasContainer);

/**
 * Render invisible items?
 *
 * @param  bool $renderInvisible [optional] boolean flag
 * @return HelperInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, setRenderInvisible);

/**
 * Return renderInvisible flag
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, getRenderInvisible);

/**
 * Sets ACL role to use when iterating pages
 *
 * @param  mixed $role [optional] role to set.  Expects a string, an
 *                     instance of type {@link Acl\Role}, or null. Default
 *                     is null.
 * @throws \Zend\View\Exception\ExceptionInterface if $role is invalid
 * @return HelperInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, setRole);

/**
 * Returns ACL role to use when iterating pages, or null if it isn't set
 *
 * @return string|Acl\Role\RoleInterface|null
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, getRole);

/**
 * Checks if the helper has an ACL role
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, hasRole);

/**
 * Sets whether ACL should be used
 *
 * @param  bool $useAcl [optional] whether ACL should be used. Default is true.
 * @return HelperInterface
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, setUseAcl);

/**
 * Returns whether ACL should be used
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_View_Helper_Navigation_HelperInterface, getUseAcl);

