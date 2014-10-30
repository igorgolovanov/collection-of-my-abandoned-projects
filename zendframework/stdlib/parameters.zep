/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib;

use ArrayObject as PhpArrayObject;

class Parameters extends PhpArrayObject implements ParametersInterface
{

    /**
     * Constructor
     *
     * Enforces that we have an array, and enforces parameter access to array
     * elements.
     *
     * @param  array $values
     */
    public function __construct(array! values = null)
    {
        if values === null {
            let values = [];
        }
        parent::__construct(values, PhpArrayObject::ARRAY_AS_PROPS);
    }

    /**
     * Populate from native PHP array
     *
     * @param  array $values
     * @return void
     */
    public function fromArray(array! values) -> void
    {
        this->exchangeArray(values);
    }

    /**
     * Populate from query string
     *
     * @param  string $string
     * @return void
     */
    public function fromString(string $string) -> void
    {
        var data = [];

        parse_str($string, data);
        this->fromArray(data);
    }

    /**
     * Serialize to native PHP array
     *
     * @return array
     */
    public function toArray() -> array
    {
        return this->getArrayCopy();
    }

    /**
     * Serialize to query string
     *
     * @return string
     */
    public function toString() -> string
    {
        return http_build_query(this);
    }

    /**
     * Retrieve by key
     *
     * Returns null if the key does not exist.
     *
     * @param  string $name
     * @return mixed
     */
    public function offsetGet(string name)
    {
        if this->offsetExists(name) {
            return parent::offsetGet(name);
        }
        return null;
    }

    /**
     * @param string $name
     * @param mixed $default optional default value
     * @return mixed
     */
    public function get(string name, var defaultVal = null)
    {
        if this->offsetExists(name) {
            return parent::offsetGet(name);
        }
        return defaultVal;
    }

    /**
     * @param string $name
     * @param mixed $value
     * @return Parameters
     */
    public function set(string name, var value) -> <Parameters>
    {
        this->offsetSet(name, value);
        return this;
    }

}
