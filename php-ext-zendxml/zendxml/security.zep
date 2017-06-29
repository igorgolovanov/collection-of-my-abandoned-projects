/*

This file is part of the php-ext-zendxml package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace ZendXml;

use DOMDocument;
use SimpleXMLElement;

class Security
{
    const ENTITY_DETECT = "Detected use of ENTITY in XML, disabled to prevent XXE/XEE attacks";

    /**
     * Heuristic scan to detect entity in XML
     *
     * @param  string xml
     * @throws Exception\RuntimeException
     */
    protected static function heuristicScan(string xml) -> void
    {
        if xml->index("<!ENTITY") !== false {
            throw new Exception\RuntimeException(self::ENTITY_DETECT);
        }
    }

    /**
     * Scan XML string for potential XXE and XEE attacks
     *
     * @param   string xml
     * @param   DomDocument dom
     * @throws  Exception\RuntimeException
     * @return  SimpleXMLElement|DomDocument|boolean
     */
    public static function scan(string xml, <DOMDocument> dom = null) -> <SimpleXMLElement>|<DomDocument>|boolean
    {
        var useInternalXmlErrors, loadEntities, result, child, isPhpFpm;
        boolean simpleXml = false;
        array errorHandler;

        // If running with PHP-FPM we perform an heuristic scan
        // We cannot use libxml_disable_entity_loader because of this bug
        // @see https://bugs.php.net/bug.php?id=64938
        if self::isPhpFpm() {
            self::heuristicScan(xml);
        }

        if dom === null {
            let simpleXml = true;
            let dom = new DOMDocument();
        }

        let isPhpFpm = self::isPhpFpm();

        if !isPhpFpm {
            let loadEntities = libxml_disable_entity_loader(true);
            let useInternalXmlErrors = libxml_use_internal_errors(true);
        }

        // Load XML with network access disabled (LIBXML_NONET)
        // error disabled with @ for PHP-FPM scenario
        let errorHandler = ["ZendXml\\Security", "scanErrorHandler"];
        set_error_handler(errorHandler, E_WARNING);
        let result = dom->loadXml(xml, LIBXML_NONET);
        restore_error_handler();

        // Entity load to previous setting
        if !isPhpFpm {
            libxml_disable_entity_loader(loadEntities);
            libxml_use_internal_errors(useInternalXmlErrors);
        }

        if !result {
            return false;
        }

        // Scan for potential XEE attacks using ENTITY, if not PHP-FPM
        if !isPhpFpm {
            for child in iterator_to_array(dom->childNodes) {
                if child->nodeType === XML_DOCUMENT_TYPE_NODE {
                    if unlikely child->entities->length > 0 {
                        throw new Exception\RuntimeException(self::ENTITY_DETECT);
                    }
                }
            }
        }

        if simpleXml {
            let result = simplexml_import_dom(dom);
            if !(result instanceof SimpleXMLElement) {
                return false;
            }
            return result;
        }
        return dom;
    }

    final public static function scanErrorHandler(int errno, string errstr) -> boolean
    {
        return substr_count(errstr, "DOMDocument::loadXML()") > 0;
    }

    /**
     * Scan XML file for potential XXE/XEE attacks
     *
     * @param  string $file
     * @param  DOMDocument $dom
     * @throws Exception\InvalidArgumentException
     * @return SimpleXMLElement|DomDocument
     */
    public static function scanFile(string file, <DOMDocument> dom = null) -> <SimpleXMLElement>|<DomDocument>
    {
        var contents;

        if unlikely !file_exists(file) {
            throw new Exception\InvalidArgumentException("The file " . file . " specified doesn't exist");
        }
        let contents = file_get_contents(file);
        return self::scan(contents, dom);
    }

    /**
     * Return true if PHP is running with PHP-FPM
     *
     * @return boolean
     */
    public static function isPhpFpm() -> boolean
    {
        string sapi;

        let sapi = (string) php_sapi_name();

        return sapi->index("fpm") === 0;
    }
}