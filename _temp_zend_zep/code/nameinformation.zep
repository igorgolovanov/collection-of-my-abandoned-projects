/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code;

class NameInformation
{
    /**
     * @var string
     */
    protected $namespace;

    /**
     * @var array
     */
    protected uses = [];

    /**
     * @param  string $namespace
     * @param  array $uses
     */
    public function __construct(string $namespace = null, array! uses = [])
    {
        if !empty $namespace {
            this->setNamespace($namespace);
        }
        if !empty uses {
            this->setUses(uses);
        }
    }

    /**
     * @param  string $namespace
     * @return NameInformation
     */
    public function setNamespace(string $namespace) -> <NameInformation>
    {
        let this->$namespace = $namespace;

        return this->$namespace;
    }

    /**
     * @return string
     */
    public function getNamespace() -> string
    {
        return this->$namespace;
    }

    /**
     * @return bool
     */
    public function hasNamespace() -> boolean
    {
        return !empty this->$namespace;
    }

    /**
     * @param  array $uses
     * @return NameInformation
     */
    public function setUses(array! uses) -> <NameInformation>
    {
        let this->uses = [];
        this->addUses(uses);

        return this;
    }

    /**
     * @param  array $uses
     * @return NameInformation
     */
    public function addUses(array! uses) -> <NameInformation>
    {
        var key, value;

        for key, value in uses {
            if typeof key == "integer" {
                this->addUse(value);
                continue;
            }
            if typeof key == "string" {
                this->addUse(key, value);
            }
        }

        return this;
    }

    /**
     * @param  array|string $use
     * @param  string $as
     */
    public function addUse(var $use, string $as = null)
    {

    }

    /**
     * @return array
     */
    public function getUses() -> array
    {
        return this->uses;
    }

    /**
     * @param  string $name
     * @return string
     */
    public function resolveName(string name) -> string
    {

    }

}
