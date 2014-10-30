/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Form;

/**
 * Deprecated by https://github.com/zendframework/zf2/pull/5636
 *
 * @deprecated
 */
interface FieldsetPrepareAwareInterface
{
    /**
     * Prepare the fieldset element (called while this fieldset is added to another one)
     *
     * @return mixed
     */
    public function prepareFieldset();

}
