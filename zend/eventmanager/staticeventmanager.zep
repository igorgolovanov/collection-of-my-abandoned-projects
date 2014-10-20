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

        // todo: change self -> static
        if self::instance === null {
             self::setInstance(new self());
        }
        return self::instance;
    }

    /**
     * Set the singleton to a specific SharedEventManagerInterface instance
     *
     * @param SharedEventManagerInterface $instance
     * @return void
     */
    public static function setInstance(<SharedEventManagerInterface> instance) -> void
    {

        // todo: change self -> static
        let self::instance = instance;
    }

    /**
     * Is a singleton instance defined?
     *
     * @return bool
     */
    public static function hasInstance() -> boolean
    {

        // todo: change self -> static
        return self::instance instanceof SharedEventManagerInterface;
    }

    /**
     * Reset the singleton instance
     *
     * @return void
     */
    public static function resetInstance() -> void
    {

        // todo: change self -> static
        let self::instance = null;
    }

}
