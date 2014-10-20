/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib;

interface MessageInterface
{
    /**
     * Set metadata
     *
     * @param  string|int|array|\Traversable $spec
     * @param  mixed $value
     */
    public function setMetadata(var spec, value = null);

    /**
     * Get metadata
     *
     * @param  null|string|int $key
     * @return mixed
     */
    public function getMetadata(var key = null);

    /**
     * Set content
     *
     * @param  mixed $content
     * @return mixed
     */
    public function setContent(content);

    /**
     * Get content
     *
     * @return mixed
     */
    public function getContent();

}
