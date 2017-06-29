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
 */
abstract class YiiImageFillGradientLineral extends YiiImageFill
{

    /**
     * Lenght.
     * 
     * @var integer
     */
    private $_length;

    /**
     * Start color.
     * 
     * @var YiiImageColor
     */
    private $_start;

    /**
     * End color.
     * 
     * @var YiiImageColor
     */
    private $_end;

    /**
     * Constructs a linear gradient with overall gradient length, and start and
     * end shades, which default to 0 and 255 accordingly
     *
     * @param integer $length
     * @param YiiImageColor $start
     * @param YiiImageColor $end
     */
    final public function __construct($length, YiiImageColor $start,
                                      YiiImageColor $end)
    {
        $this->_length = $length;
        $this->_start = $start;
        $this->_end = $end;
    }

    /**
     */
    final public function getColor(YiiImagePoint $position)
    {
        $l = $this->getDistance($position);

        if ($l >= $this->_length) {
            return $this->end;
        }

        if ($l < 0) {
            return $this->start;
        }

        $color = new YiiImageColor(array(
                    (int) min(255,
                              min($this->start->red, $this->end->getRed()) + round(abs($this->end->getRed() - $this->start->getRed()) * $l / $this->_length)),
                    (int) min(255,
                              min($this->start->green, $this->end->getGreen()) + round(abs($this->end->getGreen() - $this->start->getGreen()) * $l / $this->_length)),
                    (int) min(255,
                              min($this->start->blue, $this->end->getBlue()) + round(abs($this->end->getBlue() - $this->start->getBlue()) * $l / $this->_length)),
                        ),
                        (int) min(100,
                                  min($this->start->alpha,
                                      $this->end->getAlpha()) + round(abs($this->end->getAlpha() - $this->start->getAlpha()) * $l / $this->_length))
        );

        return $color;
    }

    /**
     * @return YiiImageColor
     */
    final public function getStart()
    {
        return $this->start;
    }

    /**
     * @return 
     */
    final public function getEnd()
    {
        return $this->end;
    }

    /**
     * Get the distance of the position relative to the beginning of the gradient
     *
     * @param YiiImagePoint $position
     *
     * @return integer
     */
    abstract protected function getDistance(YiiImagePoint $position);

}