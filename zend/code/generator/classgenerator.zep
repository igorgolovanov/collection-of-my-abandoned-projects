/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

use Zend\Code\Reflection\ClassReflection;

class ClassGenerator extends AbstractGenerator
{
    const FLAG_ABSTRACT = 0x01;
    const FLAG_FINAL    = 0x02;

    /**
     * @var FileGenerator
     */
    protected containingFileGenerator;

    /**
     * @var string
     */
    protected namespaceName;

    /**
     * @var DocBlockGenerator
     */
    protected docBlock;

    /**
     * @var string
     */
    protected name;

    /**
     * @var bool
     */
    protected flags = 0;

    /**
     * @var string
     */
    protected extendedClass;

    /**
     * @var array Array of string names
     */
    protected implementedInterfaces = [];

    /**
     * @var PropertyGenerator[] Array of properties
     */
    protected properties = [];

    /**
     * @var MethodGenerator[] Array of methods
     */
    protected methods = [];

    /**
     * @var array Array of string names
     */
    protected uses = [];

    /**
     * Build a Code Generation Php Object from a Class Reflection
     *
     * @param  ClassReflection $classReflection
     * @return ClassGenerator
     */
    public static function fromReflection(<ClassReflection> classReflection) -> <ClassGenerator>
    {
        string className, name, docComment, ns, declaringClassName, parentClassName;
        var cg, sourceContent, docBlock, parentClass, val, reflectionProperty, 
            declaringClass, property, reflectionMethod, method;
        array interfaces, interfacesRefl, interfacesParent, 
            interfaceNames = [], properties = [], methods = [];

        let className = get_called_class();
        let name = classReflection->getName();
        // class generator
        let cg = <ClassReflection> new {className}(name);
        let sourceContent = cg->getSourceContent();

        cg->setSourceContent(sourceContent);
        cg->setSourceDirty(false);


        let docComment = classReflection->getDocComment();

        if docComment != "" {
            let docBlock = classReflection->getDocBlock();
            let docBlock = DocBlockGenerator::fromReflection(docBlock);

            cg->setDocBlock(docBlock);
        }

        // set the namespace
        if classReflection->inNamespace() {
            let ns = classReflection->getNamespaceName();
            cg->setNamespaceName(ns);
        }

        let parentClass = <ClassReflection> classReflection->getParentClass();

        if parentClass {
            let parentClassName = parentClass->getName();
            cg->setExtendedClass(parentClassName);

            let interfacesParent = parentClass->getInterfaces();
            let interfacesRefl = classReflection->getInterfaces();

            let interfaces = array_diff(interfacesRefl, interfacesParent);
        } else {
            let interfaces = classReflection->getInterfaces();
        }

        for val in interfaces {
            let interfaceNames[] = val->getName();
        }

        cg->setImplementedInterfaces(interfaceNames);

        for reflectionProperty in classReflection->getProperties() {
            let declaringClass = <ClassReflection> reflectionProperty->getDeclaringClass();
            let declaringClassName = declaringClass->getName();

            if declaringClassName == name {
                let property = <PropertyGenerator> PropertyGenerator::fromReflection(reflectionProperty);
                let properties[] = property;
            }
        }

        cg->addProperties(properties);

        for reflectionMethod in classReflection->getMethods() {
            let name = cg->getName();
            let ns = cg->getNamespaceName();
            if !empty ns {
                let name = ns . "\\" . name;
            }
            let declaringClass = <ClassReflection> reflectionProperty->getDeclaringClass();
            let declaringClassName = declaringClass->getName();

            if declaringClassName == name {
                let method = <MethodGenerator> MethodGenerator::fromReflection(reflectionMethod);
                let methods[] = method;
            }
        }

        cg->addMethods(methods);

        return cg;
    }

