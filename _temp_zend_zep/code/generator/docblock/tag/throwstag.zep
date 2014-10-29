/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator\DocBlock\Tag;

class ThrowsTag extends AbstractTypeableTag implements TagInterface
{
    /**
     * @return string
     */
    public function getName() -> string
    {
        return "throws";
    }

    /**
     * @return string
     */
    public function generate() -> string
    {
        string output = "@throws", typesAsString;

        if !empty this->types {
            let typesAsString = this->getTypesAsString();
            let output = output . " " . typesAsString;
        }
        if !empty this->description {
            let output = output . " " . this->description;
        }

        return output;
    }

}
