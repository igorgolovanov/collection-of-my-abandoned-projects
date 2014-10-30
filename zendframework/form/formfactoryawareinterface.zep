/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Form;

interface FormFactoryAwareInterface
{
    /**
     * Compose a form factory into the object
     *
     * @param Factory $factory
     */
    public function setFormFactory(factory); // todo: type <Factory>

}
