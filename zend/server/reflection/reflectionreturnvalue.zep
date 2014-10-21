/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Reflection;

/**
 * Return value reflection
 *
 * Stores the return value type and description
 */
class ReflectionReturnValue
{
    /**
     * Return value type
     * @var string
     */
    protected type;

    /**
     * Return value description
     * @var string
     */
    protected description;

    /**
     * Constructor
     *
     * @param string $type Return value type
     * @param string $description Return value type
     */
    public function __construct(string type = "mixed", string description = "")
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

}
