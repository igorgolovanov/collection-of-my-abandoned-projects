<?php
/**
 * Plugin Name: WP Term Metadata
 * Plugin URI: https://github.com/golovanov/wp-term-metadata
 * Description: WP Term Metadata Plugin for retrieving and manipulating metadata
 * of term objects. Metadata for an object is a represented by a simple key-value
 * pair. Objects may contain multiple metadata entries that share the same key
 * and differ only in their value.
 * Version: 0.2
 * Author: Igor Golovanov
 * Author URI: https://github.com/golovanov/
 * License: GPLv2
 */

/**
 * Initialize term metadata.
 */
function wp_term_metadata_init() {
	global $wpdb;
	$wpdb->termmeta = "{$wpdb->prefix}termmeta";
}

add_action( 'init', 'wp_term_metadata_init' );
add_action( 'switch_blog', 'wp_term_metadata_init' );

/**
 * Activation hook for term metadata.
 *
 * @param $network
 */
function wp_term_metadata_activation_hook( $network ) {
	if ( ! $network ) {
		wp_term_metadata_setup_blog();

		return;
	}
	global $wpdb;

	$blog_ids = $wpdb->get_col( $wpdb->prepare( "SELECT blog_id FROM $wpdb->blogs WHERE site_id = %d", $wpdb->siteid ) );
	array_walk( $blog_ids, 'wp_term_metadata_setup_blog' );
}

register_activation_hook( __FILE__, 'wp_term_metadata_activation_hook' );

/**
 * Setup term metadata for each blog.
 *
 * @param int $blog_id
 */
function wp_term_metadata_setup_blog( $blog_id = null ) {
	global $wpdb;

	$charset_collate = '';

	if ( ! empty( $wpdb->charset ) ) {
		$charset_collate = "DEFAULT CHARACTER SET $wpdb->charset";
	}
	if ( ! empty( $wpdb->collate ) ) {
		$charset_collate .= " COLLATE $wpdb->collate";
	}

	if ( $blog_id && $blog_id != $wpdb->blogid ) {
		$old_blog_id = $wpdb->set_blog_id( $blog_id );
	}
	$tables = $wpdb->get_results( $wpdb->prepare( "SHOW TABLES LIKE %s", $wpdb->prefix . 'termmeta' ) );

	if ( ! count( $tables ) ) {
		$wpdb->query(
			"CREATE TABLE {$wpdb->prefix}termmeta (
				meta_id bigint(20) unsigned NOT NULL auto_increment,
				term_id bigint(20) unsigned NOT NULL default '0',
				meta_key varchar(255) default NULL,
				meta_value longtext,
				PRIMARY KEY	(meta_id),
				KEY term_key (term_id),
				KEY meta_key (meta_key)
			) $charset_collate;"
		);
	}
	if ( isset( $old_blog_id ) ) {
		$wpdb->set_blog_id( $old_blog_id );
	}
}

add_action( 'wpmu_new_blog', 'wp_term_metadata_setup_blog', 10, 6 );

/**
 * Delete all meta data from a term.
 *
 * @uses delete_metadata_by_mid()
 *
 * @param int $term_id Term ID.
 *
 * @return bool True on success, false on failure.
 */
function wp_term_metadata_delete( $term_id ) {
	/**
	 * @var wpdb $wpdb
	 */
	global $wpdb;

	if ( ! $term_id = absint( $term_id ) ) {
		return false;
	}

	if ( $wpdb->get_var( $wpdb->prepare( "SELECT 1 FROM $wpdb->term_taxonomy WHERE term_id = %d", $term_id ) ) ) {
		return true;
	}
	$meta_ids = $wpdb->get_col( $wpdb->prepare( "SELECT meta_id FROM $wpdb->termmeta WHERE term_id = %d", $term_id ) );
	foreach ( $meta_ids as $mid ) {
		delete_metadata_by_mid( 'term', $mid );
	}

	return true;
}

