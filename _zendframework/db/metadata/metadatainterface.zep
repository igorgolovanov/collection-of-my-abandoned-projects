/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Db\Metadata;

// todo: types

interface MetadataInterface
{
    public function getSchemas();

    public function getTableNames(schema = null, boolean includeViews = false);

    public function getTables(schema = null, boolean includeViews = false);

    public function getTable(tableName, schema = null);

    public function getViewNames(schema = null);

    public function getViews(schema = null);

    public function getView(viewName, schema = null);

    public function getColumnNames(table, schema = null);

    public function getColumns(table, schema = null);

    public function getColumn(columnName, table, schema = null);

    public function getConstraints(table, schema = null);

    public function getConstraint(constraintName, table, schema = null);

    public function getConstraintKeys(constraint, table, schema = null);

    public function getTriggerNames(schema = null);

    public function getTriggers(schema = null);

    public function getTrigger(triggerName, schema = null);

}
