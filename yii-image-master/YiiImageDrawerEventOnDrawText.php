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
 * @property string $text Text.
 * @property integer $angle Angle.
 * @property-read YiiImageFont $font Font.
 * @property-read YiiImagePoint $position Position.
 */
class YiiImageDrawerEventOnDrawText extends YiiImageDrawerEvent
{

    /**
     * Text.
     *
     * @var string
     */
    private $_text;

    /**
     * Font.
     * 
     * @var YiiImageFont
     */
    private $_font;

    /**
     * Position.
     * 
     * @var YiiImagePoint
     */
    private $_position;

    /**
     * Angle.
     * 
     * @var integer
     */
    private $_angle;

    /**
     * Constructor.
     * 
     * @param string $text Tetx
     * @param YiiImageFont $font
     * @param YiiImagePoint $position
     * @param integer $angle
     * @param YiiImageDrawer $drawer
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct($text, YiiImageFont $font,
                                YiiImagePoint $position, $angle,
                                YiiImageDrawer $drawer, $sender = null,
                                $params = null)
    {
        parent::__construct($drawer, $sender, $params);
    }

    /**
     * Get text.
     * 
     * @return strings
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
     * Get angle.
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

    /**
     * Font.
     * 
     * @return YiiImageFont 
     */
    public function getFont()
    {
        return $this->_font;
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

}
