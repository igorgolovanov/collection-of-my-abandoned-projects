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
 * Image font which based on Gmagick extension.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiImageGmagickFont extends YiiImageFont implements YiiImageGmagickAware
{

    /**
     * @var Gmagick
     */
    private $_gmagick;

    /**
     * Constructor.
     * 
     * @param Gmagick             $gmagick
     * @param string              $file
     * @param integer             $size
     * @param YiiImageColor     $color
     */
    public function __construct(Gmagick $gmagick, $file, $size,
                                YiiImageColor $color)
    {
        $this->_gmagick = $gmagick;

        parent::__construct($file, $size, $color);
    }

    /**
     * Gmagick.
     * 
     * @return Gmagick
     */
    public function getGmagick()
    {
        return $this->_gmagick;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doBox($string, $angle)
    {
        $text = new GmagickDraw();

        $text->setfont($this->file);
        $text->setfontsize($this->size);
        $text->setfontstyle(Gmagick::STYLE_OBLIQUE);

        $info = $this->gmagick->queryfontmetrics($text, $string);

        return new YiiImageBox($info['textWidth'], $info['textHeight']);
    }

}
