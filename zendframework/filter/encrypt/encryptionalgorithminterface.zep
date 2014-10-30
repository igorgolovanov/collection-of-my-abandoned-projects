/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Filter\Encrypt;

/**
 * Encryption interface
 */
interface EncryptionAlgorithmInterface
{
    /**
     * Encrypts $value with the defined settings
     *
     * @param  string $value Data to encrypt
     * @return string The encrypted data
     */
    public function encrypt(string value) -> string;

    /**
     * Decrypts $value with the defined settings
     *
     * @param  string $value Data to decrypt
     * @return string The decrypted data
     */
    public function decrypt(string value) -> string;

    /**
     * Return the adapter name
     *
     * @return string
     */
    public function toString() -> string;

}
