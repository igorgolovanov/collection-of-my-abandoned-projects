/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Tag;

interface TaggableInterface
{
    /**
     * Get the title of the tag
     *
     * @return string
     */
    public function getTitle() -> string;

    /**
     * Get the weight of the tag
     *
     * @return float
     */
    public function getWeight() -> float;

    /**
     * Set a parameter
     *
     * @param string $name
     * @param string $value
     */
    public function setParam(string name, string value);

    /**
     * Get a parameter
     *
     * @param  string $name
     * @return mixed
     */
    public function getParam(string name);

}
