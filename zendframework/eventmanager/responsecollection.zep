/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\EventManager;

use SplStack;

/**
 * Collection of signal handler return values
 */
class ResponseCollection extends SplStack
{
    protected stopped = false;

    /**
     * Did the last response provided trigger a short circuit of the stack?
     *
     * @return bool
     */
    public function stopped() -> boolean
    {
        return this->stopped;
    }

    /**
     * Mark the collection as stopped (or its opposite)
     *
     * @param  bool $flag
     * @return ResponseCollection
     */
    public function setStopped(boolean flag) -> <ResponseCollection>
    {
        let this->stopped = flag;
        
        return this;
    }

    /**
     * Convenient access to the first handler return value.
     *
     * @return mixed The first handler return value
     */
    public function first()
    {
        return parent::bottom();
    }

    /**
     * Convenient access to the last handler return value.
     *
     * If the collection is empty, returns null. Otherwise, returns value
     * returned by last handler.
     *
     * @return mixed The last handler return value
     */
    public function last()
    {
        if count(this) === 0 {
            return null;
        }
        return parent::top();
    }

    /**
     * Check if any of the responses match the given value.
     *
     * @param  mixed $value The value to look for among responses
     * @return bool
     */
    public function contains(value) -> boolean
    {
        var response;
        for response in iterator(this) {
            if response === value {
                return true;
            }
        }
        return false;
    }

}
