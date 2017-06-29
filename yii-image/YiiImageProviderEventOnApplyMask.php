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
 * @property-read YiiImageProvider $mask Mask.
 */
class YiiImageProviderEventOnApplyMask extends YiiImageProviderEvent
{

    /**
     * Mask.
     * 
     * @var YiiImageProvider 
     */
    private $_mask;

    /**
     * Constructor.
     * 
     * @param YiiImageProvider $mask Mask.
     * @param YiiImageProvider $provider Provider.
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageProvider $mask,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->_mask = $mask;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Mask.
     *
     * @return YiiImageProvider  
     */
    public function getMask()
    {
        return $this->_mask;
    }

}
