/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server;

use Zend\Stdlib\ErrorHandler;

/**
 * \Zend\Server\Cache: cache server definitions
 */
class Cache
{
    /**
     * @var array Methods to skip when caching server
     */
    protected static skipMethods; // todo: []

    /**
     * Cache a file containing the dispatch list.
     *
     * Serializes the server definition stores the information
     * in $filename.
     *
     * Returns false on any error (typically, inability to write to file), true
     * on success.
     *
     * @param  string $filename
     * @param  \Zend\Server\Server $server
     * @return bool
     */
    public static function save(string filename, <\Zend\Server\Server> server) -> boolean
    {
        var methods, definition, method, test;
        array skipMethods;
        string name, serialized;

        if empty filename || (!file_exists(filename) && !is_writable(dirname(filename))) {
            return false;
        }

        let methods = server->getFunctions();

        if methods instanceof Definition {
            let definition = new Definition();
            for method in methods {
                let skipMethods = static::skipMethods;
                let name = method->getName();
                if in_array(name, skipMethods) {
                    continue;
                }
                definition->addMethod(method);
            }
            let methods = definition;
        }

        ErrorHandler::start();
        let serialized = serialize(methods);
        let test = file_put_contents(filename, serialized);
        ErrorHandler::stop();

        return test !== 0;
    }

    /**
     * Load server definition from a file
     *
     * Unserializes a stored server definition from $filename. Returns false if
     * it fails in any way, true on success.
     *
     * Useful to prevent needing to build the server definition on each
     * request. Sample usage:
     *
     * <code>
     * if (!Zend\Server\Cache::get($filename, $server)) {
     *     require_once 'Some/Service/ServiceClass.php';
     *     require_once 'Another/Service/ServiceClass.php';
     *
     *     // Attach Some\Service\ServiceClass with namespace 'some'
     *     $server->attach('Some\Service\ServiceClass', 'some');
     *
     *     // Attach Another\Service\ServiceClass with namespace 'another'
     *     $server->attach('Another\Service\ServiceClass', 'another');
     *
     *     Zend\Server\Cache::save($filename, $server);
     * }
     *
     * $response = $server->handle();
     * echo $response;
     * </code>
     *
     * @param  string $filename
     * @param  \Zend\Server\Server $server
     * @return bool
     */
    public static function get(string filename, <\Zend\Server\Server> server) -> boolean
    {
        var dispatch, dispatchArray;

        if empty filename || !file_exists(filename) || !is_rreadable(filename) {
            return false;
        }

        ErrorHandler::start();
        let dispatch = file_get_contents(filename);
        ErrorHandler::stop();

        if dispatch === false {
            return false;
        }

        ErrorHandler::start(E_NOTICE);
        let dispatchArray = unserialize(dispatch);
        ErrorHandler::stop();

        if dispatchArray === false {
            return false;
        }

        server->loadFunctions(dispatchArray);
        
        return true;
    }

    /**
     * Remove a cache file
     *
     * @param  string $filename
     * @return bool
     */
    public static function delete(string filename) -> boolean
    {
        if !empty filename && file_exists(filename) {
            unlink(filename);
            return true;
        }
        return false;
    }

}
