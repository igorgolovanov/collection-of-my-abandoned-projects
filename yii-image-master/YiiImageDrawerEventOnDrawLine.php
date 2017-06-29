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
 * @property-read YiiImagePoint $start Start point
 * @property-read YiiImagePoint $end End point.
 * @property-read YiiImageColor $color Color.   
 */
class YiiImageDrawerEventOnDrawLine extends YiiImageDrawerEvent
{

    /**
     * Start point.
     *
     * @var YiiImagePoint
     */
    private $_start;

    /**
     * End point.
     * 
     * @var YiiImagePoint
     */
    private $_end;

    /**
     * Color.
     * 
     * @var YiiImageColor 
     */
    private $_color;

    /**
     * Constructor.
     * 
     * @param YiiImagePoint $start Start point.
     * @param YiiImagePoint $end End point.
     * @param YiiImageColor $color Color.
     * @param YiiImageDrawer $drawer Drawer.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct(YiiImagePoint $start, YiiImagePoint $end,
                                YiiImageColor $color, YiiImageDrawer $drawer,
                                $sender = null, $params = null)
    {
        $this->_start = $start;
        $this->_end = $end;
        $this->_color = $color;

        parent::__construct($drawer, $sender, $params);
    }

    /**
     * Start point.
     * 
     * @return YiiImagePoint 
     */
    public function getStartPoint()
    {
        return $this->_start;
    }

    /**
     * End point.
     * 
     * @return YiiImagePoint 
     */
    public function getEndPoint()
    {
        return $this->_end;
    }

    /**
     * Color.
     * 
     * @return YiiImagePoint 
     */
    public function getColor()
    {
        return $this->_color;
    }

}
