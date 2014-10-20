/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
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
    protected items; // []

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
    public function insert(string name, value, int priority = 0) -> void
    {
        array data = [];
        int serial;

        let this->sorted = false;
        let this->count = this->count + 1;
        let serial = this->serial;

        let data["data"] = value;
        let data["priority"] = priority;
        let data["serial"] = serial;

        let this->serial = serial + 1;
        let this->items[name] = data;
    }

    public function setPriority(string name, int priority) -> <PriorityList>
    {
        string exceptionMsg;

        if unlikely !isset this->items[name] {
            let exceptionMsg = "item %s not found";
            let exceptionMsg = sprintf(exceptionMsg, name); 

            throw new \Exception(exceptionMsg);
        }
    }

    /**
     * Remove a item.
     *
     * @param  string $name
     * @return void
     */
    public function remove(string name) -> void
    {
        if !isset this->items[name] {
            return;
        }
        let this->count = this->count - 1;
        unset this->items[name];
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
        var item, data;

        if fetch item, this->items[name] {
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
        array callback = [];

        if !this->sorted {
            let callback[] = this;
            let callback[] = "compare";
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
        if flag !== null {
            if flag === true {
                let flag = 1;
            } else {
                let flag = -1;
            }
            if flag !== this->isLIFO {
                let this->isLIFO = flag;
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
    public function toArray(int flag = self::EXTR_DATA) -> array
    {
        this->sort();

        if flag == self::EXTR_BOTH {
            return this->items;
        }

        // todo: array_map
    }

}
