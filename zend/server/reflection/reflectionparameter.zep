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

    }

    /**
     * Retrieve parameter type
     *
     * @return string
     */
    public function getType() -> string
    {

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

    }

    /**
     * Retrieve parameter description
     *
     * @return string
     */
    public function getDescription() -> string
    {

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

    }

    /**
     * Set parameter position
     *
     * @param int $index
     * @return void
     */
    public function setPosition(int index) -> void
    {

    }

    /**
     * Return parameter position
     *
     * @return int
     */
    public function getPosition() -> int
    {

    }

}
