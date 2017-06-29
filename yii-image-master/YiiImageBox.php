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
 * Image box.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * 
 * @property-read integer $height Height.
 * @property-read integer $width  Width.
 */
class YiiImageBox extends CComponent
{

    /**
     * Width.
     * 
     * @var integer
     */
    private $_width;

    /**
     * Height.
     * 
     * @var integer
     */
    private $_height;

    /**
     * Constructs the Size with given width and height
     *
     * @param integer $width    Width.
     * @param integer $height   Height.
     *
     * @throws InvalidArgumentException
     */
    public function __construct($width, $height)
    {
        $width  = (int) $width;
        $height = (int) $height;

        if ($height < 1 || $width < 1) {
            throw new InvalidArgumentException(sprintf(
                            'Length of either side cannot be 0 or negative, current size ' .
                            'is %sx%s', $width, $height
            ));
        }

        $this->_width = $width;
        $this->_height = $height;
    }

    /**
     * Gets current image height
     *
     * @return integer
     */
    public function getHeight()
    {
        return $this->_height;
    }

    /**
     * Gets current image width
     *
     * @return integer
     */
    public function getWidth()
    {
        return $this->_width;
    }

    /**
     * Returns a string representation of the current box
     *
     * @return string
     */
    public function __toString()
    {
        return sprintf('%dx%d px', $this->width, $this->height);
    }

    /**
     * Creates new YiiImageBox instance with ratios applied to both sides
     *
     * @param float $ratio Ratio.
     *
     * @return YiiImageBox
     */
    public function scale($ratio)
    {
        return new YiiImageBox(round($ratio * $this->width), round($ratio * $this->height));
    }

    /**
     * Creates new YiiImageBox, adding given size to both sides
     *
     * @param integer $size Size.
     *
     * @return YiiImageBox
     */
    public function increase($size)
    {
        return new YiiImageBox((int) $size + $this->width, (int) $size + $this->height);
    }

    /**
     * Checks whether current box can fit given box at a given start position,
     * start position defaults to top left corner xy(0,0)
     *
     * @param YiiImageBox   $box    Box.
     * @param YiiImagePoint $start  Start point.
     *
     * @return Boolean
     */
    public function contains(YiiImageBox $box, YiiImagePoint $start = null)
    {
        $start = $start ? $start : new YiiImagePoint(0, 0);

        return $start->in($this) &&
                $this->width >= $box->width + $start->x &&
                $this->height >= $box->height + $start->y;
    }

    /**
     * Gets current box square, useful for getting total number of pixels in a
     * given box
     *
     * @return integer
     */
    public function square()
    {
        return $this->width * $this->height;
    }

    /**
     * Resizes box to given width, constraining proportions and returns the new box
     *
     * @param integer $width Width.
     * 
     * @return YiiImageBox
     */
    public function widen($width)
    {
        return $this->scale($width / $this->width);
    }

    /**
     * Resizes box to given height, constraining proportions and returns the new box
     *
     * @param integer $height Height.
     * 
     * @return YiiImageBox
     */
    public function heighten($height)
    {
        return $this->scale($height / $this->height);
    }

}