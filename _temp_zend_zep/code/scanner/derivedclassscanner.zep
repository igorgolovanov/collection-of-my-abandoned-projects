/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class DerivedClassScanner extends ClassScanner implements ScannerInterface
{
    /**
     * @var DirectoryScanner
     */
    protected directoryScanner;

    /**
     * @var ClassScanner
     */
    protected classScanner;

    /**
     * @var array
     */
    protected parentClassScanners; // []

    /**
     * @var array
     */
    protected interfaceClassScanners; // []

    /**
     * @param ClassScanner $classScanner
     * @param DirectoryScanner $directoryScanner
     */
    public function __construct(<ClassScanner> classScanner, <DirectoryScanner> directoryScanner)
    {

    }

    /**
     * @return null|string
     */
    public function getName() -> string
    {

    }

    /**
     * @return null|string
     */
    public function getShortName() -> string
    {

    }

    /**
     * @return bool
     */
    public function isInstantiable() -> boolean
    {

    }

    /**
     * @return bool
     */
    public function isFinal() -> boolean
    {

    }

    /**
     * @return bool
     */
    public function isAbstract() -> boolean
    {

    }

    /**
     * @return bool
     */
    public function isInterface() -> boolean
    {

    }

    /**
     * @return array
     */
    public function getParentClasses() -> array
    {

    }

    /**
     * @return bool
     */
    public function hasParentClass() -> boolean
    {

    }

    /**
     * @return null|string
     */
    public function getParentClass() -> string
    {

    }

    /**
     * @param  bool $returnClassScanners
     * @return array
     */
    public function getInterfaces(boolean returnClassScanners = false) -> array
    {

    }

    /**
     * Return a list of constant names
     *
     * @return array
     */
    public function getConstantNames() -> array
    {

    }

    /**
     * Return a list of constants
     *
     * @param  bool $namesOnly Set false to return instances of ConstantScanner
     * @return array|ConstantScanner[]
     */
    public function getConstants(boolean namesOnly = true) -> array
    {

    }

    /**
     * Return a single constant by given name or index of info
     *
     * @param  string|int $constantNameOrInfoIndex
     * @throws Exception\InvalidArgumentException
     * @return bool|ConstantScanner
     */
    public function getConstant(var constantNameOrInfoIndex) -> boolean|<ConstantScanner>
    {

    }

    /**
     * Verify if class or parent class has constant
     *
     * @param  string $name
     * @return bool
     */
    public function hasConstant(string name) -> boolean
    {

    }

    /**
     * Return a list of property names
     *
     * @return array
     */
    public function getPropertyNames() -> array
    {

    }

    /**
     * @param  bool $returnScannerProperty
     * @return array
     */
    public function getProperties(boolean returnScannerProperty = false) -> array
    {

    }

    /**
     * Return a single property by given name or index of info
     *
     * @param  string|int $propertyNameOrInfoIndex
     * @throws Exception\InvalidArgumentException
     * @return bool|PropertyScanner
     */
    public function getProperty(var propertyNameOrInfoIndex) -> boolean|<PropertyScanner>
    {

    }

    /**
     * Verify if class or parent class has property
     *
     * @param  string $name
     * @return bool
     */
    public function hasProperty(string name) -> boolean
    {

    }

    /**
     * @return array
     */
    public function getMethodNames() -> array
    {

    }

    /**
     * @return MethodScanner[]
     */
    public function getMethods() -> array
    {

    }

    /**
     * @param  int|string $methodNameOrInfoIndex
     * @return MethodScanner
     * @throws Exception\InvalidArgumentException
     */
    public function getMethod(var methodNameOrInfoIndex) -> <MethodScanner>
    {

    }

    /**
     * Verify if class or parent class has method by given name
     *
     * @param  string $name
     * @return bool
     */
    public function hasMethod(string name) -> boolean
    {

    }

}
