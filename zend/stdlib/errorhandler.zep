/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
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
        return count(static::stack);
    }

    /**
     * Starting the error handler
     *
     * @param int $errorLevel
     */
    public static function start(int errorLevel = \E_WARNING)
    {
        array callback;
        string className;

        if !static::stack {
            let className = get_called_class();
            let callback = [className, "addError"];

            set_error_handler(callback, errorLevel);
        }
        let static::stack[] = null;
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
        var errorException;

        if static::stack {
            let errorException = array_pop(static::stack);

            if !static::stack {
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
        if static::stack {
            restore_error_handler();
        }
        let static::stack = [];
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
        int count;
        var stack;

        let count = count(static::stack);
        let stack = & static::stack[count - 1]; // todo: support &
        let stack = new ErrorException(errstr, 0, errno, errfile, errline, stack);
    }

}
