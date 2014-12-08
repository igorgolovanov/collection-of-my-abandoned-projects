/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http;

use ArrayIterator;
use Countable;
use Iterator;
use Traversable;
use Zend\Loader\PluginClassLocator;

/**
 * Basic HTTP headers collection functionality
 * Handles aggregation of headers
 *
 * @see        http://www.w3.org/Protocols/rfc2616/rfc2616-sec4.html#sec4.2
 */
class Headers implements Countable, Iterator
{
    /**
     * @var PluginClassLocator
     */
    protected pluginClassLoader;

    /**
     * @var array key names for $headers array
     */
    protected headersKeys = [];

    /**
     * @var array Array of header array information or Header instances
     */
    protected headers = [];

    /**
     * Populates headers from string representation
     *
     * Parses a string for headers, and aggregates them, in order, in the
     * current instance, primarily as strings until they are needed (they
     * will be lazy loaded)
     *
     * @param  string $string
     * @return Headers
     * @throws Exception\RuntimeException
     */
    public static function fromString(string $string) -> <Headers>
    {
        var className, headers, current = [], lines, line,
            name, matches = null, key;
        string exceptionMsg;

        let className = get_called_class();
        let headers = new {className}();
        let lines = explode("\r\n", $string);

        for line in lines {
            // check if a header name is present
            if preg_match("/^(?P<name>[^()><@,;:\"\\/\[\]?=}{ \t]+):.*$/", line, matches) {
                let name = current["name"];
                if current {
                    // a header name was present, then store the current complete line
                    let key = static::createKey(name);

                    let this->headersKeys[] = key;
                    let this->headers[] = current;
                }
                let current = ["name": name, "line": trim(line)];
                continue;
            }
            if preg_match("/^(?P<ws>\s+).*$/", line, matches) {
                // continuation: append to current line
                let current["line"] .= "\r\n" . matches["ws"] . trim(line);
                continue;
            }
            if preg_match("/^\s*$/", line) {
                // empty line indicates end of headers
                break;
            }
            // Line does not match header format!
            let exceptionMsg = "Line \"" . line . "\" does not match header format!";
            throw new Exception\RuntimeException(exceptionMsg);
        }

        if current {
            let name = current["name"];
            let key = static::createKey(name);

            let headers->headersKeys[] = key;
            let headers->headers[] = current;
        }

        return headers;
    }

    /**
     * Set an alternate implementation for the PluginClassLoader
     *
     * @param \Zend\Loader\PluginClassLocator $pluginClassLoader
     * @return Headers
     */
    public function setPluginClassLoader(<PluginClassLocator> pluginClassLoader) -> <Headers>
    {
        let this->pluginClassLoader = pluginClassLoader;

        return this;
    }

    /**
     * Return an instance of a PluginClassLocator, lazyload and inject map if necessary
     *
     * @return PluginClassLocator
     */
    public function getPluginClassLoader()
    {
        var pluginClassLoader;

        let pluginClassLoader = this->pluginClassLoader;
        if pluginClassLoader === null {
            let pluginClassLoader = new HeaderLoader();
            let this->pluginClassLoader = pluginClassLoader;
        }

        return this->pluginClassLoader;
    }

    /**
     * Add many headers at once
     *
     * Expects an array (or Traversable object) of type/value pairs.
     *
     * @param  array|Traversable $headers
     * @return Headers
     * @throws Exception\InvalidArgumentException
     */
    public function addHeaders(var headers) -> <Headers>
    {
        string exceptionMsg;
        var type, name, value, count, k, v;

        if unlikely typeof headers != "array" && !(headers instanceof Traversable) {
            let type = typeof headers;
            if type == "object" {
                let type = get_class(headers);
            }
            let exceptionMsg = "Expected array or Traversable; received \"" . type . "\"";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }
        if typeof headers == "object" {
            let headers = iterator_to_array(headers);
        }

        for name, value in headers {
            if typeof name == "integer" {
                if typeof value == "string" {
                    this->addHeaderLine(value);
                    continue;
                }
                if typeof value == "array" {
                    let count = count(value);
                    if count == 1 {
                        let k = key(value);
                        let v = current(value);
                        this->addHeaderLine(k, v);
                        continue;
                    }
                    if count == 2 {
                        let k = value[0];
                        let v = value[1];
                        this->addHeaderLine(k, v);
                        continue;
                    }
                }
                if value instanceof Header\HeaderInterface {
                    this->addHeader(value);
                }
            }
            if typeof name == "string" {
                this->addHeaderLine(name, value);
            }
        }
        return this;
    }

