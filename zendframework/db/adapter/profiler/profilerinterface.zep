/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Adapter\Profiler;

interface ProfilerInterface
{
    /**
     * @param string|\Zend\Db\Adapter\StatementContainerInterface $target
     * @return mixed
     */
    public function profilerStart(var target);

    public function profilerFinish();

}
