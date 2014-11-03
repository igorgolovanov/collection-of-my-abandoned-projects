/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Code\Generic\Prototype;

use Zend\Code\Reflection\Exception;

/**
 * This is a factory for classes which are identified by name.
 *
 * All classes that this factory can supply need to
 * be registered before (prototypes). This prototypes need to implement
 * an interface which ensures every prototype has a name.
 *
 * If the factory can not supply the class someone is asking for
 * it tries to fallback on a generic default prototype, which would
 * have need to be set before.
 */
class PrototypeClassFactory
{
    /**
     * @var array
     */
    protected prototypes = [];

    /**
     * @var PrototypeGenericInterface
     */
    protected genericPrototype;

    /**
     * @param PrototypeInterface[] $prototypes
     * @param PrototypeGenericInterface $genericPrototype
     */
    public function __construct(var prototypes = [], <PrototypeGenericInterface> genericPrototype = null)
    {
        var prototype;

        if typeof prototypes != "array" {
            let prototypes = [prototypes];
        }

        for prototype in prototypes {
            this->addPrototype(prototype);
        }

        if genericPrototype !== null {
            this->setGenericPrototype(genericPrototype);
        }
    }

    /**
     * @param PrototypeInterface $prototype
     * @throws Exception\InvalidArgumentException
     */
    public function addPrototype(<PrototypeInterface> prototype) -> <PrototypeInterface>
    {
        var normalized, name;

        let name = prototype->getName();
        let normalized = this->normalizeName(name);

        if unlikely isset this->prototypes[normalized] {
            throw new Exception\InvalidArgumentException("A prototype with this name already exists in this manager");
        }

        let this->prototypes[normalized] = prototype;

        return this;
    }

    /**
     * @param PrototypeGenericInterface $prototype
     * @throws Exception\InvalidArgumentException
     * @return PrototypeClassFactory
     */
    public function setGenericPrototype(<PrototypeGenericInterface> prototype) -> <PrototypeClassFactory>
    {
        if unlikely !empty this->genericPrototype {
            throw new Exception\InvalidArgumentException("A default prototype is already set");
        }

        let this->genericPrototype = prototype;

        return this;
    }

    /**
     * @param string $name
     * @return string
     */
    protected function normalizeName(string name) -> string
    {
        array chars = ["-", "_"];
        var normalized;

        let normalized = str_replace(chars, "", name);

        return normalized;
    }

    /**
     * @param string $name
     * @return bool
     */
    public function hasPrototype(string name) -> boolean
    {
        var normalized;

        let normalized = this->normalizeName(name);

        return isset this->prototypes[normalized];
    }

    /**
     * @param  string $prototypeName
     * @return PrototypeInterface
     * @throws Exception\RuntimeException
     */
    public function getClonedPrototype(string prototypeName) -> <PrototypeInterface>
    {
        var normalized, prototype, prototypeBase;

        let normalized = this->normalizeName(prototypeName);

        if unlikely !this->hasPrototype(normalized) && empty this->genericPrototype {
            throw new Exception\RuntimeException("This tag name is not supported by this tag manager");
        }

        if !this->hasPrototype(normalized) {
            let prototypeBase = <PrototypeInterface> this->genericPrototype;
            let prototype = clone prototypeBase;

            prototype->setName(normalized);
        } else {
            let prototypeBase = <PrototypeInterface> this->prototypes[normalized];
            let prototype = clone prototypeBase;
        }

        return prototype;
    }

}