    /**
     * Generate from array
     *
     * @configkey name           string        [required] Class Name
     * @configkey filegenerator  FileGenerator File generator that holds this class
     * @configkey namespacename  string        The namespace for this class
     * @configkey docblock       string        The docblock information
     * @configkey flags          int           Flags, one of ClassGenerator::FLAG_ABSTRACT ClassGenerator::FLAG_FINAL
     * @configkey extendedclass  string        Class which this class is extending
     * @configkey implementedinterfaces
     * @configkey properties
     * @configkey methods
     *
     * @throws Exception\InvalidArgumentException
     * @param  array $array
     * @return ClassGenerator
     */
    public static function fromArray(array! $array) -> <ClassGenerator>
    {
        var cg, key, value, docBlock;
        string className, name, normilizedKey;
        array wildcards = [".", "-", "_"];

        if unlikely !isset $array["name"] {
            throw new Exception\InvalidArgumentException(
                "Class generator requires that a name is provided for this object"
            );
        }

        let className = get_called_class();
        let name = $array["name"];
        let cg = <ClassReflection> new {className}(name);

        for key, value in $array {
            let normilizedKey = str_replace(wildcards, "", key);
            switch normilizedKey->lower() {
                case "containingfile":
                    cg->setContainingFileGenerator(value);
                    break;
                case "namespacename":
                    cg->setNamespaceName(value);
                    break;
                case "docblock":
                    if value instanceof DocBlockGenerator {
                        let docBlock = value;
                    } else {
                        let docBlock = DocBlockGenerator::fromArray(value);
                    }
                    cg->setDocBlock(docBlock);
                    break;
                case "flags":
                    cg->setFlags(value);
                    break;
                case "extendedclass":
                    cg->setExtendedClass(value);
                    break;
                case "implementedinterfaces":
                    cg->setImplementedInterfaces(value);
                    break;
                case "properties":
                    cg->addProperties(value);
                    break;
                case "methods":
                    cg->addMethods(value);
                    break;

            }
        }

        return cg;
    }

    /**
     * @param  string $name
     * @param  string $namespaceName
     * @param  array|string $flags
     * @param  string $extends
     * @param  array $interfaces
     * @param  array $properties
     * @param  array $methods
     * @param  DocBlockGenerator $docBlock
     */
    public function __construct(string name = null, string namespaceName = null, var flags = null, string $extends = null, array interfaces = [], array properties = [], array methods = [], <DocBlockGenerator> docBlock = null)
    {
        if !empty name {
            this->setName(name);
        }
        if !empty namespaceName {
            this->setNamespaceName(namespaceName);
        }
        if flags !== null {
            this->setFlags(flags);
        }
        if !empty properties {
            this->addProperties(properties);
        }
        if !empty $extends {
            this->setExtendedClass($extends);
        }
        if !empty interfaces {
            this->setImplementedInterfaces(interfaces);
        }
        if !empty methods {
            this->addMethods(methods);
        }
        if docBlock !== null {
            this->setDocBlock(docBlock);
        }
    }

    /**
     * @param  string $name
     * @return ClassGenerator
     */
    public function setName(string name) -> <ClassGenerator>
    {
        string namespaceName;
        if strstr(name, "\\") {
            let namespaceName = substr(name, 0, strrpos(name, "\\"));
            let name = substr(name, strrpos(name, "\\") + 1);

            this->setNamespaceName(namespaceName);
        }
        let this->name = name;

        return this;
    }

    /**
     * @return string
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * @param  string $namespaceName
     * @return ClassGenerator
     */
    public function setNamespaceName(string namespaceName) -> <ClassGenerator>
    {
        let this->namespaceName = namespaceName;

        return this;
    }

    /**
     * @return string
     */
    public function getNamespaceName() -> string
    {
        return this->namespaceName;
    }

    /**
     * @param  FileGenerator $fileGenerator
     * @return ClassGenerator
     */
    public function setContainingFileGenerator(<FileGenerator> fileGenerator) -> <ClassGenerator>
    {
        let this->containingFileGenerator = fileGenerator;

        return this;
    }

    /**
     * @return FileGenerator
     */
    public function getContainingFileGenerator() -> <FileGenerator>
    {
        return this->containingFileGenerator;
    }

    /**
     * @param  DocBlockGenerator $docBlock
     * @return ClassGenerator
     */
    public function setDocBlock(<DocBlockGenerator> docBlock) -> <ClassGenerator>
    {
        let this->docBlock = docBlock;

        return this;
    }

    /**
     * @return DocBlockGenerator
     */
    public function getDocBlock() -> <DocBlockGenerator>
    {
        return this->docBlock;
    }

    /**
     * @param  array|string $flags
     * @return ClassGenerator
     */
    public function setFlags(var flags) -> <ClassGenerator>
    {
        array flagsArray;
        var flag;

        if typeof flags == "array" {
            let flagsArray = flags;
            let flags = 0x00;

            for flag in flagsArray {
                let flags = flags | flag;
            }
        }

        let this->flags = flags;

        return this;
    }

    /**
     * @param  string $flag
     * @return ClassGenerator
     */
    public function addFlag(string flag) -> <ClassGenerator>
    {
        this->setFlags(this->flags | flag);

        return this;
    }

    /**
     * @param  string $flag
     * @return ClassGenerator
     */
    public function removeFlag(string flag) -> <ClassGenerator>
    {
        this->setFlags(this->flags & ~flag);

        return this;
    }

    /**
     * @param  bool $isAbstract
     * @return ClassGenerator
     */
    public function setAbstract(boolean isAbstract) -> <ClassGenerator>
    {
        if isAbstract {
            this->addFlag(self::FLAG_ABSTRACT);
        } else {
            this->removeFlag(self::FLAG_ABSTRACT);
        }
    }

