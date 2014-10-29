/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\InputFilter;

interface InputFilterInterface extends \Countable
{
    const VALIDATE_ALL = "INPUT_FILTER_ALL";

    /**
     * Add an input to the input filter
     *
     * @param  InputInterface|InputFilterInterface|array $input
     * @param  null|string $name Name used to retrieve this input
     * @return InputFilterInterface
     */
    public function add(var input, var name = null) -> <InputFilterInterface>;

    /**
     * Retrieve a named input
     *
     * @param  string $name
     * @return InputInterface|InputFilterInterface
     */
    public function get(string name) -> <InputInterface>|<InputFilterInterface>;

    /**
     * Test if an input or input filter by the given name is attached
     *
     * @param  string $name
     * @return bool
     */
    public function has(string name) -> boolean;

    /**
     * Remove a named input
     *
     * @param  string $name
     * @return InputFilterInterface
     */
    public function remove(string name) -> <InputFilterInterface>;

    /**
     * Set data to use when validating and filtering
     *
     * @param  array|Traversable $data
     * @return InputFilterInterface
     */
    public function setData(var data) -> <InputFilterInterface>;

    /**
     * Is the data set valid?
     *
     * @return bool
     */
    public function isValid() -> boolean;

    /**
     * Provide a list of one or more elements indicating the complete set to validate
     *
     * When provided, calls to {@link isValid()} will only validate the provided set.
     *
     * If the initial value is {@link VALIDATE_ALL}, the current validation group, if
     * any, should be cleared.
     *
     * Implementations should allow passing a single array value, or multiple arguments,
     * each specifying a single input.
     *
     * @param  mixed $name
     * @return InputFilterInterface
     */
    public function setValidationGroup(var name) -> <InputFilterInterface>;

    /**
     * Return a list of inputs that were invalid.
     *
     * Implementations should return an associative array of name/input pairs
     * that failed validation.
     *
     * @return InputInterface[]
     */
    public function getInvalidInput() -> array;

    /**
     * Return a list of inputs that were valid.
     *
     * Implementations should return an associative array of name/input pairs
     * that passed validation.
     *
     * @return InputInterface[]
     */
    public function getValidInput() -> array;

    /**
     * Retrieve a value from a named input
     *
     * @param  string $name
     * @return mixed
     */
    public function getValue(string name);

    /**
     * Return a list of filtered values
     *
     * List should be an associative array, with the values filtered. If
     * validation failed, this should raise an exception.
     *
     * @return array
     */
    public function getValues() -> array;

    /**
     * Retrieve a raw (unfiltered) value from a named input
     *
     * @param  string $name
     * @return mixed
     */
    public function getRawValue(string name);

    /**
     * Return a list of unfiltered values
     *
     * List should be an associative array of named input/value pairs,
     * with the values unfiltered.
     *
     * @return array
     */
    public function getRawValues() -> array;

    /**
     * Return a list of validation failure messages
     *
     * Should return an associative array of named input/message list pairs.
     * Pairs should only be returned for inputs that failed validation.
     *
     * @return array
     */
    public function getMessages() -> array;

}
