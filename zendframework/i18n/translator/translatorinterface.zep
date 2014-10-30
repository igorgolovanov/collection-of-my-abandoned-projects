/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\I18n\Translator;

/**
 * Translator interface.
 */
interface TranslatorInterface
{
    /**
     * Translate a message.
     *
     * @param  string $message
     * @param  string $textDomain
     * @param  string $locale
     * @return string
     */
    public function translate(string message, string textDomain = "default", string locale = null) -> string;

    /**
     * Translate a plural message.
     *
     * @param  string      $singular
     * @param  string      $plural
     * @param  int         $number
     * @param  string      $textDomain
     * @param  string|null $locale
     * @return string
     */
    public function translatePlural(string singular, string plural, int number, string textDomain = "default", string locale = null) -> string;

}
