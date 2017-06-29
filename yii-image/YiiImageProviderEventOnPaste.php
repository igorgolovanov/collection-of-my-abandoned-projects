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
 * @property-read YiiImageProvider $image Image.
 * @property-read YiiImagePoint $startPoint Start point.
 */
class YiiImageProviderEventOnPaste extends YiiImageProviderEvent
{

    /**
     * Start point.
     *
     * @var YiiImagePoint 
     */
    private $_startPoint;

    /**
     * Image.
     *
     * @var YiiImageProvider 
     */
    private $_image;

    /**
     * Constructor.
     * 
     * @param YiiImageProvider $image Image.
     * @param YiiImagePoint $startPoint Start point.
     * @param YiiImageProvider $provider Provider.
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageProvider $image,
                                YiiImagePoint $startPoint,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->_image = $image;
        $this->_startPoint = $startPoint;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Image.
     * 
     * @return YiiImageProvider
     */
    public function getImage()
    {
        return $this->_image;
    }

    /**
     * Start point.
     *
     * @return YiiImagePoint 
     */
    public function getStartPoint()
    {
        return $this->_startPoint;
    }

}