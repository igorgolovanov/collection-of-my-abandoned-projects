/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Form;

interface LabelAwareInterface
{
    /**
     * Set the label (if any) used for this element
     *
     * @param  $label
     * @return ElementInterface
     */
    public function setLabel(string label) -> <ElementInterface>;

    /**
     * Retrieve the label (if any) used for this element
     *
     * @return string
     */
    public function getLabel() -> string;

    /**
     * Set the attributes to use with the label
     *
     * @param array $labelAttributes
     * @return self
     */
    public function setLabelAttributes(array! labelAttributes) -> <LabelAwareInterface>;

    /**
     * Get the attributes to use with the label
     *
     * @return array
     */
    public function getLabelAttributes() -> array;

    /**
     * Set many label options at once
     *
     * Implementation will decide if this will overwrite or merge.
     *
     * @param  array|\Traversable $arrayOrTraversable
     * @return self
     */
    public function setLabelOptions(var arrayOrTraversable) -> <LabelAwareInterface>;

    /**
     * Get label specific options
     *
     * @return array
     */
    public function getLabelOptions() -> array;

    /**
     * Set a single label optionn
     *
     * @param  string $key
     * @param  mixed  $value
     * @return Element|ElementInterface
     */
    public function setLabelOption(string key, value) -> <Element>|<ElementInterface>;

    /**
     * Retrieve a single label option
     *
     * @param  $key
     * @return mixed|null
     */
    public function getLabelOption(string key);

    /**
     * Remove a single label option
     *
     * @param string $key
     * @return ElementInterface
     */
    public function removeLabelOption(string key) -> <ElementInterface>;

    /**
     * Does the element has a specific label option ?
     *
     * @param  string $key
     * @return bool
     */
    public function hasLabelOption(string key) -> boolean;

    /**
     * Remove many attributes at once
     *
     * @param array $keys
     * @return ElementInterface
     */
    public function removeLabelOptions(array! keys) -> <ElementInterface>;

    /**
     * Clear all label options
     *
     * @return ElementInterface
     */
    public function clearLabelOptions() -> <ElementInterface>;

}
