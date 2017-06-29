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
 * Event for draw arc.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * 
 * @property-read   YiiImagePoint   $center Center point.
 * @property-read   YiiImageBox     $size   Size. 
 * @property-read   YiiImageColor   $color  Color 
 * @property        integer         $start  Start.
 * @property        integer         $end    End.
 */
class YiiImageDrawerEventOnDrawArc extends YiiImageDrawerEvent
{

    /**
     * Center.
     * 
     * @var YiiImagePoint
     */
    private $_center;

    /**
     * Size.
     * 
     * @var YiiImageBox
     */
    private $_size;

    /**
     * Color.
     * 
     * @var YiiImageColor
     */
    private $_color;

    /**
     * Start.
     * 
     * @var integer
     */
    private $_start;

    /**
     * End.
     * 
     * @var integer
     */
    private $_end;

    /**
     * Constructor.
     * 
     * @param YiiImagePoint $center Center.
     * @param YiiImageBox $size Size.
     * @param integer $start Start.
     * @param integer $end End.
     * @param YiiImageColor $color Color.
     * @param YiiImageDrawer $driwer Driwer.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct(YiiImagePoint $center, YiiImageBox $size,
                                $start, $end, YiiImageColor $color,
                                YiiImageDrawer $drawer, $sender = null,
                                $params = null)
    {
        $this->_center = $center;
        $this->_size = $size;
        $this->_color = $color;

        $this->setStart($start);
        $this->setEnd($end);

        parent::__construct($drawer, $sender, $params);
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

    /**
     * Center.
     * 
     * @return YiiImagePoint 
     */
    public function getCenter()
    {
        return $this->_center;
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

    /**
     * Get start.
     * 
     * @return integer
     */
    public function getStart()
    {
        return $this->_start;
    }

    /**
     * Get end.
     * 
     * @return integer
     */
    public function getEnd()
    {
        return $this->_end;
    }

    /**
     * Set start.
     * 
     * @param integer $start 
     */
    public function setStart($start)
    {
        $this->_start = (integer) $start;
    }

    /**
     * Set end.
     * 
     * @param integer $start 
     */
    public function setEnd($end)
    {
        $this->_end = (integer) $end;
    }

}
