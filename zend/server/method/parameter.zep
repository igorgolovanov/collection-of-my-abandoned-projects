/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server\Method;

/**
 * Method parameter metadata
 */
class Parameter
{
    /**
     * Default parameter value
     *
     * @var mixed
     */
    protected defaultValue;

    /**
     * Parameter description
     *
     * @var string
     */
    protected description = "";

    /**
     * Parameter variable name
     *
     * @var string
     */
    protected name;

    /**
     * Is parameter optional?
     *
     * @var bool
     */
    protected optional = false;

    /**
     * Parameter type
     *
     * @var string
     */
    protected type = "mixed";

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
     * Set object state from array of options
     *
     * @param  array $options
     * @return \Zend\Server\Method\Parameter
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
     * Set default value
     *
     * @param  mixed $defaultValue
     * @return \Zend\Server\Method\Parameter
     */
    public function setDefaultValue(var defaultValue) -> self
    {
        let this->defaultValue = defaultValue;
        
        return this;
    }

    /**
     * Retrieve default value
     *
     * @return mixed
     */
    public function getDefaultValue()
    {
        return this->defaultValue;
    }

    /**
     * Set description
     *
     * @param  string $description
     * @return \Zend\Server\Method\Parameter
     */
    public function setDescription(string description) -> self
    {
        let this->description = description;
        
        return this;
    }

    /**
     * Retrieve description
     *
     * @return string
     */
    public function getDescription() -> string
    {
        return this->description;
    }

    /**
     * Set name
     *
     * @param  string $name
     * @return \Zend\Server\Method\Parameter
     */
    public function setName(string name) -> self
    {
        let this->name = name;
        
        return this;
    }

    /**
     * Retrieve name
     *
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Set optional flag
     *
     * @param  bool $flag
     * @return \Zend\Server\Method\Parameter
     */
    public function setOptional(boolean flag) -> self
    {
        let this->optional = flag;
        
        return this;
    }

    /**
     * Is the parameter optional?
     *
     * @return bool
     */
    public function isOptional() -> boolean
    {
        return this->optional;
    }

    /**
     * Set parameter type
     *
     * @param  string $type
     * @return \Zend\Server\Method\Parameter
     */
    public function setType(string type) -> self
    {
        let this->type = type;

        return this;
    }

    /**
     * Retrieve parameter type
     *
     * @return string
     */
    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Cast to array
     *
     * @return array
     */
    public function toArray() -> array
    {
        array data = [];

        let data["type"] = this->getType();
        let data["name"] = this->getName();
        let data["optional"] = this->isOptional();
        let data["defaultValue"] = this->getDefaultValue();
        let data["description"] = this->getDescription();

        return data;
    }

}
