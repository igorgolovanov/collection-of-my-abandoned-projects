/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Soap\Wsdl\ComplexTypeStrategy;

/**
 * Interface strategies that generate an XSD-Schema for complex data types in WSDL files.
 */
interface ComplexTypeStrategyInterface
{
    /**
     * Method accepts the current WSDL context file.
     *
     * @param Wsdl $context
     */
    public function setContext(var context); // todo: check Wsdl

    /**
     * Create a complex type based on a strategy
     *
     * @param  string $type
     * @return string XSD type
     */
    public function addComplexType(string type) -> string;

}
