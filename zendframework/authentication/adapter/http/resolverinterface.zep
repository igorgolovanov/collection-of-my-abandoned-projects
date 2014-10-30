/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Authentication\Adapter\Http;

/**
 * Auth HTTP Resolver Interface
 *
 * Defines an interface to resolve a username/realm combination into a shared
 * secret usable by HTTP Authentication.
 */
interface ResolverInterface
{
    /**
     * Resolve username/realm to password/hash/etc.
     *
     * @param  string $username Username
     * @param  string $realm    Authentication Realm
     * @param  string $password Password (optional)
     * @return string|array|false User's shared secret as string if found in realm, or User's identity as array
     *         if resolved, false otherwise.
     */
    public function resolve(string username, string realm, string password = null) -> string|array;

}
