/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Cache\Pattern;

interface PatternInterface
{
    /**
     * Set pattern options
     *
     * @param  PatternOptions $options
     * @return PatternInterface
     */
    public function setOptions( options) -> <PatternInterface>; // todo: <PatternOptions> options

    /**
     * Get all pattern options
     *
     * @return PatternOptions
     */
    public function getOptions() -> <PatternOptions>;

}
