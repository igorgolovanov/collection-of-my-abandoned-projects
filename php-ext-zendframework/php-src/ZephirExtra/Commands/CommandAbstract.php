<?php

namespace ZephirExtra\Commands;

use Zephir\Config;
use Zephir\Logger;
use ZephirExtra\Compiler;

abstract class CommandAbstract extends \Zephir\Commands\CommandAbstract
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
