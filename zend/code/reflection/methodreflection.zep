/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection;

use ReflectionMethod as PhpReflectionMethod;
use Zend\Code\Annotation\AnnotationManager;
use Zend\Code\Scanner\AnnotationScanner;
use Zend\Code\Scanner\CachingFileScanner;

class MethodReflection extends PhpReflectionMethod implements ReflectionInterface
{
    /**
     * Constant use in @MethodReflection to display prototype as an array
     */
    const PROTOTYPE_AS_ARRAY = "prototype_as_array";

    /**
     * Constant use in @MethodReflection to display prototype as a string
     */
    const PROTOTYPE_AS_STRING = "prototype_as_string";

    /**
     * @var AnnotationScanner
     */
    protected annotations;

    /**
     * Retrieve method DocBlock reflection
     *
     * @return DocBlockReflection|false
     */
    public function getDocBlock() -> <DocBlockReflection>
    {

    }

    /**
     * @param  AnnotationManager $annotationManager
     * @return AnnotationScanner
     */
    public function getAnnotations(annotationManager)
    {

    }

    /**
     * Get start line (position) of method
     *
     * @param  bool $includeDocComment
     * @return int
     */
    public function getStartLine(boolean includeDocComment = false) -> int
    {

    }

    /**
     * Get reflection of declaring class
     *
     * @return ClassReflection
     */
    public function getDeclaringClass() -> <ClassReflection>
    {

    }

    /**
     * Get method prototype
     *
     * @return array
     */
    public function getPrototype(format = Zend\Code\Reflection\MethodReflection::PROTOTYPE_AS_ARRAY) -> array
    {

    }

    /**
     * Get all method parameter reflection objects
     *
     * @return ParameterReflection[]
     */
    public function getParameters() -> array
    {

    }

    /**
     * Get method contents
     *
     * @param  bool $includeDocBlock
     * @return string|bool
     */
    public function getContents(boolean includeDocBlock = true) -> string|boolean
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

    /**
     * Tokenize method string and return concatenated body
     *
     * @param bool $bodyOnly
     * @return string
     */
    protected function extractMethodContents(boolean bodyOnly = false) -> string
    {

    }

    /**
     * Take current position and find any whitespace
     *
     * @param $haystack
     * @param $position
     * @return string
     */
    protected function extractPrefixedWhitespace(haystack, position) -> string
    {

    }

    /**
     * Test for ending brace
     *
     * @param $haystack
     * @param $position
     * @return bool
     */
    protected function isEndingBrace(haystack, position) -> boolean
    {

    }

    /**
     * Test to see if current position is valid function or
     * closure.  Returns true if it's a function and NOT a closure
     *
     * @param $haystack
     * @param $position
     * @return bool
     */
    protected function isValidFunction(haystack, position, functionName = null) -> boolean
    {

    }

    public function toString()
    {

    }

    public function __toString()
    {

    }

    /**
     * Creates a new FileScanner instance.
     *
     * By having this as a seperate method it allows the method to be overridden
     * if a different FileScanner is needed.
     *
     * @param  string $filename
     *
     * @return CachingFileScanner
     */
    protected function createFileScanner(string filename)
    {

    }

}
