/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Log\Writer;

interface WriterInterface
{
    /**
     * Add a log filter to the writer
     *
     * @param  int|string|Filter $filter
     * @return WriterInterface
     */
    public function addFilter(var filter) -> <WriterInterface>;

    /**
     * Set a message formatter for the writer
     *
     * @param string|Formatter $formatter
     * @return WriterInterface
     */
    public function setFormatter(string formatter) -> <WriterInterface>;

    /**
     * Write a log message
     *
     * @param  array $event
     * @return WriterInterface
     */
    public function write(array! event) -> <WriterInterface>;

    /**
     * Perform shutdown activities
     *
     * @return void
     */
    public function shutdown() -> void;

}
