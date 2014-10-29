/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\View\Model;

/**
 * Interface describing a Retrievable Child Model
 *
 * Models implementing this interface provide a way to get there children by capture
 */
interface RetrievableChildrenInterface
{
    /**
     * Returns an array of Viewmodels with captureTo value $capture
     *
     * @param string $capture
     * @param bool $recursive search recursive through children, default true
     * @return array
     */
    public function getChildrenByCaptureTo(string capture, boolean recursive = true) -> array;

}
