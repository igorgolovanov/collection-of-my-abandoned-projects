/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Crypt\Symmetric;

interface SymmetricInterface
{
    /**
     * @param string $data
     */
    public function encrypt(string data);

    /**
     * @param string $data
     */
    public function decrypt(string data);

    /**
     * @param string $key
     */
    public function setKey(string key);

    public function getKey();

    public function getKeySize();

    public function getAlgorithm();

    /**
     * @param  string $algo
     */
    public function setAlgorithm(string algo);

    public function getSupportedAlgorithms();

    /**
     * @param string|false $salt
     */
    public function setSalt(var salt);

    public function getSalt();

    public function getSaltSize();

    public function getBlockSize();

    /**
     * @param string $mode
     */
    public function setMode(string mode);

    public function getMode();

    public function getSupportedModes();

}
