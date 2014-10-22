/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Extractor;

interface ExtractionInterface
{
    /**
     * Extract values from an object
     *
     * @param  object $object
     * @return array
     */
    public function extract(object! $object) -> array;

}
