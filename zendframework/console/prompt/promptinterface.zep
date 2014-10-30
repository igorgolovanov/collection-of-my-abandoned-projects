/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Console\Prompt;

use Zend\Console\Adapter\AdapterInterface as ConsoleAdapter;

interface PromptInterface
{
    /**
     * Show the prompt to user and return the answer.
     *
     * @return mixed
     */
    public function show();

    /**
     * Return last answer to this prompt.
     *
     * @return mixed
     */
    public function getLastResponse();

    /**
     * Return console adapter to use when showing prompt.
     *
     * @return ConsoleAdapter
     */
    public function getConsole() -> <ConsoleAdapter>;

    /**
     * Set console adapter to use when showing prompt.
     *
     * @param ConsoleAdapter $adapter
     * @return void
     */
    public function setConsole(<ConsoleAdapter> adapter) -> void;

}
