<?php

/*
 * This file is part of the YiiStorage package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

/**
 * @author  Igor Golovanov <igor.golovanov@gmail.com> 
 */
class YiiStorageEventOnRead extends YiiStorageEvent
{
    /**
     * Key.
     * 
     * @var string 
     */
    public $key;
    
    /**
     * Content.
     * 
     * @var string
     */
    public $content;
    
    /**
     * Constructor.
     * 
     * @param string $key Key.
     * @param YiiImageProvider $provider Provider.
     * @param mixed $sender Sender.
     * @param mixed $params Params
     */
    public function __construct($key, YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        parent::__construct($provider, $sender, $params);
        
        $this->key = $key;
    }
}
