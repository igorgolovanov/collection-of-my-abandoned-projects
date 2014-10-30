/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Config\Processor;

interface ProcessorInterface
{
    /**
     * Process the whole Config structure and recursively parse all its values.
     *
     * @param  Config $value
     * @return Config
     */
    public function process(value); // todo: types

    /**
     * Process a single value
     *
     * @param  mixed $value
     * @return mixed
     */
    public function processValue(value); // todo: types

}
