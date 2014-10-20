
namespace Zend\Code\Reflection;

class FunctionReflection extends \ReflectionFunction implements \Reflector, ReflectionInterface
{
    const PROTOTYPE_AS_ARRAY = "prototype_as_array";

    const PROTOTYPE_AS_STRING = "prototype_as_string";

    const IS_DEPRECATED = 262144;

    /**
     * Get function DocBlock
     *
     * @throws Exception\InvalidArgumentException
     * @return DocBlockReflection
     */
    public function getDocBlock() -> <DocBlockReflection>
    {

    }

    /**
     * Get start line (position) of function
     *
     * @param  bool $includeDocComment
     * @return int
     */
    public function getStartLine(boolean includeDocComment = false) -> int
    {

    }

    /**
     * Get contents of function
     *
     * @param  bool   $includeDocBlock
     * @return string
     */
    public function getContents(boolean includeDocBlock = true) -> string
    {

    }

    /**
     * Get method prototype
     *
     * @return array
     */
    public function getPrototype(format = Zend\Code\Reflection\FunctionReflection::PROTOTYPE_AS_ARRAY) -> array
    {

    }

    /**
     * Get function parameters
     *
     * @return ParameterReflection[]
     */
    public function getParameters() -> array
    {

    }

    /**
     * Get return type tag
     *
     * @throws Exception\InvalidArgumentException
     * @return DocBlockReflection
     */
    public function getReturn() -> <DocBlockReflection>
    {

    }

    /**
     * Get method body
     *
     * @return string|bool
     */
    public function getBody() -> string|boolean
    {

    }

    public function toString()
    {

    }

    /**
     * Required due to bug in php
     *
     * @return string
     */
    public function __toString() -> string
    {

    }

}
