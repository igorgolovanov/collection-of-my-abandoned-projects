/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Text\Table\Decorator;

/**
 * Interface for Zend\Text\Table decorators
 */
interface DecoratorInterface
{
    /**
     * Get a single character for the top left corner
     *
     * @return string
     */
    public function getTopLeft() -> string;

    /**
     * Get a single character for the top right corner
     *
     * @return string
     */
    public function getTopRight() -> string;

    /**
     * Get a single character for the bottom left corner
     *
     * @return string
     */
    public function getBottomLeft() -> string;

    /**
     * Get a single character for the bottom right corner
     *
     * @return string
     */
    public function getBottomRight() -> string;

    /**
     * Get a single character for a vertical line
     *
     * @return string
     */
    public function getVertical() -> string;

    /**
     * Get a single character for a horizontal line
     *
     * @return string
     */
    public function getHorizontal() -> string;

    /**
     * Get a single character for a crossing line
     *
     * @return string
     */
    public function getCross() -> string;

    /**
     * Get a single character for a vertical divider right
     *
     * @return string
     */
    public function getVerticalRight() -> string;

    /**
     * Get a single character for a vertical divider left
     *
     * @return string
     */
    public function getVerticalLeft() -> string;

    /**
     * Get a single character for a horizontal divider down
     *
     * @return string
     */
    public function getHorizontalDown() -> string;

    /**
     * Get a single character for a horizontal divider up
     *
     * @return string
     */
    public function getHorizontalUp() -> string;

}
