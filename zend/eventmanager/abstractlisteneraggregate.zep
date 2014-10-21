/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\EventManager;

/**
 * Abstract aggregate listener
 */
abstract class AbstractListenerAggregate implements ListenerAggregateInterface
{
    /**
     * @var \Zend\Stdlib\CallbackHandler[]
     */
    protected listeners = [];

    /**
     * {@inheritDoc}
     */
    public function detach(<EventManagerInterface> events) -> void
    {
        var index, callback;
        boolean detached;

        for index, callback in this->listeners {
            let detached = events->detach(callback);
            if detached {
                unset this->listeners[index];
            }
        }
    }

}
