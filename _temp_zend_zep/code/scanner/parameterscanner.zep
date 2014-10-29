/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class ParameterScanner
{
    /**
     * @var bool
     */
    protected isScanned = false;

    /**
     * @var null|ClassScanner
     */
    protected declaringScannerClass;

    /**
     * @var null|string
     */
    protected declaringClass;

    /**
     * @var null|MethodScanner
     */
    protected declaringScannerFunction;

    /**
     * @var null|string
     */
    protected declaringFunction;

    /**
     * @var null|string
     */
    protected defaultValue;

    /**
     * @var null|string
     */
    protected $class;

    /**
     * @var null|string
     */
    protected name;

    /**
     * @var null|int
     */
    protected position;

    /**
     * @var bool
     */
    protected isArray = false;

    /**
     * @var bool
     */
    protected isDefaultValueAvailable = false;

    /**
     * @var bool
     */
    protected isOptional = false;

    /**
     * @var bool
     */
    protected isPassedByReference = false;

    /**
     * @var array|null
     */
    protected tokens;

    /**
     * @var null|NameInformation
     */
    protected nameInformation;

    /**
     * @param  array $parameterTokens
     * @param  NameInformation $nameInformation
     */
    public function __construct(array! parameterTokens, nameInformation = null)
    {

    }

    /**
     * Set declaring class
     *
     * @param  string $class
     * @return void
     */
    public function setDeclaringClass(string $class) -> void
    {

    }

    /**
     * Set declaring scanner class
     *
     * @param  ClassScanner $scannerClass
     * @return void
     */
    public function setDeclaringScannerClass(<ClassScanner> scannerClass) -> void
    {

    }

    /**
     * Set declaring function
     *
     * @param  string $function
     * @return void
     */
    public function setDeclaringFunction(string $function) -> void
    {

    }

    /**
     * Set declaring scanner function
     *
     * @param  MethodScanner $scannerFunction
     * @return void
     */
    public function setDeclaringScannerFunction(<MethodScanner> scannerFunction) -> void
    {

    }

    /**
     * Set position
     *
     * @param  int $position
     * @return void
     */
    public function setPosition(int position) -> void
    {

    }

    /**
     * Scan
     *
     * @return void
     */
    protected function scan() -> void
    {

    }

    /**
     * Get declaring scanner class
     *
     * @return ClassScanner
     */
    public function getDeclaringScannerClass() -> <ClassScanner>
    {

    }

    /**
     * Get declaring class
     *
     * @return string
     */
    public function getDeclaringClass() -> string
    {

    }

    /**
     * Get declaring scanner function
     *
     * @return MethodScanner
     */
    public function getDeclaringScannerFunction() -> <MethodScanner>
    {

    }

    /**
     * Get declaring function
     *
     * @return string
     */
    public function getDeclaringFunction() -> string
    {

    }

    /**
     * Get default value
     *
     * @return string
     */
    public function getDefaultValue() -> string
    {

    }

    /**
     * Get class
     *
     * @return string
     */
    public function getClass() -> string
    {

    }

    /**
     * Get name
     *
     * @return string
     */
    public function getName() -> string
    {

    }

    /**
     * Get position
     *
     * @return int
     */
    public function getPosition() -> int
    {

    }

    /**
     * Check if is array
     *
     * @return bool
     */
    public function isArray() -> boolean
    {

    }

    /**
     * Check if default value is available
     *
     * @return bool
     */
    public function isDefaultValueAvailable() -> boolean
    {

    }

    /**
     * Check if is optional
     *
     * @return bool
     */
    public function isOptional() -> boolean
    {

    }

    /**
     * Check if is passed by reference
     *
     * @return bool
     */
    public function isPassedByReference() -> boolean
    {

    }

}
