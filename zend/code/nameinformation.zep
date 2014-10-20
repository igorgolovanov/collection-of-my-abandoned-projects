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
    protected uses; // []

    /**
     * @param  string $namespace
     * @param  array $uses
     */
    public function __construct(string $namespace = null, array! uses = [])
    {

    }

    /**
     * @param  string $namespace
     * @return NameInformation
     */
    public function setNamespace(string $namespace) -> <NameInformation>
    {

    }

    /**
     * @return string
     */
    public function getNamespace() -> string
    {

    }

    /**
     * @return bool
     */
    public function hasNamespace() -> boolean
    {

    }

    /**
     * @param  array $uses
     * @return NameInformation
     */
    public function setUses(array! uses) -> <NameInformation>
    {

    }

    /**
     * @param  array $uses
     * @return NameInformation
     */
    public function addUses(array! uses) -> <NameInformation>
    {

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

    }

    /**
     * @param  string $name
     * @return string
     */
    public function resolveName(string name) -> string
    {

    }

}
