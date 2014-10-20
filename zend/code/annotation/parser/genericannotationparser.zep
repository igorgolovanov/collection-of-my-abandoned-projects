/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Annotation\Parser;

use Traversable;
use Zend\Code\Annotation\AnnotationInterface;
use Zend\Code\Exception;
use Zend\EventManager\EventInterface;

/**
 * Generic annotation parser
 *
 * Expects registration of AnnotationInterface instances. Such instances
 * will be passed annotation content to their initialize() method, which
 * they are then responsible for parsing.
 */
class GenericAnnotationParser implements ParserInterface
{
    /**
     * @var array
     */
    protected aliases = [];

    /**
     * @var array
     */
    protected annotationNames = [];

    /**
     * @var AnnotationInterface[]
     */
    protected annotations = [];

    /**
     * Listen to onCreateAnnotation, and attempt to return an annotation object
     * instance.
     *
     * If the annotation class or alias is not registered, immediately returns
     * false. Otherwise, resolves the class, clones it, and, if any content is
     * present, calls {@link AnnotationInterface::initialize()} with the
     * content.
     *
     * @param  EventInterface $e
     * @return false|AnnotationInterface
     */
    public function onCreateAnnotation(<EventInterface> e) -> object|boolean
    {
        string className, content;
        var content, index, annotation, annotationNew;

        let className = e->getParam("class", false);
        if empty className || !this->hasAnnotation(className) {
            return false;
        }

        let content = e->getParam("content", "");
        let content = content->trim();

        if this->hasAlias(className) {
            let className = this->resolveAlias(className);
        }

        let index = array_search(className, this->annotationNames);
        let annotation = <AnnotationInterface> this->annotations[index];
        let annotationNew = <AnnotationInterface> clone annotation;

        if content {
            annotationNew->initialize(content);
        }

        return annotationNew;
    }

    /**
     * Register annotations
     *
     * @param  string|AnnotationInterface $annotation String class name of an
     *         AnnotationInterface implementation, or actual instance
     * @return GenericAnnotationParser
     * @throws Exception\InvalidArgumentException
     */
    public function registerAnnotation(var annotation) -> self
    {
        var className = false;
        string exceptionMsg, type;

        if typeof annotation == "string" && class_exists(annotation) {
            let className = annotation;
            let annotation = <AnnotationInterface> new {annotation}();
        }

        if unlikely !(annotation instanceof AnnotationInterface) {
            let type = typeof annotation;
            if type == "object" {
                let type = get_class(annotation);
            }

            let exceptionMsg = __METHOD__ ": expects an instance of " . __NAMESPACE__ . "\AnnotationInterface; received \"" . type . "\"";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        if !className {
            let className = get_class(annotation);
        }

        if unlikely in_array(className, this->annotationNames) {
            let exceptionMsg = "An annotation for this class " . className . " already exists";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        let this->annotation[] = annotation;
        let this->annotationNames[] = className;

        return this;
    }

    /**
     * Register many annotations at once
     *
     * @param  array|Traversable $annotations
     * @throws Exception\InvalidArgumentException
     * @return GenericAnnotationParser
     */
    public function registerAnnotations(var annotations) -> self
    {
        string exceptionMsg;
        var annotation;

        let type = typeof annotations;

        if unlikely type != "array" && !(annotations instanceof Traversable) {
            if type == "object" {
                let type = get_class(annotations);
            }
            let exceptionMsg = __METHOD__ . ": expects an array or Traversable; received \"" . type . "\"";
             throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        for annotation in annotations {
            this->registerAnnotation(annotation);
        }

        return this;
    }

    /**
     * Checks if the manager has annotations for a class
     *
     * @param  string $class
     * @return bool
     */
    public function hasAnnotation(string $class) -> boolean
    {
        if in_array($class, this->annotationNames) {
            return true;
        }

        return this->hasAlias($class);
    }

    /**
     * Alias an annotation name
     *
     * @param  string $alias
     * @param  string $class May be either a registered annotation name or another alias
     * @throws Exception\InvalidArgumentException
     * @return GenericAnnotationParser
     */
    public function setAlias(string alias, string $class) -> self
    {
        string normilized, exceptionMsg;

        if unlikely !in_array($class, this->annotationNames) && !this->hasAlias($class) {
            let exceptionMsg = __METHOD__ . ": Cannot alias \"" . alias . "\" to \"" . $class . "\", as class \"" . $class . "\" is not currently a registered annotation or alias";
            throw new Exception\InvalidArgumentException(exceptionMsg);

        }

        let normilized = this->normalizeAlias(alias);
        let this->aliases[normilized] = $class;

        return this;
    }

    /**
     * Normalize an alias name
     *
     * @param  string $alias
     * @return string
     */
    protected function normalizeAlias(string alias) -> string
    {
        array chars = ["-", "_", " ", "\\", "/"];
        string replaced;

        let replaced = str_replace(chars, "", alias);
        
        return replaced->lower();
    }

    /**
     * Do we have an alias by the provided name?
     *
     * @param  string $alias
     * @return bool
     */
    protected function hasAlias(string alias) -> boolean
    {
        string normilized;

        let normilized = this->normalizeAlias(alias);

        return isset this->aliases[normilized];
    }

    /**
     * Resolve an alias to a class name
     *
     * @param  string $alias
     * @return string
     */
    protected function resolveAlias(string alias) -> string
    {
        string normilized, className;

        do {
            let normilized = this->normalizeAlias(alias);
            let className = this->aliases[normilized];
        } while this->hasAlias[className];

        return className;
    }

}
