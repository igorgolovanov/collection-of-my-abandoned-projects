/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class TokenArrayScanner implements ScannerInterface
{
    /**
     * @var bool
     */
    protected isScanned = false;

    /**
     * @var array
     */
    protected tokens; // []

    /**
     * @var null
     */
    protected docComment;

    /**
     * @var NameInformation
     */
    protected nameInformation;

    /**
     * @var array
     */
    protected infos; // []

    /**
     * @var AnnotationManager
     */
    protected annotationManager;

    /**
     * @param null|array $tokens
     * @param null|AnnotationManager $annotationManager
     */
    public function __construct(array tokens, annotationManager = null)
    {

    }

    /**
     * @return AnnotationManager
     */
    public function getAnnotationManager()
    {

    }

    /**
     * Get doc comment
     *
     * @todo Assignment of $this->docComment should probably be done in scan()
     *       and then $this->getDocComment() just retrieves it.
     *
     * @return string
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
     * @return ClassScanner[]
     */
    public function getClasses() -> array
    {

    }

    /**
     * Return the class object from this scanner
     *
     * @param  string|int $name
     * @throws Exception\InvalidArgumentException
     * @return ClassScanner
     */
    public function getClass(var name) -> <ClassScanner>
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

    /**
     * Export
     *
     * @param $tokens
     */
    public static function export(tokens)
    {

    }

    public function __toString()
    {

    }

    /**
     * Scan
     *
     * @todo: $this->docComment should be assigned for valid docblock during
     *        the scan instead of $this->getDocComment() (starting with
     *        T_DOC_COMMENT case)
     *
     * @throws Exception\RuntimeException
     */
    protected function scan()
    {

    }

    /**
     * Check for namespace
     *
     * @param string $namespace
     * @return bool
     */
    public function hasNamespace(string $namespace) -> boolean
    {

    }

    /**
     * @param  string $namespace
     * @return null|array
     * @throws Exception\InvalidArgumentException
     */
    protected function getUsesNoScan(string $namespace) -> array
    {

    }

}
