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
 * Image font which based on GD extension.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiImageGdFont extends YiiImageFont
{

    /**
     * {@inheritDoc}
     */
    protected function doBox($string, $angle = 0)
    {
        $angle = -1 * $angle;
        $info  = imageftbbox($this->size, $angle, $this->file, $string);
        $xs    = array($info[0], $info[2], $info[4], $info[6]);
        $ys = array($info[1], $info[3], $info[5], $info[7]);
        $width  = abs(max($xs) - min($xs));
        $height = abs(max($ys) - min($ys));

        return new Box($width, $height);
    }

}
