/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Strategy;

use Zend\Stdlib\Exception\InvalidArgumentException;
use Zend\Serializer\Adapter\AdapterInterface as SerializerAdapter;
use Zend\Serializer\Serializer as SerializerFactory;

class SerializableStrategy implements StrategyInterface
{
    /**
     * @var string|SerializerAdapter
     */
    protected serializer;

    /**
     * @var array
     */
    protected serializerOptions; // [] // todo array

    /**
     *
     * @param mixed $serializer string or SerializerAdapter
     * @param mixed $serializerOptions
     */
    public function __construct(serializer, serializerOptions = null)
    {
        this->setSerializer(serializer);

        if isset serializerOptions {
            this->setSerializerOptions(serializerOptions);
        }
    }

    /**
     * Serialize the given value so that it can be extracted by the hydrator.
     *
     * @param mixed $value The original value.
     * @return mixed Returns the value that should be extracted.
     */
    public function extract(value)
    {
        var serializer;
        let serializer = <SerializerAdapter> this->getSerializer();

        return serializer->serialize(value);
    }

    /**
     * Unserialize the given value so that it can be hydrated by the hydrator.
     *
     * @param mixed $value The original value.
     * @return mixed Returns the value that should be hydrated.
     */
    public function hydrate(value)
    {
        var serializer;
        let serializer = <SerializerAdapter> this->getSerializer();

        return serializer->unserialize(value);
    }

    /**
     * Set serializer
     *
     * @param  string|SerializerAdapter $serializer
     * @return SerializableStrategy
     */
    public function setSerializer(var serializer) -> <SerializableStrategy>
    {
        string exceptionMsg, type;

        let type = typeof serializer;

        if type != "string" && !serializer instanceof SerializerAdapter {
            let exceptionMsg = "%s expects either a string serializer name or Zend\Serializer\Adapter\AdapterInterface instance; received \"%s\"";
            let exceptionMsg = sprintf(exceptionMsg, __METHOD__, type);

            throw new InvalidArgumentException(exceptionMsg);
        }
        let this->serializer = serializer;

        return this;
    }

    /**
     * Get serializer
     *
     * @return SerializerAdapter
     */
    public function getSerializer() -> <SerializerAdapter>
    {
        var options, serializer;

        let serializer = this->serializer;

        if typeof serializer == "string" {
            let options = this->getSerializerOptions();
            let serializer = <SerializerAdapter> SerializerFactory::factory(serializer, options);

            this->setSerializer(serializer);
        } else {
            if serializer === null {
                let serializer = <SerializerAdapter> SerializerFactory::getDefaultAdapter();
                this->setSerializer(serializer);
            }
        }

        return serializer;
    }   

    /**
     * Set configuration options for instantiating a serializer adapter
     *
     * @param  mixed $serializerOptions
     * @return SerializableStrategy
     */
    public function setSerializerOptions(serializerOptions) -> <SerializableStrategy>
    {
        let this->serializerOptions = serializerOptions;
        return this;
    }

    /**
     * Get configuration options for instantiating a serializer adapter
     *
     * @return mixed
     */
    public function getSerializerOptions()
    {
        return this->serializerOptions;
    }

}
