/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di;

/**
 * Registry of instantiated objects, their names and the parameters used to build them
 */
class InstanceManager
{
    /**
     * Array of shared instances
     * @var array
     */
    protected sharedInstances; // []

    /**
     * Array of shared instances with params
     * @var array
     */
    protected sharedInstancesWithParams; // ["hashShort": [], "hashLong": []]

    /**
     * Array of class aliases
     * @var array key: alias, value: class
     */
    protected aliases; // []

    /**
         * alias|class => bool
         */
    protected configurationTemplate; // ["parameters": [], "injections": [], "shared": true]

    /**
     * An array of instance configuration data
     * @var array
     */
    protected configurations; // []

    /**
     * An array of globally preferred implementations for interfaces/abstracts
     * @var array
     */
    protected typePreferences; // []

    /**
     * Does this instance manager have this shared instance
     * @param  string $classOrAlias
     * @return bool
     */
    public function hasSharedInstance(string classOrAlias) -> boolean
    {
        return isset this->sharedInstances[classOrAlias];
    }

    /**
     * getSharedInstance()
     */
    public function getSharedInstance(classOrAlias)
    {
        var sharedInstance;

        if fetch sharedInstance, this->sharedInstances[classOrAlias] {
            return sharedInstance;
        }
        return null;
    }

    /**
     * Add shared instance
     *
     * @param  object                             $instance
     * @param  string                             $classOrAlias
     * @throws Exception\InvalidArgumentException
     */
    public function addSharedInstance(object instance, string classOrAlias)
    {
        string exceptionMsg;

        if typeof instance != "object" {
            let exceptionMsg = "This method requires an object to be shared. Class or Alias given: %s";
            let exceptionMsg = sprintf(exceptionMsg, classOrAlias);

            throw new Exception\InvalidArgumentException(exceptionMsg);
        }
        let this->sharedInstances[classOrAlias] = instance;
    }

    /**
     * hasSharedInstanceWithParameters()
     *
     * @param  string      $classOrAlias
     * @param  array       $params
     * @param  bool        $returnFastHashLookupKey
     * @return bool|string
     */
    public function hasSharedInstanceWithParameters(string classOrAlias, array! params, boolean returnFastHashLookupKey = false) -> boolean|string
    {

    }

    /**
     * addSharedInstanceWithParameters()
     *
     * @param  object $instance
     * @param  string $classOrAlias
     * @param  array  $params
     * @return void
     */
    public function addSharedInstanceWithParameters(object instance, string classOrAlias, array! params) -> void
    {

    }

    /**
     * Retrieves an instance by its name and the parameters stored at its instantiation
     *
     * @param  string      $classOrAlias
     * @param  array       $params
     * @param  bool|null   $fastHashFromHasLookup
     * @return object|bool false if no instance was found
     */
    public function getSharedInstanceWithParameters(string classOrAlias, array! params, boolean fastHashFromHasLookup = null) -> object|boolean
    {

    }

    /**
     * Check for an alias
     *
     * @param  string $alias
     * @return bool
     */
    public function hasAlias(string alias) -> boolean
    {
        return isset this->aliases[alias];
    }

    /**
     * Get aliases
     *
     * @return array
     */
    public function getAliases() -> array
    {
        return this->aliases;
    }

    /**
     * getClassFromAlias()
     *
     * @param string
     * @return string|bool
     * @throws Exception\RuntimeException
     */
    public function getClassFromAlias(alias) -> string|boolean
    {

    }

    /**
     * @param  string                     $alias
     * @return string|bool
     * @throws Exception\RuntimeException
     */
    protected function getBaseAlias(string alias) -> string|boolean
    {

    }

    /**
     * Add alias
     *
     * @throws Exception\InvalidArgumentException
     * @param  string                             $alias
     * @param  string                             $class
     * @param  array                              $parameters
     * @return void
     */
    public function addAlias(string alias, string $class, array! parameters = []) -> void
    {

    }

    /**
     * Check for configuration
     *
     * @param  string $aliasOrClass
     * @return bool
     */
    public function hasConfig(string aliasOrClass) -> boolean
    {

    }

    /**
     * Sets configuration for a single alias/class
     *
     * @param string $aliasOrClass
     * @param array  $configuration
     * @param bool   $append
     */
    public function setConfig(string aliasOrClass, array! configuration, boolean append = false)
    {

    }

    /**
     * Get classes
     *
     * @return array
     */
    public function getClasses() -> array
    {

    }

    /**
     * @param  string $aliasOrClass
     * @return array
     */
    public function getConfig(string aliasOrClass) -> array
    {

    }

    /**
     * setParameters() is a convenience method for:
     *    setConfig($type, array('parameters' => array(...)), true);
     *
     * @param  string $aliasOrClass Alias or Class
     * @param  array  $parameters   Multi-dim array of parameters and their values
     * @return void
     */
    public function setParameters(string aliasOrClass, array! parameters) -> void
    {

    }

    /**
     * setInjections() is a convenience method for:
     *    setConfig($type, array('injections' => array(...)), true);
     *
     * @param  string $aliasOrClass Alias or Class
     * @param  array  $injections   Multi-dim array of methods and their parameters
     * @return void
     */
    public function setInjections(string aliasOrClass, array! injections) -> void
    {

    }

    /**
     * Set shared
     *
     * @param  string $aliasOrClass
     * @param  bool   $isShared
     * @return void
     */
    public function setShared(string aliasOrClass, boolean isShared) -> void
    {

    }

    /**
     * Check for type preferences
     *
     * @param  string $interfaceOrAbstract
     * @return bool
     */
    public function hasTypePreferences(string interfaceOrAbstract) -> boolean
    {

    }

    /**
     * Set type preference
     *
     * @param  string          $interfaceOrAbstract
     * @param  array           $preferredImplementations
     * @return InstanceManager
     */
    public function setTypePreference(string interfaceOrAbstract, array! preferredImplementations) -> <InstanceManager>
    {

    }

    /**
     * Get type preferences
     *
     * @param  string $interfaceOrAbstract
     * @return array
     */
    public function getTypePreferences(string interfaceOrAbstract) -> array
    {

    }

    /**
     * Unset type preferences
     *
     * @param  string $interfaceOrAbstract
     * @return void
     */
    public function unsetTypePreferences(string interfaceOrAbstract) -> void
    {

    }

    /**
     * Adds a type preference. A type preference is a redirection to a preferred alias or type when an abstract type
     * $interfaceOrAbstract is requested
     *
     * @param  string $interfaceOrAbstract
     * @param  string $preferredImplementation
     * @return self
     */
    public function addTypePreference(string interfaceOrAbstract, string preferredImplementation) -> <InstanceManager>
    {

    }

    /**
     * Removes a previously set type preference
     *
     * @param  string    $interfaceOrAbstract
     * @param  string    $preferredType
     * @return bool|self
     */
    public function removeTypePreference(string interfaceOrAbstract, string preferredType) -> boolean|<InstanceManager>
    {

    }

    /**
     * @param  string   $classOrAlias
     * @param  string[] $paramKeys
     * @return string
     */
    protected function createHashForKeys(string classOrAlias, array paramKeys) -> string
    {

    }

    /**
     * @param  string $classOrAlias
     * @param  array  $paramValues
     * @return string
     */
    protected function createHashForValues(string classOrAlias, array paramValues) -> string
    {

    }

}
