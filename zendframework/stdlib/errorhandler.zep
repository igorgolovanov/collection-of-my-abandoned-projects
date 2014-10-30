/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib;

use ErrorException;

/**
 * ErrorHandler that can be used to catch internal PHP errors
 * and convert to an ErrorException instance.
 */
abstract class ErrorHandler
{
    /**
     * Active stack
     *
     * @var array
     */
    protected static stack; // todo: []

    /**
     * Check if this error handler is active
     *
     * @return bool
     */
    public static function started() -> boolean
    {
        return static::getNestedLevel();
    }

    /**
     * Get the current nested level
     *
     * @return int
     */
    public static function getNestedLevel() -> int
    {
        var className, stackData = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&stackData, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack") TSRMLS_CC);
        }%

        if typeof stackData === "array" {
            return count(stackData);
        }
        return 0;
    }

    /**
     * Starting the error handler
     *
     * @param int $errorLevel
     */
    public static function start(int errorLevel = 2) // errorLevel = E_WARNING
    {
        var className, stackData = null;

        let className = get_called_class();

        %{
            zephir_read_static_property(&stackData, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack") TSRMLS_CC);
        }%

        if stackData {
            set_error_handler([className, "addError"], errorLevel);
        }

        if typeof stackData != "array" {
            let stackData = [];
        }
        let stackData[] = null;

        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack"), &stackData TSRMLS_CC);
        }%
    }

    /**
     * Stopping the error handler
     *
     * @param  bool $throw Throw the ErrorException if any
     * @return null|ErrorException
     * @throws ErrorException If an error has been catched and $throw is true
     */
    public static function stop(boolean $throw = false) -> <\ErrorException>|null
    {
        var errorException = null, className, stackData = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&stackData, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack") TSRMLS_CC);
        }%

        if typeof stackData == "array" && !empty stackData {
            let errorException = array_pop(stackData);

            %{
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack"), &stackData TSRMLS_CC);
            }%

            if !empty stackData {
                restore_error_handler();
            }
            if errorException && $throw {
                throw errorException;
            }
        }
        return errorException;
    }

    /**
     * Stop all active handler
     *
     * @return void
     */
    public static function clean() -> void
    {
        var className, stackData = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&stackData, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack") TSRMLS_CC);
        }%

        if !empty stackData {
            restore_error_handler();
        }
        let stackData = [];
        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack"), &stackData TSRMLS_CC);
        }%
    }

    /**
     * Add an error to the stack
     *
     * @param int    $errno
     * @param string $errstr
     * @param string $errfile
     * @param int    $errline
     * @return void
     */
    public static function addError(int errno, string errstr = "", string errfile = "", int errline = 0) -> void
    {
        var stackData = null, className, stackIndex, stackItem = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&stackData, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack") TSRMLS_CC);
        }%

        if typeof stackData !== "array" {
            let stackData = [];
        }
        let stackIndex = count(stackData);
        let stackIndex--;
        if stackIndex < 0 {
            let stackIndex = 0;
        }
        if isset stackData[stackIndex] {
            let stackItem = stackData[stackIndex];
        }
        let stackData[stackIndex] = new ErrorException(errstr, 0, errno, errfile, errline, stackItem);
        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("stack"), &stackData TSRMLS_CC);
        }%
    }

}
