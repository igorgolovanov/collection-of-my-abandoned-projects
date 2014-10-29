/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Di\Definition;

use Zend\Code\Annotation\AnnotationManager;
use Zend\Code\Annotation\Parser\GenericAnnotationParser;

/**
 * Strategy used to discover methods to be considered as endpoints for dependency injection based on implemented
 * interfaces, annotations and method names
 */
class IntrospectionStrategy
{
    /**
     * @var bool
     */
    protected useAnnotations = false;

    /**
     * @var string[]
     */
    protected methodNameInclusionPatterns; // ["/^set[A-Z]{1}\w*/"]

    /**
     * @var string[]
     */
    protected interfaceInjectionInclusionPatterns; // ["/\w*Aware\w*/"]

    /**
     * @var AnnotationManager
     */
    protected annotationManager;

    /**
     * Constructor
     *
     * @param null|AnnotationManager $annotationManager
     */
    public function __construct(<AnnotationManager> annotationManager = null)
    {
        if annotationManager === null {
            let annotationManager = <AnnotationManager> this->createDefaultAnnotationManager();
        }
        let this->annotationManager = annotationManager;
    }

    /**
     * Get annotation manager
     *
     * @return null|AnnotationManager
     */
    public function getAnnotationManager() -> <AnnotationManager>
    {
        return this->annotationManager;
    }

    /**
     * Create default annotation manager
     *
     * @return AnnotationManager
     */
    public function createDefaultAnnotationManager() -> <AnnotationManager>
    {
        var manager, parser, annotation;

        let manager = new AnnotationManager();
        let parser = new GenericAnnotationParser();
        let annotation = new Annotation\Inject();

        parser->registerAnnotation(annotation);
        manager->attach(parser);

        return manager;

    }

    /**
     * set use annotations
     *
     * @param bool $useAnnotations
     */
    public function setUseAnnotations(boolean useAnnotations)
    {
        let this->useAnnotations = useAnnotations;
    }

    /**
     * Get use annotations
     *
     * @return bool
     */
    public function getUseAnnotations() -> boolean
    {
        return this->useAnnotations;
    }

    /**
     * Set method name inclusion pattern
     *
     * @param array $methodNameInclusionPatterns
     */
    public function setMethodNameInclusionPatterns(array! methodNameInclusionPatterns)
    {
        let this->methodNameInclusionPatterns = methodNameInclusionPatterns;
    }

    /**
     * Get method name inclusion pattern
     *
     * @return array
     */
    public function getMethodNameInclusionPatterns() -> array
    {
        return this->methodNameInclusionPatterns;
    }

    /**
     * Set interface injection inclusion patterns
     *
     * @param array $interfaceInjectionInclusionPatterns
     */
    public function setInterfaceInjectionInclusionPatterns(array! interfaceInjectionInclusionPatterns)
    {
        let this->interfaceInjectionInclusionPatterns = interfaceInjectionInclusionPatterns;
    }

    /**
     * Get interface injection inclusion patterns
     *
     * @return array
     */
    public function getInterfaceInjectionInclusionPatterns() -> array
    {
        return this->interfaceInjectionInclusionPatterns;
    }

}
