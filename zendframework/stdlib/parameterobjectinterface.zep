/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Stdlib;

interface ParameterObjectInterface
{
    /**
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function __set(string key, var value) -> void;

    /**
     * @param string $key
     * @return mixed
     */
    public function __get(string key);

    /**
     * @param string $key
     * @return bool
     */
    public function __isset(string key) -> boolean;

    /**
     * @param string $key
     * @return void
     */
    public function __unset(string key) -> void;

}
