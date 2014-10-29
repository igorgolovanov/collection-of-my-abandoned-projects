/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Validator;

use Traversable;
use Zend\Stdlib\ArrayUtils;

abstract class AbstractValidator implements Translator\TranslatorAwareInterface, ValidatorInterface
{
    /**
     * The value to be validated
     *
     * @var mixed
     */
    protected value;

    /**
     * Default translation object for all validate objects
     * @var Translator\TranslatorInterface
     */
    protected static defaultTranslator;

    /**
     * Default text domain to be used with translator
     * @var string
     */
    protected static defaultTranslatorTextDomain = "default";

    /**
     * Limits the maximum returned length of an error message
     *
     * @var int
     */
    protected static messageLength = -1;

    protected abstractOptions = []; // ["messages": [], "messageTemplates": [], "messageVariables": [], "translator": null, "translatorTextDomain": null, "translatorEnabled": true, "valueObscured": false]

    /**
     * Abstract constructor for all validators
     * A validator should accept following parameters:
     *  - nothing f.e. Validator()
     *  - one or multiple scalar values f.e. Validator($first, $second, $third)
     *  - an array f.e. Validator(array($first => 'first', $second => 'second', $third => 'third'))
     *  - an instance of Traversable f.e. Validator($config_instance)
     *
     * @param array|Traversable $options
     */
    public function __construct(var options = null)
    {
        if options instanceof Traversable {
            let options = ArrayUtils::iteratorToArray(options);
        }

        if isset this->messageTemplates {
            let this->abstractOptions["messageTemplates"] = this->messageTemplates;
        }
        if isset this->messageVariables {
            let this->abstractOptions["messageVariables"] = this->messageVariables;
        }

        if typeof options == "array" {
            this->setOptions(options);
        }
    }

    /**
     * Returns an option
     *
     * @param string $option Option to be returned
     * @return mixed Returned option
     * @throws Exception\InvalidArgumentException
     */
    public function getOption(string option)
    {
        var val;
        string exceptionMsg;

        if fetch val, this->abstractOptions[option] {
            return val;
        }

        if isset this->options && fetch val, this->options[option] {
            return val;
        }

        let exceptionMsg = "Invalid option '" . option . "'";
        throw new Exception\InvalidArgumentException(exceptionMsg);
    }

    /**
     * Returns all available options
     *
     * @return array Array with all available options
     */
    public function getOptions() -> array
    {
        var result, options; 

        let result = this->abstractOptions;

        if isset this->options {
            let result = array_merge(result, this->options);
        }
        return result;
    }

    /**
     * Sets one or multiple options
     *
     * @param  array|Traversable $options Options to set
     * @throws Exception\InvalidArgumentException If $options is not an array or Traversable
     * @return AbstractValidator Provides fluid interface
     */
    public function setOptions(var options = []) -> <AbstractValidator>
    {

    }

    /**
     * Returns array of validation failure messages
     *
     * @return array
     */
    public function getMessages() -> array
    {
        array messages;

        let messages = this->abstractOptions["messages"];
        let messages = array_unique(messages, SORT_REGULAR);

        return messages;
    }

    /**
     * Invoke as command
     *
     * @param  mixed $value
     * @return bool
     */
    public function __invoke(value) -> boolean
    {
        return this->isValid(value);
    }

    /**
     * Returns an array of the names of variables that are used in constructing validation failure messages
     *
     * @return array
     */
    public function getMessageVariables() -> array
    {
        array variables, keys;

        let variables = this->abstractOptions["messageVariables"];
        let keys = array_keys(variables);

        return keys;
    }

    /**
     * Returns the message templates from the validator
     *
     * @return array
     */
    public function getMessageTemplates() -> array
    {

    }

    /**
     * Sets the validation failure message template for a particular key
     *
     * @param  string $messageString
     * @param  string $messageKey     OPTIONAL
     * @return AbstractValidator Provides a fluent interface
     * @throws Exception\InvalidArgumentException
     */
    public function setMessage(string messageString, string messageKey = null) -> <AbstractValidator>
    {

    }

    /**
     * Sets validation failure message templates given as an array, where the array keys are the message keys,
     * and the array values are the message template strings.
     *
     * @param  array $messages
     * @return AbstractValidator
     */
    public function setMessages(array! messages) -> <AbstractValidator>
    {
        var key, message;

        for key, message in messages {
            this->setMessages(message, key);
        }
        return this;
    }

    /**
     * Magic function returns the value of the requested property, if and only if it is the value or a
     * message variable.
     *
     * @param  string $property
     * @return mixed
     * @throws Exception\InvalidArgumentException
     */
    public function __get(string property)
    {

    }

    /**
     * Constructs and returns a validation failure message with the given message key and value.
     *
     * Returns null if and only if $messageKey does not correspond to an existing template.
     *
     * If a translator is available and a translation exists for $messageKey,
     * the translation will be used.
     *
     * @param  string              $messageKey
     * @param  string|array|object $value
     * @return string
     */
    protected function createMessage(string messageKey, var value) -> string
    {

    }

    /**
     * @param  string $messageKey
     * @param  string $value      OPTIONAL
     * @return void
     */
    protected function error(string messageKey, string value = null) -> void
    {
        array keys;

        if empty messageKey {
            let keys = array_keys(this->abstractOptions["messageTemplates"]);
            let messageKey = current(keys);
        }

        if empty value {
            let value = this->value;
        }
        let this->abstractOptions["messages"][messageKey] = this->createMessage(messageKey, value);
    }

    /**
     * Returns the validation value
     *
     * @return mixed Value to be validated
     */
    protected function getValue()
    {
         return this->value;
    }

