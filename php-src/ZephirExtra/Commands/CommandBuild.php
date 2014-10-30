<?php

namespace ZephirExtra\Commands;

use Zephir\Commands\CommandBuild as ZephirCommandBuild;
use Zephir\Config;
use Zephir\Logger;
use ZephirExtra\Compiler;

class CommandBuild extends ZephirCommandBuild
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
