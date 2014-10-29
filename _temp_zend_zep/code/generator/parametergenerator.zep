/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

class ParameterGenerator extends AbstractGenerator implements GeneratorInterface
{
    const LINE_FEED = "
";

    /**
     * @var string
     */
    protected name;

    /**
     * @var string
     */
    protected type;

    /**
     * @var string|ValueGenerator
     */
    protected defaultValue;

    /**
     * @var int
     */
    protected position;

    /**
     * @var bool
     */
    protected passedByReference = false;

    /**
     * @var array
     */
    protected static simple; // ["int", "bool", "string", "float", "resource", "mixed", "object"]

    /**
     * @param  ParameterReflection $reflectionParameter
     * @return ParameterGenerator
     */
    public static function fromReflection(reflectionParameter) -> <ParameterGenerator>
    {

    }

    /**
     * Generate from array
     *
     * @configkey name              string                                          [required] Class Name
     * @configkey type              string
     * @configkey defaultvalue      null|bool|string|int|float|array|ValueGenerator
     * @configkey passedbyreference bool
     * @configkey position          int
     * @configkey sourcedirty       bool
     * @configkey indentation       string
     * @configkey sourcecontent     string
     *
     * @throws Exception\InvalidArgumentException
     * @param  array $array
     * @return ParameterGenerator
     */
    public static function fromArray(array! $array) -> <ParameterGenerator>
    {

    }

    /**
     * @param  string $name
     * @param  string $type
     * @param  mixed $defaultValue
     * @param  int $position
     * @param  bool $passByReference
     */
    public function __construct(string name = null, string type = null, defaultValue = null, int position = null, boolean passByReference = false)
    {

    }

    /**
     * @param  string $type
     * @return ParameterGenerator
     */
    public function setType(string type) -> <ParameterGenerator>
    {

    }

    /**
     * @return string
     */
    public function getType() -> string
    {

    }

    /**
     * @param  string $name
     * @return ParameterGenerator
     */
    public function setName(string name) -> <ParameterGenerator>
    {

    }

    /**
     * @return string
     */
    public function getName() -> string
    {

    }

    /**
     * Set the default value of the parameter.
     *
     * Certain variables are difficult to express
     *
     * @param  null|bool|string|int|float|array|ValueGenerator $defaultValue
     * @return ParameterGenerator
     */
    public function setDefaultValue(var defaultValue) -> <ParameterGenerator>
    {

    }

    /**
     * @return string
     */
    public function getDefaultValue() -> string
    {

    }

    /**
     * @param  int $position
     * @return ParameterGenerator
     */
    public function setPosition(int position) -> <ParameterGenerator>
    {

    }

    /**
     * @return int
     */
    public function getPosition() -> int
    {

    }

    /**
     * @return bool
     */
    public function getPassedByReference() -> boolean
    {

    }

    /**
     * @param  bool $passedByReference
     * @return ParameterGenerator
     */
    public function setPassedByReference(boolean passedByReference) -> <ParameterGenerator>
    {

    }

    /**
     * @return string
     */
    public function generate() -> string
    {

    }

}
