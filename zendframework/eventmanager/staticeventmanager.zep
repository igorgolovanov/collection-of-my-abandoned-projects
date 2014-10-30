/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

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
    final public function __construct()
    {
        var className, instance = null;

        let className = get_class(this);
        %{
            zephir_read_static_property(&instance, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance") TSRMLS_CC);
        }%
        if instance !== null {
            throw new \Exception("Can't create new instance of StaticEventManager");
        }
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
        var className, instance = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&instance, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance") TSRMLS_CC);
        }%
        if instance === null {
            let instance = new {className}(); //todo: <StaticEventManager>
            %{
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance"), &instance TSRMLS_CC);
            }%
        }
        return instance;
    }

    /**
     * Set the singleton to a specific SharedEventManagerInterface instance
     *
     * @param SharedEventManagerInterface $instance
     * @return void
     */
    public static function setInstance(<SharedEventManagerInterface> instance) -> void
    {
        var className;

        let className = get_called_class();
        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance"), &instance TSRMLS_CC);
        }%
    }

    /**
     * Is a singleton instance defined?
     *
     * @return bool
     */
    public static function hasInstance() -> boolean
    {
        var className, instance = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&instance, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance") TSRMLS_CC);
        }%
        return instance instanceof SharedEventManagerInterface;
    }

    /**
     * Reset the singleton instance
     *
     * @return void
     */
    public static function resetInstance() -> void
    {
        var className, instance;

        let className = get_called_class();
        let instance = null;
        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("instance"), &instance TSRMLS_CC);
        }%
    }

}
