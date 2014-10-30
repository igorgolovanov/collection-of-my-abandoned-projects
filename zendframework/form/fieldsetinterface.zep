/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Form;

use Zend\Stdlib\Hydrator\HydratorInterface;

interface FieldsetInterface extends \Countable, \IteratorAggregate, ElementInterface, ElementPrepareAwareInterface, FormFactoryAwareInterface
{
    /**
     * Add an element or fieldset
     *
     * $flags could contain metadata such as the alias under which to register
     * the element or fieldset, order in which to prioritize it, etc.
     *
     * @param  array|\Traversable|ElementInterface $elementOrFieldset Typically, only allow objects implementing ElementInterface;
     *                                                                however, keeping it flexible to allow a factory-based form
     *                                                                implementation as well
     * @param  array $flags
     * @return FieldsetInterface
     */
    public function add(var elementOrFieldset, array! flags = []) -> <FieldsetInterface>;

    /**
     * Does the fieldset have an element/fieldset by the given name?
     *
     * @param  string $elementOrFieldset
     * @return bool
     */
    public function has(string elementOrFieldset) -> boolean;

    /**
     * Retrieve a named element or fieldset
     *
     * @param  string $elementOrFieldset
     * @return ElementInterface
     */
    public function get(string elementOrFieldset) -> <ElementInterface>;

    /**
     * Remove a named element or fieldset
     *
     * @param  string $elementOrFieldset
     * @return FieldsetInterface
     */
    public function remove(string elementOrFieldset) -> <FieldsetInterface>;

    /**
     * Set/change the priority of an element or fieldset
     *
     * @param string $elementOrFieldset
     * @param int $priority
     * @return FieldsetInterface
     */
    public function setPriority(string elementOrFieldset, int priority) -> <FieldsetInterface>;

    /**
     * Retrieve all attached elements
     *
     * Storage is an implementation detail of the concrete class.
     *
     * @return array|\Traversable
     */
    public function getElements() -> array|<\Traversable>;

    /**
     * Retrieve all attached fieldsets
     *
     * Storage is an implementation detail of the concrete class.
     *
     * @return array|\Traversable
     */
    public function getFieldsets() -> array|<\Traversable>;

    /**
     * Recursively populate value attributes of elements
     *
     * @param  array|\Traversable $data
     * @return void
     */
    public function populateValues(var data) -> void;

    /**
     * Set the object used by the hydrator
     *
     * @param  $object
     * @return FieldsetInterface
     */
    public function setObject($object) -> <FieldsetInterface>;

    /**
     * Get the object used by the hydrator
     *
     * @return mixed
     */
    public function getObject();

    /**
     * Checks if the object can be set in this fieldset
     *
     * @param $object
     * @return bool
     */
    public function allowObjectBinding($object) -> boolean;

    /**
     * Set the hydrator to use when binding an object to the element
     *
     * @param  HydratorInterface $hydrator
     * @return FieldsetInterface
     */
    public function setHydrator(<HydratorInterface> hydrator) -> <FieldsetInterface>;

    /**
     * Get the hydrator used when binding an object to the element
     *
     * @return null|HydratorInterface
     */
    public function getHydrator() -> <HydratorInterface>|null;

    /**
     * Bind values to the bound object
     *
     * @param  array $values
     * @return mixed
     */
    public function bindValues(array! values = []);

    /**
     * Checks if this fieldset can bind data
     *
     * @return bool
     */
    public function allowValueBinding() -> boolean;

}