add_action( 'delete_term', 'wp_term_metadata_delete' );


if ( ! function_exists( 'add_term_meta' ) ):
	/**
	 * Add meta data field to a term.
	 *
	 * @uses add_metadata()
	 *
	 * @param int $term_id Term ID.
	 * @param string $meta_key Metadata name.
	 * @param mixed $meta_value Metadata value.
	 * @param bool $unique Optional, default is false. Whether the same key should not be added.
	 *
	 * @return int|bool Meta ID on success, false on failure.
	 */
	function add_term_meta( $term_id, $meta_key, $meta_value, $unique = false ) {
		return add_metadata( 'term', $term_id, $meta_key, $meta_value, $unique );
	}
endif;

if ( ! function_exists( 'delete_term_meta' ) ):
	/**
	 * Remove meta data matching criteria from a term.
	 *
	 * You can match based on the key, or key and value. Removing based on key and
	 * value, will keep from removing duplicate metadata with the same key. It also
	 * allows removing all metadata matching key, if needed.
	 *
	 * @uses delete_metadata()
	 *
	 * @param int $term_id Term ID.
	 * @param string $meta_key Metadata name.
	 * @param mixed $meta_value Optional. Metadata value.
	 *
	 * @return bool True on success, false on failure.
	 */
	function delete_term_meta( $term_id, $meta_key, $meta_value = '' ) {
		return delete_metadata( 'term', $term_id, $meta_key, $meta_value );
	}
endif;

if ( ! function_exists( 'get_term_meta' ) ):
	/**
	 * Retrieve term meta field for a term.
	 *
	 * @uses get_metadata()
	 *
	 * @param int $term_id Term ID.
	 * @param string $meta_key Optional. The meta key to retrieve. By default, returns data for all keys.
	 * @param bool $single Whether to return a single value.
	 *
	 * @return mixed Will be an array if $single is false. Will be value of meta data field if $single
	 *  is true.
	 */
	function get_term_meta( $term_id, $meta_key = '', $single = false ) {
		return get_metadata( 'term', $term_id, $meta_key, $single );
	}
endif;

if ( ! function_exists( 'update_term_meta' ) ):
	/**
	 * Update term meta field based on term ID.
	 *
	 * Use the $prev_value parameter to differentiate between meta fields with the
	 * same key and term ID.
	 *
	 * If the meta field for the user does not exist, it will be added.
	 *
	 * @uses update_metadata()
	 *
	 * @param int $term_id Term ID.
	 * @param string $meta_key Metadata key.
	 * @param mixed $meta_value Metadata value.
	 * @param mixed $prev_value Optional. Previous value to check before removing.
	 *
	 * @return bool True on success, false on failure.
	 */
	function update_term_meta( $term_id, $meta_key, $meta_value, $prev_value = '' ) {
		return update_metadata( 'term', $term_id, $meta_key, $meta_value, $prev_value );
	}
endif;

if ( ! function_exists( 'add_term_taxonomy_meta' ) ):
	/**
	 * Add meta data field to a term based on taxonomy name.
	 *
	 * @uses add_metadata()
	 * @uses taxonomy_exists()
	 *
	 * @param int $term_id Term ID.
	 * @param string $taxonomy Name of taxonomy object
	 * @param string $meta_key Metadata name.
	 * @param mixed $meta_value Metadata value.
	 * @param bool $unique Optional, default is false. Whether the same key should not be added.
	 *
	 * @return int|bool Meta ID on success, false on failure.
	 */
	function add_term_taxonomy_meta( $term_id, $taxonomy, $meta_key, $meta_value, $unique = false ) {
		if ( ! taxonomy_exists( $taxonomy ) ) {
			wp_die( __( 'Invalid taxonomy' ) );
		}
		if ( strpos( $meta_key, '_' ) === 0 ) {
			$meta_key = substr( $meta_key, 1 );
			$taxonomy = '_' . $taxonomy;
		}
		$meta_key = $taxonomy . '__' . $meta_key;

		return add_term_meta( $term_id, $meta_key, $meta_value, $unique );
	}
