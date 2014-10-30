/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib\Hydrator;

interface HydratorAwareInterface
{
    /**
     * Set hydrator
     *
     * @param  HydratorInterface $hydrator
     * @return HydratorAwareInterface
     */
    public function setHydrator(<HydratorInterface> hydrator) -> <HydratorAwareInterface>;

    /**
     * Retrieve hydrator
     *
     * @return HydratorInterface
     */
    public function getHydrator() -> <HydratorInterface>;

}
