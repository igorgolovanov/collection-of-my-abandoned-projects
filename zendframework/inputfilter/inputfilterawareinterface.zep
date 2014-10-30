/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\InputFilter;

interface InputFilterAwareInterface
{
    /**
     * Set input filter
     *
     * @param  InputFilterInterface $inputFilter
     * @return InputFilterAwareInterface
     */
    public function setInputFilter(<InputFilterInterface> inputFilter) -> <InputFilterAwareInterface>;

    /**
     * Retrieve input filter
     *
     * @return InputFilterInterface
     */
    public function getInputFilter() -> <InputFilterInterface>;

}
