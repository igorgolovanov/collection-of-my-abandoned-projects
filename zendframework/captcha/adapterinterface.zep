/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Captcha;

use Zend\Validator\ValidatorInterface;

/**
 * Generic Captcha adapter interface
 *
 * Each specific captcha implementation should implement this interface
 */
interface AdapterInterface extends ValidatorInterface
{
    /**
     * Generate a new captcha
     *
     * @return string new captcha ID
     */
    public function generate() -> string;

    /**
     * Set captcha name
     *
     * @param  string $name
     * @return AdapterInterface
     */
    public function setName(string name) -> <AdapterInterface>;

    /**
     * Get captcha name
     *
     * @return string
     */
    public function getName() -> string;

    /**
     * Get helper name to use when rendering this captcha type
     *
     * @return string
     */
    public function getHelperName() -> string;

}