    /**
     * @return bool
     */
    public function isAbstract() -> boolean
    {
        return this->flags & self::FLAG_ABSTRACT;
    }

    /**
     * @param  bool $isFinal
     * @return ClassGenerator
     */
    public function setFinal(boolean isFinal) -> <ClassGenerator>
    {
        if isFinal {
            this->addFlag(self::FLAG_FINAL);
        } else {
            this->removeFlag(self::FLAG_FINAL);
        }
    }

    /**
     * @return bool
     */
    public function isFinal() -> boolean
    {
        return this->flags & self::FLAG_FINAL;
    }

    /**
     * @param  string $extendedClass
     * @return ClassGenerator
     */
    public function setExtendedClass(string extendedClass) -> <ClassGenerator>
    {
        let this->extendedClass = extendedClass;

        return this;
    }

    /**
     * @return string
     */
    public function getExtendedClass() -> string
    {
        return this->extendedClass;
    }

    /**
     * @param  array $implementedInterfaces
     * @return ClassGenerator
     */
    public function setImplementedInterfaces(array! implementedInterfaces) -> <ClassGenerator>
    {
        let this->implementedInterfaces = implementedInterfaces;
    }

    /**
     * @return array
     */
    public function getImplementedInterfaces() -> array
    {
        return this->implementedInterfaces;
    }

    /**
     * @param  array $properties
     * @return ClassGenerator
     */
    public function addProperties(array! properties) -> <ClassGenerator>
    {
        var property;
        array callback;

        for property in properties {
            if property instanceof PropertyGenerator {
                this->addPropertyFromGenerator(property);
                continue;
            } 
            if typeof property == "string" {
                this->addProperty(property);
                continue;
            }
            if typeof property == "array" {
                let callback = [this, "addProperty"];
                call_user_func_array(callback, property);
            }
        }
        return this;
    }

    /**
     * Add Property from scalars
     *
     * @param  string $name
     * @param  string|array $defaultValue
     * @param  int $flags
     * @throws Exception\InvalidArgumentException
     * @return ClassGenerator
     */
    public function addProperty(string name, var defaultValue = null, int flags = Zend\Code\Generator\PropertyGenerator::FLAG_PUBLIC) -> <ClassGenerator>
    {
        string exceptionMsg;
        var pg;

        if unlikely empty name {
            let exceptionMsg = __METHOD__ . " expects string for name";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }
        let pg = new PropertyGenerator(name, defaultValue, flags)

        this->addPropertyFromGenerator(pg);

        return this;
    }

