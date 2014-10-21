/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\ModuleManager\Listener;

/**
 * Module resolver listener
 */
class ModuleDependencyCheckerListener
{
    /**
     * @var array of already loaded modules, indexed by module name
     */
    protected loaded = [];

    /**
     * @param \Zend\ModuleManager\ModuleEvent $e
     *
     * @throws Exception\MissingDependencyModuleException
     */
    public function __invoke(<\Zend\ModuleManager\ModuleEvent> e)
    {

    }

}
