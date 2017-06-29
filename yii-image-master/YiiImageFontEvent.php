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
 * Base font event.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * @property-read YiiImageFont $font Font.
 */
class YiiImageFontEvent extends CEvent
{

    /**
     * Font.
     * 
     * @var YiiImageFont
     */
    private $_font;

    /**
     * Constructor.
     * 
     * @param YiiImageFont $font
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageFont $font, $sender = null,
                                $params = null)
    {
        $this->_font = $font;

        parent::__construct($sender, $params);
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

}
