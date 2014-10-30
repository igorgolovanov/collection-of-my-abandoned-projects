/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib\Hydrator\NamingStrategy;

/**
 * Allow property extraction / hydration for hydrator
 *
 * Interface PropertyStrategyInterface
 * @package Zend\Stdlib\Hydrator\NamingStrategy
 */
interface NamingStrategyInterface
{
    /**
     * Converts the given name so that it can be extracted by the hydrator.
     *
     * @param string $name   The original name
     * @param object $object (optional) The original object for context.
     * @return mixed         The hydrated name
     */
    public function hydrate(string name);

    /**
     * Converts the given name so that it can be hydrated by the hydrator.
     *
     * @param string $name The original name
     * @param array  $data (optional) The original data for context.
     * @return mixed The extracted name
     */
    public function extract(string name);

}
