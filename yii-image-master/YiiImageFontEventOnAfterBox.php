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
 * @property-read YiiImageBox $box Box.
 */
class YiiImageFontEventOnAfterBox extends YiiImageFontEventOnBeforeBox
{

    /**
     * Box.
     * 
     * @var YiiImageBox
     */
    private $_box;

    /**
     * Constructor.
     * 
     * @param YiiImageBox $box
     * @param string $text
     * @param integer $angle
     * @param YiiImageFont $font
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageBox $box, $text, $angle,
                                YiiImageFont $font, $sender = null,
                                $params = null)
    {
        $this->_box = $box;

        parent::__construct($text, $angle, $font, $sender, $params);
    }

    /**
     * Box.
     * 
     * @return YiiImageBox 
     */
    public function getBox()
    {
        return $this->_box;
    }

}
