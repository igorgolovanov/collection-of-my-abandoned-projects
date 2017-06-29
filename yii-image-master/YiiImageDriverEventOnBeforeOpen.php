<?php

/*
 * This file is part of the YiiImage package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

/**
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * 
 * @property string $path
 */
class YiiImageDriverEventOnBeforeOpen extends YiiImageDriverEvent
{

    /**
     * Path.
     * 
     * @var string
     */
    public $path;

    /**
     * Constructor.
     * 
     * @param string $path Path.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct($path, $sender = null, $params = null)
    {
        $this->path = $path;

        parent::__construct($sender, $params);
    }

}