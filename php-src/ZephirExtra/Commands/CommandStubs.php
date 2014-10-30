<?php

namespace ZephirExtra\Commands;

use Zephir\Commands\CommandStubs as ZephirCommandStubs;
use Zephir\Config;
use Zephir\Logger;
use ZephirExtra\Compiler;

class CommandStubs extends ZephirCommandStubs
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
