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
 * @property-read YiiImagePoint  $center Center point.
 * @property-read YiiImageBox    $size   Size. 
 * @property-read YiiImageColor  $color Color
 * @property boolean $fill Fill.
 */
class YiiImageDrawerEventOnDrawEllipse extends YiiImageDrawerEvent
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
     * @param YiiImageColor $color Color.
     * @param YiiImageDrawer $driwer Driwer.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct(YiiImagePoint $center, YiiImageBox $size,
                                YiiImageColor $color, $fill,
                                YiiImageDrawer $drawer, $sender = null,
                                $params = null)
    {
        $this->_center = $center;
        $this->_size = $size;
        $this->_color = $color;
        $this->fill = $fill;

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
