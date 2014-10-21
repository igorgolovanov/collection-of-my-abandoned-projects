/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ModuleManager\Listener;

/**
 * Listener options
 */
class ListenerOptions extends \Zend\Stdlib\AbstractOptions implements \Zend\Stdlib\ParameterObjectInterface
{
    /**
     * @var array
     */
    protected modulePaths = [];

    /**
     * @var array
     */
    protected configGlobPaths = [];

    /**
     * @var array
     */
    protected configStaticPaths = [];

    /**
     * @var array
     */
    protected extraConfig = [];

    /**
     * @var bool
     */
    protected configCacheEnabled = false;

    /**
     * @var string
     */
    protected configCacheKey;

    /**
     * @var string
     */
    protected cacheDir;

    /**
     * @var bool
     */
    protected checkDependencies = true;

    /**
     * @var string
     */
    protected moduleMapCacheEnabled = false;

    /**
     * @var string
     */
    protected moduleMapCacheKey;

    /**
     * Get an array of paths where modules reside
     *
     * @return array
     */
    public function getModulePaths() -> array
    {

    }

    /**
     * Set an array of paths where modules reside
     *
     * @param  array|Traversable $modulePaths
     * @throws Exception\InvalidArgumentException
     * @return ListenerOptions Provides fluent interface
     */
    public function setModulePaths(var modulePaths) -> <ListenerOptions>
    {

    }

    /**
     * Get the glob patterns to load additional config files
     *
     * @return array
     */
    public function getConfigGlobPaths() -> array
    {

    }

    /**
     * Get the static paths to load additional config files
     *
     * @return array
     */
    public function getConfigStaticPaths() -> array
    {

    }

    /**
     * Set the glob patterns to use for loading additional config files
     *
     * @param array|Traversable $configGlobPaths
     * @throws Exception\InvalidArgumentException
     * @return ListenerOptions Provides fluent interface
     */
    public function setConfigGlobPaths(var configGlobPaths) -> <ListenerOptions>
    {

    }

    /**
     * Set the static paths to use for loading additional config files
     *
     * @param array|Traversable $configStaticPaths
     * @throws Exception\InvalidArgumentException
     * @return ListenerOptions Provides fluent interface
     */
    public function setConfigStaticPaths(var configStaticPaths) -> <ListenerOptions>
    {

    }

    /**
     * Get any extra config to merge in.
     *
     * @return array|Traversable
     */
    public function getExtraConfig() -> array|<\Traversable>
    {

    }

    /**
     * Add some extra config array to the main config. This is mainly useful
     * for unit testing purposes.
     *
     * @param array|Traversable $extraConfig
     * @throws Exception\InvalidArgumentException
     * @return ListenerOptions Provides fluent interface
     */
    public function setExtraConfig(var extraConfig) -> <ListenerOptions>
    {

    }

    /**
     * Check if the config cache is enabled
     *
     * @return bool
     */
    public function getConfigCacheEnabled() -> boolean
    {

    }

    /**
     * Set if the config cache should be enabled or not
     *
     * @param  bool $enabled
     * @return ListenerOptions
     */
    public function setConfigCacheEnabled(boolean enabled) -> <ListenerOptions>
    {

    }

    /**
     * Get key used to create the cache file name
     *
     * @return string
     */
    public function getConfigCacheKey() -> string
    {

    }

    /**
     * Set key used to create the cache file name
     *
     * @param  string $configCacheKey the value to be set
     * @return ListenerOptions
     */
    public function setConfigCacheKey(string configCacheKey) -> <ListenerOptions>
    {

    }

    /**
     * Get the path to the config cache
     *
     * Should this be an option, or should the dir option include the
     * filename, or should it simply remain hard-coded? Thoughts?
     *
     * @return string
     */
    public function getConfigCacheFile() -> string
    {

    }

    /**
     * Get the path where cache file(s) are stored
     *
     * @return string
     */
    public function getCacheDir() -> string
    {

    }

    /**
     * Set the path where cache files can be stored
     *
     * @param  string $cacheDir the value to be set
     * @return ListenerOptions
     */
    public function setCacheDir(string cacheDir) -> <ListenerOptions>
    {

    }

    /**
     * Check if the module class map cache is enabled
     *
     * @return bool
     */
    public function getModuleMapCacheEnabled() -> boolean
    {

    }

    /**
     * Set if the module class map cache should be enabled or not
     *
     * @param  bool $enabled
     * @return ListenerOptions
     */
    public function setModuleMapCacheEnabled(boolean enabled) -> <ListenerOptions>
    {

    }

    /**
     * Get key used to create the cache file name
     *
     * @return string
     */
    public function getModuleMapCacheKey() -> string
    {

    }

    /**
     * Set key used to create the cache file name
     *
     * @param  string $moduleMapCacheKey the value to be set
     * @return ListenerOptions
     */
    public function setModuleMapCacheKey(string moduleMapCacheKey) -> <ListenerOptions>
    {

    }

    /**
     * Get the path to the module class map cache
     *
     * @return string
     */
    public function getModuleMapCacheFile() -> string
    {

    }

    /**
     * Set whether to check dependencies during module loading or not
     *
     * @return string
     */
    public function getCheckDependencies() -> string
    {

    }

    /**
     * Set whether to check dependencies during module loading or not
     *
     * @param  bool $checkDependencies the value to be set
     *
     * @return ListenerOptions
     */
    public function setCheckDependencies(boolean checkDependencies) -> <ListenerOptions>
    {

    }

    /**
     * Normalize a path for insertion in the stack
     *
     * @param  string $path
     * @return string
     */
    public static function normalizePath(string path) -> string
    {

    }

}
