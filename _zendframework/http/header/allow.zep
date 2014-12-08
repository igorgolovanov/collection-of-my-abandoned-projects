/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * Allow Header
 *
 * @link       http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14.7
 */
class Allow implements HeaderInterface
{
    /**
     * List of request methods
     * true states that method is allowed, false - disallowed
     * By default GET and POST are allowed
     *
     * @var array
     */
    protected methods = [
		"OPTIONS": false, 
		"GET": true, 
		"HEAD": false, 
		"POST": true, 
		"PUT": false, 
		"DELETE": false, 
		"TRACE": false, 
		"CONNECT": false, 
		"PATCH": false
	];

    /**
     * Create Allow header from header line
     *
     * @param string $headerLine
     * @return Allow
     * @throws Exception\InvalidArgumentException
     */
    public static function fromString(string headerLine) -> <Allow>
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
     * Get comma-separated list of allowed methods
     *
     * @return string
     */
    public function getFieldValue() -> string
    {

    }

    /**
     * Get list of all defined methods
     *
     * @return array
     */
    public function getAllMethods() -> array
    {

    }

    /**
     * Get list of allowed methods
     *
     * @return array
     */
    public function getAllowedMethods() -> array
    {

    }

    /**
     * Allow methods or list of methods
     *
     * @param array|string $allowedMethods
     * @return Allow
     */
    public function allowMethods(var allowedMethods) -> <Allow>
    {

    }

    /**
     * Disallow methods or list of methods
     *
     * @param array|string $disallowedMethods
     * @return Allow
     */
    public function disallowMethods(var disallowedMethods) -> <Allow>
    {

    }

    /**
     * Convenience alias for @see disallowMethods()
     *
     * @param array|string $disallowedMethods
     * @return Allow
     */
    public function denyMethods(var disallowedMethods) -> <Allow>
    {

    }

    /**
     * Check whether method is allowed
     *
     * @param string $method
     * @return bool
     */
    public function isAllowedMethod(string method) -> boolean
    {

    }

    /**
     * Return header as string
     *
     * @return string
     */
    public function toString() -> string
    {

    }

}
