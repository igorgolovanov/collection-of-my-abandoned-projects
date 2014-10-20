/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

class PropertyValueGenerator extends ValueGenerator implements GeneratorInterface
{
    const TYPE_AUTO = "auto";

    const TYPE_BOOLEAN = "boolean";

    const TYPE_BOOL = "bool";

    const TYPE_NUMBER = "number";

    const TYPE_INTEGER = "integer";

    const TYPE_INT = "int";

    const TYPE_FLOAT = "float";

    const TYPE_DOUBLE = "double";

    const TYPE_STRING = "string";

    const TYPE_ARRAY = "array";

    const TYPE_CONSTANT = "constant";

    const TYPE_NULL = "null";

    const TYPE_OBJECT = "object";

    const TYPE_OTHER = "other";

    const OUTPUT_MULTIPLE_LINE = "multipleLine";

    const OUTPUT_SINGLE_LINE = "singleLine";

    const LINE_FEED = "
";

    protected arrayDepth = 1;

    /**
     * @return string
     */
    public function generate() -> string
    {

    }

}
