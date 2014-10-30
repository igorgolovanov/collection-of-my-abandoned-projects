/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Authentication;

/**
 * Provides an API for authentication and identity management
 */
interface AuthenticationServiceInterface
{
    /**
     * Authenticates and provides an authentication result
     *
     * @return Result
     */
    public function authenticate(); //todo: -> <Result>;

    /**
     * Returns true if and only if an identity is available
     *
     * @return bool
     */
    public function hasIdentity() -> boolean;

    /**
     * Returns the authenticated identity or null if no identity is available
     *
     * @return mixed|null
     */
    public function getIdentity();

    /**
     * Clears the identity
     *
     * @return void
     */
    public function clearIdentity() -> void;

}
