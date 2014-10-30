<?php

namespace ZephirExtra\Commands;

use Zephir\Commands\CommandCompile as ZephirCommandCompile;
use Zephir\Config;
use Zephir\Logger;
use ZephirExtra\Compiler;

class CommandCompile extends ZephirCommandCompile
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
