/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib;

use Countable;
use IteratorAggregate;
use Serializable;
use SplPriorityQueue;

/**
 * Re-usable, serializable priority queue implementation
 *
 * SplPriorityQueue acts as a heap; on iteration, each item is removed from the
 * queue. If you wish to re-use such a queue, you need to clone it first. This
 * makes for some interesting issues if you wish to delete items from the queue,
 * or, as already stated, iterate over it multiple times.
 *
 * This class aggregates items for the queue itself, but also composes an
 * "inner" iterator in the form of an SplPriorityQueue object for performing
 * the actual iteration.
 */
class PriorityQueue implements Countable, IteratorAggregate, Serializable
{
    const EXTR_DATA = 1;
    const EXTR_PRIORITY = 2;
    const EXTR_BOTH = 3;

    /**
     * Inner queue class to use for iteration
     * @var string
     */
    protected queueClass = "Zend\\Stdlib\\SplPriorityQueue";

    /**
     * Actual items aggregated in the priority queue. Each item is an array
     * with keys "data" and "priority".
     * @var array
     */
    protected items = [];

    /**
     * Inner queue object
     * @var SplPriorityQueue
     */
    protected queue;

    /**
     * Insert an item into the queue
     *
     * Priority defaults to 1 (low priority) if none provided.
     *
     * @param  mixed $data
     * @param  int $priority
     * @return PriorityQueue
     */
    public function insert(data, int priority = 1) -> <PriorityQueue>
    {
        var queue;
        array datum;

        let datum = ["data" : data, "priority" : priority];
        let this->items[] = data;

        let queue = <SplPriorityQueue> this->getQueue();
        queue->insert(datum, priority);

        return this;
    }

    /**
     * Remove an item from the queue
     *
     * This is different than {@link extract()}; its purpose is to dequeue an
     * item.
     *
     * This operation is potentially expensive, as it requires
     * re-initialization and re-population of the inner queue.
     *
     * Note: this removes the first item matching the provided item found. If
     * the same item has been added multiple times, it will not remove other
     * instances.
     *
     * @param  mixed $datum
     * @return bool False if the item was not found, true otherwise.
     */
    public function remove(datum) -> boolean
    {
        boolean found = false;
        var key, item, queue, data, priority;

        for key, item in this->items {
            if item["data"] === datum {
                let found = true;
                break;
            }
        }

        if found {
            unset this->items[key];
            let this->queue = null;

            if !this->isEmpty() {
                let queue = <SplPriorityQueue> this->getQueue();
                for item in this->items {
                    let data = item["data"];
                    let priority = item["priority"];

                    queue->insert(data, priority);
                }
            }
            return true;
        }
        return false;
    }

    /**
     * Is the queue empty?
     *
     * @return bool
     */
    public function isEmpty() -> boolean
    {
        return 0 === this->count();
    }

    /**
     * How many items are in the queue?
     *
     * @return int
     */
    public function count() -> int
    {
        return count(this->items);
    }

    /**
     * Peek at the top node in the queue, based on priority.
     *
     * @return mixed
     */
    public function top()
    {
        var iterator, item;

        let iterator = <SplPriorityQueue> this->getIterator();
        let item = iterator->top();

        return item;
    }

    /**
     * Extract a node from the inner queue and sift up
     *
     * @return mixed
     */
    public function extract()
    {
        var queue, item;

        let queue = <SplPriorityQueue> this->getQueue();
        let item = queue->extract();

        return item;
    }

    /**
     * Retrieve the inner iterator
     *
     * SplPriorityQueue acts as a heap, which typically implies that as items
     * are iterated, they are also removed. This does not work for situations
     * where the queue may be iterated multiple times. As such, this class
     * aggregates the values, and also injects an SplPriorityQueue. This method
     * retrieves the inner queue object, and clones it for purposes of
     * iteration.
     *
     * @return SplPriorityQueue
     */
    public function getIterator() -> <SplPriorityQueue>
    {
        var queue;
        let queue = <SplPriorityQueue> this->getQueue();

        return clone queue;
    }

    /**
     * Serialize the data structure
     *
     * @return string
     */
    public function serialize() -> string
    {
        var items, serialized;

        let items = this->items;
        let serialized = serialize(items);

        return serialized;
    }

    /**
     * Unserialize a string into a PriorityQueue object
     *
     * Serialization format is compatible with {@link Zend\Stdlib\SplPriorityQueue}
     *
     * @param  string $data
     * @return void
     */
    public function unserialize(string data) -> void
    {
        var unserialized, datum, item, priority;

        let unserialized = unserialize(data);

        for item in unserialized {
            let datum = item["data"];
            let priority = item["priority"];

            this->insert(datum, priority);
        }
    }

    /**
     * Serialize to an array
     *
     * By default, returns only the item data, and in the order registered (not
     * sorted). You may provide one of the EXTR_* flags as an argument, allowing
     * the ability to return priorities or both data and priority.
     *
     * @param  int $flag
     * @return array
     */
    public function toArray(var flag = self::EXTR_DATA) -> array
    {
        var result, items;
        array callback;

        let items = this->items;

        switch flag {
            case self::EXTR_BOTH:
                let result = items;
                break;

            case self::EXTR_PRIORITY:
                let callback = [this, "toPriorityArray"];
                let result = array_map(callback, items);
                break;
                
            case self::EXTR_DATA:
            default:
                let callback = [this, "toDataArray"];
                let result = array_map(callback, items);
                break;        
        }

        return result;
    }

    private function toDataArray(array! item)
    {
        return item["data"];
    }

    private function toPriorityArray(array! item)
    {
        return item["priority"];
    }

    /**
     * Specify the internal queue class
     *
     * Please see {@link getIterator()} for details on the necessity of an
     * internal queue class. The class provided should extend SplPriorityQueue.
     *
     * @param  string $class
     * @return PriorityQueue
     */
    public function setInternalQueueClass(string $class) -> <PriorityQueue>
    {
        let this->queueClass = $class;
        return this;
    }

    /**
     * Does the queue contain the given datum?
     *
     * @param  mixed $datum
     * @return bool
     */
    public function contains(var datum) -> boolean
    {
        var item;

        for item in this->items {
            if item["data"] === datum {
                return true;
            }
        }
        return false;
    }

    /**
     * Does the queue have an item with the given priority?
     *
     * @param  int $priority
     * @return bool
     */
    public function hasPriority(int priority) -> boolean
    {
        var item;

        for item in this->items {
            if item["priority"] === priority {
                return true;
            }
        }
        return false;
    }

    /**
     * Get the inner priority queue instance
     *
     * @throws Exception\DomainException
     * @return SplPriorityQueue
     */
    protected function getQueue() -> <SplPriorityQueue>
    {
        string exceptionMsg;
        var queue, queueClass;

        let queue = this->queue;
        if this->queue === null {
            let queueClass = this->queueClass;
            let queue = new {queueClass}();

            if unlikely !(queue instanceof SplPriorityQueue) {
                let exceptionMsg = "PriorityQueue expects an internal queue of type SplPriorityQueue; received \"" . queueClass . "\"";
                throw new Exception\DomainException(exceptionMsg);
            }
            let this->queue = queue;
        }

        return queue;
    }

    /**
     * Add support for deep cloning
     *
     * @return void
     */
    public function __clone() -> void
    {
        if this->queue !== null {
            let this->queue = clone this->queue;
        }
    }

}
