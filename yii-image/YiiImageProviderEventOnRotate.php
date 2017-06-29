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
 * @property integer $angle Angle rotate.
 * @property YiiImageColor $backgroundColor Background color.
 */
class YiiImageProviderEventOnRotate extends YiiImageProviderEvent
{

    /**
     * Angle.
     * 
     * @var integer
     */
    private $_angle;

    /**
     * Color.
     * 
     * @var YiiImageColor
     */
    private $_backgroundColor;

    /**
     * Constructor.
     *
     * @param integer $angle Angle rotate.
     * @param YiiImageColor $backgroundColor Background color.
     * @param YiiImageProvider $provider Provider.
     * @param mixed $sender Sender.
     * @param mixed $params Params.
     */
    public function __construct($angle, YiiImageColor $backgroundColor,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->angle = $angle;
        $this->_backgroundColor = $backgroundColor;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Get rotate angle.
     * 
     * @return integer
     */
    public function getAngle()
    {
        return $this->_angle;
    }

    /**
     * Set rotate angle.
     * 
     * @param integer $angle Angle.
     * @return YiiImageProviderEventOnRotate 
     */
    public function setAngle($angle)
    {
        $this->_angle = CPropertyValue::ensureInteger($angle);
        return $this;
    }

    /**
     * Background color.
     * 
     * @return YiiImageColor 
     */
    public function getBackgroundColor()
    {
        return $this->_backgroundColor;
    }

}
