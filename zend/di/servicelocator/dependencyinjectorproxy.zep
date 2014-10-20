/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di\ServiceLocator;

/**
 * Proxy used to analyze how instances are created by a given Di. Overrides Zend\Di\Di to produce artifacts that
 * represent the process used to instantiate a particular instance
 */
class DependencyInjectorProxy extends \Zend\Di\Di implements \Zend\Di\LocatorInterface, \Zend\Di\DependencyInjectionInterface
{
    const RESOLVE_EAGER = 1;

    const RESOLVE_STRICT = 2;

    const METHOD_IS_OPTIONAL = 0;

    const METHOD_IS_AWARE = 1;

    const METHOD_IS_CONSTRUCTOR = 3;

    const METHOD_IS_INSTANTIATOR = 3;

    const METHOD_IS_REQUIRED = 3;

    const METHOD_IS_EAGER = 1;

    /**
     * @var Di
     */
    protected di;

    /**
     * @param Di $di
     */
    public function __construct(<Di> di)
    {

    }

    /**
     * {@inheritDoc}
     * @return GeneratorInstance
     */
    public function get(name, array! params = []) -> <GeneratorInstance>
    {

    }

    /**
     * {@inheritDoc}
     * @return GeneratorInstance
     */
    public function newInstance(name, array! params = [], boolean isShared = true) -> <GeneratorInstance>
    {

    }

    /**
     * {@inheritDoc}
     * @return GeneratorInstance
     */
    public function createInstanceViaConstructor($class, params, alias = null) -> <GeneratorInstance>
    {

    }

    /**
     * {@inheritDoc}
     * @throws \Zend\Di\Exception\InvalidCallbackException
     * @return GeneratorInstance
     */
    public function createInstanceViaCallback(callback, params, alias) -> <GeneratorInstance>
    {

    }

    /**
     * {@inheritDoc}
     */
    public function handleInjectionMethodForObject($class, method, params, alias, isRequired)
    {

    }

    /**
     * {@inheritDoc}
     */
    protected function resolveAndCallInjectionMethodForInstance(instance, method, params, alias, methodIsRequired, methodClass = null)
    {

    }

    /**
     * {@inheritDoc}
     */
    protected function getClass(instance)
    {

    }

}
