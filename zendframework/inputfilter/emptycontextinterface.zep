/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\InputFilter;

interface EmptyContextInterface
{
    public function setContinueIfEmpty(continueIfEmpty);

    public function continueIfEmpty();

}
