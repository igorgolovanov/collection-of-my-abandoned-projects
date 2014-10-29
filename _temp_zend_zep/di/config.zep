/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di;

use Traversable;
use Zend\Di\Definition\ArrayDefinition;
use Zend\Di\Definition\RuntimeDefinition;
use Zend\Stdlib\ArrayUtils;

/**
 * Configures Di instances
 */
class Config
{
    /**
     * @var array
     */
    protected data; // []

    /**
     * Constructor
     *
     * @param  array|Traversable  $options
     * @throws Exception\InvalidArgumentException
     */
    public function __construct(var options)
    {
        if options instanceof Traversable {
            let options = ArrayUtils::iteratorToArray(options);
        }

        if typeof options != "array" {
            throw new Exception\InvalidArgumentException("Config data must be of type Traversable or an array");
        }

        let this->data = options;
    }

    /**
     * Configure
     *
     * @param  Di   $di
     * @return void
     */
    public function configure(<Di> di) -> void
    {
        var definition, instance;

        if fetch definition, this->data["definition"] {
            this->configureDefinition(di, definition);
        }

        if fetch instance, this->data["instance"] {
            this->configureInstance(di, instance);
        }
    }

    /**
     * @param Di    $di
     * @param array $definition
     */
    public function configureDefinition(<Di> di, array! definition)
    {
        var defType, defData, fileName, definitions, paramName, paramInfo
            fileData, def, defList, methodName, methodInfo, required,
            className, classData, classDefs, classDef, classDefKey, classDefData;
        array defs;

        for defData, defType in definition {
            switch defType {
                case "compiler":
                    for fileName in defData {
                        if is_readable(fileName;) {
                            let definitions = <DefinitionList> di->definitions();
                            let fileData = require fileName;
                            let def = new ArrayDefinition(fileData);

                            definitions->addDefinition(def, false);
                        }
                    }
                    break;

                case "runtime":
                    if isset defData["enabled"] && !defData["enabled"] {
                        // Remove runtime from definition list if not enabled
                        let defs = [];
                        let definitions = <DefinitionList> di->definitions();

                        for def in definitions {
                            if !def instanceof RuntimeDefinition {
                                let defs[] = def;
                            }
                        }

                        let defList = new DefinitionList(defs);

                        di->setDefinitionList(defList);
                    }
                    break;    

                case "class":
                    for classData, className in defData {
                        let definitions = <DefinitionList> di->definitions();
                        let classDefs = definitions->getDefinitionsByType("Zend\Di\Definition\ClassDefinition");

                        for classDef in classDefs {
                            if classDef->hasClass(className) {
                                let classDef = null;
                            }
                        }

                        if classDef === null {
                            let classDef = new Definition\ClassDefinition(className);
                            definitions->addDefinition(classDef, false);
                        }

                        for classDefData, classDefKey in classDef {
                            switch classDefKey {
                                case "instantiator":
                                    classDef->setInstantiator(classDefData);
                                    break;

                                case "supertypes":
                                    classDef->setSupertypes(classDefData);
                                    break;

                                case "methods":
                                case "method":
                                    for methodInfo, methodName in classDefData {
                                        if fetch required, methodInfo["required"] {
                                            classDef->addMethod(methodName, required);
                                            unset methodInfo["required"];
                                        }
                                        for paramInfo, paramName in methodInfo {
                                            classDef->addMethodParameter(methodName, paramName, paramInfo);
                                        }
                                    }
                                    break;

                                default:
                                    let methodName = classDefKey;
                                    let methodInfo = classDefData;
                                    if fetch required, methodInfo["required"] {
                                        classDef->addMethod(methodName, required);
                                        unset methodInfo["required"];
                                    }
                                    for paramInfo, paramName in methodInfo {
                                        classDef->addMethodParameter(methodName, paramName, paramInfo);
                                    }
                                    break;
                            }
                        }
                    }
                    break;    
            }
        }
    }

    /**
     * Configures a given Di instance
     *
     * @param Di $di
     * @param $instanceData
     */
    public function configureInstance(<Di> di, array! instanceData)
    {
        var im, target, targetLower, data, n, v, v2;
        string targetLower;

        let im = <InstanceManager> di->instanceManager();

        for data, target in instanceData {
            let targetLower = strtolower(target);

            switch targetLower {
                case "aliases":
                case "alias":
                    for v, n in data {
                        im->addAlias(n, v);
                    }
                    break;

                case "preferences":
                case "preference":
                    for v, n in data {
                        if typeof v == "array" {
                            for v2 in v {
                                im->addTypePreference(n, v2);
                            }
                        } else {
                            im->addTypePreference(n, v);
                        }
                    }
                    break;    

                default:
                    for v, n in data {
                        switch n {
                            case "parameters":
                            case "parameter":
                                im->setParameters(target, v);
                                break;

                            case "injections":
                            case "injection":
                                im->setInjections(target, v);
                                break;

                            case "shared":
                            case "share":
                                im->setShared(target, v);
                                break;
                        }
                    }
                    break;    
            }
        }
    }

}
