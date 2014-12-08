/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\EventManager;

/**
 * Representation of an event
 */
interface EventInterface
{
    /**
     * Get event name
     *
     * @return string
     */
    public function getName() -> string;

    /**
     * Get target/context from which event was triggered
     *
     * @return null|string|object
     */
    public function getTarget() -> string|object;

    /**
     * Get parameters passed to the event
     *
     * @return array|ArrayAccess
     */
    public function getParams() -> array|<\ArrayAccess>;

    /**
     * Get a single parameter by name
     *
     * @param  string $name
     * @param  mixed $default Default value to return if parameter does not exist
     * @return mixed
     */
    public function getParam(string name, var $default = null);

    /**
     * Set the event name
     *
     * @param  string $name
     * @return void
     */
    public function setName(string name) -> void;

    /**
     * Set the event target/context
     *
     * @param  null|string|object $target
     * @return void
     */
    public function setTarget(var target) -> void;

    /**
     * Set event parameters
     *
     * @param  string $params
     * @return void
     */
    public function setParams(string params) -> void;

    /**
     * Set a single parameter by key
     *
     * @param  string $name
     * @param  mixed $value
     * @return void
     */
    public function setParam(string name, var value) -> void;

    /**
     * Indicate whether or not the parent EventManagerInterface should stop propagating events
     *
     * @param  bool $flag
     * @return void
     */
    public function stopPropagation(boolean flag = true) -> void;

    /**
     * Has this event indicated event propagation should stop?
     *
     * @return bool
     */
    public function propagationIsStopped() -> boolean;

}
