/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di\Definition;

/**
 * Class definitions based on a set of directories to be scanned
 */
class CompilerDefinition implements DefinitionInterface
{
    protected isCompiled = false;

    protected introspectionStrategy;

    protected allowReflectionExceptions = false;

    /**
     * @var AggregateDirectoryScanner
     */
    protected directoryScanner;

    protected classes; // []

    /**
     * Constructor
     *
     * @param null|IntrospectionStrategy $introspectionStrategy
     */
    public function __construct(<IntrospectionStrategy> introspectionStrategy = null)
    {

    }

    /**
     * Set introspection strategy
     *
     * @param IntrospectionStrategy $introspectionStrategy
     */
    public function setIntrospectionStrategy(<IntrospectionStrategy> introspectionStrategy)
    {

    }

    /**
     * @param bool $allowReflectionExceptions
     */
    public function setAllowReflectionExceptions(boolean allowReflectionExceptions = true)
    {

    }

    /**
     * Get introspection strategy
     *
     * @return IntrospectionStrategy
     */
    public function getIntrospectionStrategy() -> <IntrospectionStrategy>
    {

    }

    /**
     * Add directory
     *
     * @param string $directory
     */
    public function addDirectory(string directory)
    {

    }

    /**
     * Add directory scanner
     *
     * @param DirectoryScanner $directoryScanner
     */
    public function addDirectoryScanner(directoryScanner)
    {

    }

    /**
     * Add code scanner file
     *
     * @param FileScanner $fileScanner
     */
    public function addCodeScannerFile(fileScanner)
    {

    }

    /**
     * Compile
     *
     * @return void
     */
    public function compile() -> void
    {

    }

    /**
     * @return ArrayDefinition
     */
    public function toArrayDefinition() -> <ArrayDefinition>
    {

    }

    /**
     * @param  string               $class
     * @throws \ReflectionException
     */
    protected function processClass(string $class)
    {

    }

    /**
     * @param array                                  $def
     * @param \Zend\Code\Reflection\ClassReflection  $rClass
     * @param \Zend\Code\Reflection\MethodReflection $rMethod
     */
    protected function processParams(array def, <\Zend\Code\Reflection\ClassReflection> rClass, <\Zend\Code\Reflection\MethodReflection> rMethod)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function getClasses()
    {

    }

    /**
     * {@inheritDoc}
     */
    public function hasClass($class)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function getClassSupertypes($class)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function getInstantiator($class)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function hasMethods($class)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function hasMethod($class, method)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function getMethods($class)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function hasMethodParameters($class, method)
    {

    }

    /**
     * {@inheritDoc}
     */
    public function getMethodParameters($class, method)
    {

    }

}
