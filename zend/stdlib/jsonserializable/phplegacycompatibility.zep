/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\JsonSerializable;

/**
 * Interface compatible with the built-in JsonSerializable interface
 *
 * JsonSerializable was introduced in PHP 5.4.0.
 *
 * @see http://php.net/manual/class.jsonserializable.php
 */
interface PhpLegacyCompatibility
{
    /**
     * Returns data which can be serialized by json_encode().
     *
     * @return mixed
     * @see    http://php.net/manual/jsonserializable.jsonserialize.php
     */
    public function jsonSerialize();

}
