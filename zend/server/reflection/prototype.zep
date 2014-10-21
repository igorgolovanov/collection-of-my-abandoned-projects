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

    /**
     * Constructor
     *
     * @param ReflectionReturnValue $return
     * @param ReflectionParameter[] $params
     * @throws Exception\InvalidArgumentException
     */
    public function __construct(<ReflectionReturnValue> return, array! params = [])
    {

    }

    /**
     * Retrieve return type
     *
     * @return string
     */
    public function getReturnType() -> string
    {

    }

    /**
     * Retrieve the return value object
     *
     * @return \Zend\Server\Reflection\ReflectionReturnValue
     */
    public function getReturnValue() -> <ReflectionReturnValue>
    {

    }

    /**
     * Retrieve method parameters
     *
     * @return ReflectionParameter[] Array of {@link \Zend\Server\Reflection\ReflectionParameter}s
     */
    public function getParameters() -> array
    {

    }

}
