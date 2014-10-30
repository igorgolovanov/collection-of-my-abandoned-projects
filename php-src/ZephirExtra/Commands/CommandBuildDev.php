<?php

namespace ZephirExtra\Commands;

use Zephir\Commands\CommandBuild as ZephirCommandBuildDev;
use Zephir\Config;
use Zephir\Logger;
use ZephirExtra\Compiler;

class CommandBuildDev extends ZephirCommandBuildDev
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
