<?php

/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

error_reporting(E_ALL);

ini_set('display_errors', 1);
ini_set('date.timezone', 'Europe/Kiev');

$uri = OAuth\Uri::createFromSuperGlobals($_SERVER);
$uri->setQuery('');

require_once __DIR__ . '/init.php';
