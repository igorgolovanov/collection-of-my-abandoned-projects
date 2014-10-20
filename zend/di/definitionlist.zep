/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di;

use SplDoublyLinkedList;

/**
 * Class definition based on multiple definitions
 */
class DefinitionList extends SplDoublyLinkedList implements Definition\DefinitionInterface
{
    /**
     * @param Definition\DefinitionInterface|Definition\DefinitionInterface[] $definitions
     */
    public function __construct(var definitions)
    {
        var definition;

        if typeof definitions != "array" {
            let definitions = [definitions];
        }

        for definition in definitions {
            this->push(definition);
        }
    }

    /**
     * Add definitions
     *
     * @param  Definition\DefinitionInterface $definition
     * @param  bool                           $addToBackOfList
     * @return void
     */
    public function addDefinition(<Definition\DefinitionInterface> definition, boolean addToBackOfList = true) -> void
    {
        if addToBackOfList {
            this->push(definition);
        } else {
            this->unshift(definition);
        }
    }

    /**
     * @param  string       $type
     * @return Definition\DefinitionInterface[]
     */
    public function getDefinitionsByType(string type) -> array
    {
        var definition;
        array definitions = [];

        for definition in this {
            if definition instanceof {type} {
                let definitions[] = definition;
            }
        }

        return definitions;
    }

    /**
     * Get definition by type
     *
     * @param  string                         $type
     * @return Definition\DefinitionInterface
     */
    public function getDefinitionByType(string type) -> <Definition\DefinitionInterface>|boolean
    {
        var definition;

        for definition in this {
            if definition instanceof {type} {
                return definition;
            }
        }

        return false;
    }

    /**
     * @param  string                              $class
     * @return bool|Definition\DefinitionInterface
     */
    public function getDefinitionForClass(string $class) -> boolean|<Definition\DefinitionInterface>
    {
        var definition;

        for definition in this {
            if definition->hasClass($class) {
                return definition;
            }
        }

        return false;
    }

    /**
     * @param  string                              $class
     * @return bool|Definition\DefinitionInterface
     */
    public function forClass(string $class) -> boolean|<Definition\DefinitionInterface>
    {
        return this->getDefinitionForClass($class);
    }

    /**
     * {@inheritDoc}
     */
    public function getClasses() -> array
    {
        array classes = [], defClasses;
        var definition;

        for definition in this {
            let defClasses = definition->getClasses();
            let classes = array_merge(classes, defClasses);
        }

        return classes;
    }

    /**
     * {@inheritDoc}
     */
    public function hasClass(string $class) -> boolean
    {
        var definition;

        for definition in this {
            if definition->hasClass($class) {
                return true;
            }
        }

        return false;
    }

    /**
     * {@inheritDoc}
     */
    public function getClassSupertypes(string $class) -> array
    {
        array supertypes = [], classSupertypes;
        var definition;

        for definition in this {
            if definition->hasClass($class) {
                let classSupertypes = definition->getClassSupertypes($class);
                let supertypes = array_merge(supertypes, classSupertypes);

                if definition instanceof Definition\PartialMarker {
                    continue;
                }

                return supertypes;
            }
        }

        return supertypes;
    }

    /**
     * {@inheritDoc}
     */
    public function getInstantiator(string $class) -> string|array|boolean
    {
        var value, definition;

        for definition in this {
            if definition->hasClass($class) {
                let value = definition->getInstantiator($class);
                if value === null && definition instanceof Definition\PartialMarker {
                    continue;
                }
                return value;
            }
        }

        return false;
    }

    /**
     * {@inheritDoc}
     */
    public function hasMethods(string $class) -> boolean
    {
        var definition;

        for definition in this {
            if definition->hasClass($class) {
                if definitions->hasMethods($class) === false && definition instanceof Definition\PartialMarker {
                    continue;
                }
                return definition->hasMethods($class);
            }
        }
        return false;
    }

    /**
     * {@inheritDoc}
     */
    public function hasMethod(string $class, string method) -> boolean
    {
        var definition;

        if !this->hasMethods($class) {
            return false;
        }

        for definition in this {
            if definition->hasClass($class) && definition->hasMethod($class, method) {
                return true;
            }
        }
        return false;
    }

    /**
     * {@inheritDoc}
     */
    public function getMethods(string $class) -> array
    {
        array methods = [], defMethods;
        var definition;

        for definition in this {
            if definition->hasClass($class) {
                let defMethods = definition->getMethods($class);
                let methods = array_merge(defMethods, methods);

                if !definition instanceof Definition\PartialMarker {
                    break;
                }
            }
        }

        return methods;
    }

    /**
     * {@inheritDoc}
     */
    public function hasMethodParameters(string $class, string method) -> boolean
    {
        var params;
        let params = this->getMethodParameters($class, method);

        if count(params) > 0 {
            return true;
        }
        return false;
    }

    /**
     * {@inheritDoc}
     */
    public function getMethodParameters(string $class, string method) -> array
    {
        array params = [];
        var definition;

        for definition in this {
            if definition->hasClass($class) && definition->hasMethod($class, method) && definition->hasMethodParameters($class, method) {
                let params = definition->getMethodParameters($class, method);
                break;
            }
        }

        return params;
    }

}
