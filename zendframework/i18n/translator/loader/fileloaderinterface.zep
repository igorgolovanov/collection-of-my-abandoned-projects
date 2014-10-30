/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\I18n\Translator\Loader;

/**
 * File loader interface.
 */
interface FileLoaderInterface
{
    /**
     * Load translations from a file.
     *
     * @param  string $locale
     * @param  string $filename
     * @return \Zend\I18n\Translator\TextDomain|null
     */
    public function load(string locale, string filename); // todo: -> <\Zend\I18n\Translator\TextDomain>;

}
