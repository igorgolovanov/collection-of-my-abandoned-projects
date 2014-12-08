/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\InputFilter;

// todo: types

interface InputInterface
{
    public function setAllowEmpty(allowEmpty);

    public function setBreakOnFailure(breakOnFailure);

    public function setErrorMessage(errorMessage);

    public function setFilterChain(filterChain);

    public function setName(name);

    public function setRequired(required);

    public function setValidatorChain(validatorChain);

    public function setValue(value);

    public function merge(input);

    public function allowEmpty();

    public function breakOnFailure();

    public function getErrorMessage();

    public function getFilterChain();

    public function getName();

    public function getRawValue();

    public function isRequired();

    public function getValidatorChain();

    public function getValue();

    public function isValid();

    public function getMessages();

}
