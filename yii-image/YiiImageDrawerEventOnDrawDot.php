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
 * @property-read YiiImagePoint  $position Position
 * @property-read YiiImageColor  $color Color
 */
class YiiImageDrawerEventOnDrawDot extends YiiImageDrawerEvent
{

    /**
     * Position.
     * 
     * @var YiiImagePoint
     */
    private $_position;

    /**
     * Color.
     * 
     * @var YiiImageColor
     */
    private $_color;

    /**
     * Constructor.
     * 
     * @param YiiImagePoint $position Position.
     * @param YiiImageColor $color Color.
     * @param YiiImageDrawer $drawer Drawer.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct(YiiImagePoint $position, YiiImageColor $color,
                                YiiImageDrawer $drawer, $sender = null,
                                $params = null)
    {
        $this->_position = $position;
        $this->_color = $color;

        parent::__construct($drawer, $sender, $params);
    }

    /**
     * Position.
     * 
     * @return YiiImagePoint 
     */
    public function getPosition()
    {
        return $this->_position;
    }

    /**
     * Color.
     * 
     * @return YiiImageColor
     */
    public function getColor()
    {
        return $this->_color;
    }

}
