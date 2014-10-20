/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Validator;

class ValidatorChain implements \Countable, ValidatorInterface
{
    /**
     * @var ValidatorPluginManager
     */
    protected plugins;

    /**
     * Validator chain
     *
     * @var array
     */
    protected validators = [];

    /**
     * Array of validation failure messages
     *
     * @var array
     */
    protected messages = [];

    /**
     * Return the count of attached validators
     *
     * @return int
     */
    public function count() -> int
    {
        int count;

        let count = count(this->validators);

        return count;
    }

    /**
     * Get plugin manager instance
     *
     * @return ValidatorPluginManager
     */
    public function getPluginManager() -> <ValidatorPluginManager>
    {
        
    }

    /**
     * Set plugin manager instance
     *
     * @param  ValidatorPluginManager $plugins Plugin manager
     * @return ValidatorChain
     */
    public function setPluginManager(<ValidatorPluginManager> plugins) -> <ValidatorChain>
    {

    }

    /**
     * Retrieve a validator by name
     *
     * @param  string     $name    Name of validator to return
     * @param  null|array $options Options to pass to validator constructor (if not already instantiated)
     * @return ValidatorInterface
     */
    public function plugin(string name, array! options = null) -> <ValidatorInterface>
    {

    }

    /**
     * Attach a validator to the end of the chain
     *
     * If $breakChainOnFailure is true, then if the validator fails, the next validator in the chain,
     * if one exists, will not be executed.
     *
     * @param  ValidatorInterface      $validator
     * @param  bool                 $breakChainOnFailure
     * @return ValidatorChain Provides a fluent interface
     */
    public function attach(<ValidatorInterface> validator, boolean breakChainOnFailure = false) -> <ValidatorChain>
    {

    }

    /**
     * Proxy to attach() to keep BC
     *
     * @deprecated Please use attach()
     * @param  ValidatorInterface      $validator
     * @param  bool                 $breakChainOnFailure
     * @return ValidatorChain Provides a fluent interface
     */
    public function addValidator(<ValidatorInterface> validator, boolean breakChainOnFailure = false) -> <ValidatorChain>
    {

    }

    /**
     * Adds a validator to the beginning of the chain
     *
     * If $breakChainOnFailure is true, then if the validator fails, the next validator in the chain,
     * if one exists, will not be executed.
     *
     * @param  ValidatorInterface      $validator
     * @param  bool                 $breakChainOnFailure
     * @return ValidatorChain Provides a fluent interface
     */
    public function prependValidator(<ValidatorInterface> validator, boolean breakChainOnFailure = false) -> <ValidatorChain>
    {

    }

    /**
     * Use the plugin manager to add a validator by name
     *
     * @param  string $name
     * @param  array  $options
     * @param  bool   $breakChainOnFailure
     * @return ValidatorChain
     */
    public function attachByName(string name, array options = [], boolean breakChainOnFailure = false) -> <ValidatorChain>
    {

    }

    /**
     * Proxy to attachByName() to keep BC
     *
     * @deprecated Please use attachByName()
     * @param  string $name
     * @param  array  $options
     * @param  bool   $breakChainOnFailure
     * @return ValidatorChain
     */
    public function addByName(string name, array options = [], boolean breakChainOnFailure = false) -> <ValidatorChain>
    {

    }

    /**
     * Use the plugin manager to prepend a validator by name
     *
     * @param  string $name
     * @param  array  $options
     * @param  bool   $breakChainOnFailure
     * @return ValidatorChain
     */
    public function prependByName(string name, array options = [], boolean breakChainOnFailure = false) -> <ValidatorChain>
    {

    }

    /**
     * Returns true if and only if $value passes all validations in the chain
     *
     * Validators are run in the order in which they were added to the chain (FIFO).
     *
     * @param  mixed $value
     * @param  mixed $context Extra "context" to provide the validator
     * @return bool
     */
    public function isValid(value, context = null) -> boolean
    {

    }

    /**
     * Merge the validator chain with the one given in parameter
     *
     * @param ValidatorChain $validatorChain
     * @return ValidatorChain
     */
    public function merge(<ValidatorChain> validatorChain) -> <ValidatorChain>
    {

    }

    /**
     * Returns array of validation failure messages
     *
     * @return array
     */
    public function getMessages() -> array
    {

    }

    /**
     * Get all the validators
     *
     * @return array
     */
    public function getValidators() -> array
    {

    }

    /**
     * Invoke chain as command
     *
     * @param  mixed $value
     * @return bool
     */
    public function __invoke(value) -> boolean
    {

    }

    /**
     * Prepare validator chain for serialization
     *
     * Plugin manager (property 'plugins') cannot
     * be serialized. On wakeup the property remains unset
     * and next invocation to getPluginManager() sets
     * the default plugin manager instance (ValidatorPluginManager).
     *
     * @return array
     */
    public function __sleep() -> array
    {

    }

}
