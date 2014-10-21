/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Method;

/**
 * Method prototype metadata
 */
class Prototype
{
    /**
     * @var string Return type
     */
    protected returnType = "void";

    /**
     * @var array Map parameter names to parameter index
     */
    protected parameterNameMap = [];

    /**
     * @var array Method parameters
     */
    protected parameters = [];

    /**
     * Constructor
     *
     * @param  null|array $options
     */
    public function __construct(var options = null)
    {
        if typeof options == "array" {
            this->setOptions(options);
        }
    }

    /**
     * Set return value
     *
     * @param  string $returnType
     * @return \Zend\Server\Method\Prototype
     */
    public function setReturnType(string returnType) -> self
    {
        let this->returnType = returnType;

        return this;
    }

    /**
     * Retrieve return type
     *
     * @return string
     */
    public function getReturnType() -> string
    {
        return this->returnType;
    }

    /**
     * Add a parameter
     *
     * @param  string $parameter
     * @return \Zend\Server\Method\Prototype
     */
    public function addParameter(var parameter) -> self
    {
        var name, data;
        string type;

        if parameter instanceof Parameter {
            let this->parameters[] = parameter;
            let name = parameter->getName();

            if name !== null {
                let this->parameterNameMap[name] = count(this->parameters) - 1;
            }
        } else {
            let type = strval(parameter);
            let data = ["type" : type]
            let parameter = new Parameter(data);
            let this->parameters[] = parameter;
        }

        return this;
    }

    /**
     * Add parameters
     *
     * @param  array $parameters
     * @return \Zend\Server\Method\Prototype
     */
    public function addParameters(array! parameters) -> self
    {
        var parameter;

        for parameter in parameters {
            this->addParameter(parameter);
        }

        return this;
    }

    /**
     * Set parameters
     *
     * @param  array $parameters
     * @return \Zend\Server\Method\Prototype
     */
    public function setParameters(array! parameters) -> self
    {
        let this->parameters = [];
        let this->parameterNameMap = [];

        this->addParameters(parameters);

        return this;
    }

    /**
     * Retrieve parameters as list of types
     *
     * @return array
     */
    public function getParameters() -> array
    {
        array types = [];
        var parameter;

        for parameter in this->parameters {
            let types[] = parameter->getType();
        }

        return types;
    }

    /**
     * Get parameter objects
     *
     * @return array
     */
    public function getParameterObjects() -> array
    {
        return this->parameters;
    }

    /**
     * Retrieve a single parameter by name or index
     *
     * @param  string|int $index
     * @return null|\Zend\Server\Method\Parameter
     */
    public function getParameter(var index) -> <Parameter>
    {
        var index2;

        if typeof index != "string" && typeof != "int" {
            return null;
        }
        if fetch index2, this->parameterNameMap[index] {
            if fetch index, this->parameters[index2] {
                return index;
            }
        }

        return null;
    }

    /**
     * Set object state from array
     *
     * @param  array $options
     * @return \Zend\Server\Method\Prototype
     */
    public function setOptions(array! options) -> self
    {
        var key, value;
        string methodName;

        for key, value in options {
            let methodName = ucfirst(key);
            let methodName = "set" . methodName;

            if method_exists(this, methodName) {
                this->{methodName}(value);
            }
        }

        return this;
    }

    /**
     * Serialize to array
     *
     * @return array
     */
    public function toArray() -> array
    {
        array data = [];

        let data["returnType"] = this->getReturnType();
        let data["parameters"] = this->getParameters();

        return data;
    }

}
