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
 * @property-read YiiImageColor $color Color
 * @property-read YiiImageBox $size Size
 * @property-read YiiImageProvider $provider Provider
 */
class YiiImageDriverEventOnAfterCreate extends YiiImageEventOnBeforeCreate
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
     * @param YiiImageProvider $provider 
     * @param YiiImageBox $size Size.
     * @param YiiImageColor $color Color.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct(YiiImageProvider $provider, YiiImageBox $size,
                                YiiImageColor $color = null, $sender = null,
                                $params = null)
    {
        $this->_provider = $provider;

        parent::__construct($size, $color, $sender, $params);
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
