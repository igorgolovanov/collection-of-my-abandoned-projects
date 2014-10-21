/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Reflection;

/**
 * Node Tree class for Zend\Server reflection operations
 */
class Node
{
    /**
     * Node value
     * @var mixed
     */
    protected value;

    /**
     * Array of child nodes (if any)
     * @var array
     */
    protected children = [];

    /**
     * Parent node (if any)
     * @var \Zend\Server\Reflection\Node
     */
    protected parent;

    /**
     * Constructor
     *
     * @param mixed $value
     * @param \Zend\Server\Reflection\Node $parent Optional
     * @return \Zend\Server\Reflection\Node
     */
    public function __construct(value, <\Zend\Server\Reflection\Node> parent = null) -> <Node>
    {

    }

    /**
     * Set parent node
     *
     * @param \Zend\Server\Reflection\Node $node
     * @param  bool $new Whether or not the child node is newly created
     * and should always be attached
     * @return void
     */
    public function setParent(<\Zend\Server\Reflection\Node> node, boolean $new = false) -> void
    {

    }

    /**
     * Create and attach a new child node
     *
     * @param mixed $value
     * @access public
     * @return \Zend\Server\Reflection\Node New child node
     */
    public function createChild(value) -> <Node>
    {

    }

    /**
     * Attach a child node
     *
     * @param \Zend\Server\Reflection\Node $node
     * @return void
     */
    public function attachChild(<\Zend\Server\Reflection\Node> node) -> void
    {

    }

    /**
     * Return an array of all child nodes
     *
     * @return array
     */
    public function getChildren() -> array
    {

    }

    /**
     * Does this node have children?
     *
     * @return bool
     */
    public function hasChildren() -> boolean
    {

    }

    /**
     * Return the parent node
     *
     * @return null|\Zend\Server\Reflection\Node
     */
    public function getParent() -> <Node>
    {

    }

    /**
     * Return the node's current value
     *
     * @return mixed
     */
    public function getValue()
    {

    }

    /**
     * Set the node value
     *
     * @param mixed $value
     * @return void
     */
    public function setValue(value) -> void
    {

    }

    /**
     * Retrieve the bottommost nodes of this node's tree
     *
     * Retrieves the bottommost nodes of the tree by recursively calling
     * getEndPoints() on all children. If a child is null, it returns the parent
     * as an end point.
     *
     * @return array
     */
    public function getEndPoints() -> array
    {

    }

}
