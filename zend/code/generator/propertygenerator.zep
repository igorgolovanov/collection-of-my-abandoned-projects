/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

class PropertyGenerator extends AbstractMemberGenerator implements GeneratorInterface
{
    const FLAG_CONSTANT = 8;

    const FLAG_ABSTRACT = 1;

    const FLAG_FINAL = 2;

    const FLAG_STATIC = 4;

    const FLAG_PUBLIC = 16;

    const FLAG_PROTECTED = 32;

    const FLAG_PRIVATE = 64;

    const VISIBILITY_PUBLIC = "public";

    const VISIBILITY_PROTECTED = "protected";

    const VISIBILITY_PRIVATE = "private";

    const LINE_FEED = "
";

    /**
     * @var bool
     */
    protected isConst;

    /**
     * @var PropertyValueGenerator
     */
    protected defaultValue;

    /**
     * @param  PropertyReflection $reflectionProperty
     * @return PropertyGenerator
     */
    public static function fromReflection(reflectionProperty) -> <PropertyGenerator>
    {

    }

    /**
     * Generate from array
     *
     * @configkey name         string                                          [required] Class Name
     * @configkey const        bool
     * @configkey defaultvalue null|bool|string|int|float|array|ValueGenerator
     * @configkey flags        int
     * @configkey abstract     bool
     * @configkey final        bool
     * @configkey static       bool
     * @configkey visibility   string
     *
     * @throws Exception\InvalidArgumentException
     * @param  array $array
     * @return PropertyGenerator
     */
    public static function fromArray(array! $array) -> <PropertyGenerator>
    {

    }

    /**
     * @param string $name
     * @param PropertyValueGenerator|string|array $defaultValue
     * @param int $flags
     */
    public function __construct(string name = null, var defaultValue = null, int flags = self::FLAG_PUBLIC)
    {

    }

    /**
     * @param  bool $const
     * @return PropertyGenerator
     */
    public function setConst(boolean $const) -> <PropertyGenerator>
    {

    }

    /**
     * @return bool
     */
    public function isConst() -> boolean
    {

    }

    /**
     * @param PropertyValueGenerator|mixed $defaultValue
     * @param string                       $defaultValueType
     * @param string                       $defaultValueOutputMode
     *
     * @return PropertyGenerator
     */
    public function setDefaultValue(defaultValue, string defaultValueType = Zend\Code\Generator\PropertyValueGenerator::TYPE_AUTO, string defaultValueOutputMode = Zend\Code\Generator\PropertyValueGenerator::OUTPUT_MULTIPLE_LINE) -> <PropertyGenerator>
    {

    }

    /**
     * @return PropertyValueGenerator
     */
    public function getDefaultValue() -> <PropertyValueGenerator>
    {

    }

    /**
     * @throws Exception\RuntimeException
     * @return string
     */
    public function generate() -> string
    {

    }

}
