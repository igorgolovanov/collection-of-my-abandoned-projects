/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Tag\Cloud\Decorator;

/**
 * Interface for decorators
 */
interface DecoratorInterface
{
    /**
     * Constructor
     *
     * Allow passing options to the constructor.
     *
     * @param  mixed $options
     */
    public function __construct(var options = null);

    /**
     * Render a list of tags
     *
     * @param  mixed $tags
     * @return string
     */
    public function render(var tags) -> string;

}
