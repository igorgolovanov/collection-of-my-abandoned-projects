/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class CachingFileScanner extends FileScanner implements ScannerInterface
{
    /**
     * @var array
     */
    protected static cache; // []

    /**
     * @var null|FileScanner
     */
    protected fileScanner;

    /**
     * @param  string $file
     * @param  AnnotationManager $annotationManager
     * @throws Exception\InvalidArgumentException
     */
    public function __construct(string file, annotationManager = null)
    {

    }

    /**
     * @return void
     */
    public static function clearCache() -> void
    {

    }

    /**
     * @return AnnotationManager
     */
    public function getAnnotationManager()
    {

    }

    /**
     * @return array|null|string
     */
    public function getFile() -> array|string
    {

    }

    /**
     * @return null|string
     */
    public function getDocComment() -> string
    {

    }

    /**
     * @return array
     */
    public function getNamespaces() -> array
    {

    }

    /**
     * @param  null|string $namespace
     * @return array|null
     */
    public function getUses(string $namespace = null) -> array
    {

    }

    /**
     * @return array
     */
    public function getIncludes() -> array
    {

    }

    /**
     * @return array
     */
    public function getClassNames() -> array
    {

    }

    /**
     * @return array
     */
    public function getClasses() -> array
    {

    }

    /**
     * @param  int|string $className
     * @return ClassScanner
     */
    public function getClass(var className) -> <ClassScanner>
    {

    }

    /**
     * @param  string $className
     * @return bool|null|NameInformation
     */
    public function getClassNameInformation(string className) -> boolean
    {

    }

    /**
     * @return array
     */
    public function getFunctionNames() -> array
    {

    }

    /**
     * @return array
     */
    public function getFunctions() -> array
    {

    }

}
