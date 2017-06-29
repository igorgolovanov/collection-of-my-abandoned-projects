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
 * @property-read YiiImagePoint $startPoint Start point.
 * @property-read YiiImageBox $size Size.
 */
class YiiImageProviderEventOnCrop extends YiiImageProviderEvent
{

    /**
     * Start point.
     * 
     * @var YiiImagePoint
     */
    private $_startPoint;

    /**
     * Size.
     * 
     * @var YiiImageBox
     */
    private $_size;

    /**
     * Constructor.
     *
     * @param YiiImagePoint $startPoint Start point.
     * @param YiiImageBox $size Size.
     * @param YiiImageProvider $provider Provider.
     * @param mixed $sender Sender.
     * @param mixed $params Params.
     */
    public function __construct(YiiImagePoint $startPoint, YiiImageBox $size,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->_startPoint = $startPoint;
        $this->_size = $size;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Start Point.
     * 
     * @return YiiImagePoint
     */
    public function getStartPoint()
    {
        return $this->_startPoint;
    }

    /**
     * Size.
     * 
     * @return YiiImageBox 
     */
    public function getSize()
    {
        return $this->_size;
    }

}
