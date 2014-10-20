
namespace Zend\Log;

/**
 * Logger aware interface
 */
interface LoggerAwareInterface
{
    /**
     * Set logger instance
     *
     * @param LoggerInterface
     * @return void
     */
    public function setLogger(<LoggerInterface> logger) -> void;

}
