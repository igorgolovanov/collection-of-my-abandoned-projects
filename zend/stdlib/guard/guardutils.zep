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
    const DEFAULT_EXCEPTION_CLASS = "Zend\Stdlib\Exception\InvalidArgumentException";

    /**
     * Verifies that the data is an array or Traversable
     *
     * @param  mixed  $data           the data to verify
     * @param  string $dataName       the data name
     * @param  string $exceptionClass FQCN for the exception
     * @throws \Exception
     */
    public static function guardForArrayOrTraversable(data, string dataName = "Argument", string! exceptionClass = self::DEFAULT_EXCEPTION_CLASS)
    {
        string message, type;

        let type = typeof data;

        if typeof data != type && !data instanceof Traversable {
            if type == "object" {
                let type = get_class(data);
            }
            let message = "%s must be an array or Traversable, [%s] given";
            let message = sprintf(message, dataName, type);

            throw new {exceptionClass}(message);
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
    public static function guardAgainstEmpty(data, string dataName = "Argument", string! exceptionClass = self::DEFAULT_EXCEPTION_CLASS)
    {
        string message;

        if empty data {
            let message = "%s cannot be empty";
            let message = sprintf(message, dataName);

            throw new {exceptionClass}(message);
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
    public static function guardAgainstNull(data, string dataName = "Argument", string! exceptionClass = self::DEFAULT_EXCEPTION_CLASS)
    {
        string message;

        if data === null {
            let message = "%s cannot be null";
            let message = sprintf(message, dataName);

            throw new {exceptionClass}(message);
        }
    }

}
