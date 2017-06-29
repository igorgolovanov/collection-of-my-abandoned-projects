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
 * YiiImageColor.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * 
 * @property-read integer $red      RED value of the color.
 * @property-read integer $green    GREEN value of the color.
 * @property-read integer $blue     BLUE value of the color.
 * @property-read integer $alpha    Percentage of transparency of the color.
 * @property-read boolean $isOpaque Is opaque.
 */
final class YiiImageColor extends CComponent
{

    /**
     * RED value of the color.
     * 
     * @var integer
     */
    private $_red;

    /**
     * GREEN value of the color.
     * 
     * @var integer
     */
    private $_green;

    /**
     * BLUE value of the color.
     * 
     * @var integer
     */
    private $_blue;

    /**
     * Percentage of transparency of the color.
     * 
     * @var integer
     */
    private $_alpha;

    /**
     * Constructs image color, e.g.:
     *     - new YiiImageColor('fff') - will produce non-transparent white color
     *     - new YiiImageColor('ffffff', 50) - will product 50% transparent white
     *     - new YiiImageColor(array(255, 255, 255)) - another way of getting white
     *     - new YiiImageColor(0x00FF00) - hexadecimal notation for green
     *
     * @param array|string|integer $color Color.
     * @param integer              $alpha Percentage of transparency of the color.
     * 
     * @throws InvalidArgumentException
     */
    public function __construct($color, $alpha = 0)
    {
        list($this->_red, $this->_green, $this->_blue) = $this->prepareColor($color);

        if (!is_int($alpha) || $alpha < 0 || $alpha > 100) {
            throw new InvalidArgumentException(sprintf(
                'Alpha must be an integer between 0 and 100, %s given',
                $alpha
            ));
        }
        $this->_alpha = $alpha;

        $this->attachBehaviors($this->behaviors());
    }

    /**
     * Behaviors.
     * 
     * @return array 
     */
    public function behaviors()
    {
        return array();
    }

    /**
     * Returns RED value of the color
     *
     * @return integer
     */
    public function getRed()
    {
        return $this->_red;
    }

    /**
     * Returns GREEN value of the color
     *
     * @return integer
     */
    public function getGreen()
    {
        return $this->_green;
    }

    /**
     * Returns BLUE value of the color
     *
     * @return integer
     */
    public function getBlue()
    {
        return $this->_blue;
    }

    /**
     * Returns percentage of transparency of the color
     *
     * @return integer
     */
    public function getAlpha()
    {
        return $this->_alpha;
    }

    /**
     * Returns a copy of current color, incrementing the alpha channel by the
     * given amount
     *
     * @param integer $alpha Alpha.
     *
     * @return YiiImageColor
     */
    public function dissolve($alpha)
    {
        return new YiiImageColor((string) $this, $this->alpha + $alpha);
    }

    /**
     * Returns a copy of the current color, lightened by the specified number
     * of shades
     *
     * @param integer $shade Shade.
     *
     * @return YiiImageColor
     */
    public function lighten($shade)
    {
        return new YiiImageColor(
                        array(
                            min(255, $this->red + $shade),
                            min(255, $this->green + $shade),
                            min(255, $this->blue + $shade),
                        ),
                        $this->alpha
        );
    }

    /**
     * Returns a copy of the current color, darkened by the specified number of
     * shades
     *
     * @param integer $shade Shade.
     *
     * @return YiiImageColor
     */
    public function darken($shade)
    {
        return new YiiImageColor(
                        array(
                            max(0, $this->red - $shade),
                            max(0, $this->green - $shade),
                            max(0, $this->blue - $shade),
                        ),
                        $this->alpha
        );
    }

    /**
     * Internal
     *
     * Performs checks for color validity (hex or array of array(R, G, B))
     *
     * @param string|array $color Color
     * 
     * @return array
     * 
     * @throws InvalidArgumentException
     */
    private function prepareColor($color)
    {
        if (!is_string($color) && !is_array($color) && !is_int($color)) {
            throw new InvalidArgumentException(sprintf(
                            'Color must be specified as a hexadecimal string, array ' .
                            'or integer, %s given', gettype($color)
            ));
        }
        if (is_array($color) && count($color) !== 3) {
            throw new InvalidArgumentException(
                    'Color argument if array, must look like array(R, G, B), ' .
                    'where R, G, B are the integer values between 0 and 255 for ' .
                    'red, green and blue color indexes accordingly'
            );
        }

        if (is_string($color)) {
            $color = ltrim($color, '#');

            if (strlen($color) !== 3 && strlen($color) !== 6) {
                throw new InvalidArgumentException(sprintf(
                                'Color must be a hex value in regular (6 characters) or ' .
                                'short (3 characters) notation, "%s" given',
                                $color
                ));
            }

            if (strlen($color) === 3) {
                $color = $color[0] . $color[0] .
                        $color[1] . $color[1] .
                        $color[2] . $color[2];
            }

            $color = array_map('hexdec', str_split($color, 2));
        }

        if (is_int($color)) {
            $color = array(
                255 & ($color >> 16),
                255 & ($color >> 8),
                255 & $color
            );
        }

        return array_values($color);
    }

    /**
     * Returns hex representation of the color
     *
     * @return string
     */
    public function __toString()
    {
        return sprintf('#%02x%02x%02x', $this->red, $this->green, $this->blue);
    }

    /**
     * Checks if the current color is opaque
     *
     * @return boolean
     */
    public function getIsOpaque()
    {
        return 0 === $this->alpha;
    }

    /**
     * Min.
     *
     * @param YiiImageColor $color Color.
     * 
     * @return YiiImageColor
     */
    public function min(YiiImageColor $color)
    {
        return new YiiImageColor(array(
                    min(array($this->red, $color->red)),
                    min(array($this->green, $color->green)),
                    min(array($this->blue, $color->blue)),
                        ), min(array($this->alpha, $color->alpha)));
    }

    /**
     * Max.
     *
     * @param YiiImageColor $color Color.
     * 
     * @return YiiImageColor
     */
    public function max(YiiImageColor $color)
    {
        return new YiiImageColor(array(
                    max(array($this->red, $color->red)),
                    max(array($this->green, $color->green)),
                    max(array($this->blue, $color->blue)),
                        ), max(array($this->alpha, $color->alpha)));
    }

    /**
     * Round.
     * 
     * @param YiiImageColor $color Color.
     * 
     * @return YiiImageColor
     */
    public function round(YiiImageColor $color)
    {
        return new YiiImageColor(array(
                    round(abs($this->red - $color->red)),
                    round(abs($this->green - $color->green)),
                    round(abs($this->blue - $color->blue)),
                        ), round(abs($this->alpha - $color->alpha)));
    }

}
