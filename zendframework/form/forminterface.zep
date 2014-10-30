/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Form;

use Zend\InputFilter\InputFilterInterface;

interface FormInterface extends FieldsetInterface
{
    const BIND_ON_VALIDATE = 0;

    const BIND_MANUAL = 1;

    const VALIDATE_ALL = 16;

    const VALUES_NORMALIZED = 17;

    const VALUES_RAW = 18;

    const VALUES_AS_ARRAY = 19;

    /**
     * Set data to validate and/or populate elements
     *
     * Typically, also passes data on to the composed input filter.
     *
     * @param  array|\ArrayAccess $data
     * @return FormInterface
     */
    public function setData(var data) -> <FormInterface>;

    /**
     * Bind an object to the element
     *
     * Allows populating the object with validated values.
     *
     * @param  object $object
     * @param  int $flags
     * @return mixed
     */
    public function bind(object $object, int flags = Zend\Form\FormInterface::VALUES_NORMALIZED);

    /**
     * Whether or not to bind values to the bound object when validation succeeds
     *
     * @param  int $bindOnValidateFlag
     * @return void
     */
    public function setBindOnValidate(int bindOnValidateFlag) -> void;

    /**
     * Set input filter
     *
     * @param  InputFilterInterface $inputFilter
     * @return FormInterface
     */
    public function setInputFilter(<InputFilterInterface> inputFilter) -> <FormInterface>;

    /**
     * Retrieve input filter
     *
     * @return InputFilterInterface
     */
    public function getInputFilter() -> <InputFilterInterface>;

    /**
     * Validate the form
     *
     * Typically, will proxy to the composed input filter.
     *
     * @return bool
     */
    public function isValid() -> boolean;

    /**
     * Retrieve the validated data
     *
     * By default, retrieves normalized values; pass one of the VALUES_*
     * constants to shape the behavior.
     *
     * @param  int $flag
     * @return array|object
     */
    public function getData(int flag = Zend\Form\FormInterface::VALUES_NORMALIZED) -> array|object;

    /**
     * Set the validation group (set of values to validate)
     *
     * Typically, proxies to the composed input filter
     *
     * @return FormInterface
     */
    public function setValidationGroup() -> <FormInterface>;

}
