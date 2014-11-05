/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Code\Scanner;

use Zend\Code\Annotation\AnnotationManager;
use Zend\Code\Exception;
use Zend\Code\NameInformation;

class CachingFileScanner extends FileScanner
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
    public function __construct(string file, <AnnotationManager> annotationManager = null)
    {
        var className, cache = null, fileScanner;
        string exceptionMsg, cacheId;

        if unlikely !file_exists(file) {
            let exceptionMsg = "File \"" . file . "\" not found";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let file = realpath(file);

        let cacheId = md5(file) . "/";
        if annotationManager !== null {
            let cacheId .= spl_object_hash(annotationManager);
        } else {
            let cacheId .= "no-annotation";
        }
        let className = get_class(this);
        %{
            zephir_read_static_property(&cache, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("cache") TSRMLS_CC);
        }%
        if typeof cache == "array" && fetch fileScanner, cache[cacheId] {
            let this->fileScanner = fileScanner;
        } else {
            if typeof cache != "array" {
                let cache = [];
            }
            let fileScanner = new FileScanner(file, annotationManager);
            let this->fileScanner = fileScanner;
            let cache[cacheId] = fileScanner;
            %{
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("cache"), &cache TSRMLS_CC);
            }%
        }
    }

    /**
     * @return void
     */
    public static function clearCache() -> void
    {
        var className, cache = [];

        let className = get_called_class();
        %{
            zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("cache"), &cache TSRMLS_CC);
        }%
    }

    /**
     * @return AnnotationManager
     */
    public function getAnnotationManager() -> <AnnotationManager>
    {
        var fs, am;

        let fs = <FileScanner> this->fileScanner;
        let am = <AnnotationManager> fs->getAnnotationManager();

        return am;
    }

    /**
     * @return array|null|string
     */
    public function getFile() -> array|string|null
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getFile();
    }

    /**
     * @return null|string
     */
    public function getDocComment() -> string|null
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getDocComment();
    }

    /**
     * @return array
     */
    public function getNamespaces() -> array
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getNamespaces();
    }

    /**
     * @param  null|string $namespace
     * @return array|null
     */
    public function getUses(string $namespace = null) -> array|null
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getUses($namespace);
    }

    /**
     * @return array
     */
    public function getIncludes() -> array
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getIncludes();
    }

    /**
     * @return array
     */
    public function getClassNames() -> array
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getClassNames();
    }

    /**
     * @return array
     */
    public function getClasses() -> array
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getClasses();
    }

    /**
     * @param  int|string $className
     * @return ClassScanner
     */
    public function getClass(var className) -> <ClassScanner>
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getClass(className);
    }

    /**
     * @param  string $className
     * @return bool|null|NameInformation
     */
    public function getClassNameInformation(string className) -> boolean|null|<NameInformation>
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getClassNameInformation(className);
    }

    /**
     * @return array
     */
    public function getFunctionNames() -> array
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getFunctionNames();
    }

    /**
     * @return array
     */
    public function getFunctions() -> array
    {
        var fs;

        let fs = <FileScanner> this->fileScanner;

        return fs->getFunctions();
    }

}
