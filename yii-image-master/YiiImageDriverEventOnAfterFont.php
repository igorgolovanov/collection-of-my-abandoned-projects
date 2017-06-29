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
 * @property-read YiiImageFont $font Font.
 */
class YiiImageDriverEventOnAfterFont extends YiiImageDriverEventOnBeforeFont
{

    /**
     * Font.
     * 
     * @var YiiImageFont
     */
    private $_font;

    public function __construct(YiiImageFont $font, $file, $size,
                                YiiImageColor $color, YiiImageDriver $driver,
                                $sender = null, $params = null)
    {
        $this->_font = $font;

        parent::__construct($file, $size, $color, $driver, $sender, $params);
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
