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
 *
 * @property-read YiiImageProvider $provider Provider. 
 */
class YiiStorageEvent extends CEvent
{
    /**
     * Provider.
     * 
     * @var YiiImageProvider 
     */
    private $_provider;
    
    /**
     * Constructor.
     *
     * @param YiiImageProvider  $provider   Provider.
     * @param object            $sender     Sender.
     * @param mixed             $params     Params.
     */
    public function __construct(YiiImageProvider $provider, $sender = null, $params = null)
    {
        parent::__construct($sender, $params);
        
        $this->_provider = $provider;
    }
    
    /**
     * Provider.
     * 
     * @return YiiImageProvider 
     */
    public function getProvider()
    {
        return $this->_provider;
    }
}