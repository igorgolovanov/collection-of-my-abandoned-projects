<?php

namespace ZephirExtra;

use Zephir\Commands\CommandAbstract;
use Zephir\Config;
use Zephir\Logger;

class Bootstrap extends \Zephir\Bootstrap
{

    /**
     * Boots the compiler executing the specified action
     */
    public static function boot()
    {
        try {

            /**
             * Global config
             */
            $config = new Config();
            register_shutdown_function(array($config, 'saveOnExit'));

            /**
             * Global logger
             */
            $logger = new Logger($config);

            if (isset($_SERVER['argv'][1])) {
                $action = $_SERVER['argv'][1];
            } else {
                $action = 'help';
            }

            /**
             * Change configurations flags
             */
            if ($_SERVER['argc'] >= 2) {
                for ($i = 2; $i < $_SERVER['argc']; $i++) {

                    $parameter = $_SERVER['argv'][$i];

                    if (preg_match('/^-fno-([a-z0-9\-]+)/', $parameter, $matches) || preg_match('/^-f([a-z0-9\-]+)/', $parameter, $matches)) {
                        $config->set($matches[1], false, 'optimizations');
                        continue;
                    }

                    if (preg_match('/^-W([a-z0-9\-]+)/', $parameter, $matches) || preg_match('/^-w([a-z0-9\-]+)/', $parameter, $matches)) {
                        $logger->set($matches[1], false, 'warnings');
                        continue;
                    }

                    switch ($parameter) {
                        case '-w':
                            $config->set('silent', true);
                            break;
                        case '-v':
                            $config->set('verbose', true);
                            break;
                        case '-V':
                            $config->set('verbose', false);
                            break;
                        default:
                            break;
                    }
                }
            }

            /**
             * Register built-in commands
             * @var $item \DirectoryIterator
             */
            foreach (new \DirectoryIterator(ZEPHIRPATH . '/Library/Commands') as $item) {
                if (!$item->isDir()) {

                    $className = 'Zephir\\Commands\\' . str_replace('.php', '', $item->getBaseName());
                    $class = new \ReflectionClass($className);

                    if (!$class->isAbstract() && !$class->isInterface()) {
                        /**
                         * @var $command CommandAbstract
                         */
                        $command = new $className();

                        if (!($command instanceof CommandAbstract)) {
                            throw new \Exception('Class ' . $class->name . ' must be instance of CommandAbstract');
                        }

                        static::$commands[$command->getCommand()] = $command;
                    }
                }
            }

            /**
             * Register built-in commands
             * @var $item \DirectoryIterator
             */
            foreach (new \DirectoryIterator(__DIR__ . '/Commands') as $item) {
                if (!$item->isDir()) {

                    $className = 'ZephirExtra\\Commands\\' . str_replace('.php', '', $item->getBaseName());
                    $class = new \ReflectionClass($className);

                    if (!$class->isAbstract() && !$class->isInterface()) {
                        /**
                         * @var $command CommandAbstract
                         */
                        $command = new $className();

                        if (!($command instanceof CommandAbstract)) {
                            throw new \Exception('Class ' . $class->name . ' must be instance of CommandAbstract');
                        }

                        static::$commands[$command->getCommand()] = $command;
                    }
                }
            }

            if (!isset(self::$commands[$action])) {
                $message = 'Unrecognized action "' . $action . '"';
                $metaphone = metaphone($action);
                foreach (self::$commands as $key => $command) {
                    if (metaphone($key) == $metaphone) {
                        $message .= PHP_EOL . PHP_EOL . 'Did you mean "' . $key . '"?';
                    }
                }

                throw new \Exception($message);
            }

            /**
             * Execute the command
             */
            static::$commands[$action]->execute($config, $logger);

        } catch (\Exception $e) {
            self::showException($e, isset($config) ? $config : null);
        }
    }
} 