    /**
     * Sets the value to be validated and clears the messages and errors arrays
     *
     * @param  mixed $value
     * @return void
     */
    protected function setValue(var value) -> void
    {
        let this->value = value;
        let this->abstractOptions["messages"] = [];
    }

    /**
     * Set flag indicating whether or not value should be obfuscated in messages
     *
     * @param  bool $flag
     * @return AbstractValidator
     */
    public function setValueObscured(boolean flag) -> <AbstractValidator>
    {
        let this->abstractOptions["valueObscured"] = flag;

        return this;
    }

    /**
     * Retrieve flag indicating whether or not value should be obfuscated in
     * messages
     *
     * @return bool
     */
    public function isValueObscured() -> boolean
    {
        var valueObscured;

        if fetch valueObscured, this->abstractOptions["valueObscured"] {
            if valueObscured {
                return true;
            }
        }
        return false;
    }

    /**
     * Set translation object
     *
     * @param  Translator\TranslatorInterface|null $translator
     * @param  string          $textDomain (optional)
     * @return AbstractValidator
     * @throws Exception\InvalidArgumentException
     */
    public function setTranslator(<Translator\TranslatorInterface> translator = null, string textDomain = null) -> <AbstractValidator>
    {
        let this->abstractOptions["translator"] = translator;
        if !empty textDomain {
            this->setTranslatorTextDomain(textDomain);
        }
        return this;
    }

    /**
     * Return translation object
     *
     * @return Translator\TranslatorInterface|null
     */
    public function getTranslator() -> <Translator\TranslatorInterface>
    {
        var translator;

        if !this->isTranslatorEnabled() {
            return null;
        }
        if fetch translator, this->abstractOptions["translator"] {
            if translator {
                return true;
            }
        }
        let translator = self::getDefaultTranslator();
        let this->abstractOptions["translator"] = translator;

        return translator;
    }

    /**
     * Does this validator have its own specific translator?
     *
     * @return bool
     */
    public function hasTranslator() -> boolean
    {
        var translator;

        if fetch translator, this->abstractOptions["translator"] {
            if translator {
                return true;
            }
        }
        return false;
    }

    /**
     * Set translation text domain
     *
     * @param  string $textDomain
     * @return AbstractValidator
     */
    public function setTranslatorTextDomain(string textDomain = "default") -> <AbstractValidator>
    {
        let this->abstractOptions["translatorTextDomain"] = textDomain;

        return this;
    }

    /**
     * Return the translation text domain
     *
     * @return string
     */
    public function getTranslatorTextDomain() -> string
    {
        var translatorTextDomain;

        if fetch translatorTextDomain, this->abstractOptions["translatorTextDomain"] {
            if !empty translatorTextDomain {
                return translatorTextDomain;
            }
        }
        let translatorTextDomain = self::getDefaultTranslatorTextDomain();
        let this->abstractOptions["translatorTextDomain"] = translatorTextDomain;

        return translatorTextDomain;
    }

    /**
     * Set default translation object for all validate objects
     *
     * @param  Translator\TranslatorInterface|null $translator
     * @param  string          $textDomain (optional)
     * @return void
     * @throws Exception\InvalidArgumentException
     */
    public static function setDefaultTranslator(<Translator\TranslatorInterface> translator = null, string textDomain = null) -> void
    {
        let static::defaultTranslator = translator;

        if !empty textDomain {
            self::setDefaultTranslatorTextDomain(textDomain);
        }
    }

    /**
     * Get default translation object for all validate objects
     *
     * @return Translator\TranslatorInterface|null
     */
    public static function getDefaultTranslator() -> <Translator\TranslatorInterface>
    {
        return static::defaultTranslator;
    }

    /**
     * Is there a default translation object set?
     *
     * @return bool
     */
    public static function hasDefaultTranslator() -> boolean
    {
        return static::defaultTranslator;
    }

    /**
     * Set default translation text domain for all validate objects
     *
     * @param  string $textDomain
     * @return void
     */
    public static function setDefaultTranslatorTextDomain(string textDomain = "default") -> void
    {
        let static::defaultTranslatorTextDomain = textDomain;
    }

    /**
     * Get default translation text domain for all validate objects
     *
     * @return string
     */
    public static function getDefaultTranslatorTextDomain() -> string
    {
        return static::defaultTranslatorTextDomain;
    }

    /**
     * Indicate whether or not translation should be enabled
     *
     * @param  bool $flag
     * @return AbstractValidator
     */
    public function setTranslatorEnabled(boolean flag = true) -> <AbstractValidator>
    {
        let this->abstractOptions["translatorEnabled"] = flag;
        
        return this;
    }

    /**
     * Is translation enabled?
     *
     * @return bool
     */
    public function isTranslatorEnabled() -> boolean
    {
        if isset this->abstractOptions["translatorEnabled"] && this->abstractOptions["translatorEnabled"] {
            return true;
        }
        return false;
    }

    /**
     * Returns the maximum allowed message length
     *
     * @return int
     */
    public static function getMessageLength() -> int
    {
        return static::messageLength;
    }

    /**
     * Sets the maximum allowed message length
     *
     * @param int $length
     */
    public static function setMessageLength(int length = -1)
    {
        let static::messageLength = length;
    }

    /**
     * Translate a validation message
     *
     * @param  string $messageKey
     * @param  string $message
     * @return string
     */
    protected function translateMessage(string messageKey, string message) -> string
    {
        var translator;
        string translated, textDomain;

        let translator = <Translator\TranslatorInterface> this->getTranslator();
        let textDomain = this->getTranslatorTextDomain();
        let translated = translator->translate(message, textDomain);

        return translated;
    }

}
