/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Session;

// todo: types

/**
 * Session manager interface
 */
interface ManagerInterface
{
    public function setConfig(config);

    public function getConfig();

    public function setStorage(storage);

    public function getStorage();

    public function setSaveHandler(saveHandler);

    public function getSaveHandler();

    public function sessionExists();

    public function start();

    public function destroy();

    public function writeClose();

    public function setName(name);

    public function getName();

    public function setId(id);

    public function getId();

    public function regenerateId();

    public function rememberMe(ttl = null);

    public function forgetMe();

    public function expireSessionCookie();

    public function setValidatorChain(chain);

    public function getValidatorChain();

    public function isValid();

}
