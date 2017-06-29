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
class YiiStorageEventOnRename extends YiiStorageEvent
{
    /**
     * Key.
     * 
     * @var string 
     */
    private $_key;
    
    /**
     * New key.
     * 
     * @var string 
     */
    private $_newkey;
    
    public function __construct(YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        parent::__construct($provider, $sender, $params);
    }
    
    public function getKey()
    {
        
    }
}