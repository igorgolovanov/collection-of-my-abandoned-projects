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
}