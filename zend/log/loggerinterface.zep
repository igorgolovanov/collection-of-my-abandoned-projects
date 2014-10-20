
namespace Zend\Log;

interface LoggerInterface
{
    /**
     * @param string $message
     * @param array|Traversable $extra
     * @return LoggerInterface
     */
    public function emerg(string message, var extra = []) -> <LoggerInterface>;

    /**
     * @param string $message
     * @param array|Traversable $extra
     * @return LoggerInterface
     */
    public function alert(string message, var extra = []) -> <LoggerInterface>;

    /**
     * @param string $message
     * @param array|Traversable $extra
     * @return LoggerInterface
     */
    public function crit(string message, var extra = []) -> <LoggerInterface>;

    /**
     * @param string $message
     * @param array|Traversable $extra
     * @return LoggerInterface
     */
    public function err(string message, var extra = []) -> <LoggerInterface>;

    /**
     * @param string $message
     * @param array|Traversable $extra
     * @return LoggerInterface
     */
    public function warn(string message, var extra = []) -> <LoggerInterface>;

    /**
     * @param string $message
     * @param array|Traversable $extra
     * @return LoggerInterface
     */
    public function notice(string message, var extra = []) -> <LoggerInterface>;

    /**
     * @param string $message
     * @param array|Traversable $extra
     * @return LoggerInterface
     */
    public function info(string message, var extra = []) -> <LoggerInterface>;

    /**
     * @param string $message
     * @param array|Traversable $extra
     * @return LoggerInterface
     */
    public function debug(string message, var extra = []) -> <LoggerInterface>;

}
