/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Form;

interface ElementInterface
{
    /**
     * Set the name of this element
     *
     * In most cases, this will proxy to the attributes for storage, but is
     * present to indicate that elements are generally named.
     *
     * @param  string $name
     * @return ElementInterface
     */
    public function setName(string name) -> <ElementInterface>;

    /**
     * Retrieve the element name
     *
     * @return string
     */
    public function getName() -> string;

    /**
     * Set options for an element
     *
     * @param  array|\Traversable $options
     * @return ElementInterface
     */
    public function setOptions(var options) -> <ElementInterface>;

    /**
     * Set a single option for an element
     *
     * @param  string $key
     * @param  mixed $value
     * @return self
     */
    public function setOption(string key, value) -> <ElementInterface>;

    /**
     * get the defined options
     *
     * @return array
     */
    public function getOptions() -> array;

    /**
     * return the specified option
     *
     * @param string $option
     * @return null|mixed
     */
    public function getOption(string option);

    /**
     * Set a single element attribute
     *
     * @param  string $key
     * @param  mixed $value
     * @return ElementInterface
     */
    public function setAttribute(string key, value) -> <ElementInterface>;

    /**
     * Retrieve a single element attribute
     *
     * @param  string $key
     * @return mixed
     */
    public function getAttribute(string key);

    /**
     * Return true if a specific attribute is set
     *
     * @param  string $key
     * @return bool
     */
    public function hasAttribute(string key) -> boolean;

    /**
     * Set many attributes at once
     *
     * Implementation will decide if this will overwrite or merge.
     *
     * @param  array|\Traversable $arrayOrTraversable
     * @return ElementInterface
     */
    public function setAttributes(var arrayOrTraversable) -> <ElementInterface>;

    /**
     * Retrieve all attributes at once
     *
     * @return array|\Traversable
     */
    public function getAttributes() -> array|<\Traversable>;

    /**
     * Set the value of the element
     *
     * @param  mixed $value
     * @return ElementInterface
     */
    public function setValue(value) -> <ElementInterface>;

    /**
     * Retrieve the element value
     *
     * @return mixed
     */
    public function getValue();

    /**
     * Set the label (if any) used for this element
     *
     * @param  $label
     * @return ElementInterface
     */
    public function setLabel(label) -> <ElementInterface>;

    /**
     * Retrieve the label (if any) used for this element
     *
     * @return string
     */
    public function getLabel() -> string;

    /**
     * Set a list of messages to report when validation fails
     *
     * @param  array|\Traversable $messages
     * @return ElementInterface
     */
    public function setMessages(var messages) -> <ElementInterface>;

    /**
     * Get validation error messages, if any
     *
     * Returns a list of validation failure messages, if any.
     *
     * @return array|\Traversable
     */
    public function getMessages() -> array|<\Traversable>;

}