endif;

if ( ! function_exists( 'delete_term_taxonomy_meta' ) ):
	/**
	 * Remove meta data matching criteria from a term based on taxonomy name.
	 *
	 * You can match based on the key and taxonomy name, or key and value. Removing based on key and
	 * value, will keep from removing duplicate metadata with the same key. It also
	 * allows removing all metadata matching key, if needed.
	 *
	 * @uses delete_metadata()
	 * @uses taxonomy_exists()
	 *
	 * @param int $term_id Term ID.
	 * @param string $taxonomy Name of taxonomy object
	 * @param string $meta_key Metadata name.
	 * @param mixed $meta_value Optional. Metadata value.
	 *
	 * @return bool True on success, false on failure.
	 */
	function delete_term_taxonomy_meta( $term_id, $taxonomy, $meta_key, $meta_value = '' ) {
		if ( ! taxonomy_exists( $taxonomy ) ) {
			wp_die( __( 'Invalid taxonomy' ) );
		}
		if ( strpos( $meta_key, '_' ) === 0 ) {
			$meta_key = substr( $meta_key, 1 );
			$taxonomy = '_' . $taxonomy;
		}
		$meta_key = $taxonomy . '__' . $meta_key;

		return delete_term_meta( $term_id, $meta_key, $meta_value );
	}
endif;

if ( ! function_exists( 'get_term_taxonomy_meta' ) ):
	/**
	 * Retrieve term meta field for a term based on taxonomy name.
	 *
	 * @uses get_metadata()
	 * @uses taxonomy_exists()
	 *
	 * @param int $term_id Term ID.
	 * @param string $taxonomy Name of taxonomy object
	 * @param string $meta_key Optional. The meta key to retrieve. By default, returns data for all keys.
	 * @param bool $single Whether to return a single value.
	 *
	 * @return mixed Will be an array if $single is false. Will be value of meta data field if $single
	 *  is true.
	 */
	function get_term_taxonomy_meta( $term_id, $taxonomy, $meta_key = '', $single = false ) {
		if ( ! taxonomy_exists( $taxonomy ) ) {
			wp_die( __( 'Invalid taxonomy' ) );
		}
		if ( strpos( $meta_key, '_' ) === 0 ) {
			$meta_key = substr( $meta_key, 1 );
			$taxonomy = '_' . $taxonomy;
		}
		$meta_key = $taxonomy . '__' . $meta_key;

		return get_term_meta( $term_id, $meta_key, $single );
	}
endif;

if ( ! function_exists( 'update_term_taxonomy_meta' ) ):
	/**
	 * Update term meta field based on term ID and taxonomy name.
	 *
	 * Use the $prev_value parameter to differentiate between meta fields with the
	 * same key and term ID.
	 *
	 * If the meta field for the user does not exist, it will be added.
	 *
	 * @uses update_term_meta()
	 * @uses taxonomy_exists()
	 *
	 * @param int $term_id Term ID.
	 * @param string $taxonomy Name of taxonomy object
	 * @param string $meta_key Metadata key.
	 * @param mixed $meta_value Metadata value.
	 * @param mixed $prev_value Optional. Previous value to check before removing.
	 *
	 * @return bool True on success, false on failure.
	 */
	function update_term_taxonomy_meta( $term_id, $taxonomy, $meta_key, $meta_value, $prev_value = '' ) {
		if ( ! taxonomy_exists( $taxonomy ) ) {
			wp_die( __( 'Invalid taxonomy' ) );
		}
		if ( strpos( $meta_key, '_' ) === 0 ) {
			$meta_key = substr( $meta_key, 1 );
			$taxonomy = '_' . $taxonomy;
		}
		$meta_key = $taxonomy . '__' . $meta_key;

		return update_term_meta( $term_id, $meta_key, $meta_value, $prev_value );
	}
endif;