/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib;

use ArrayIterator;
use ArrayObject as PhpArrayObject;

/**
 * ArrayObject that acts as a stack with regards to iteration
 */
class ArrayStack extends PhpArrayObject
{
    /**
     * Retrieve iterator
     *
     * Retrieve an array copy of the object, reverse its order, and return an
     * ArrayIterator with that reversed array.
     *
     * @return ArrayIterator
     */
    public function getIterator() -> <ArrayIterator>
    {
        var data, iterator;

        let data = this->getArrayCopy();
        let data = array_reverse(data);
        let iterator = new ArrayIterator(data);

        return iterator;
    }

}
