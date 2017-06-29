<?php
/**
Plugin Name: WP Taxonomy Metadata
Plugin URI: https://github.com/golovanov/wp-taxonomy-metadata
Description: Taxonomy Metadata plugin for WordPress.
Version: 0.1
Author: Igor Golovanov
Author URI: https://github.com/golovanov/
*/

/**
 * Init taxonomy metadata.
 */
function wp_taxonomy_metadata_init() {
    global $wpdb;
    $wpdb->taxonomymeta = "{$wpdb->prefix}term_taxonomymeta";
}

/**
 * Activation hook for taxonomy metadata.
 *
 * @param $network
 */
function wp_taxonomy_metadata_activation_hook($network) {
    if (!$network) {
        wp_taxonomy_metadata_setup_blog();
        return;
    }
    global $wpdb;

    $blogs = $wpdb->get_col("SELECT blog_id FROM {$wpdb->blogs} WHERE site_id = '{$wpdb->siteid}'");
    array_walk($blogs, 'wp_taxonomy_metadata_setup_blog');
}

/**
 * Setup taxonomy metadata for each blog.
 *
 * @param int $blog_id
 */
function wp_taxonomy_metadata_setup_blog($blog_id = null) {
    global $wpdb;

    $charset_collate = '';

    if (!empty($wpdb->charset)) {
        $charset_collate = "DEFAULT CHARACTER SET $wpdb->charset";
    }
    if (!empty($wpdb->collate)) {
        $charset_collate .= " COLLATE $wpdb->collate";
    }

    if ($blog_id && $blog_id != $wpdb->blogid) {
        $old_blog_id = $wpdb->set_blog_id($blog_id);
    }
    $tables = $wpdb->get_results("show tables like '{$wpdb->prefix}term_taxonomymeta'");

    if (!count($tables)) {
        $wpdb->query("CREATE TABLE {$wpdb->prefix}term_taxonomymeta (
				meta_id bigint(20) unsigned NOT NULL auto_increment,
				term_taxonomy_id bigint(20) unsigned NOT NULL default '0',
				meta_key varchar(255) default NULL,
				meta_value longtext,
				PRIMARY KEY	(meta_id),
				KEY term_taxonomy_key (term_taxonomy_id),
				KEY meta_key (meta_key)
			) $charset_collate;");
    }
    if (isset($old_blog_id)) {
        $wpdb->set_blog_id($old_blog_id);
    }
}

add_action('init', 'wp_taxonomy_metadata_init');
add_action('switch_blog', 'wp_taxonomy_metadata_init');
add_action('wpmu_new_blog', 'wp_taxonomy_metadata_setup_blog', 10, 6);

register_activation_hook( __FILE__, 'wp_taxonomy_metadata_activation_hook');


if (!function_exists('add_taxonomy_meta')):
/**
 * Add meta data field to a term taxonomy.
 *
 * @uses add_metadata()
 *
 * @param int $term_taxonomy_id Term Taxonomy ID.
 * @param string $meta_key Metadata name.
 * @param mixed $meta_value Metadata value.
 * @param bool $unique Optional, default is false. Whether the same key should not be added.
 * @return int|bool Meta ID on success, false on failure.
 */
function add_taxonomy_meta($term_taxonomy_id, $meta_key, $meta_value, $unique = false) {
    return add_metadata('term_taxonomy', $term_taxonomy_id, $meta_key, $meta_value, $unique);
}
endif;

if (!function_exists('delete_taxonomy_meta')):
/**
 * Remove metadata matching criteria from a term taxonomy.
 *
 * You can match based on the key, or key and value. Removing based on key and
 * value, will keep from removing duplicate metadata with the same key. It also
 * allows removing all metadata matching key, if needed.
 *
 * @uses delete_metadata()
 *
 * @param int $term_taxonomy_id Term Taxonomy ID.
 * @param string $meta_key Metadata name.
 * @param mixed $meta_value Optional. Metadata value.
 * @return bool True on success, false on failure.
 */
function delete_taxonomy_meta($term_taxonomy_id, $meta_key, $meta_value = '') {
    return delete_metadata('term_taxonomy', $term_taxonomy_id, $meta_key, $meta_value);
}
endif;

if (!function_exists('get_taxonomy_meta')):
/**
 * Retrieve user meta field for a term taxonomy.
 *
 * @uses get_metadata()
 *
 * @param int $term_taxonomy_id Term Taxonomy ID.
 * @param string $key Optional. The meta key to retrieve. By default, returns data for all keys.
 * @param bool $single Whether to return a single value.
 * @return mixed Will be an array if $single is false. Will be value of meta data field if $single
 *  is true.
 */
function get_taxonomy_meta($term_taxonomy_id, $key = '', $single = false) {
    return get_metadata('term_taxonomy', $term_taxonomy_id, $key, $single);
}
endif;

if (!function_exists('update_taxonomy_meta')):
/**
 * Update user meta field based on term taxonomy ID.
 *
 * Use the $prev_value parameter to differentiate between meta fields with the
 * same key and user ID.
 *
 * If the meta field for the user does not exist, it will be added.
 *
 * @uses update_metadata()
 *
 * @param int $term_taxonomy_id Term Taxonomy ID.
 * @param string $meta_key Metadata key.
 * @param mixed $meta_value Metadata value.
 * @param mixed $prev_value Optional. Previous value to check before removing.
 * @return bool True on success, false on failure.
 */
function update_taxonomy_meta($term_taxonomy_id, $meta_key, $meta_value, $prev_value = '') {
    return update_metadata('term_taxonomy', $term_taxonomy_id, $meta_key, $meta_value, $prev_value);
}
endif;