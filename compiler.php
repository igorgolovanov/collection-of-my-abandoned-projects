<?php

error_reporting(E_ALL);

define('ZEPHIRPATH', __DIR__ . '/vendor/phalcon/zephir/');
define('T', "\t");
define('2T', "\t\t");

require __DIR__ . '/vendor/autoload.php';

ZephirExtra\Bootstrap::boot();