/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Config\Writer;

interface WriterInterface
{
    /**
     * Write a config object to a file.
     *
     * @param  string  $filename
     * @param  mixed   $config
     * @param  bool $exclusiveLock
     * @return void
     */
    public function toFile(string filename, var config, boolean exclusiveLock = true) -> void;

    /**
     * Write a config object to a string.
     *
     * @param  mixed $config
     * @return string
     */
    public function toString(var config) -> string;

}
