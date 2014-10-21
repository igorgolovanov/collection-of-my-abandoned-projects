/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Config;

use Traversable;
use Zend\ServiceManager;
/**
* Class AbstractConfigFactory
*/
class AbstractConfigFactory implements ServiceManager\AbstractFactoryInterface
{
    /**
     * @var array
     */
    protected configs = [];

    /**
     * @var string[]
     */
    protected defaultPatterns = ["#config[\._-](.*)$#i", "#^(.*)[\\\._-]config$#i"];

    /**
     * @var string[]
     */
    protected patterns;

    /**
     * Determine if we can create a service with name
     *
     * @param ServiceManager\ServiceLocatorInterface $serviceLocator
     * @param string $name
     * @param string $requestedName
     * @return bool
     */
    public function canCreateServiceWithName(serviceLocator, string name, string requestedName) -> boolean
    {

    }

    /**
     * Create service with name
     *
     * @param ServiceManager\ServiceLocatorInterface $serviceLocator
     * @param string $name
     * @param string $requestedName
     * @return string|mixed|array
     */
    public function createServiceWithName(serviceLocator, string name, string requestedName)
    {

    }

    /**
     * @param string $pattern
     * @return self
     * @throws Exception\InvalidArgumentException
     */
    public function addPattern(string pattern) -> <AbstractConfigFactory>
    {

    }

    /**
     * @param array|Traversable $patterns
     * @return self
     * @throws Exception\InvalidArgumentException
     */
    public function addPatterns(var patterns) -> <AbstractConfigFactory>
    {

    }

    /**
     * @param array|Traversable $patterns
     * @return self
     * @throws \InvalidArgumentException
     */
    public function setPatterns(var patterns) -> <AbstractConfigFactory>
    {

    }

    /**
     * @return array
     */
    public function getPatterns() -> array
    {

    }

    /**
     * @param string $requestedName
     * @return null|string
     */
    protected function match(string requestedName) -> string
    {

    }

}
