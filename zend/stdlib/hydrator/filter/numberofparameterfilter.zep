/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Filter;

use ReflectionException;
use ReflectionMethod;
use Zend\Stdlib\Exception\InvalidArgumentException;

class NumberOfParameterFilter implements FilterInterface
{
    /**
     * The number of parameters beeing accepted

     * @var int
     */
    protected numberOfParameters;

    /**
     * @param int $numberOfParameters Number of accepted parameters
     */
    public function __construct(int numberOfParameters = 0)
    {
        let this->numberOfParameters = numberOfParameters;
    }

    /**
     * @param string $property the name of the property
     * @return bool
     * @throws InvalidArgumentException
     */
    public function filter(string property) -> boolean
    {
        var exception, reflectionMethod;
        int numberOfParameters;

        try {
            let reflectionMethod = new ReflectionMethod(property);
        } catch (ReflectionException exception) {
            throw new InvalidArgumentException(
                "Method $property doesn't exist"
            );
        }

        let numberOfParameters = reflectionMethod->getNumberOfParameters();

        return numberOfParameters === this->numberOfParameters;
    }

}
