<?php

namespace ZephirExtra\Commands;

use Zephir\Commands\CommandInstall as ZephirCommandInstall;
use Zephir\Config;
use Zephir\Logger;
use ZephirExtra\Compiler;

class CommandInstall extends ZephirCommandInstall
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
