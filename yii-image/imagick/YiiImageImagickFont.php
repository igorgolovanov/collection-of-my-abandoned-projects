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
 * @property-read Imagick $imagick
 */
class YiiImageImagickFont extends YiiImageFont implements YiiImageImagickAware
{

    /**
     * @var Imagick
     */
    private $_imagick;

    /**
     * Constructor.
     * 
     * @param Imagick             $imagick
     * @param string              $file
     * @param integer             $size
     * @param YiiImageColor     $color
     */
    public function __construct(Imagick $imagick, $file, $size,
                                YiiImageColor $color)
    {
        $this->_imagick = $imagick;

        parent::__construct($file, $size, $color);
    }

    /**
     * Imagick.
     * 
     * @return Imagick
     */
    public function getImagick()
    {
        return $this->_imagick;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doBox($string, $angle)
    {
        $text = new ImagickDraw();

        $text->setFont($this->file);
        $text->setFontSize($this->size);

        $info = $this->imagick->queryFontMetrics($text, $string);

        return YiiImageBox($info['textWidth'], $info['textHeight']);
    }

}

