/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Permissions\Rbac;

abstract class AbstractIterator implements \RecursiveIterator, \Traversable, \Iterator
{
    /**
     * @var int
     */
    protected index = 0;

    /**
     * @var array
     */
    protected children = [];

    /**
     * (PHP 5 &gt;= 5.0.0)<br/>
     * Return the current element
     * @link http://php.net/manual/en/iterator.current.php
     * @return mixed Can return any type.
     */
    public function current()
    {
        int index;
        let index = this->index;

        return this->children[index];
    }

    /**
     * (PHP 5 &gt;= 5.0.0)<br/>
     * Move forward to next element
     * @link http://php.net/manual/en/iterator.next.php
     * @return void Any returned value is ignored.
     */
    public function next() -> void
    {
        let this->index++;
    }

    /**
     * (PHP 5 &gt;= 5.0.0)<br/>
     * Return the key of the current element
     * @link http://php.net/manual/en/iterator.key.php
     * @return int|null scalar on success, or null on failure.
     */
    public function key() -> int
    {
        return this->index;
    }

    /**
     * (PHP 5 &gt;= 5.0.0)<br/>
     * Checks if current position is valid
     * @link http://php.net/manual/en/iterator.valid.php
     * @return bool The return value will be casted to boolean and then evaluated.
     * Returns true on success or false on failure.
     */
    public function valid() -> boolean
    {
        int index;
        let index = this->index;

        return isset this->children[index];
    }

    /**
     * (PHP 5 &gt;= 5.0.0)<br/>
     * Rewind the Iterator to the first element
     * @link http://php.net/manual/en/iterator.rewind.php
     * @return void Any returned value is ignored.
     */
    public function rewind() -> void
    {
        let this->index = 0;
    }

    /**
     * (PHP 5 &gt;= 5.1.0)<br/>
     * Returns if an iterator can be created fot the current entry.
     * @link http://php.net/manual/en/recursiveiterator.haschildren.php
     * @return bool true if the current entry can be iterated over, otherwise returns false.
     */
    public function hasChildren() -> boolean
    {
        var current;

        if this->valid() {
            let current = this->current();
            if current instanceof RecursiveIterator {
                return true;
            }
        }

        return false;
    }

    /**
     * (PHP 5 &gt;= 5.1.0)<br/>
     * Returns an iterator for the current entry.
     * @link http://php.net/manual/en/recursiveiterator.getchildren.php
     * @return RecursiveIterator An iterator for the current entry.
     */
    public function getChildren() -> <\RecursiveIterator>
    {
        int index;
        let index = this->index;

        return this->children[index];
    }

}
