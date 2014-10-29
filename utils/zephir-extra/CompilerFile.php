<?php

namespace ZephirExtra;

use Zephir\Compiler as ZephirCompiler;

class CompilerFile extends \Zephir\CompilerFile
{
    public function genIR(ZephirCompiler $compiler)
    {
        $ir = parent::genIR($compiler);

        foreach($ir as $k => $i) {
            if(!empty($i['type']) && $i['type'] == 'namespace') {
                if(0 === stripos($i['name'], 'Zend\\')) {
                    $ir[$k]['name'] = 'ZendFramework\\' . substr($i['name'], 5);
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

