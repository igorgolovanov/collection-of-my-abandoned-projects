<?php

namespace ZephirExtra;

use Zephir\ClassDefinition as ZephirClassDefinition;

class ClassDefinition extends ZephirClassDefinition
{
    /**
     * Returns a valid namespace to be used in C-sources
     *
     * @return string
     */
    public function getNCNamespace()
    {
        $namespace = $this->namespace;
        if (0 === stripos($namespace, 'ZendFramework\\')) {
            $namespace = 'Zend\\' . substr($namespace, 14);
        }
        return str_replace('\\', '\\\\', $namespace);
    }

    /**
     * Convert Class/Interface name to C ClassEntry
     *
     * @param  string $className
     * @param  CompilationContext $compilationContext
     * @param  boolean $check
     * @return string
     * @throws CompilerException
     */
    public function getClassEntryByClassName($className, $compilationContext, $check = false)
    {
        switch (strtolower($className)) {
            case 'splstack':
                $compilationContext->headersManager->add('ext/spl/spl_dllist');
                $classEntry = 'spl_ce_SplStack';
                break;
            case 'splqueue':
                $compilationContext->headersManager->add('ext/spl/spl_dllist');
                $classEntry = 'spl_ce_SplQueue';
                break;
            case 'spldoublylinkedlist':
                $compilationContext->headersManager->add('ext/spl/spl_dllist');
                $classEntry = 'spl_ce_SplDoublyLinkedList';
                break;
//
//            // Reflection
//            case 'reflector':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflector_ptr';
//                break;
//            case 'reflectionexception':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_exception_ptr';
//                break;
//            case 'reflection':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_ptr';
//                break;
//            case 'reflectionfunctionabstract':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_function_abstract_ptr';
//                break;
//            case 'reflectionfunction':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_function_ptr';
//                break;
//            case 'reflectionparameter':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_parameter_ptr';
//                break;
//            case 'reflectionclass':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_class_ptr';
//                break;
//            case 'reflectionobject':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_object_ptr';
//                break;
//            case 'reflectionmethod':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_method_ptr';
//                break;
//            case 'reflectionproperty':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_property_ptr';
//                break;
//            case 'reflectionextension':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_extension_ptr';
//                break;
//            case 'reflectionzendextension':
//                $compilationContext->headersManager->add('ext/reflection/php_reflection');
//                $classEntry = 'reflection_zend_extension_ptr';
//                break;

            default:
                $classEntry = parent::getClassEntryByClassName($className, $compilationContext, $check);
        }

        return $classEntry;
    }
}