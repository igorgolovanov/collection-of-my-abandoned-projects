/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\EventManager\Filter;

use Zend\Stdlib\CallbackHandler;
use Zend\Stdlib\SplPriorityQueue;

/**
 * Specialized priority queue implementation for use with an intercepting
 * filter chain.
 *
 * Allows removal
 */
class FilterIterator extends SplPriorityQueue
{
    /**
     * Does the queue contain a given value?
     *
     * @param  mixed $datum
     * @return bool
     */
    public function contains(var datum) -> boolean
    {
        var chain, item;

        let chain = clone this;

        for item in iterator(chain) {
            if item === datum {
                return true;
            }
        }
        return false;
    }

    /**
     * Remove a value from the queue
     *
     * This is an expensive operation. It must first iterate through all values,
     * and then re-populate itself. Use only if absolutely necessary.
     *
     * @param  mixed $datum
     * @return bool
     */
    public function remove(var datum) -> boolean
    {
        boolean removed = false;
        array items = [];
        var item, data, priority;

        this->setExtractFlags(\SplPriorityQueue::EXTR_BOTH);
        this->rewind();

        while !this->isEmpty() {
            let item = this->extract();
            if fetch data, item["data"] {
                if data === datum {
                    let removed = true;
                    continue;
                }
            }
            array_push(items, item);
        }

        for item in items {
            if fetch data, item["data"] {
                if fetch priority, item["priority"] {
                    this->insert(data, priority);
                }
            }
        }
        this->setExtractFlags(\SplPriorityQueue::EXTR_DATA);

        return removed;
    }

    /**
     * Iterate the next filter in the chain
     *
     * Iterates and calls the next filter in the chain.
     *
     * @param  mixed $context
     * @param  array $params
     * @param  FilterIterator $chain
     * @return mixed
     */
    public function next(var context = null, array! params = [], <FilterIterator> chain = null)
    {
        var next, callback, returns;
        if empty context || chain->isEmpty() {
            return;
        }

        let next = this->extract();
        if !(next instanceof CallbackHandler) {
            return;
        }
        let callback = next->getCallback();
        let returns = call_user_func(callback, context, params, chain);

        return returns;
    }

}
