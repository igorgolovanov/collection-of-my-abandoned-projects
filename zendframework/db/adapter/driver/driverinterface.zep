/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Adapter\Driver;

interface DriverInterface
{
    const PARAMETERIZATION_POSITIONAL = "positional";

    const PARAMETERIZATION_NAMED = "named";

    const NAME_FORMAT_CAMELCASE = "camelCase";

    const NAME_FORMAT_NATURAL = "natural";

    /**
     * Get database platform name
     *
     * @param string $nameFormat
     * @return string
     */
    public function getDatabasePlatformName(string nameFormat = self::NAME_FORMAT_CAMELCASE) -> string;

    /**
     * Check environment
     *
     * @return bool
     */
    public function checkEnvironment() -> boolean;

    /**
     * Get connection
     *
     * @return ConnectionInterface
     */
    public function getConnection() -> <ConnectionInterface>;

    /**
     * Create statement
     *
     * @param string|resource $sqlOrResource
     * @return StatementInterface
     */
    public function createStatement(var sqlOrResource = null) -> <StatementInterface>;

    /**
     * Create result
     *
     * @param resource $resource
     * @return ResultInterface
     */
    public function createResult(resource $resource) -> <ResultInterface>;

    /**
     * Get prepare type
     *
     * @return array
     */
    public function getPrepareType() -> array;

    /**
     * Format parameter name
     *
     * @param string $name
     * @param mixed  $type
     * @return string
     */
    public function formatParameterName(string name, type = null) -> string;

    /**
     * Get last generated value
     *
     * @return mixed
     */
    public function getLastGeneratedValue();

}
