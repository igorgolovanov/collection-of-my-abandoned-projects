/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Reflection;

/**
 * Parameter Reflection
 *
 * Decorates a ReflectionParameter to allow setting the parameter type
 */
class ReflectionParameter
{
    /**
     * @var \ReflectionParameter
     */
    protected reflection;

    /**
     * Parameter position
     * @var int
     */
    protected position;

    /**
     * Parameter type
     * @var string
     */
    protected type;

    /**
     * Parameter description
     * @var string
     */
    protected description;

    /**
     * Constructor
     *
     * @param \ReflectionParameter $r
     * @param string $type Parameter type
     * @param string $description Parameter description
     */
    public function __construct(<ReflectionParameter> r, string type = "mixed", string description = "")
    {
        let this->reflection = r;
    
        this->setType(type);
        this->setDescription(description);
    }

    /**
     * Proxy reflection calls
     *
     * @param string $method
     * @param array $args
     * @throws Exception\BadMethodCallException
     * @return mixed
     */
    public function __call(string method, array args)
    {
        var reflection, result;
        array callback;

        let reflection = <\ReflectionParameter> this->reflection;

        if unlikely !method_exists(reflection, method) {
            throw new Exception\BadMethodCallException("Invalid reflection method");
        }
        let callback = [reflection, method];
        let result = call_user_func_array(callback, args);

        return result;
    }

    /**
     * Retrieve parameter type
     *
     * @return string
     */
    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Set parameter type
     *
     * @param string|null $type
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public function setType(string type) -> void
    {
        if unlikely typeof type != "string" && type !== null {
            throw new Exception\InvalidArgumentException("Invalid parameter type"); 
        }
        let this->type = type;
    }

    /**
     * Retrieve parameter description
     *
     * @return string
     */
    public function getDescription() -> string
    {
        return this->description;
    }

    /**
     * Set parameter description
     *
     * @param string|null $description
     * @throws Exception\InvalidArgumentException
     * @return void
     */
    public function setDescription(string description) -> void
    {
        if unlikely typeof description != "string" && description !== null {
            throw new Exception\InvalidArgumentException("Invalid parameter description"); 
        }
        let this->description = description;
    }

    /**
     * Set parameter position
     *
     * @param int $index
     * @return void
     */
    public function setPosition(int index) -> void
    {
        let this->position = index;
    }

    /**
     * Return parameter position
     *
     * @return int
     */
    public function getPosition() -> int
    {
        return this->position;
    }

}