    /**
     * Add property from PropertyGenerator
     *
     * @param  PropertyGenerator           $property
     * @throws Exception\InvalidArgumentException
     * @return ClassGenerator
     */
    public function addPropertyFromGenerator(<PropertyGenerator> property) -> <ClassGenerator>
    {
        string propertyName, exceptionMsg;

        let propertyName = property->getName();

        if unlikely isset this->properties[propertyName] {
            let exceptionMsg = "A property by name " . propertyName . " already exists in this class.";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let this->properties[propertyName] = property;

        return this;
    }

    /**
     * Add a class to "use" classes
     *
     * @param  string $use
     * @param  string|null $useAlias
     * @return ClassGenerator
     */
    public function addUse(string $use, string useAlias = null) -> <ClassGenerator>
    {
        if !empty useAlias {
            let $use = $use . " as " . useAlias;
        }

        let this->uses[$use] = $use;

        return this;
    }

    /**
     * @return PropertyGenerator[]
     */
    public function getProperties() -> array
    {
        return this->properties;
    }

    /**
     * @param  string $propertyName
     * @return PropertyGenerator|false
     */
    public function getProperty(string propertyName) -> <PropertyGenerator>|boolean
    {
        array properties;
        var property;
        string name;

        let properties = this->getProperties();
        for property in properties {
            let name = property->getName();
            if name == propertyName {
                return property;
            }
        }
        return false;
    }

    /**
     * Returns the "use" classes
     *
     * @return array
     */
    public function getUses() -> array
    {
        return array_values(this->uses);
    }

    /**
     * @param  string $propertyName
     * @return bool
     */
    public function hasProperty(string propertyName) -> boolean
    {
        return isset this->properties[propertyName];
    }

    /**
     * @param  array $methods
     * @return ClassGenerator
     */
    public function addMethods(array! methods) -> <ClassGenerator>
    {
        var method;
        array callback;

        for method in methods {
            if method instanceof MethodGenerator {
                this->addMethodFromGenerator(method);
                continue;
            }
            if typeof method == "string" {
                this->addMethod(method);
                continue;
            }
            if typeof method == "array" {
                let callback = [this, "addMethod"];
                call_user_func_array(callback, method);
            }
        }

        return this;
    }

    /**
     * Add Method from scalars
     *
     * @param  string $name
     * @param  array $parameters
     * @param  int $flags
     * @param  string $body
     * @param  string $docBlock
     * @throws Exception\InvalidArgumentException
     * @return ClassGenerator
     */
    public function addMethod(string name = null, array! parameters = [], int flags = MethodGenerator::FLAG_PUBLIC, string body = null, string docBlock = null) -> <ClassGenerator>
    {
        string exceptionMsg;
        var mg;

        if unlikely empty name {
            let exceptionMsg = __METHOD__ . " expects string for name";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let mg = new MethodGenerator(name, parameters, flags, body, docBlock);

        this->addMethodFromGenerator(mg);

        return this;
    }

    /**
     * Add Method from MethodGenerator
     *
     * @param  MethodGenerator                    $method
     * @throws Exception\InvalidArgumentException
     * @return ClassGenerator
     */
    public function addMethodFromGenerator(<MethodGenerator> method) -> <ClassGenerator>
    {
        string methodName, exceptionMsg;

        let methodName = property->getName();

        if unlikely isset this->hasMethod(methodName) {
            let exceptionMsg = "A method by name " . methodName . " already exists in this class.";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let this->methods[methodName->lower()] = method;

        return this;
    }

    /**
     * @return MethodGenerator[]
     */
    public function getMethods() -> array
    {
        return this->methods;
    }

    /**
     * @param  string $methodName
     * @return MethodGenerator|false
     */
    public function getMethod(string methodName) -> <MethodGenerator>|boolean
    {
        var method;

        if this->hasMethod(methodName) {
            return this->methods[methodName->lower()];
        }
        return false;
    }

    /**
     * @param  string $methodName
     * @return ClassGenerator
     */
    public function removeMethod(string methodName) -> <ClassGenerator>
    {
        if this->hasMethod(methodName) {
            unset this->methods[methodName->lower()];
        }

        return this;
    }

    /**
     * @param  string $methodName
     * @return bool
     */
    public function hasMethod(string methodName) -> boolean
    {
        return isset this->methods[methodName->lower()];
    }

    /**
     * @return bool
     */
    public function isSourceDirty() -> boolean
    {
        var docBlock, property, method;
        array properties, methods;

        let docBlock = <DocBlockGenerator> this->getDocBlock();
        if docBlock && docBlock->isSourceDirty() {
            return true;
        }

        let properties = this->getProperties();
        for property in properties {
            if property->isSourceDirty() {
                return true;
            }
        }

        let methods = this->getMethods();
        for method in methods {
            if method->isSourceDirty() {
                return true;
            }
        }

        return parent::isSourceDirty();
    }

    /**
     * @return string
     */
    public function generate() -> string
    {
        string output, ns, use1, name, implementedStr, propertyStr, methodStr, docBlockStr;
        array uses, implemented, properties, methods;
        var docBlock, property, method;

        if this->isSourceDirty() {
            let output = this->getSourceContent();
            if !empty output {
                return output;
            }
        }

        let output = "";
        let ns = this->getNamespaceName();
        let uses = this->getUses();
        let docBlock = <DocBlockGenerator> this->getDocBlock();
        let name = this->getName();
        let properties = this->getProperties();
        let implemented = this->getImplementedInterfaces();
        let methods = this->getMethods(); 

        if !empty ns {
            let output = output . "namespace " . ns . ";" . self::LINE_FEED . self::LINE_FEED;
        }

        if !empty uses {
            for use1 in uses {
                let output = output . "use " . use1 . ";" . self::LINE_FEED;
            }
            let output = output . self::LINE_FEED;
        }

        if docBlock !== null {
            docBlock->setIndentation("");
            let docBlockStr = docBlock->generate();
            let output = output . docBlockStr;
        }

        if this->isAbstract() {
            let output = output . "abstract ";
        }
        let output = output . "class " . name;

        if !empty implemented {
            let implementedStr = implode(", ", implemented);
            let output = output . " implements " . implementedStr;
        }

        let output = output . self::LINE_FEED . "{" . self::LINE_FEED . self::LINE_FEED;

        if !empty properties {
            for property in properties {
                let propertyStr = property->generate();
                let output = output . propertyStr . self::LINE_FEED . self::LINE_FEED;
            }
        }

        if !empty methods {
            for property in methods {
                let methodStr = method->generate();
                let output = output . methodStr . self::LINE_FEED;
            }
        }

        let output = output . self::LINE_FEED . "}" . self::LINE_FEED;

        return output;
    }

}
































