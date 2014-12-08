/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\View\Model;

use IteratorAggregate;
use Countable;

/**
 * Interface describing a view model.
 *
 * Extends "Countable"; count() should return the number of children attached
 * to the model.
 *
 * Extends "IteratorAggregate"; should allow iterating over children.
 */
interface ModelInterface extends Countable, IteratorAggregate
{
    /**
     * Set renderer option/hint
     *
     * @param  string $name
     * @param  mixed $value
     * @return ModelInterface
     */
    public function setOption(string name, var value) -> <ModelInterface>;

    /**
     * Set renderer options/hints en masse
     *
     * @param  array|\Traversable $options
     * @return ModelInterface
     */
    public function setOptions(var options) -> <ModelInterface>;

    /**
     * Get renderer options/hints
     *
     * @return array|\Traversable
     */
    public function getOptions() -> array|<\Traversable>;

    /**
     * Get a single view variable
     *
     * @param  string       $name
     * @param  mixed|null   $default (optional) default value if the variable is not present.
     * @return mixed
     */
    public function getVariable(string name, var $default = null);

    /**
     * Set view variable
     *
     * @param  string $name
     * @param  mixed $value
     * @return ModelInterface
     */
    public function setVariable(string name, var value) -> <ModelInterface>;

    /**
     * Set view variables en masse
     *
     * @param  array|\ArrayAccess $variables
     * @return ModelInterface
     */
    public function setVariables(var variables) -> <ModelInterface>;

    /**
     * Get view variables
     *
     * @return array|\ArrayAccess
     */
    public function getVariables() -> array|<\ArrayAccess>;

    /**
     * Set the template to be used by this model
     *
     * @param  string $template
     * @return ModelInterface
     */
    public function setTemplate(string template) -> <ModelInterface>;

    /**
     * Get the template to be used by this model
     *
     * @return string
     */
    public function getTemplate() -> string;

    /**
     * Add a child model
     *
     * @param  ModelInterface $child
     * @param  null|string $captureTo Optional; if specified, the "capture to" value to set on the child
     * @param  null|bool $append Optional; if specified, append to child  with the same capture
     * @return ModelInterface
     */
    public function addChild(<ModelInterface> child, string captureTo = null, boolean append = false) -> <ModelInterface>;

    /**
     * Return all children.
     *
     * Return specifies an array, but may be any iterable object.
     *
     * @return array
     */
    public function getChildren() -> array;

    /**
     * Does the model have any children?
     *
     * @return bool
     */
    public function hasChildren() -> boolean;

    /**
     * Set the name of the variable to capture this model to, if it is a child model
     *
     * @param  string $capture
     * @return ModelInterface
     */
    public function setCaptureTo(string capture) -> <ModelInterface>;

    /**
     * Get the name of the variable to which to capture this model
     *
     * @return string
     */
    public function captureTo() -> string;

    /**
     * Set flag indicating whether or not this is considered a terminal or standalone model
     *
     * @param  bool $terminate
     * @return ModelInterface
     */
    public function setTerminal(boolean terminate) -> <ModelInterface>;

    /**
     * Is this considered a terminal or standalone model?
     *
     * @return bool
     */
    public function terminate() -> boolean;

    /**
     * Set flag indicating whether or not append to child  with the same capture
     *
     * @param  bool $append
     * @return ModelInterface
     */
    public function setAppend(boolean append) -> <ModelInterface>;

    /**
     * Is this append to child  with the same capture?
     *
     * @return bool
     */
    public function isAppend() -> boolean;

}
