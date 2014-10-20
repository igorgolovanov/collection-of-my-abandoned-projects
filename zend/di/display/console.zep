/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di\Display;

use Zend\Di\Di;
use Zend\Di\DefinitionList;
use Zend\Di\InstanceManager;
use Zend\Di\Definition\DefinitionInterface;
use ReflectionProperty;
use ReflectionClass;

/**
 * Exporter for class definitions
 */
class Console
{
    /**
     * @var Di
     */
    protected di;

    /**
     * @var string[]
     */
    protected runtimeClasses; // []

    /**
     * Export
     *
     * @param  Di    $di
     * @param  array $runtimeClasses
     * @return void
     */
    public static function export(<Di> di, array! runtimeClasses = []) -> void
    {
        // todo: change to self -> static
        var className, console;

        let className = get_called_class();
        let console = <Console> {className}(di);

        console->addRuntimeClasses(runtimeClasses);
        console->render(di);
    }

    /**
     * Constructor
     *
     * @param null|Di $di
     */
    public function __construct(<Di> di = null)
    {
        if di === null {
            let di = new Di();
        }
        let this->di = di;
    }

    /**
     * @param string[] $runtimeClasses
     */
    public function addRuntimeClasses(array! runtimeClasses)
    {
        string runtimeClass;

        for runtimeClass in runtimeClasses {
            this->addRuntimeClass(runtimeClass);
        }
    }

    /**
     * @param string $runtimeClass
     */
    public function addRuntimeClass(string runtimeClass)
    {
        let this->runtimeClasses[] = runtimeClass;
    }

    public function render()
    {
        array knownClasses = [], classes, unknownRuntimeClasses, 
            runtimeClasses, configuredTypes = [], info;
        var definitions, di, definition, im, parameters, injections, value;
        string className, type, param, injection;

        echo "Definitions" + PHP_EOL + PHP_EOL;

        let di = <Di> this->di;
        let definitions = <DefinitionList> di->definitions();

        for definition in definitions {
            this->renderDefinition(definition);
            let classes = definition->getClasses();
            for className in classes {
                let knownClasses[] = className;
                this->renderClassDefinition(definition, className);
            }

            if empty classes {
                echo PHP_EOL + "    No Classes Found'" + PHP_EOL + PHP_EOL;
            }
        }

        if this->runtimeClasses {
            echo "  Runtime classes:" + PHP_EOL;
        }

        let runtimeClasses = this->runtimeClasses;
        let unknownRuntimeClasses = array_diff(runtimeClasses, knownClasses);

        for className in unknownRuntimeClasses {
            let definition = definitions->getDefinitionForClass(className);
            this->renderClassDefinition(definition, runtimeClass);
        } 

        echo PHP_EOL + "Instance Configuration Info:" + PHP_EOL;
        echo PHP_EOL + "    Aliases:" + PHP_EOL;

        let im = <InstanceManager> di->instanceManager();
        let classes = im->getClasses();

        for className in classes {
            echo "      " + className + PHP_EOL;
            let configuredTypes[] = className;
        }

        echo  PHP_EOL + "   Configurations:" + PHP_EOL;

        for type in configuredTypes {
            let info = im->getConfig(type);
            echo "      " + type + PHP_EOL;

            if fetch parameters, info["parameters"] {
                echo "      parameters:" + PHP_EOL;
                for value, param in parameters {
                    echo "          " + param + " = " + value + PHP_EOL;
                }
            }

            if fetch injections, info["injections"] {
                echo "      injections:" + PHP_EOL;
                for value, injection in injections {
                    var_dump(injection, value);
                }
            }
        }
    }

    /**
     * @param object $definition
     */
    protected function renderDefinition(object definition)
    {
        var ref, property, value;
        array properties;
        string name;

        echo "  Definition Type: " + get_class(definition) + PHP_EOL;

        let ref = new ReflectionClass(definition);
        let properties = ref->getProperties(ReflectionProperty::IS_PUBLIC | ReflectionProperty::IS_PROTECTED);

        for property in properties {
            property->setAccessible(true);
            
            let name = property->getName();
            let value = property->getValue(definition);

            echo "      internal property: " + name;
            if typeof value == "object" {
                echo " instance of " + get_class(value);
            } else {
                echo " = " + value;
            }
            echo PHP_EOL
        }
    }

    /**
     * @param \Zend\Di\Definition\DefinitionInterface $definition
     * @param string                                  $class
     */
    protected function renderClassDefinition(<DefinitionInterface> definition, string $class)
    {
        var ref, methods, methodIsRequired;
        array methods, parameters, paramData;
        string methodName, fqName;

        echo PHP_EOL + "    Parameters For Class: " + $class + PHP_EOL;

        let methods = definition->getMethods($class);
        for methodIsRequired, methodName in methods {
            let parameters = definition->getMethodParameters($class, methodName);
            for paramData, fqName in parameters {
                echo "      "  + paramData[0] + "[type: ";
                echo  paramData[1] ? paramData[1] : 'scalar';
                echo (paramData[2] === true && methodIsRequired) ? ', required' : ', not required';
                echo "injection-method: " + methodName;
                echo " fq-name: " + fqName;
                echo "]" + PHP_EOL;
            }
        }
        echo PHP_EOL;
    }

}
