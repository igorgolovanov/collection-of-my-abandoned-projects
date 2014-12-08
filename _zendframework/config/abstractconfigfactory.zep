/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Config;

use Traversable;
use Zend\ServiceManager\AbstractFactoryInterface;
use Zend\ServiceManager\ServiceLocatorInterface;

/**
* Class AbstractConfigFactory
*/
class AbstractConfigFactory implements AbstractFactoryInterface
{
    /**
     * @var array
     */
    protected configs = [];

    /**
     * @var string[]
     */
    protected defaultPatterns = [
        "#config[\._-](.*)$#i",
        "#^(.*)[\\\\\._-]config$#i"
    ];

    /**
     * @var string[]
     */
    protected patterns;

    /**
     * Determine if we can create a service with name
     *
     * @param ServiceLocatorInterface $serviceLocator
     * @param string $name
     * @param string $requestedName
     * @return bool
     */
    public function canCreateServiceWithName(<ServiceLocatorInterface> serviceLocator, string name, string requestedName) -> boolean
    {
        var key, config;

        if isset this->configs[requestedName] {
            return true;
        }
        if !serviceLocator->has("Config") {
            return false;
        }

        let key = this->match(requestedName);
        if key === null {
            return false;
        }

        let config = serviceLocator->get("Config");

        return isset config[key];
    }

    /**
     * Create service with name
     *
     * @param ServiceLocatorInterface $serviceLocator
     * @param string $name
     * @param string $requestedName
     * @return string|mixed|array
     */
    public function createServiceWithName(<ServiceLocatorInterface> serviceLocator, string name, string requestedName)
    {
        var config, key;

        if fetch config, this->configs[requestedName] {
            return config;
        }

        let key = this->match(requestedName);
        if fetch config, this->configs[key] {
            let this->configs[requestedName] = config;
            return config;
        }

        let config = serviceLocator->get("Config");

        let this->configs[requestedName] = config;
        let this->configs[key] = config;

        return config;
    }

    /**
     * @param string $pattern
     * @return self
     * @throws Exception\InvalidArgumentException
     */
    public function addPattern(var pattern) -> <AbstractConfigFactory>
    {
        var patterns;

        if unlikely typeof pattern != "string" {
            throw new Exception\InvalidArgumentException("pattern must be string");
        }

        let patterns = this->getPatterns();
        array_unshift(patterns, pattern);
        this->setPatterns(patterns);

        return this;

    }

    /**
     * @param array|Traversable $patterns
     * @return self
     * @throws Exception\InvalidArgumentException
     */
    public function addPatterns(var patterns) -> <AbstractConfigFactory>
    {
        var pattern;

        if patterns instanceof Traversable {
            let patterns = iterator_to_array(patterns);
        }

        if unlikely typeof patterns != "array" {
             throw new Exception\InvalidArgumentException("patterns must be array or Traversable");
        }
        for pattern in patterns {
            this->addPattern(pattern);
        }

        return this;
    }

    /**
     * @param array|Traversable $patterns
     * @return self
     * @throws \InvalidArgumentException
     */
    public function setPatterns(var patterns) -> <AbstractConfigFactory>
    {

        if patterns instanceof Traversable {
            let patterns = iterator_to_array(patterns);
        }

        if unlikely typeof patterns != "array" {
             throw new Exception\InvalidArgumentException("patterns must be array or Traversable");
        }
        let this->patterns = patterns;

        return this;
    }

    /**
     * @return array
     */
    public function getPatterns() -> array
    {
        if this->patterns === null {
            this->setPatterns(this->defaultPatterns);
        }
        return this->patterns;
    }

    /**
     * @param string $requestedName
     * @return null|string
     */
    protected function match(string requestedName) -> string|null
    {
        var patterns, pattern, matches = [];

        let patterns = this->getPatterns();
        for pattern in patterns {
            if preg_match(pattern, requestedName, matches) {
                return matches[1];
            }
        }
        return null;
    }

}
