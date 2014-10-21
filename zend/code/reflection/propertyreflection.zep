/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection;

use ReflectionProperty as PhpReflectionProperty;
use Zend\Code\Annotation\AnnotationManager;
use Zend\Code\Scanner\AnnotationScanner;
use Zend\Code\Scanner\CachingFileScanner;

/**
 * @todo       implement line numbers
 */
class PropertyReflection extends PhpReflectionProperty implements ReflectionInterface
{

    /**
     * @var AnnotationScanner
     */
    protected annotations;

    /**
     * Get declaring class reflection object
     *
     * @return ClassReflection
     */
    public function getDeclaringClass() -> <ClassReflection>
    {
        var phpReflection, zendReflection;
        string name;

        let phpReflection = <ClassReflection> parent::getDeclaringClass();
        let name = phpReflection->getName();
        let zendReflection = new ClassReflection(name);

        unset phpReflection;

        return zendReflection;
    }

    /**
     * Get DocBlock comment
     *
     * @return string|false False if no DocBlock defined
     */
    public function getDocComment() -> string|boolean
    {
        return parent::getDocComment();
    }

    /**
     * @return false|DocBlockReflection
     */
    public function getDocBlock() -> <DocBlockReflection>|boolean
    {
        string docComment;
        var docBlockReflection;

        let docComment = this->getDocComment();
        if !docComment {
            return false;
        }
        let docBlockReflection = new DocBlockReflection(docComment);

        return docBlockReflection;
    }

    /**
     * @param  AnnotationManager $annotationManager
     * @return AnnotationScanner
     */
    public function getAnnotations(<AnnotationManager> annotationManager) -> <AnnotationScanner>
    {
        string docComment, fileName;
        var annotations, classRef, cachingFileScanner, nameInformation;

        let annotations = this->annotations;
        if annotations === null {
            let docComment = this->getDocComment();
            if !docComment {
                return false;
            }
            let classRef = <ClassReflection> this->getDeclaringClass();
            let fileName = classRef->getFileName();
            let cachingFileScanner = <CachingFileScanner> this->createFileScanner(fileName);
            let nameInformation = cachingFileScanner->getClassNameInformation(fileName);

            if !nameInformation {
                return false;
            }
            let annotations = new AnnotationScanner(annotationManager, docComment, nameInformation);
            let this->annotations = annotations;
        }
        return annotations;
    }

    public function toString() -> string
    {
        return this->__toString();
    }

    /**
     * Creates a new FileScanner instance.
     *
     * By having this as a seperate method it allows the method to be overridden
     * if a different FileScanner is needed.
     *
     * @param  string $filename
     *
     * @return CachingFileScanner
     */
    protected function createFileScanner(string filename) -> <CachingFileScanner>
    {
        return new CachingFileScanner(filename);
    }

}
