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
 * Event
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * 
 * @property-read YiiImagePoint  $center Center point.
 * @property-read YiiImageBox    $size   Size. 
 * @property-read YiiImageColor  $color Color.
 * @property integer $start Start.
 * @property integer $end End.
 * @property boolean $fill Fill.
 */
class YiiImageDrawerEventOnDrawChord extends YiiImageDrawerEvent
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
     * Fill.
     * 
     * @var boolean
     */
    private $_fill;

    /**
     * Constructor.
     * 
     * @param YiiImagePoint $center Center.
     * @param YiiImageBox $size Size.
     * @param integer $start Start.
     * @param integer $end End.
     * @param YiiImageColor $color Color.
     * @param YiiImageDrawer $drawer Driwer.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct(YiiImagePoint $center, YiiImageBox $size,
                                $start, $end, YiiImageColor $color, $fill,
                                YiiImageDrawer $drawer, $sender = null,
                                $params = null)
    {
        $this->_center = $center;
        $this->_size = $size;
        $this->_color = $color;

        $this->setStart($start);
        $this->setEnd($end);
        $this->setFill($fill);

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

    /**
     * Get fill.
     * 
     * @return boolean
     */
    public function getFill()
    {
        return $this->_end;
    }

    /**
     * Set fill.
     * 
     * @param boolean $fill
     */
    public function setFill($fill)
    {
        $this->_fill = (boolean) $fill;
    }

}
