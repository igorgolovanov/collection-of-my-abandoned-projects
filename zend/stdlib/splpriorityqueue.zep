/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib;

/**
 * Serializable version of SplPriorityQueue
 *
 * Also, provides predictable heap order for datums added with the same priority
 * (i.e., they will be emitted in the same order they are enqueued).
 */
class SplPriorityQueue extends \SplPriorityQueue implements \Serializable
{
    /**
     * @var int Seed used to ensure queue order for items of the same priority
     */
    protected serial = PHP_INT_MAX; //9223372036854775807;

    /**
     * Insert a value with a given priority
     *
     * Utilizes {@var $serial} to ensure that values of equal priority are
     * emitted in the same order in which they are inserted.
     *
     * @param  mixed $datum
     * @param  mixed $priority
     * @return void
     */
    public function insert(datum, priority) -> void
    {
        var serial;

        if typeof priority != "array" {
            let serial = this->serial;
            let priority = [priority, serial];
            let this->serial--;
        }
        parent::insert(datum, priority);
    }

    /**
     * Serialize to an array
     *
     * Array will be priority => data pairs
     *
     * @return array
     */
    public function toArray() -> array
    {
        var item;
        array data = [];

        for item in this {
            let data[] = item;
        }
        return data;
    }

    /**
     * Serialize
     *
     * @return string
     */
    public function serialize() -> string
    {
        string serialized;
        array data;

        let data = this->toArray();
        let serialized = serialize(data);

        return serialized;
    }

    /**
     * Deserialize
     *
     * @param  string $data
     * @return void
     */
    public function unserialize(string data) -> void
    {
        var unserialized, item, value, priority;

        let unserialized = unserialize(data);

        for item in unserialized {
            if fetch value, item["data"] {
                if fetch priority, item["priority"] {
                    this->insert(value, priority);
                }
            }
        }
    }

}
