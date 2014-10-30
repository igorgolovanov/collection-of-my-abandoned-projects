/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\InputFilter;

/**
 * Mark an input as able to be replaced by another when merging input filters.
 *
 */
interface ReplaceableInputInterface
{
    public function replace(input, name); // todo: types

}
