/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\EventManager\Filter;

use Zend\EventManager\ResponseCollection;
use Zend\Stdlib\CallbackHandler;

/**
* Interface for intercepting filter chains
*/
interface FilterInterface
{
    /**
     * Execute the filter chain
     *
     * @param  string|object $context
     * @param  array $params
     * @return mixed
     */
    public function run(var context, array! params = []);

    /**
     * Attach an intercepting filter
     *
     * @param  callable $callback
     * @return CallbackHandler
     */
    public function attach(var callback) -> <CallbackHandler>;

    /**
     * Detach an intercepting filter
     *
     * @param  CallbackHandler $filter
     * @return bool
     */
    public function detach(<CallbackHandler> filter) -> boolean;

    /**
     * Get all intercepting filters
     *
     * @return array
     */
    public function getFilters() -> array;

    /**
     * Clear all filters
     *
     * @return void
     */
    public function clearFilters() -> void;

    /**
     * Get all filter responses
     *
     * @return ResponseCollection
     */
    public function getResponses() -> <ResponseCollection>;
}
