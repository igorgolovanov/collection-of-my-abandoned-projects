/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Permissions\Rbac;

class Role extends AbstractRole implements RoleInterface
{
    /**
     * @param string $name
     */
    public function __construct(string name)
    {
    	let this->name = name;
    }
}
