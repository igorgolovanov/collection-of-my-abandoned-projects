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
 * @property-read integer $x X-coordinate
 * @property-read integer $y Y-coordinate
 */
class YiiImagePoint extends CComponent
{

    /**
     * X-coordinate
     * 
     * @var integer
     */
    private $_x;

    /**
     * Y-coordinate
     * 
     * @var integer 
     */
    private $_y;

    /**
     * Constructor.
     * 
     * @param integer $x X-coordinate.
     * @param integer $y Y-coordinate.
     */
    public function __construct($x, $y)
    {
        $this->_x = (int) $x;
        $this->_y = (int) $y;
    }

    /**
     * Gets points x coordinate
     *
     * @return integer
     */
    public function getX()
    {
        return $this->_x;
    }

    /**
     * Gets points y coordinate
     *
     * @return integer
     */
    public function getY()
    {
        return $this->_y;
    }

    /**
     * Checks if current coordinate is inside a given bo
     *
     * @param YiiImageBox $box
     *
     * @return boolean
     */
    public function in(YiiImageBox $box)
    {
        return $this->x < $box->width && $this->y < $box->height;
    }

    /**
     * Returns another point, moved by a given amout from current coordinates
     *
     * @param $amount
     * 
     * @return YiiImagePoint
     */
    public function move($amount)
    {
        return new YiiImagePoint($this->x + $amount, $this->y + $amount);
    }

    /**
     * Gets a string representation for the current point
     *
     * @return string
     */
    public function __toString()
    {
        return sprintf('(%d, %d)', $this->x, $this->y);
    }

}
