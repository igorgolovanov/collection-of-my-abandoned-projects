/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di;

interface DependencyInjectionInterface extends LocatorInterface
{
    /**
     * Retrieve a new instance of a class
     *
     * Forces retrieval of a discrete instance of the given class, using the
     * constructor parameters provided.
     *
     * @param  mixed       $name   Class name or service alias
     * @param  array       $params Parameters to pass to the constructor
     * @return object|null
     */
    public function newInstance(name, array! params = []) -> object;

}
