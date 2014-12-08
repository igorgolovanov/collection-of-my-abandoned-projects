/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

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
    protected parameters = [];

    /**
     * @param  string|null $name
     * @return InjectionMethod
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
    public function addParameter(string name, var $class = null, var isRequired = null, var defaultVal = null) -> <InjectionMethod>
    {
        var param = [];

        let param[] = name;
        let param[] = $class;
        let param[] = self::detectMethodRequirement(isRequired);
        let param[] = defaultVal;

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
    public static function detectMethodRequirement(var requirement) -> int
    {
        int result = 0;
        string type, req;

        let type = typeof requirement;

        if type == "boolean" {
            if requirement {
                return Di::METHOD_IS_REQUIRED;
            }
            return Di::METHOD_IS_OPTIONAL;
        }

        if requirement === null {
            //This is mismatch to ClassDefinition::addMethod is it ok ? is optional?
            return Di::METHOD_IS_REQUIRED;
        }

        if type == "integer" {
            return requirement;
        }

        if type == "string" {
            let req = strtolower(requirement);

            switch req {
                case "eager":
                    let result = Di::METHOD_IS_EAGER;
                    break;
                case "instantiator":
                    let result = Di::METHOD_IS_INSTANTIATOR;
                    break;
                case "constructor":
                    let result = Di::METHOD_IS_CONSTRUCTOR;
                    break;
                case "optional":
                    let result = Di::METHOD_IS_OPTIONAL;
                    break;
                case "aware":
                    let result = Di::METHOD_IS_AWARE;
                    break;
                case "required":
                case "require":
                default:
                    let result = Di::METHOD_IS_REQUIRED;
            }
        }
        return result;
    }

}
