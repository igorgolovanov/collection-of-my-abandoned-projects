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
        this->setType(type);
        this->setDescription(description);
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
    public function setType(var type) -> void
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
    public function setDescription(var description) -> void
    {
        if unlikely typeof description != "string" && description !== null {
            throw new Exception\InvalidArgumentException("Invalid parameter description"); 
        }
        let this->description = description;
    }

}
