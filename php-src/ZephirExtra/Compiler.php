<?php

namespace ZephirExtra;

class Compiler extends \Zephir\Compiler
{
    /**
     * Pre-compiles classes creating a CompilerFile definition
     *
     * @param string $filePath
     */
    protected function preCompile($filePath)
    {
        if (preg_match('/\.zep$/', $filePath)) {

            $className = str_replace('/', '\\', $filePath);
            $className = preg_replace('/.zep$/', '', $className);

            $className = join('\\', array_map(function ($i) {
                return ucfirst($i);
            }, explode('\\', $className)));


            $this->files[$className] = new CompilerFile($className, $filePath, $this->config, $this->logger);
            $this->files[$className]->preCompile($this);

            $this->definitions[$className] = $this->files[$className]->getClassDefinition();
        }
    }

    protected function checkDirectory()
    {
        return 'zendframework';
    }
} 