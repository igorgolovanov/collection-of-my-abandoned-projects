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
 * Font event.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * 
 * @property string  $text  Text.
 * @property integer $angle Angle.
 */
class YiiImageFontEventOnBeforeBox extends YiiImageFontEvent
{

    /**
     * Text.
     * 
     * @var string
     */
    private $_text;

    /**
     * Angle.
     * 
     * @var integer
     */
    private $_angle;

    /**
     * Constructor.
     * 
     * @param string $text
     * @param integer $angle
     * @param YiiImageFont $font
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct($text, $angle, YiiImageFont $font,
                                $sender = null, $params = null)
    {
        $this->text = $text;
        $this->angle = $angle;

        parent::__construct($font, $sender, $params);
    }

    /**
     * Get text.
     * 
     * @return string
     */
    public function getText()
    {
        return $this->_text;
    }

    /**
     * Set text.
     * 
     * @param string $text 
     */
    public function setText($text)
    {
        $this->_text = (string) $text;
    }

    /**
     * Angle.
     * 
     * @return integer 
     */
    public function getAngle()
    {
        return $this->_angle;
    }

    /**
     * Set angle.
     * 
     * @param integer $angle 
     */
    public function setAngle($angle)
    {
        $this->_angle = (integer) $angle;
    }

}