    /**
     * Add a raw header line, either in name => value, or as a single string 'name: value'
     *
     * This method allows for lazy-loading in that the parsing and instantiation of Header object
     * will be delayed until they are retrieved by either get() or current()
     *
     * @throws Exception\InvalidArgumentException
     * @param string $headerFieldNameOrLine
     * @param string $fieldValue optional
     * @return Headers
     */
    public function addHeaderLine(string headerFieldNameOrLine, var fieldValue = null) -> <Headers>
    {
        var matches = null, headerName, headerKey, line;

        if preg_match("", headerFieldNameOrLine, matches) && fieldValue === null {
            let headerName = matches["name"];
            let headerKey = static::createKey(headerName);
            let line = headerFieldNameOrLine;
        } elseif unlikely fieldValue === null {
            throw new Exception\InvalidArgumentException("A field name was provided without a field value");
        } else {
            let headerName = headerFieldNameOrLine;
            let headerKey = static::createKey(headerFieldNameOrLine);

            if typeof fieldValue == "array" {
                let fieldValue = implode(", ", fieldValue);
            }
            let line = headerFieldNameOrLine . ": " . fieldValue;
        }

        let this->headersKeys[] = headerKey;
        let this->headers[] = ["name": headerName, "line": line];

        return this;
    }

    /**
     * Add a Header to this container, for raw values @see addHeaderLine() and addHeaders()
     *
     * @param  Header\HeaderInterface $header
     * @return Headers
     */
    public function addHeader(<Header\HeaderInterface> header) -> <Headers>
    {
        var key, name;

        let name = header->getFieldName();
        let key = static::createKey(name);

        let this->headersKeys[] = key;
        let this->headers[] = header;

        return this;
    }

    /**
     * Remove a Header from the container
     *
     * @param Header\HeaderInterface $header
     * @return bool
     */
    public function removeHeader(<Header\HeaderInterface> header) -> boolean
    {
        var index;

        let index = array_search(header, this->headers);

        if index !== false {
            unset this->headersKeys[index];
            unset this->headers[index];

            return true;
        }
        return false;
    }

    /**
     * Clear all headers
     *
     * Removes all headers from queue
     *
     * @return Headers
     */
    public function clearHeaders() -> <Headers>
    {
        let this->headers = [];
        let this->headersKeys = [];

        return this;
    }

    /**
     * Get all headers of a certain name/type
     *
     * @param  string $name
     * @return bool|Header\HeaderInterface|ArrayIterator
     */
    public function get(string name) -> boolean|<Header\HeaderInterface>|<\ArrayIterator>
    {
        var current, className, headers = [], header, key, keys, index;

        let key = static::createKey(name);
        if !in_array(key, this->headersKeys) {
            return false;
        }


        let current = this->headers[name]; // todo:  check index name
        let className = this->getPluginClassLoader()->load(key);
        if !className {
            let className = "Zend\\Http\\Header\\GenericHeader";
        }
        if is_subclass_of(className, "Zend\\Http\\Header\\MultipleHeaderInterface") {
            let keys = array_keys(this->headersKeys, key);
            for index in keys {
                if typeof this->headers[index] == "array" {
                    this->lazyLoadHeader(index);
                }
            }
            let keys = array_keys(this->headersKeys, key);
            for index in keys {
                let headers[] = this->headers[index];
            }
            return new ArrayIterator(headers);
        }

        let index = array_search(key, this->headersKeys);
        if index === false {
            return false;
        }
        if typeof this->headers[index] == "array" {
            return this->lazyLoadHeader(index);
        }

        return this->headers[index];
    }

    /**
     * Test for existence of a type of header
     *
     * @param  string $name
     * @return bool
     */
    public function has(string name) -> boolean
    {
        var key;

        let key = static::createKey(name);

        return in_array(key, this->headersKeys);
    }

