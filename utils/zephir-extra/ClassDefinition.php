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
            case 'splqueue':
                $classEntry = 'spl_ce_Queue';
                break;
            case 'splpriorityqueue':
                $classEntry = 'spl_ce_PriorityQueue';
                break;
            case 'splstack':
                $classEntry = 'spl_ce_Stack';
                break;
            default:
                $classEntry = parent::getClassEntryByClassName($className, $compilationContext, $check);
        }

        return $classEntry;
    }
}