/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mail\Storage\Part;

interface PartInterface extends \RecursiveIterator, \Traversable, \Iterator
{
    /**
     * Check if part is a multipart message
     *
     * @return bool if part is multipart
     */
    public function isMultipart() -> boolean;

    /**
     * Body of part
     *
     * If part is multipart the raw content of this part with all sub parts is returned
     *
     * @return string body
     * @throws Exception\ExceptionInterface
     */
    public function getContent() -> string;

    /**
     * Return size of part
     *
     * @return int size
     */
    public function getSize() -> int;

    /**
     * Get part of multipart message
     *
     * @param  int $num number of part starting with 1 for first part
     * @return PartInterface wanted part
     * @throws Exception\ExceptionInterface
     */
    public function getPart(int num) -> <PartInterface>;

    /**
     * Count parts of a multipart part
     *
     * @return int number of sub-parts
     */
    public function countParts() -> int;

    /**
     * Get all headers
     *
     * The returned headers are as saved internally. All names are lowercased. The value is a string or an array
     * if a header with the same name occurs more than once.
     *
     * @return \Zend\Mail\Headers
     */
    public function getHeaders(); // todo: -> <\Zend\Mail\Headers>;

    /**
     * Get a header in specified format
     *
     * Internally headers that occur more than once are saved as array, all other as string. If $format
     * is set to string implode is used to concat the values (with Zend\Mime\Mime::LINEEND as delim).
     *
     * @param  string $name   name of header, matches case-insensitive, but camel-case is replaced with dashes
     * @param  string $format change type of return value to 'string' or 'array'
     * @return string|array|\Zend\Mail\Header\HeaderInterface|\ArrayIterator value of header in wanted or internal format
     * @throws Exception\ExceptionInterface
     */
    public function getHeader(string name, string format = null) -> string|array|<\Zend\Mail\Header\HeaderInterface>|<\ArrayIterator>;

    /**
     * Get a specific field from a header like content type or all fields as array
     *
     * If the header occurs more than once, only the value from the first header
     * is returned.
     *
     * Throws an exception if the requested header does not exist. If
     * the specific header field does not exist, returns null.
     *
     * @param  string $name       name of header, like in getHeader()
     * @param  string $wantedPart the wanted part, default is first, if null an array with all parts is returned
     * @param  string $firstName  key name for the first part
     * @return string|array wanted part or all parts as array($firstName => firstPart, partname => value)
     * @throws Exception\ExceptionInterface
     */
    public function getHeaderField(string name, string wantedPart = "0", string firstName = "0") -> string|array;

    /**
     * Getter for mail headers - name is matched in lowercase
     *
     * This getter is short for PartInterface::getHeader($name, 'string')
     *
     * @see PartInterface::getHeader()
     *
     * @param  string $name header name
     * @return string value of header
     * @throws Exception\ExceptionInterface
     */
    public function __get(string name) -> string;

    /**
     * magic method to get content of part
     *
     * @return string content
     */
    public function __toString() -> string;

}
