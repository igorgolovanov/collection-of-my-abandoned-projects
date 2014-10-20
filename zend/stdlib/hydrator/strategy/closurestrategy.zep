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
    public function __construct(var extractFunc = null, var hydrateFunc = null)
    {
        if !empty extractFunc {

        } else {
            
        }
    }

    /**
     * Converts the given value so that it can be extracted by the hydrator.
     *
     * @param  mixed $value  The original value.
     * @param  array $object The object is optionally provided as context.
     * @return mixed Returns the value that should be extracted.
     */
    public function extract(value, array $object = null)
    {
        // todo
    }

    /**
     * Converts the given value so that it can be hydrated by the hydrator.
     *
     * @param  mixed $value The original value.
     * @param  array $data  The whole data is optionally provided as context.
     * @return mixed Returns the value that should be hydrated.
     */
    public function hydrate(value, array data = null)
    {
        // todo
    }

}
