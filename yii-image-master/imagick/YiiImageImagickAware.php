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
 * Imagick aware interface.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
interface YiiImageImagickAware
{

    /**
     * Imagick.
     * 
     * @return Imagick
     */
    function getImagick();

}
