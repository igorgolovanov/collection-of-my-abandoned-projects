/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Authentication\Adapter;

interface ValidatableAdapterInterface extends AdapterInterface
{
    /**
     * Returns the identity of the account being authenticated, or
     * NULL if none is set.
     *
     * @return mixed
     */
    public function getIdentity();

    /**
     * Sets the identity for binding
     *
     * @param  mixed                       $identity
     * @return ValidatableAdapterInterface
     */
    public function setIdentity(var identity) -> <ValidatableAdapterInterface>;

    /**
     * Returns the credential of the account being authenticated, or
     * NULL if none is set.
     *
     * @return mixed
     */
    public function getCredential();

    /**
     * Sets the credential for binding
     *
     * @param  mixed                       $credential
     * @return ValidatableAdapterInterface
     */
    public function setCredential(var credential) -> <ValidatableAdapterInterface>;

}
