/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib;

interface ArraySerializableInterface
{
    /**
     * Exchange internal values from provided array
     *
     * @param  array $array
     * @return void
     */
    public function exchangeArray(array! $array) -> void;

    /**
     * Return an array representation of the object
     *
     * @return array
     */
    public function getArrayCopy() -> array;

}
