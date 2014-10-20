/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

class MethodGenerator extends AbstractMemberGenerator implements GeneratorInterface
{
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
     * @var DocBlockGenerator
     */
    protected docBlock;

    /**
     * @var ParameterGenerator[]
     */
    protected parameters; // []

    /**
     * @var string
     */
    protected body;

    /**
     * @param  MethodReflection $reflectionMethod
     * @return MethodGenerator
     */
    public static function fromReflection(reflectionMethod) -> <MethodGenerator>
    {

    }

    /**
     * Generate from array
     *
     * @configkey name           string        [required] Class Name
     * @configkey docblock       string        The docblock information
     * @configkey flags          int           Flags, one of MethodGenerator::FLAG_ABSTRACT MethodGenerator::FLAG_FINAL
     * @configkey parameters     string        Class which this class is extending
     * @configkey body           string
     * @configkey abstract       bool
     * @configkey final          bool
     * @configkey static         bool
     * @configkey visibility     string
     *
     * @throws Exception\InvalidArgumentException
     * @param  array $array
     * @return MethodGenerator
     */
    public static function fromArray(array! $array) -> <MethodGenerator>
    {

    }

    /**
     * @param  string $name
     * @param  array $parameters
     * @param  int $flags
     * @param  string $body
     * @param  DocBlockGenerator|string $docBlock
     */
    public function __construct(string name = null, array! parameters = [], int flags = self::FLAG_PUBLIC, string body = null, var docBlock = null)
    {

    }

    /**
     * @param  array $parameters
     * @return MethodGenerator
     */
    public function setParameters(array! parameters) -> <MethodGenerator>
    {

    }

    /**
     * @param  ParameterGenerator|string $parameter
     * @throws Exception\InvalidArgumentException
     * @return MethodGenerator
     */
    public function setParameter(var parameter) -> <MethodGenerator>
    {

    }

    /**
     * @return ParameterGenerator[]
     */
    public function getParameters() -> array
    {

    }

    /**
     * @param  string $body
     * @return MethodGenerator
     */
    public function setBody(string body) -> <MethodGenerator>
    {

    }

    /**
     * @return string
     */
    public function getBody() -> string
    {

    }

    /**
     * @return string
     */
    public function generate() -> string
    {

    }

    public function __toString()
    {

    }

}
