/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib;

use ArrayAccess;
use Countable;
use Serializable;

/*
* Basically, an ArrayObject. You could simply define something like:
* class QueryParams extends ArrayObject implements Parameters {}
* and have 90% of the functionality
*/
interface ParametersInterface extends ArrayAccess, Countable, Serializable // todo: Traversable
{
    /**
     * Constructor
     *
     * @param array $values
     */
    public function __construct(array! values = null);

    /**
     * From array
     *
     * Allow deserialization from standard array
     *
     * @param array $values
     * @return mixed
     */
    public function fromArray(array! values);

    /**
     * From string
     *
     * Allow deserialization from raw body; e.g., for PUT requests
     *
     * @param $string
     * @return mixed
     */
    public function fromString($string);

    /**
     * To array
     *
     * Allow serialization back to standard array
     *
     * @return mixed
     */
    public function toArray();

    /**
     * To string
     *
     * Allow serialization to query format; e.g., for PUT or POST requests
     *
     * @return mixed
     */
    public function toString();

    /**
     * Get
     *
     * @param string $name
     * @param mixed|null $default
     * @return mixed
     */
    public function get(string name, var $default = null);

    /**
     * Set
     *
     * @param string $name
     * @param mixed $value
     * @return ParametersInterface
     */
    public function set(string name, var value) -> <ParametersInterface>;

}
