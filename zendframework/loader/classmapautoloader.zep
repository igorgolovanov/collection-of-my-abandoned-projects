/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Loader;

use Traversable;

/**
 * Class-map autoloader
 *
 * Utilizes class-map files to lookup classfile locations.
 */
class ClassMapAutoloader implements SplAutoloader
{
    /**
     * Registry of map files that have already been loaded
     * @var array
     */
    protected mapsLoaded; // todo: []

    /**
     * Class name/filename map
     * @var array
     */
    protected map; // todo: []

    /**
     * Constructor
     *
     * Create a new instance, and optionally configure the autoloader.
     *
     * @param  null|array|Traversable $options
     */
    public function __construct(var options = null)
    {
        if typeof this->mapsLoaded != "array" {
            let this->mapsLoaded = [];
        }
        if typeof this->map != "array" {
            let this->map = [];
        }

        if options !== null {
            this->setOptions(options);
        }
    }

    /**
     * Configure the autoloader
     *
     * Proxies to {@link registerAutoloadMaps()}.
     *
     * @param  array|Traversable $options
     * @return ClassMapAutoloader
     */
    public function setOptions(var options) -> <ClassMapAutoloader>
    {
        this->registerAutoloadMaps(options);

        return this;
    }

    /**
     * Register an autoload map
     *
     * An autoload map may be either an associative array, or a file returning
     * an associative array.
     *
     * An autoload map should be an associative array containing
     * classname/file pairs.
     *
     * @param  string|array $map
     * @throws Exception\InvalidArgumentException
     * @return ClassMapAutoloader
     */
    public function registerAutoloadMap(var map) -> <ClassMapAutoloader>
    {
        var exceptionMsg, location = null, merged, baseMap, mapsLoaded;

        if typeof map == "string" {
            let location = map;
            let map = this->loadMapFromFile(location);
            if map === this {
                return this;
            }
        }

        if unlikely typeof map != "array" {
            let exceptionMsg = "Map file provided does not return a map. Map file: \"";
            if empty location {
                let location = "unexpected type: " . typeof map;
            }
            let exceptionMsg = exceptionMsg . location . "\"";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }
        let baseMap = this->map;
        if typeof baseMap != "array" {
            let baseMap = [];
        }
        let merged = array_merge(baseMap, map);
        let this->map = merged;

        if !empty location {
            let mapsLoaded = this->mapsLoaded;
            if typeof mapsLoaded != "array" {
                let mapsLoaded = [];
            }
            let mapsLoaded[] = location;
            let this->mapsLoaded = mapsLoaded;
        }
        return this;
    }

    /**
     * Register many autoload maps at once
     *
     * @param  array $locations
     * @throws Exception\InvalidArgumentException
     * @return ClassMapAutoloader
     */
    public function registerAutoloadMaps(var locations) -> <ClassMapAutoloader>
    {
        var location;

        if typeof locations != "array" {
            if unlikely !is_subclass_of(locations, "Traversable") { // todo: locations instanceof Traversable
                throw new Exception\InvalidArgumentException("Map list must be an array or implement Traversable");
            }
            let locations = iterator_to_array(locations);
        }

        for location in locations {
            this->registerAutoloadMap(location);
        }
        return this;
    }

    /**
     * Retrieve current autoload map
     *
     * @return array
     */
    public function getAutoloadMap() -> array
    {
        return this->map;
    }

    /**
     * {@inheritDoc}
     */
    public function autoload(string $class) -> string|boolean
    {
        var path, map;

        let map = this->map;
        if typeof map != "array" {
            let this->map = [];
            return false;
        }

        if fetch path, map[$class] {
            require path;
            return $class;
        }
        return false;
    }

    /**
     * Register the autoloader with spl_autoload registry
     *
     * @return void
     */
    public function register() -> void
    {
        spl_autoload_register([this, "autoload"], true, true);
    }

    /**
     * Load a map from a file
     *
     * If the map has been previously loaded, returns the current instance;
     * otherwise, returns whatever was returned by calling include() on the
     * location.
     *
     * @param  string $location
     * @return ClassMapAutoloader|mixed
     * @throws Exception\InvalidArgumentException for nonexistent locations
     */
    protected function loadMapFromFile(var location)
    {
        string exceptionMsg;
        var path, map, mapsLoaded;
        
        if unlikely !file_exists(location) {
            if typeof location != "string" {
                let location = "unexpected type: " . typeof location;
            }
            let exceptionMsg = "Map file provided does not exist. Map file: \"" . location . "\"";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let path = static::realPharPath(location);
        if !path {
            let path = realpath(location);
        }
        let mapsLoaded = this->mapsLoaded;
        if typeof mapsLoaded != "array" {
            let mapsLoaded = [];
            let this->mapsLoaded = mapsLoaded;
        }
        if in_array(path, mapsLoaded) {
            // Already loaded this map
            return this;
        }

        let map = require path;

        return map;
    }

    /**
     * Resolve the real_path() to a file within a phar.
     *
     * @see https://bugs.php.net/bug.php?id=52769
     * @param  string $path
     * @return string
     */
    public static function realPharPath(string path) -> string
    {
        var match = [], value, key, parts, partsFiltered = [], realPath;
        var prefixLength;

        if !preg_match("|^phar:(/{2,3})|", path, match) {
            return "";
        }
        let prefixLength = 5 + strlen(match[1]);
        let parts = substr(path, prefixLength);
        let parts = str_replace(["/", "\\"], "/", parts);
        let parts = explode("/", parts);
        for value in parts {
            if value !== "" && value !== "." {
                let partsFiltered[] = value;
            }
        }
        let parts = array_values(partsFiltered);
        for key, value in parts {
            if value === ".." {
                unset parts[key];
                unset parts[key - 1];
                let parts = array_values(parts);
            }
        }

        let realPath = str_pad("phar:", prefixLength, "/");
        let realPath = realPath . implode("/", parts);

        if file_exists(realPath) {
            return realPath;
        }
        return "";
    }
}
