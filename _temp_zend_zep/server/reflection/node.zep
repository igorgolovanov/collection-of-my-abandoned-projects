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
    public function __construct(var value, <Node> parent = null) -> void
    {
        let this->value = value;
        if parent !== null {
            this->setParent(parent, true);
        }
    }

    /**
     * Set parent node
     *
     * @param \Zend\Server\Reflection\Node $node
     * @param  bool $new Whether or not the child node is newly created
     * and should always be attached
     * @return void
     */
    public function setParent(<Node> node, boolean $new = false) -> void
    {
        let this->parent = node;

        if $new {
            node->attachChild(this);
        }
    }

    /**
     * Create and attach a new child node
     *
     * @param mixed $value
     * @access public
     * @return \Zend\Server\Reflection\Node New child node
     */
    public function createChild(var value) -> <Node>
    {
        string className;
        var instance;

        let className = get_called_class();
        let instance = <Node> new {className}(value, this);

        return instance;
    }

    /**
     * Attach a child node
     *
     * @param \Zend\Server\Reflection\Node $node
     * @return void
     */
    public function attachChild(<Node> node) -> void
    {
        var parent;

        let this->children[] = node;
        let parent = node->getParent();

        if parent !== this {
            node->setParent(this);
        }
    }

    /**
     * Return an array of all child nodes
     *
     * @return array
     */
    public function getChildren() -> array
    {
        return this->children;
    }

    /**
     * Does this node have children?
     *
     * @return bool
     */
    public function hasChildren() -> boolean
    {
        int count;
        let count = count(this->children);

        return count > 0;
    }

    /**
     * Return the parent node
     *
     * @return null|\Zend\Server\Reflection\Node
     */
    public function getParent() -> <Node>
    {
        return this->parent;
    }

    /**
     * Return the node's current value
     *
     * @return mixed
     */
    public function getValue()
    {
        return this->value;
    }

    /**
     * Set the node value
     *
     * @param mixed $value
     * @return void
     */
    public function setValue(var value) -> void
    {
        let this->value = value;
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
        array endPoints = [], childEndPoints;
        var child, value;

        if !this->hasChildren() {
            return endPoints;
        }

        for child in this->children {
            let value = child->getValue();

            if value === null {
                let endPoints[] = this;
                continue;
            }

            if child->hasChildren() {
                let childEndPoints = child->getEndPoints();
                if !empty childEndPoints {
                    let endPoints = array_merge(endPoints, childEndPoints);
                }
                continue;
            } else {
                let endPoints[] = child;
            }
        }

        return endPoints;
    }

}
