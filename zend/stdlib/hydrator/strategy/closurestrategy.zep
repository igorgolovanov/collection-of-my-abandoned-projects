/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Strategy;

class ClosureStrategy implements StrategyInterface
{
    /**
     * Function, used in extract method, default:
     * function ($value) {
     *     return $value;
     * };
     * @var callable
     */
    protected extractFunc;

    /**
     * Function, used in hydrate method, default:
     * function ($value) {
     *     return $value;
     * };
     * @var callable
     */
    protected hydrateFunc;

    /**
     * You can describe how your values will extract and hydrate, like this:
     * $hydrator->addStrategy('category', new ClosureStrategy(
     *     function (Category $value) {
     *         return (int) $value->id;
     *     },
     *     function ($value) {
     *         return new Category((int) $value);
     *     }
     * ));
     *
     * @param callable $extractFunc - anonymous function, that extract values
     * from object
     * @param callable $hydrateFunc - anonymous function, that hydrate values
     * into object
     */
    public function __construct(callable extractFunc = null, callable hydrateFunc = null)
    {
        if extractFunc !== null {
            // todo: remove when zephir will be supported type "callable"
            if unlikely !is_callable(extractFunc) {
                throw new \InvalidArgumentException("$extractFunc must be callable");
            }
        } else {
            let extractFunc = [this, "_dummyCallback"];
        }

        if hydrateFunc !== null {
            // todo: remove when zephir will be supported type "callable"
            if unlikely !is_callable(hydrateFunc) { 
                throw new \InvalidArgumentException("$hydrateFunc must be callable");
            }
        } else {
            let hydrateFunc = [this, "_dummyCallback"];
        }

        let this->extractFunc = extractFunc;
        let this->hydrateFunc = hydrateFunc;
    }

    private function _dummyCallback(var value)
    {
        return value;
    }

    /**
     * Converts the given value so that it can be extracted by the hydrator.
     *
     * @param  mixed $value  The original value.
     * @param  array $object The object is optionally provided as context.
     * @return mixed Returns the value that should be extracted.
     */
    public function extract(var value, object $object = null)
    {
        var callback, result;

        let callback = this->extractFunc;
        let result = call_user_func(callback, value, $object);

        return result;
    }

    /**
     * Converts the given value so that it can be hydrated by the hydrator.
     *
     * @param  mixed $value The original value.
     * @param  array $data  The whole data is optionally provided as context.
     * @return mixed Returns the value that should be hydrated.
     */
    public function hydrate(var value, array data = null)
    {
        var callback, result;

        let callback = this->hydrateFunc;
        let result = call_user_func(callback, value, data);

        return result;
    }

}
