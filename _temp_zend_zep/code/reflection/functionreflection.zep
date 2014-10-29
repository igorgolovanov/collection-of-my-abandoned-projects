/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection;

use ReflectionFunction;

class FunctionReflection extends ReflectionFunction implements ReflectionInterface
{
    /**
     * Constant use in @FunctionReflection to display prototype as an array
     */
    const PROTOTYPE_AS_ARRAY = "prototype_as_array";

    /**
     * Constant use in @FunctionReflection to display prototype as a string
     */
    const PROTOTYPE_AS_STRING = "prototype_as_string";

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
