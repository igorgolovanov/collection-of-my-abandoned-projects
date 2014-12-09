
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
ZEPHIR_INIT_CLASS(ZendFramework_Cache_Storage_TaggableInterface) {

	ZEPHIR_REGISTER_INTERFACE(Zend\\Cache\\Storage, TaggableInterface, zendframework, cache_storage_taggableinterface, zendframework_cache_storage_taggableinterface_method_entry);

	return SUCCESS;

}

/**
 * Set tags to an item by given key.
 * An empty array will remove all tags.
 *
 * @param string   $key
 * @param string[] $tags
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_TaggableInterface, setTags);

/**
 * Get tags of an item by given key
 *
 * @param string $key
 * @return string[]|FALSE
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_TaggableInterface, getTags);

/**
 * Remove items matching given tags.
 *
 * If $disjunction only one of the given tags must match
 * else all given tags must match.
 *
 * @param string[] $tags
 * @param  bool  $disjunction
 * @return bool
 */
ZEPHIR_DOC_METHOD(ZendFramework_Cache_Storage_TaggableInterface, clearByTags);

