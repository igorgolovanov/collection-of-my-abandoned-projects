<?php

namespace ZephirExtra\Commands;

use Zephir\Commands\CommandFullClean as ZephirCommandFullClean;
use Zephir\Config;
use Zephir\Logger;
use ZephirExtra\Compiler;

class CommandFullClean extends ZephirCommandFullClean
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
