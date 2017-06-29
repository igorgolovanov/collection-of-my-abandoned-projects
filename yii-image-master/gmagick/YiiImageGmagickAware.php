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
 * Gmagick aware interface.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
interface YiiImageGmagickAware
{

    /**
     * Gmagick.
     * 
     * @return Gmagick
     */
    function getGmagick();

}
