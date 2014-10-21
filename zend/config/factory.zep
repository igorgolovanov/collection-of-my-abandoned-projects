/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Config;

use Zend\Stdlib\ArrayUtils;

class Factory
{
    /**
     * Plugin manager for loading readers
     *
     * @var null|ReaderPluginManager
     */
    public static readers;

    /**
     * Plugin manager for loading writers
     *
     * @var null|WriterPluginManager
     */
    public static writers;

    /**
     * Registered config file extensions.
     * key is extension, value is reader instance or plugin name
     *
     * @var array
     */
    protected static extensions = [
        "ini": "ini", 
        "json": "json", 
        "xml": "xml", 
        "yaml": "yaml"
    ];

    /**
     * Register config file extensions for writing
     * key is extension, value is writer instance or plugin name
     *
     * @var array
     */
    protected static writerExtensions = [
        "php": "php", 
        "ini": "ini", 
        "json": "json", 
        "xml": "xml", 
        "yaml": "yaml"
    ];

    /**
     * Read a config from a file.
     *
     * @param  string  $filename
     * @param  bool $returnConfigObject
     * @param  bool $useIncludePath
     * @return array|Config
     * @throws Exception\InvalidArgumentException
     * @throws Exception\RuntimeException
     */
    public static function fromFile(string filename, boolean returnConfigObject = false, boolean useIncludePath = false) -> array|<Config>
    {

    }

    /**
     * Read configuration from multiple files and merge them.
     *
     * @param  array   $files
     * @param  bool $returnConfigObject
     * @param  bool $useIncludePath
     * @return array|Config
     */
    public static function fromFiles(array! files, boolean returnConfigObject = false, boolean useIncludePath = false) -> array|<Config>
    {

    }

    /**
     * Writes a config to a file
     *
     * @param string $filename
     * @param array|Config $config
     * @return bool TRUE on success | FALSE on failure
     * @throws Exception\RuntimeException
     * @throws Exception\InvalidArgumentException
     */
    public static function toFile(string filename, var config) -> boolean
    {

    }

    /**
     * Set reader plugin manager
     *
     * @param ReaderPluginManager $readers
     * @return void
     */
    public static function setReaderPluginManager(<ReaderPluginManager> readers) -> void
    {

    }

    /**
     * Get the reader plugin manager
     *
     * @return ReaderPluginManager
     */
    public static function getReaderPluginManager() -> <ReaderPluginManager>
    {

    }

    /**
     * Set writer plugin manager
     *
     * @param WriterPluginManager $writers
     * @return void
     */
    public static function setWriterPluginManager(<WriterPluginManager> writers) -> void
    {

    }

    /**
     * Get the writer plugin manager
     *
     * @return WriterPluginManager
     */
    public static function getWriterPluginManager() -> <WriterPluginManager>
    {

    }

    /**
     * Set config reader for file extension
     *
     * @param  string $extension
     * @param  string|Reader\ReaderInterface $reader
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public static function registerReader(string extension, var reader) -> void
    {

    }

    /**
     * Set config writer for file extension
     *
     * @param string $extension
     * @param string|Writer\AbstractWriter $writer
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public static function registerWriter(string extension, var writer) -> void
    {

    }

}
