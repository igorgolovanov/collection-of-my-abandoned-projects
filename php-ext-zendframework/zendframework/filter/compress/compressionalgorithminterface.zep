/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Filter\Compress;

/**
 * Compression interface
 */
interface CompressionAlgorithmInterface
{
    /**
     * Compresses $value with the defined settings
     *
     * @param  string $value Data to compress
     * @return string The compressed data
     */
    public function compress(string value) -> string;

    /**
     * Decompresses $value with the defined settings
     *
     * @param  string $value Data to decompress
     * @return string The decompressed data
     */
    public function decompress(string value) -> string;

    /**
     * Return the adapter name
     *
     * @return string
     */
    public function toString() -> string;

}
