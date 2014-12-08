/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Paginator\Adapter;

/**
 * Interface for pagination adapters.
 */
interface AdapterInterface extends \Countable
{
    /**
     * Returns a collection of items for a page.
     *
     * @param  int $offset Page offset
     * @param  int $itemCountPerPage Number of items per page
     * @return array
     */
    public function getItems(int offset, int itemCountPerPage) -> array;

}
