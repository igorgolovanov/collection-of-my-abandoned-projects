/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * Age HTTP Header
 *
 * @link       http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.6
 */
class Age implements HeaderInterface
{
    /**
     * Estimate of the amount of time in seconds since the response
     *
     * @var int
     */
    protected deltaSeconds;

    /**
     * Create Age header from string
     *
     * @param string $headerLine
     * @return Age
     * @throws Exception\InvalidArgumentException
     */
    public static function fromString(string headerLine) -> <Age>
    {

    }

    public function __construct(deltaSeconds = null)
    {

    }

    /**
     * Get header name
     *
     * @return string
     */
    public function getFieldName() -> string
    {

    }

    /**
     * Get header value (number of seconds)
     *
     * @return int
     */
    public function getFieldValue() -> int
    {

    }

    /**
     * Set number of seconds
     *
     * @param int $delta
     * @return RetryAfter
     */
    public function setDeltaSeconds(int delta) -> <RetryAfter>
    {

    }

    /**
     * Get number of seconds
     *
     * @return int
     */
    public function getDeltaSeconds() -> int
    {

    }

    /**
     * Return header line
     * In case of overflow RFC states to set value of 2147483648 (2^31)
     *
     * @return string
     */
    public function toString() -> string
    {

    }

}
