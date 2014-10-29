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
            default:
                $classEntry = parent::getClassEntryByClassName($className, $compilationContext, $check);
        }

        return $classEntry;
    }
}