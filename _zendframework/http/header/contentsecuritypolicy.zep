/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http\Header;

/**
 * Content Security Policy 1.0 Header
 *
 * @link http://www.w3.org/TR/CSP/
 */
class ContentSecurityPolicy implements HeaderInterface
{
    /**
     * Valid directive names
     *
     * @var array
     */
    protected validDirectiveNames = [
		"default-src", 
		"script-src", 
		"object-src", 
		"style-src", 
		"img-src", 
		"media-src", 
		"frame-src", 
		"font-src", 
		"connect-src", 
		"sandbox", 
		"report-uri"
	];

    /**
     * The directives defined for this policy
     *
     * @var array
     */
    protected directives = [];

    /**
     * Get the list of defined directives
     *
     * @return array
     */
    public function getDirectives() -> array
    {

    }

    /**
     * Sets the directive to consist of the source list
     *
     * Reverses http://www.w3.org/TR/CSP/#parsing-1
     *
     * @param string $name The directive name.
     * @param array $sources The source list.
     * @return self
     * @throws Exception\InvalidArgumentException If the name is not a valid directive name.
     */
    public function setDirective(string name, array! sources) -> <ContentSecurityPolicy>
    {

    }

    /**
     * Create Content Security Policy header from a given header line
     *
     * @param string $headerLine The header line to parse.
     * @return self
     * @throws Exception\InvalidArgumentException If the name field in the given header line does not match.
     */
    public static function fromString(string headerLine) -> <ContentSecurityPolicy>
    {

    }

    /**
     * Get the header name
     *
     * @return string
     */
    public function getFieldName() -> string
    {

    }

    /**
     * Get the header value
     *
     * @return string
     */
    public function getFieldValue() -> string
    {

    }

    /**
     * Return the header as a string
     *
     * @return string
     */
    public function toString() -> string
    {

    }

}
