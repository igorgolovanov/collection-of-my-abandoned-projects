/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\NamingStrategy;

use Zend\Filter\FilterChain;

class UnderscoreNamingStrategy implements NamingStrategyInterface
{
    protected static camelCaseToUnderscoreFilter;

    protected static underscoreToCamelCaseFilter;

    /**
     * Remove underscores and capitalize letters
     *
     * @param  string $name
     * @return string
     */
    public function hydrate(string name) -> string
    {
        var filter;
        string str;

        let filter = <FilterChain> this->getUnderscoreToCamelCaseFilter();
        let str = filter->filter(name);
        let str = lcfirst(str);

        return str;
    }

    /**
     * Remove capitalized letters and prepend underscores.
     *
     * @param  string $name
     * @return string
     */
    public function extract(string name) -> string
    {
        var filter;
        let filter = <FilterChain> this->getCamelCaseToUnderscoreFilter();

        return filter->filter(name);
    }

    /**
     * @return FilterChain
     */
    protected function getUnderscoreToCamelCaseFilter() -> <FilterChain>
    {
        var filter;

        // todo: change self -> static
        if self::underscoreToCamelCaseFilter instanceof FilterChain {
            return self::underscoreToCamelCaseFilter;
        }

        let filter = new FilterChain();
        filter->attachByName("WordUnderscoreToCamelCase");
        let self::underscoreToCamelCaseFilter = filter;

        return filter;
    }

    /**
     * @return FilterChain
     */
    protected function getCamelCaseToUnderscoreFilter() -> <FilterChain>
    {
        // todo: change self -> static
        var filter;

        if self::camelCaseToUnderscoreFilter instanceof FilterChain {
            return self::camelCaseToUnderscoreFilter;
        }

        let filter = new FilterChain();
        filter->attachByName("WordCamelCaseToUnderscore");
        filter->attachByName("StringToLower");
        let self::camelCaseToUnderscoreFilter = filter;

        return filter;
    }

}
