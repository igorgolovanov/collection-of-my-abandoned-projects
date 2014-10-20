/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\EventManager;

use Zend\Stdlib\CallbackHandler;

/**
 * FilterChain: intercepting filter manager
 */
class FilterChain implements \Filter\FilterInterface
{
    /**
     * @var Filter\FilterIterator All filters
     */
    protected filters;

    /**
     * Constructor
     *
     * Initializes Filter\FilterIterator in which filters will be aggregated
     */
    public function __construct()
    {
        let this->filters = new Filter\FilterIterator();
    }

    /**
     * Apply the filters
     *
     * Begins iteration of the filters.
     *
     * @param  mixed $context Object under observation
     * @param  mixed $argv Associative array of arguments
     * @return mixed
     */
    public function run(context, array! argv = [])
    {
        var chain, filters, next, returns, callback;

        let filters = <Filter\FilterIterator> this->getFilters();
        let chain = clone filters;

        if chain->isEmpty() {
            return;
        }

        let next = chain->extract();
        if unlikely next instanceof CallbackHandler {
            return;
        }
        let callback = next->getCallback();
        let returns = call_user_func(callback, context, argv, chain);

        return returns;
    }

    /**
     * Connect a filter to the chain
     *
     * @param  callable $callback PHP Callback
     * @param  int $priority Priority in the queue at which to execute; defaults to 1 (higher numbers == higher priority)
     * @return CallbackHandler (to allow later unsubscribe)
     * @throws Exception\InvalidCallbackException
     */
    public function attach(callback, int priority = 1) -> <CallbackHandler>
    {
        var filter, filters;
        array metadata = [];

        if empty callback {
            throw new Exception\InvalidCallbackException("No callback provided");
        }
        let metadata["priority"] = priority;
        let filter = new CallbackHandler(callback, metadata);
        let filters = <Filter\FilterIterator> this->getFilters();

        filters->insert(filter, priority);

        return filter;
    }

    /**
     * Detach a filter from the chain
     *
     * @param  CallbackHandler $filter
     * @return bool Returns true if filter found and unsubscribed; returns false otherwise
     */
    public function detach(<CallbackHandler> filter) -> boolean
    {
        var filters;
        let filters = <Filter\FilterIterator> this->getFilters();

        return filters->remove(filter);
    }

    /**
     * Retrieve all filters
     *
     * @return Filter\FilterIterator
     */
    public function getFilters() -> <Filter\FilterIterator>
    {
        return this->filters;
    }

    /**
     * Clear all filters
     *
     * @return void
     */
    public function clearFilters() -> void
    {
        let this->filters = new Filter\FilterIterator();
    }

    /**
     * Return current responses
     *
     * Only available while the chain is still being iterated. Returns the
     * current ResponseCollection.
     *
     * @return null|ResponseCollection
     */
    public function getResponses() -> <ResponseCollection>|null
    {
        return null;
    }

}
