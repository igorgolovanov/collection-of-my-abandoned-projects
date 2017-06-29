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
 * @property-read YiiImageFill $fill Fill.
 */
class YiiImageProviderEventOnFill extends YiiImageProviderEvent
{

    /**
     * Fill.
     * 
     * @var YiiImageFill 
     */
    private $_fill;

    /**
     * Constructor.
     * 
     * @param YiiImageFill $fill Fill.
     * @param YiiImageProvider $provider Provider.
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageFill $fill, YiiImageProvider $provider,
                                $sender = null, $params = null)
    {
        $this->_fill = $fill;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Fill.
     *
     * @return YiiImageFill 
     */
    public function getFill()
    {
        return $this->_fill;
    }

}
