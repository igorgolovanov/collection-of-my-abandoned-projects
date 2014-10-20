/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di\Definition\Builder;

use Zend\Di\Di;

/**
 * Definitions for an injection endpoint method
 */
class InjectionMethod
{
    /**
     * @var string|null
     */
    protected name;

    /**
     * @var array
     */
    protected parameters; // []

    /**
     * @param  string|null $name
     * @return self
     */
    public function setName(string name) -> <InjectionMethod>
    {
        let this->name = name;
        return this;
    }

    /**
     * @return null|string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * @param  string          $name
     * @param  string|null     $class
     * @param  mixed|null      $isRequired
     * @param  mixed|null      $default
     * @return InjectionMethod
     */
    public function addParameter(string name, string $class = null, isRequired = null, $default = null) -> <InjectionMethod>
    {
        array param = [];

        let param[] = name;
        let param[] = $class;
        let param[] = self::detectMethodRequirement(isRequired);
        let param[] = $default;

        let this->parameters[] = param;

        return this;
    }

    /**
     * @return array
     */
    public function getParameters() -> array
    {
        return this->parameters;
    }

    /**
     *
     * @param mixed $requirement
     * @return int
     */
    public static function detectMethodRequirement(requirement) -> int
    {
        string type;
        int result = 0;

        // todo
        return result;
    }

}
