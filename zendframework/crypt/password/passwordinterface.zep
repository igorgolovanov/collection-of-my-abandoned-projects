/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Crypt\Password;

interface PasswordInterface
{
    /**
     * Create a password hash for a given plain text password
     *
     * @param  string $password The password to hash
     * @return string The formatted password hash
     */
    public function create(string password) -> string;

    /**
     * Verify a password hash against a given plain text password
     *
     * @param  string $password The password to hash
     * @param  string $hash     The supplied hash to validate
     * @return bool Does the password validate against the hash
     */
    public function verify(string password, string hash) -> boolean;

}
