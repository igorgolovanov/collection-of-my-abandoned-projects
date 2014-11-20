/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib;

abstract class AbstractOptions implements ParameterObjectInterface
{
    /**
     * We use the __ prefix to avoid collisions with properties in
     * user-implementations.
     *
     * @var bool
     */
    protected __strictMode__ = true;

    /**
     * Constructor
     *
     * @param  array|Traversable|null $options
     */
    public function __construct(var options = null)
    {
        if options !== null {
            this->setFromArray(options);
        }
    }

    /**
     * Set one or more configuration properties
     *
     * @param  array|Traversable|AbstractOptions $options
     * @throws Exception\InvalidArgumentException
     * @return AbstractOptions Provides fluent interface
     */
    public function setFromArray(var options) -> <AbstractOptions>
    {
        string exceptionMsg;
        var key, value;

        if options instanceof AbstractOptions {
            let options = options->toArray();
        }

        if unlikely typeof options !== "array" && !(options instanceof Traversable) {
            let exceptionMsg = "Parameter provided to " . __METHOD__ . " must be an array, Traversable or Zend\\Stdlib\\AbstractOptions";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        for key, value in options {
            this->__set(key, value);
        }

        return this;
    }

    /**
     * Cast to array
     *
     * @return array
     */
    public function toArray() -> array
    {
        var data = [], key, value;
        var normalizedKey;

        for key, value in this {
            if key === "__strictMode__" {
                continue;
            }
            let normalizedKey = preg_replace_callback("/([A-Z])/", function(array! letters) {
                 string letter;

                 let letter = (string) array_shift(letters);
                 return "_" . letter->lower();
            }, key);
            let data[normalizedKey] = value;
        }
        return data;
    }

    /**
     * Set a configuration property
     *
     * @see ParameterObject::__set()
     * @param string $key
     * @param mixed $value
     * @throws Exception\BadMethodCallException
     * @return void
     */
    public function __set(string key, value) -> void
    {
        string setter, exceptionMsg;

        let setter = str_replace("_", "", key);
        let setter = ucwords(setter);
        let setter = str_replace(" ", "", setter);
        let setter = "set" . setter;

        if unlikely this->__strictMode__ && !method_exists(this, setter) {
            let exceptionMsg = "The option \""
                            . key
                            . "\" does not have a matching "
                            . setter
                            . " setter method which must be defined";

            throw new Exception\BadMethodCallException(exceptionMsg);
        }
        if !this->__strictMode__ && !method_exists(this, setter) {
            return;
        }

        this->{setter}(value);
    }

    /**
     * Get a configuration property
     *
     * @see ParameterObject::__get()
     * @param string $key
     * @throws Exception\BadMethodCallException
     * @return mixed
     */
    public function __get(string key)
    {
        string getter, exceptionMsg;

        let getter = str_replace("_", "", key);
        let getter = ucwords(getter);
        let getter = str_replace(" ", "", getter);
        let getter = "get" . getter;

        if unlikely !method_exists(this, getter) {
            let exceptionMsg = "The option \""
                            . key
                            . "\" does not have a matching "
                            . getter
                            . " getter method which must be defined";

            throw new Exception\BadMethodCallException(exceptionMsg);
        }

        return this->{getter}();
    }

    /**
     * Test if a configuration property is null
     * @see ParameterObject::__isset()
     * @param string $key
     * @return bool
     */
    public function __isset(string key) -> boolean
    {
        var value;
        let value = this->__get(key);

        return value !== null;
    }

    /**
     * Set a configuration property to NULL
     *
     * @see ParameterObject::__unset()
     * @param string $key
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public function __unset(string key) -> void
    {
        var e;
        string exceptionMsg;

        try {
            this->__set(key, null);
        } catch Exception\BadMethodCallException, e {
            let exceptionMsg = "The class property $" . key . "cannot be unset as NULL is an invalid value for it";
            throw new Exception\InvalidArgumentException(exceptionMsg, 0, e);
        }
    }

}
