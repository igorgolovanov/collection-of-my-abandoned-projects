<?php

namespace ZephirExtra\Commands;

use Zephir\Commands\CommandGenerate as ZephirCommandGenerate;
use Zephir\Config;
use Zephir\Logger;
use ZephirExtra\Compiler;

class CommandGenerate extends ZephirCommandGenerate
{
    /**
     * {@inheritdoc}
     */
    public function execute(Config $config, Logger $logger)
    {
        $compiler = new Compiler($config, $logger);
        $command = $this->getCommand();
        $compiler->$command($this);
    }
}
