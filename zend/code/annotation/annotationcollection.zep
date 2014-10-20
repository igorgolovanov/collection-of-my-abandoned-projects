/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Annotation;

use ArrayObject;

class AnnotationCollection extends ArrayObject
{
    /**
     * Checks if the collection has annotations for a class
     *
     * @param  string $class
     * @return bool
     */
    public function hasAnnotation(string $class) -> boolean
    {
        var annotation;
        string className;

        for annotation in this {
            let className = get_class(annotation);
            if className == $class {
                return true;
            }
        }

        return false;
    }

}
