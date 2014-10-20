/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generic\Prototype;

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
    public function addPrototype(<PrototypeInterface> prototype) -> self
    {
        string normilized, name;

        let name = prototype->getName();
        let normilized = this->notrmilizeName(name);

        if unlikely isset this->prototypes[normilized] {
            throw new Exception\InvalidArgumentException("A prototype with this name already exists in this manager");
        }

        let this->prototypes[normilized] = prototype;

        return this;
    }

    /**
     * @param PrototypeGenericInterface $prototype
     * @throws Exception\InvalidArgumentException
     */
    public function setGenericPrototype(<PrototypeGenericInterface> prototype) -> self
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
        string notrmilized;

        let notrmilized = str_replace(chars, "", name);

        return notrmilized;
    }

    /**
     * @param string $name
     * @return bool
     */
    public function hasPrototype(string name) -> boolean
    {
        string normilized;

        let normilized = this->normalizeName(name);

        return isset this->prototypes[normilized];
    }

    /**
     * @param  string $prototypeName
     * @return PrototypeInterface
     * @throws Exception\RuntimeException
     */
    public function getClonedPrototype(string prototypeName) -> <PrototypeInterface>
    {
        string normilized;
        var prototype;

        let normilized = this->normalizeName(prototypeName);

        if unlikely !this->hasPrototype(normilized) && empty this->genericPrototype {
            throw new Exception\RuntimeException("This tag name is not supported by this tag manager");
        }

        if !this->hasPrototype(normilized) {
            let prototype = <PrototypeInterface> clone this->genericPrototype;
            prototype->setName(normilized);
        } else {
            let prototype = <PrototypeInterface> clone this->prototypes[normilized];
        }

        return prototype;
    }

}
