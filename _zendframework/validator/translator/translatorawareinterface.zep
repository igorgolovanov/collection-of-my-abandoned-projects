/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Validator\Translator;

interface TranslatorAwareInterface
{
    /**
     * Sets translator to use in helper
     *
     * @param  TranslatorInterface $translator  [optional] translator.
     *             Default is null, which sets no translator.
     * @param  string $textDomain  [optional] text domain
     *             Default is null, which skips setTranslatorTextDomain
     * @return self
     */
    public function setTranslator(<TranslatorInterface> translator = null, string textDomain = null) -> <TranslatorAwareInterface>;

    /**
     * Returns translator used in object
     *
     * @return TranslatorInterface|null
     */
    public function getTranslator() -> <TranslatorInterface>;

    /**
     * Checks if the object has a translator
     *
     * @return bool
     */
    public function hasTranslator() -> boolean;

    /**
     * Sets whether translator is enabled and should be used
     *
     * @param  bool $enabled [optional] whether translator should be used.
     *                  Default is true.
     * @return TranslatorAwareInterface
     */
    public function setTranslatorEnabled(boolean enabled = true) -> <TranslatorAwareInterface>;

    /**
     * Returns whether translator is enabled and should be used
     *
     * @return bool
     */
    public function isTranslatorEnabled() -> boolean;

    /**
     * Set translation text domain
     *
     * @param  string $textDomain
     * @return TranslatorAwareInterface
     */
    public function setTranslatorTextDomain(string textDomain = "default") -> <TranslatorAwareInterface>;

    /**
     * Return the translation text domain
     *
     * @return string
     */
    public function getTranslatorTextDomain() -> string;

}
