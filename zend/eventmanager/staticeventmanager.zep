/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\EventManager;

/**
 * Static version of EventManager
 */
class StaticEventManager extends SharedEventManager implements SharedEventManagerInterface, SharedEventAggregateAwareInterface
{
    /**
     * @var StaticEventManager
     */
    protected static instance;

    /**
     * Singleton
     */
    protected function __construct()
    {

    }

    /**
     * Singleton
     *
     * @return void
     */
    private function __clone() -> void
    {

    }

    /**
     * Retrieve instance
     *
     * @return StaticEventManager
     */
    public static function getInstance() -> <StaticEventManager>
    {
        string className;
        var instance;

        if static::instance === null {
            let className = get_called_class();
            let instance = <StaticEventManager> new {className}();

            static::setInstance(instance);
        }
        return static::instance;
    }

    /**
     * Set the singleton to a specific SharedEventManagerInterface instance
     *
     * @param SharedEventManagerInterface $instance
     * @return void
     */
    public static function setInstance(<SharedEventManagerInterface> instance) -> void
    {
        let static::instance = instance;
    }

    /**
     * Is a singleton instance defined?
     *
     * @return bool
     */
    public static function hasInstance() -> boolean
    {
        return static::instance instanceof SharedEventManagerInterface;
    }

    /**
     * Reset the singleton instance
     *
     * @return void
     */
    public static function resetInstance() -> void
    {
        let static::instance = null;
    }

}
