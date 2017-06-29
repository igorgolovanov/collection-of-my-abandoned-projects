/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib;

use Countable;
use Iterator;

/**
* Priority list
*/
class PriorityList implements Iterator, Countable
{
    const EXTR_DATA = 0x00000001;
    const EXTR_PRIORITY = 0x00000002;
    const EXTR_BOTH = 0x00000003;

    /**
     * Internal list of all items.
     *
     * @var array
     */
    protected items = [];

    /**
     * Serial assigned to items to preserve LIFO.
     *
     * @var int
     */
    protected serial = 0;

    /**
     * Serial order mode
     * @var integer
     */
    protected isLIFO = 1;

    /**
     * Internal counter to avoid usage of count().
     *
     * @var int
     */
    protected count = 0;

    /**
     * Whether the list was already sorted.
     *
     * @var bool
     */
    protected sorted = false;

    /**
     * Insert a new item.
     *
     * @param  string  $name
     * @param  mixed $value
     * @param  int $priority
     * @return void
     */
    public function insert(string name, var value, int priority = 0) -> void
    {
        array data = [];

        let this->sorted = false;
        let this->count = this->count + 1;

        let data["data"] = value;
        let data["priority"] = priority;
        let data["serial"] = this->serial;

        let this->serial++;
        let this->items[name] = data;
    }

    public function setPriority(string name, int priority) -> <PriorityList>
    {
        string exceptionMsg;

        if unlikely !isset this->items[name] {
            let exceptionMsg = "item " . name . " not found";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let this->items[name]["priority"] = priority;
        let this->sorted = false;

        return this;
    }

    /**
     * Remove a item.
     *
     * @param  string $name
     * @return void
     */
    public function remove(string name) -> void
    {
        var items;
        let items = this->items;

        if typeof items != "array" {
            let items = [];
        }

        if !isset items[name] {
            return;
        }

        let this->count--;
        unset items[name];
        let this->items = items;
    }

    /**
     * Remove all items.
     *
     * @return void
     */
    public function clear() -> void
    {
        let this->items = [];
        let this->serial = 0;
        let this->count = 0;
        let this->sorted = false;
    }

    /**
     * Get a item.
     *
     * @param  string $name
     * @return mixed
     */
    public function get(string name)
    {
        var item, data, items;

        let items = this->items;

        if typeof items != "array" {
            return null;
        }

        if fetch item, items[name] {
            if fetch data, item["data"] {
                return data;
            }
        }
        return null;
    }

    /**
     * Sort all items.
     *
     * @return void
     */
    protected function sort() -> void
    {
        array callback;

        if !this->sorted {
            let callback = [this, "compare"];
            uasort(this->items, callback);
            let this->sorted = true;
        }
    }

    /**
     * Compare the priority of two items.
     *
     * @param  array $item1,
     * @param  array $item2
     * @return int
     */
    protected function compare(array! item1, array! item2) -> int
    {
        int result;

        if item1["priority"] === item2["priority"] {
            if item1["serial"] > item2["serial"] {
                let result = -1;
            } else {
                let result = 1;
            }
            let result = result * this->isLIFO;
        } else {
            if item1["priority"] > item2["priority"] {
                let result = -1;
            } else {
                let result = 1;
            }
        }
        return result;
    }

    /**
     * Get/Set serial order mode
     *
     * @param bool $flag
     * @return bool
     */
    public function isLIFO(boolean flag = null) -> boolean
    {
        int isLIFO;

        if flag !== null {
            let isLIFO = flag === true ? 1 : -1;
            if isLIFO !== this->isLIFO {
                let this->isLIFO = isLIFO;
                let this->sorted = false;
            }
        }

        return this->isLIFO === 1;
    }

    /**
     * rewind(): defined by Iterator interface.
     *
     * @see    Iterator::rewind()
     * @return void
     */
    public function rewind() -> void
    {
        this->sort();
        reset(this->items);
    }

    /**
     * current(): defined by Iterator interface.
     *
     * @see    Iterator::current()
     * @return mixed
     */
    public function current()
    {
        var node;
        let node = current(this->items);

        if node !== false {
            return node["data"];
        }
        return false;
    }

    /**
     * key(): defined by Iterator interface.
     *
     * @see    Iterator::key()
     * @return string
     */
    public function key() -> string
    {
        return key(this->items);
    }

    /**
     * next(): defined by Iterator interface.
     *
     * @see    Iterator::next()
     * @return mixed
     */
    public function next()
    {
        var node;
        let node = next(this->items);

        if node !== false {
            return node["data"];
        }
        return false;
    }

    /**
     * valid(): defined by Iterator interface.
     *
     * @see    Iterator::valid()
     * @return bool
     */
    public function valid() -> boolean
    {
        var current;
        let current = this->current();

        return current !== false;
    }

    /**
     * count(): defined by Countable interface.
     *
     * @see    Countable::count()
     * @return int
     */
    public function count() -> int
    {
        return this->count;
    }

    /**
     * Return list as array
     *
     * @param int $flag
     * @return array
     */
    public function toArray(var flag = self::EXTR_DATA) -> array
    {
        array callback;

        this->sort();

        if flag == self::EXTR_BOTH {
            return this->items;
        }

        if flag == self::EXTR_PRIORITY {
            let callback = [this, "_returnItemPriority"];
        } else {
            let callback = [this, "_returnItemData"];
        }

        return array_map(callback, this->items);
    }

    private function _returnItemPriority(array item)
    {
        var priority;

        if fetch priority, item["priority"] {
            return priority;
        }
        return null;
    }

    private function _returnItemData(array item)
    {
        var data;

        if fetch data, item["data"] {
            return data;
        }
        return null;
    }
}
