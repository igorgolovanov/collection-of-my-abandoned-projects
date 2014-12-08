/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Validator\Barcode;

interface AdapterInterface
{
    /**
     * Checks the length of a barcode
     *
     * @param  string $value  The barcode to check for proper length
     * @return bool
     */
    public function hasValidLength(string value) -> boolean;

    /**
     * Checks for allowed characters within the barcode
     *
     * @param  string $value The barcode to check for allowed characters
     * @return bool
     */
    public function hasValidCharacters(string value) -> boolean;

    /**
     * Validates the checksum
     *
     * @param string $value The barcode to check the checksum for
     * @return bool
     */
    public function hasValidChecksum(string value) -> boolean;

    /**
     * Returns the allowed barcode length
     *
     * @return int|array
     */
    public function getLength() -> int|array;

    /**
     * Returns the allowed characters
     *
     * @return int|string|array
     */
    public function getCharacters() -> int|string|array;

    /**
     * Returns if barcode uses a checksum
     *
     * @return bool
     */
    public function getChecksum() -> boolean;

    /**
     * Sets the checksum validation, if no value is given, the actual setting is returned
     *
     * @param  bool $check
     * @return AbstractAdapter|bool
     */
    public function useChecksum(boolean check = null); // todo: -> <AbstractAdapter>|boolean;

}
