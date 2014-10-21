/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Server;

/**
 * \Zend\Server\Cache: cache server definitions
 */
class Cache
{
    /**
     * @var array Methods to skip when caching server
     */
    protected static skipMethods = [];

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

    }

    /**
     * Remove a cache file
     *
     * @param  string $filename
     * @return bool
     */
    public static function delete(string filename) -> boolean
    {

    }

}
