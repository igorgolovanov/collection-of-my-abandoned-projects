<?php

namespace ZephirExtra;

use Zephir\Compiler as ZephirCompiler;

class CompilerFile extends \Zephir\CompilerFile
{
    public function genIR(ZephirCompiler $compiler)
    {
        $ir = parent::genIR($compiler);

        foreach ($ir as &$entry) {
            if (empty($entry['type'])) {
                continue;
            }
            // update namespace
            if($entry['type'] == 'namespace') {
                if(0 === stripos($entry['name'], 'Zend\\')) {
                    $entry['name'] = 'ZendFramework\\' . substr($entry['name'], 5);
                }
            }
            // update use
            if ($entry['type'] == 'use' && !empty($entry['aliases'])) {
                foreach($entry['aliases'] as &$alias) {
                    if(0 === stripos($alias['name'], 'Zend\\')) {
                        $alias['name'] = 'ZendFramework\\' . substr($alias['name'], 5);
                    }
                }
            }
            // update classes
            if ($entry['type'] == 'class') {
                if (!empty( $entry['extends'])) {
                    if (0 === stripos($entry['extends'], '\\Zend\\')) {
                        $entry['extends'] = '\\ZendFramework\\' . substr($entry['extends'], 6);
                    }
                }
                if (!empty($entry['implements'])) {
                    foreach ($entry['implements'] as &$interface) {
                        if(0 === stripos($interface['value'], '\\Zend\\')) {
                            $interface['value'] = '\\ZendFramework\\' . substr($interface['value'], 6);
                        }
                    }
                }
            }
            // update interfaces
            if ($entry['type'] == 'interface') {
                if (!empty($entry['extends'])) {
                    foreach ($entry['extends'] as &$interface) {
                        if(0 === stripos($interface['value'], '\\Zend\\')) {
                            $interface['value'] = '\\ZendFramework\\' . substr($interface['value'], 6);
                        }
                    }
                }
            }
        }
        return $ir;
    }

    /**
     * Creates a definition for a class
     *
     * @param string $namespace
     * @param array $topStatement
     */
    public function preCompileClass($namespace, $topStatement)
    {
        parent::preCompileClass($namespace, $topStatement);

        $serialized = serialize($this->_classDefinition);
        $serialized = str_replace('O:22:"Zephir\ClassDefinition"', 'O:27:"ZephirExtra\ClassDefinition"', $serialized);

        $this->_classDefinition = unserialize($serialized);
    }

    /**
     * Creates a definition for an interface
     *
     * @param string $namespace
     * @param array $topStatement
     */
    public function preCompileInterface($namespace, $topStatement)
    {
        parent::preCompileInterface($namespace, $topStatement);

        $serialized = serialize($this->_classDefinition);
        $serialized = str_replace('O:22:"Zephir\ClassDefinition"', 'O:27:"ZephirExtra\ClassDefinition"', $serialized);

        $this->_classDefinition = unserialize($serialized);
    }
}

