/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Filter;

class MethodMatchFilter implements FilterInterface
{
    /**
     * The method to exclude

     * @var string
     */
    protected method;

    /**
     * Either an exclude or an include

     * @var bool
     */
    protected exclude;

    /**
     * @param string $method The method to exclude or include
     * @param bool $exclude If the method should be excluded
     */
    public function __construct(string method, boolean exclude = true)
    {
        let this->method = method;
        let this->exclude = exclude;
    }

    public function filter(property)
    {
        var pos, str;
        string method;
        boolean exclude;

        let pos = strpos(property, "::");

        if pos !== false {
            let pos = pos + 2;
        } else {
            let pos = 0;
        }

        let str = substr(property, pos);
        let method = this->method;
        let exclude = this->exclude;

        if str === method {
            if exclude {
                return false;
            }
            return true;
        }
        
        return exclude;
    }

}
