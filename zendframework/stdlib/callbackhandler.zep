/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib;

use ReflectionClass;

/**
 * CallbackHandler
 *
 * A handler for an event, event, filterchain, etc. Abstracts PHP callbacks,
 * primarily to allow for lazy-loading and ensuring availability of default
 * arguments (currying).
 */
class CallbackHandler
{
    /**
     * @var string|array|callable PHP callback to invoke
     */
    protected callback;

    /**
     * Callback metadata, if any
     * @var array
     */
    protected metadata;

    /**
     * PHP version is greater as 5.4rc1?
     * @var bool
     */
    protected static isPhp54;

    /**
     * Constructor
     *
     * @param  string|array|object|callable $callback PHP callback
     * @param  array                        $metadata  Callback metadata
     */
    public function __construct(callable callback, array! metadata = [])
    {
        let this->metadata = metadata;
        this->registerCallback(callback);
    }

    /**
     * Registers the callback provided in the constructor
     *
     * @param  callable $callback
     * @throws Exception\InvalidCallbackException
     * @return void
     */
    protected function registerCallback(callable! callback) -> void
    {
        if unlikely !is_callable(callback) {
            // todo: remove this exception and use callable type
            throw new Exception\InvalidCallbackException("Invalid callback provided; not callable");
        }
        let this->callback = callback;
    }

    /**
     * Retrieve registered callback
     *
     * @return callable
     */
    public function getCallback()
    {
        return this->callback;
    }

    /**
     * Invoke handler
     *
     * @param  array $args Arguments to pass to callback
     * @return mixed
     */
    public function call(array! args = [])
    {
        var callback, result, arg1, arg2, arg3, className, isPhp54 = null;
        int argCount;


        let callback = this->getCallback();
        let className = get_called_class();

        %{
            zephir_read_static_property(&value, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("isPhp54") TSRMLS_CC);
        }%

        // Minor performance tweak, if the callback gets called more than once
        if isPhp54 === null {
            let isPhp54 = version_compare(PHP_VERSION, "5.4.0rc1", ">=");

            %{
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("isPhp54"), &value TSRMLS_CC);
            }%
        }

        let argCount = count(args);

        if isPhp54 && typeof callback == "string" {
            let result = this->validateStringCallbackFor54(callback);

            if result !== true && argCount <= 3 {
                let callback = result;
                // Minor performance tweak, if the callback gets called more
                // than once
                let this->callback = result;
            }
        }

        // Minor performance tweak; use call_user_func() until > 3 arguments
        // reached
        switch argCount {
            case 0:
                if isPhp54 {
                    let result = {callback}();
                } else {
                    let result = call_user_func(callback);
                }
                break;

            case 1:
                let arg1 = array_shift(args);
                if isPhp54 {
                    let result = {callback}(arg1);
                } else {
                    let result = call_user_func(callback, arg1);
                }
                break;

            case 2:
                let arg1 = array_shift(args);
                let arg2 = array_shift(args);
                if isPhp54 {
                    let result = {callback}(arg1, arg2);
                } else {
                    let result = call_user_func(callback, arg1, arg2);
                }
                break;

            case 3:
                let arg1 = array_shift(args);
                let arg2 = array_shift(args);
                let arg3 = array_shift(args);
                if isPhp54 {
                    let result = {callback}(arg1, arg2, arg3);
                } else {
                    let result = call_user_func(callback, arg1, arg2, arg3);
                }
                break;

            default:    
                let result = call_user_func_array(callback, args);
        }

        return result;
    }

    /**
     * Invoke as functor
     *
     * @return mixed
     */
    public function __invoke()
    {
        var args, result;

        let args = func_get_args();
        let result = this->call(args);

        return result;
    }

    /**
     * Get all callback metadata
     *
     * @return array
     */
    public function getMetadata() -> array
    {
        return this->metadata;
    }

    /**
     * Retrieve a single metadatum
     *
     * @param  string $name
     * @return mixed
     */
    public function getMetadatum(string name)
    {
        var value;
        if fetch value, this->metadata[name] {
            return value;
        }
        return null;
    }

    /**
     * Validate a static method call
     *
     * Validates that a static method call in PHP 5.4 will actually work
     *
     * @param  string $callback
     * @return true|array
     * @throws Exception\InvalidCallbackException if invalid
     */
    protected function validateStringCallbackFor54(string callback) -> array|boolean
    {
        string exceptionMsg;
        var parts, ref, m, className, method;

        if !strstr(callback, "::") {
            return true;
        }

        let parts = explode("::", callback, 2);
        let className = parts[0];
        let method = parts[1];

        if unlikely !class_exists(className) {
            let exceptionMsg = "Static method call \"" . callback . "\" refers to a class that does not exist";
            throw new Exception\InvalidCallbackException(exceptionMsg);
        }

        let ref = new ReflectionClass(className);

        if unlikely !ref->hasMethod(method) {
            let exceptionMsg = "Static method call \"" . callback . "\" refers to a class that does not exist";
            throw new Exception\InvalidCallbackException(exceptionMsg);
        }

        let m = <\ReflectionMethod> ref->getMethod(method);

        if unlikely !m->isStatic() {
            let exceptionMsg = "Static method call \"" . callback . "\" refers to a class that does not exist";
            throw new Exception\InvalidCallbackException(exceptionMsg);
        }

        return [className, method];
    }

}
