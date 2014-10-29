/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ModuleManager\Listener;

/**
 * Abstract listener
 */
abstract class AbstractListener
{
    /**
     * @var ListenerOptions
     */
    protected options;

    /**
     * __construct
     *
     * @param  ListenerOptions $options
     */
    public function __construct(<ListenerOptions> options = null)
    {

    }

    /**
     * Get options.
     *
     * @return ListenerOptions
     */
    public function getOptions() -> <ListenerOptions>
    {

    }

    /**
     * Set options.
     *
     * @param ListenerOptions $options the value to be set
     * @return AbstractListener
     */
    public function setOptions(<ListenerOptions> options) -> <AbstractListener>
    {

    }

    /**
     * Write a simple array of scalars to a file
     *
     * @param  string $filePath
     * @param  array $array
     * @return AbstractListener
     */
    protected function writeArrayToFile(string filePath, array $array) -> <AbstractListener>
    {

    }

}
