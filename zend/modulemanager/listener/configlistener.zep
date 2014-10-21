/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ModuleManager\Listener;

/**
 * Config listener
 */
class ConfigListener extends AbstractListener implements ConfigMergerInterface, \Zend\EventManager\ListenerAggregateInterface
{
    const STATIC_PATH = "static_path";

    const GLOB_PATH = "glob_path";

    /**
     * @var array
     */
    protected callbacks = [];

    /**
     * @var array
     */
    protected configs = [];

    /**
     * @var array
     */
    protected mergedConfig = [];

    /**
     * @var Config
     */
    protected mergedConfigObject;

    /**
     * @var bool
     */
    protected skipConfig = false;

    /**
     * @var array
     */
    protected paths = [];

    /**
     * __construct
     *
     * @param  ListenerOptions $options
     */
    public function __construct(<ListenerOptions> options = null)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function attach(events)
    {

    }

    /**
     * Pass self to the ModuleEvent object early so everyone has access.
     *
     * @param  ModuleEvent $e
     * @return ConfigListener
     */
    public function onloadModulesPre(e) -> <ConfigListener>
    {

    }

    /**
     * Merge the config for each module
     *
     * @param  ModuleEvent $e
     * @return ConfigListener
     */
    public function onLoadModule(e) -> <ConfigListener>
    {

    }

    /**
     * Merge all config files matched by the given glob()s
     *
     * This is only attached if config is not cached.
     *
     * @param  ModuleEvent $e
     * @return ConfigListener
     */
    public function onMergeConfig(e) -> <ConfigListener>
    {

    }

    /**
     * Optionally cache merged config
     *
     * This is only attached if config is not cached.
     *
     * @param  ModuleEvent $e
     * @return ConfigListener
     */
    public function onLoadModules(e) -> <ConfigListener>
    {

    }

    /**
     * {@inheritDoc}
     */
    public function detach(events)
    {

    }

    /**
     * getMergedConfig
     *
     * @param  bool $returnConfigAsObject
     * @return mixed
     */
    public function getMergedConfig(boolean returnConfigAsObject = true)
    {

    }

    /**
     * setMergedConfig
     *
     * @param  array $config
     * @return ConfigListener
     */
    public function setMergedConfig(array! config) -> <ConfigListener>
    {

    }

    /**
     * Add an array of glob paths of config files to merge after loading modules
     *
     * @param  array|Traversable $globPaths
     * @return ConfigListener
     */
    public function addConfigGlobPaths(var globPaths) -> <ConfigListener>
    {

    }

    /**
     * Add a glob path of config files to merge after loading modules
     *
     * @param  string $globPath
     * @return ConfigListener
     */
    public function addConfigGlobPath(string globPath) -> <ConfigListener>
    {

    }

    /**
     * Add an array of static paths of config files to merge after loading modules
     *
     * @param  array|Traversable $staticPaths
     * @return ConfigListener
     */
    public function addConfigStaticPaths(var staticPaths) -> <ConfigListener>
    {

    }

    /**
     * Add a static path of config files to merge after loading modules
     *
     * @param  string $staticPath
     * @return ConfigListener
     */
    public function addConfigStaticPath(string staticPath) -> <ConfigListener>
    {

    }

    /**
     * Add an array of paths of config files to merge after loading modules
     *
     * @param  Traversable|array $paths
     * @param string $type
     * @throws Exception\InvalidArgumentException
     * @return ConfigListener
     */
    protected function addConfigPaths(var paths, string type) -> <ConfigListener>
    {

    }

    /**
     * Add a path of config files to load and merge after loading modules
     *
     * @param  string $path
     * @param  string $type
     * @throws Exception\InvalidArgumentException
     * @return ConfigListener
     */
    protected function addConfigPath(string path, string type) -> <ConfigListener>
    {

    }

    /**
     * @param string $key
     * @param array|Traversable $config
     * @throws Exception\InvalidArgumentException
     * @return ConfigListener
     */
    protected function addConfig(string key, var config) -> <ConfigListener>
    {

    }

    /**
     * Given a path (glob or static), fetch the config and add it to the array
     * of configs to merge.
     *
     * @param string $path
     * @param string $type
     * @return ConfigListener
     */
    protected function addConfigByPath(string path, string type) -> <ConfigListener>
    {

    }

    /**
     * @return bool
     */
    protected function hasCachedConfig() -> boolean
    {

    }

    /**
     * @return mixed
     */
    protected function getCachedConfig()
    {

    }

}
