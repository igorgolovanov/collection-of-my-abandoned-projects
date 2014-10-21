/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Reflection;

/**
 * Method/Function prototypes
 *
 * Contains accessors for the return value and all method arguments.
 */
class Prototype
{
    /** @var ReflectionParameter[] */
    protected params;

    /** @var ReflectionReturnValue */
    protected $return;

    /**
     * Constructor
     *
     * @param ReflectionReturnValue $return
     * @param ReflectionParameter[] $params
     * @throws Exception\InvalidArgumentException
     */
    public function __construct(<ReflectionReturnValue> $return, array! params = [])
    {
        var param;

        let this->$return = $return;

        for param in params {
            if unlikely !(param instanceof ReflectionParameter) {
                throw new Exception\InvalidArgumentException("One or more params are invalid");
            }
        }
        let this->params = params;
    }

    /**
     * Retrieve return type
     *
     * @return string
     */
    public function getReturnType() -> string
    {
        var refl;
        string type;

        let refl = <ReflectionReturnValue> this->$return;
        let type = refl->getType();

        return type;
    }

    /**
     * Retrieve the return value object
     *
     * @return \Zend\Server\Reflection\ReflectionReturnValue
     */
    public function getReturnValue() -> <ReflectionReturnValue>
    {
        return this->$return;
    }

    /**
     * Retrieve method parameters
     *
     * @return ReflectionParameter[] Array of {@link \Zend\Server\Reflection\ReflectionParameter}s
     */
    public function getParameters() -> array
    {
        return this->params;
    }

}