    /**
     * Advance the pointer for this object as an iterator
     *
     * @return void
     */
    public function next() -> void
    {
        next(this->headers);
    }

    /**
     * Return the current key for this object as an iterator
     *
     * @return mixed
     */
    public function key()
    {
        return key(this->headers);
    }

    /**
     * Is this iterator still valid?
     *
     * @return bool
     */
    public function valid() -> boolean
    {
        var current;

        let current = current(this->headers);

        return current !== false;
    }

    /**
     * Reset the internal pointer for this object as an iterator
     *
     * @return void
     */
    public function rewind() -> void
    {
        reset(this->headers);
    }

    /**
     * Return the current value for this iterator, lazy loading it if need be
     *
     * @return array|Header\HeaderInterface
     */
    public function current() -> array|<Header\HeaderInterface>
    {
        var current, key;

        let current = current(this->headers);
        if typeof current == "array" {
            let key = key(this->headers);
            let current = this->lazyLoadHeader(key);
        }

        return current;
    }

    /**
     * Return the number of headers in this contain, if all headers have not been parsed, actual count could
     * increase if MultipleHeader objects exist in the Request/Response.  If you need an exact count, iterate
     *
     * @return int count of currently known headers
     */
    public function count() -> int
    {
        return count(this->headers);
    }

    /**
     * Render all headers at once
     *
     * This method handles the normal iteration of headers; it is up to the
     * concrete classes to prepend with the appropriate status/request line.
     *
     * @return string
     */
    public function toString() -> string
    {
        string headers = "";
        var fieldName, fieldValue, value;

        for fieldName, fieldValue in this->toArray() {
            if typeof fieldValue == "array" {
                // Handle multi-value headers
                for value in fieldValue {
                    let headers .= fieldName . ": " . value . "\r\n";
                }
            }
            // Handle single-value headers
            let headers .= fieldName . ": " . fieldValue . "\r\n";
        }

        return headers;
    }

    /**
     * Return the headers container as an array
     *
     * @todo determine how to produce single line headers, if they are supported
     * @return array
     */
    public function toArray() -> array
    {
        var headers = [], header, matches, name, value;

        for header in this->headers {
            if header instanceof Header\MultipleHeaderInterface {
                let name = header->getFieldName();
                let value = header->getFieldValue();
                if !isset headers[name] {
                    let headers[name] = [];
                }
                let headers[name][] = value;
            } elseif header instanceof Header\HeaderInterface {
                let name = header->getFieldName();
                let value = header->getFieldValue();
                let headers[name] = value;
            } else {
                let matches = null;

                preg_match("/^(?P<name>[^()><@,;:\"\\/\[\]?=}{ \t]+):\s*(?P<value>.*)$/", header["line"], matches);

                if matches {
                    let name = matches["name"];
                    let value = matches["value"];
                    let headers[name] = value;
                }
            }
        }

        return headers;
    }

    /**
     * By calling this, it will force parsing and loading of all headers, after this count() will be accurate
     *
     * @return bool
     */
    public function forceLoading() -> boolean
    {
        var item;

        for item in iterator(this) {
            // $item should now be loaded
        }
        return true;
    }

    /**
     * @param $index
     * @return mixed|void
     */
    protected function lazyLoadHeader(var index)
    {
        var current, className, headers, header;

        let current = this->headers[index];
        let className = this->getPluginClassLoader()->load(index); //todo: check code
        if !className {
            let className = "Zend\\Http\\Header\\GenericHeader";
        }
        let headers = call_user_func([className, "fromString"], current["line"]);
        if typeof headers == "array" {
            let current = array_shift(headers);
            let this->headers[index] = current;

            for header in headers {
                let this->headersKeys[] = index; // todo: check code
                let this->headers[] = header;
            }
            return current;
        }

        let this->headers[index] = headers;

        return headers;
    }

    /**
     * Create array key from header name
     *
     * @param string $name
     * @return string
     */
    protected static function createKey(string name) -> string
    {
        array wildcards = ["-", "_", " ", "."];
        var key;

        let name = name->lower();
        let key = str_replace(wildcards, "", name);

        return key;
    }
}
