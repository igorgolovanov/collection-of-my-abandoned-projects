<?php
/*
Plugin Name: WP Hash Uploads
Plugin URI: https://github.com/golovanov/wp-hash-uploads
Description: Change/hash uploads directory and change/hash file name.
Version: 0.1
Author: Igor Golovanov
Author URI: https://github.com/golovanov/
*/

if (!function_exists('base64url_encode')):
    /**
     * Encode data to Base64 for url.
     *
     * @param string $data
     * @return string
     */
    function base64url_encode($data) {
        return rtrim(strtr(base64_encode($data), '+/', '-_'), '=');
    }
endif;

if (!function_exists('base64url_decode')):
    /**
     * Decode data from Base64 for url.
     *
     * @param string $data
     * @return string
     */
    function base64url_decode($data) {
        return base64_decode(str_pad(strtr($data, '-_', '+/'), strlen($data) % 4, '=', STR_PAD_RIGHT));
    }
endif;

/**
 * Hash year/month in upload dir.
 *
 * @param array $uploads
 *
 * @return array
 */
function wp_hash_uploads_filter_upload_dir( $uploads ) {
    if ( empty( $uploads['subdir'] ) ) {
        return $uploads;
    }
    list( $subdir_year, $subdir_month ) = mb_split( '/', trim( $uploads['subdir'], '/' ) );

    $subdir_year  = base64url_encode( $subdir_year );
    $subdir_month = base64url_encode( $subdir_month );
    $subdir       = "/$subdir_year/$subdir_month";

    $uploads['path']   = str_ireplace( $uploads['subdir'], $subdir, $uploads['path'] );
    $uploads['url']    = str_ireplace( $uploads['subdir'], $subdir, $uploads['url'] );
    $uploads['subdir'] = $subdir;

    return $uploads;
}

add_filter( 'upload_dir', 'wp_hash_uploads_filter_upload_dir' );

/**
 * Filter a sanitized filename string.
 *
 * @param string $filename Sanitized filename.
 *
 * @return string Sanitized filename.
 */
function wp_hash_uploads_sanitize_file_name( $filename ) {
    // separate the filename into a name and extension
    $info = pathinfo($filename);
    $ext = !empty($info['extension']) ? '.' . $info['extension'] : '';
    $name = basename($filename, $ext);
    $name = base64url_encode($name);

    return $name . $ext;
}

add_filter( 'sanitize_file_name', 'wp_hash_uploads_sanitize_file_name' );