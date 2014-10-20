/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

class ValueGenerator extends AbstractGenerator implements GeneratorInterface
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

    /**
     * @var mixed
     */
    protected value;

    /**
     * @var string
     */
    protected type = "auto";

    /**
     * @var int
     */
    protected arrayDepth = 0;

    /**
     * @var string
     */
    protected outputMode = "multipleLine";

    /**
     * @var array
     */
    protected allowedTypes;

    /**
     * Autodetectable constants
     * @var ArrayObject
     */
    protected constants;

    /**
     * @param mixed       $value
     * @param string      $type
     * @param string      $outputMode
     * @param ArrayObject $constants
     */
    public function __construct(value = null, string type = self::TYPE_AUTO, string outputMode = self::OUTPUT_MULTIPLE_LINE, <\ArrayObject> constants = null)
    {

    }

    /**
     * Init constant list by defined and magic constants
     */
    public function initEnvironmentConstants()
    {

    }

    /**
     * Add constant to list
     *
     * @param string $constant
     *
     * @return $this
     */
    public function addConstant(string constant)
    {

    }

    /**
     * Delete constant from constant list
     *
     * @param string $constant
     *
     * @return bool
     */
    public function deleteConstant(string constant) -> boolean
    {

    }

    /**
     * Return constant list
     *
     * @return ArrayObject
     */
    public function getConstants() -> <\ArrayObject>
    {

    }

    /**
     * @return bool
     */
    public function isValidConstantType() -> boolean
    {

    }

    /**
     * @param  mixed $value
     * @return ValueGenerator
     */
    public function setValue(value) -> <ValueGenerator>
    {

    }

    /**
     * @return mixed
     */
    public function getValue()
    {

    }

    /**
     * @param  string $type
     * @return ValueGenerator
     */
    public function setType(string type) -> <ValueGenerator>
    {

    }

    /**
     * @return string
     */
    public function getType() -> string
    {

    }

    /**
     * @param  int $arrayDepth
     * @return ValueGenerator
     */
    public function setArrayDepth(int arrayDepth) -> <ValueGenerator>
    {

    }

    /**
     * @return int
     */
    public function getArrayDepth() -> int
    {

    }

    /**
     * @param  string $type
     * @return string
     */
    protected function getValidatedType(string type) -> string
    {

    }

    /**
     * @param  mixed $value
     * @return string
     */
    public function getAutoDeterminedType(value) -> string
    {

    }

    /**
     * @throws Exception\RuntimeException
     * @return string
     */
    public function generate() -> string
    {

    }

    /**
     * Quotes value for PHP code.
     *
     * @param  string $input Raw string.
     * @param  bool $quote Whether add surrounding quotes or not.
     * @return string PHP-ready code.
     */
    public static function escape(string input, boolean quote = true) -> string
    {

    }

    /**
     * @param  string $outputMode
     * @return ValueGenerator
     */
    public function setOutputMode(string outputMode) -> <ValueGenerator>
    {

    }

    /**
     * @return string
     */
    public function getOutputMode() -> string
    {

    }

    public function __toString()
    {

    }

}
