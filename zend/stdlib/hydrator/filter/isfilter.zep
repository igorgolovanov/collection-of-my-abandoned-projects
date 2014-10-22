/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Filter;

class IsFilter implements FilterInterface
{
    /**
     * Should return true, if the given filter
     * does not match
     *
     * @param string $property The name of the property
     * @return bool
     */
    public function filter(string property) -> boolean
    {
    	var pos, str;

    	let pos = strpos(property, "::");

    	if pos !== false {
    		let pos = pos + 2;
    	} else {
    		let pos = 0;
    	}

    	let str = substr(property, pos, 2);
    	if str === "is" {
    		return true;
    	}
    	
    	return false;
    }

}
