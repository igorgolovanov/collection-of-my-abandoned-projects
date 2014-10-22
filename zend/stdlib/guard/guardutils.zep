/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Guard;

use Traversable;

/**
 * Static guard helper class
 *
 * Bridges the gap for allowing refactoring until traits can be used by default.
 *
 * @deprecated
 */
abstract class GuardUtils
{
    const DEFAULT_EXCEPTION_CLASS = "Zend\\Stdlib\\Exception\\InvalidArgumentException";

    /**
     * Verifies that the data is an array or Traversable
     *
     * @param  mixed  $data           the data to verify
     * @param  string $dataName       the data name
     * @param  string $exceptionClass FQCN for the exception
     * @throws \Exception
     */
    public static function guardForArrayOrTraversable(var data, string dataName = "Argument", string! exceptionClass = self::DEFAULT_EXCEPTION_CLASS)
    {
        string exceptionMsg, type;

        let type = typeof data;

        if type !== "array" && !(data instanceof Traversable) {
            if type == "object" {
                let type = get_class(data);
            }
            let exceptionMsg = dataName . " must be an array or Traversable, [" . type . "] given";
            throw new {exceptionClass}(exceptionMsg);
        }
    }

    /**
     * Verify that the data is not empty
     *
     * @param  mixed  $data           the data to verify
     * @param  string $dataName       the data name
     * @param  string $exceptionClass FQCN for the exception
     * @throws \Exception
     */
    public static function guardAgainstEmpty(var data, string dataName = "Argument", string! exceptionClass = self::DEFAULT_EXCEPTION_CLASS)
    {
        string exceptionMsg;

        if empty data {
            let exceptionMsg = dataName . " cannot be empty";
            throw new {exceptionClass}(exceptionMsg);
        }
    }

    /**
     * Verify that the data is not null
     *
     * @param  mixed  $data           the data to verify
     * @param  string $dataName       the data name
     * @param  string $exceptionClass FQCN for the exception
     * @throws \Exception
     */
    public static function guardAgainstNull(var data, string dataName = "Argument", string! exceptionClass = self::DEFAULT_EXCEPTION_CLASS)
    {
        string message;

        if data === null {
            let exceptionMsg = dataName . " cannot be null";
            throw new {exceptionClass}(exceptionMsg);
        }
    }

}
