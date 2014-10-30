<?php

namespace ZephirExtra\Commands;

use Zephir\Commands\CommandClean as ZephirCommandClean;
use Zephir\Config;
use Zephir\Logger;
use ZephirExtra\Compiler;

class CommandClean extends ZephirCommandClean
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
