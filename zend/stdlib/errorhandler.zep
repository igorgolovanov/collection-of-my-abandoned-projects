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
    protected static stack; // []

    /**
     * Check if this error handler is active
     *
     * @return bool
     */
    public static function started() -> boolean
    {
        // todo: change self -> static
        return self::getNestedLevel();
    }

    /**
     * Get the current nested level
     *
     * @return int
     */
    public static function getNestedLevel() -> int
    {
        // todo: change self -> static
        return count(self::stack);
    }

    /**
     * Starting the error handler
     *
     * @param int $errorLevel
     */
    public static function start(int errorLevel = E_WARNING)
    {
        array callback;
        string className;

        // todo: change self -> static
        if !self::stack {
            let className = get_called_class();
            let callback = [className, "addError"];

            set_error_handler(callback, errorLevel);
        }
        let self::stack[] = null;
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
        // todo: change self -> static

        if self::stack {
            let errorException = array_pop(self::stack);

            if !self::stack {
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
        // todo: change self -> static
        if self::stack {
            restore_error_handler();
        }
        let self::stack = [];
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

        // todo: change self -> static
        let count = count(self::stack);
        let stack = & self::stack[count - 1];
        let stack = new ErrorException(errstr, 0, errno, errfile, errline, stack);
    }

}
