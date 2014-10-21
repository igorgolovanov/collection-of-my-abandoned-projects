/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Reflection;

use ReflectionClass;
use Zend\Code\Annotation\AnnotationCollection;
use Zend\Code\Annotation\AnnotationManager;
use Zend\Code\Scanner\AnnotationScanner;
use Zend\Code\Scanner\FileScanner;

class ClassReflection extends ReflectionClass implements ReflectionInterface
{

    /**
     * @var AnnotationScanner
     */
    protected annotations;

    /**
     * @var DocBlockReflection
     */
    protected docBlock;

    /**
     * Return the reflection file of the declaring file.
     *
     * @return FileReflection
     */
    public function getDeclaringFile() -> <FileReflection>
    {
        var instance;
        string fileName;

        let fileName = this->getFileName();
        let instance = new FileReflection(fileName);

        return instance;
    }

    /**
     * Return the classes DocBlock reflection object
     *
     * @return DocBlockReflection
     * @throws Exception\ExceptionInterface for missing DocBock or invalid reflection class
     */
    public function getDocBlock() -> <DocBlockReflection>|boolean
    {
        string docComment;

        if empty this->docBlock {
            let docComment = this->getDocComment();
            if docComment == "" {
                return false;
            }

            let this->docBlock = new DocBlockReflection(this);
        }

        return this->docBlock;
    }

    /**
     * @param  AnnotationManager $annotationManager
     * @return AnnotationCollection
     */
    public function getAnnotations(<AnnotationManager> annotationManager) -> <AnnotationCollection>|boolean
    {
        string docComment, fileName, name;
        var fileScanner, nameInformation, annotations;

        let docComment = this->getDocComment();
        if docComment == "" {
            return false;
        }

        if this->annotations {
            return this->annotations;
        }

        let fileName = this->getFileName();
        let fileScanner = <FileScanner> this->createFileScanner(fileName);
        let name = this->getName();
        let nameInformation = fileScanner->getClassNameInformation(name);

        if !nameInformation {
            return false;
        }

        let annotations = new AnnotationScanner(annotationManager, docComment, nameInformation);
        let this->annotations = annotations;

        return annotations;
    }

    /**
     * Return the start line of the class
     *
     * @param  bool $includeDocComment
     * @return int
     */
    public function getStartLine(boolean includeDocComment = false) -> int
    {
        string docComment;
        var docBlock;
        int startLine;

        if includeDocComment {
            let docComment = this->getDocComment();
            if docComment != "" {
                let docBlock = <DocBlockReflection> this->getDocBlock();
                let startLine = docBlock->getStartLine();

                return startLine;
            }
        }

        return parent::getStartLine();
    }

    /**
     * Return the contents of the class
     *
     * @param  bool $includeDocBlock
     * @return string
     */
    public function getContents(boolean includeDocBlock = true) -> string
    {
        var fileName, ;
        int startNum, endNum, startLine, endLine;
        array lines, filelines;
        string result;

        let fileName = this->getFileName();
        if fileName === false || !file_exists(fileName) {
            return "";
        }
        let filelines = file(fileName);
        let startLine = this->getStartLine();
        let endLine = this->getEndLine();
        let startNum = this->getStartLine(includeDocBlock);
        let endNum = endLine - startLine;

        // Ensure we get between the open and close braces
        let lines = array_slice(filelines, startNum, endNum);
        array_unshift(lines, filelines[startNum - 1]);

        let result = implode("", lines);
        let result = strstr(result, "{");

        return result;
    }

    /**
     * Get all reflection objects of implemented interfaces
     *
     * @return ClassReflection[]
     */
    public function getInterfaces() -> array
    {
        array phpReflections, zendReflections = [];
        var phpReflection, instance;
        string name;

        let phpReflections =  parent::getInterfaces();
        for phpReflection in phpReflections {
            let name = phpReflection->getName();
            let instance = new ClassReflection(name);

            let zendReflections[] = instance;
        }

        unset phpReflections;

        return zendReflections;

    }

    /**
     * Return method reflection by name
     *
     * @param  string $name
     * @return MethodReflection
     */
    public function getMethod(string name) -> <MethodReflection>
    {
        string className, methodName;
        var method, instance;

        let className = this->getName();
        let method = <MethodReflection> parent::getMethod(name);
        let methodName = method->getName();
        let instance = new MethodReflection(className, methodName);

        unset method;

        return method;
    }

    /**
     * Get reflection objects of all methods
     *
     * @param  int $filter
     * @return MethodReflection[]
     */
    public function getMethods(int filter = -1) -> array
    {
        array methods, result = [];
        var method, instance;
        string methodName, className;

        let className = this->getName();
        let methods = parent::getMethods(filter);
        for method in methods {
            let methodName = method->getName();
            let instance = new MethodReflection(className, methodName);

            let methods[] = instance;
        }

        unset methods;

        return result;
    }

    /**
     * Get parent reflection class of reflected class
     *
     * @return ClassReflection|bool
     */
    public function getParentClass() -> <ClassReflection>|boolean
    {
        var phpReflection, zendReflection;
        string className;

        let phpReflection = parent::getParentClass();
        if phpReflection {
            let className = phpReflection->getName();
            let zendReflection = new ClassReflection(name);

            unset phpReflection;

            return zendReflection;
        }

        return false;
    }

    /**
     * Return reflection property of this class by name
     *
     * @param  string $name
     * @return PropertyReflection
     */
    public function getProperty(string name) -> <PropertyReflection>
    {
        string className, propertyName;
        var property, instance;

        let className = this->getName();
        let property = <PropertyReflection> parent::getProperty(name);
        let propertyName = property->getName();
        let instance = new PropertyReflection(className, propertyName);

        unset property;

        return property;
    }

    /**
     * Return reflection properties of this class
     *
     * @param  int $filter
     * @return PropertyReflection[]
     */
    public function getProperties(int filter = -1) -> array
    {
        array properties, result = [];
        var property, instance;
        string propertyName, className;

        let className = this->getName();
        let properties = parent::getProperties(filter);
        for property in properties {
            let propertyName = property->getName();
            let instance = new PropertyReflection(className, propertyName);

            let properties[] = instance;
        }

        unset properties;

        return result;
    }

    public function toString() -> string
    {
        return parent::__toString();
    }

    public function __toString() -> string
    {
        return parent::__toString();
    }

    /**
     * Creates a new FileScanner instance.
     *
     * By having this as a seperate method it allows the method to be overridden
     * if a different FileScanner is needed.
     *
     * @param  string $filename
     *
     * @return FileScanner
     */
    protected function createFileScanner(string filename) -> <FileScanner>
    {
        return new FileScanner(filename);
    }

}
