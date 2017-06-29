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
 */
abstract class YiiImageFill extends CComponent
{

    /**
     * Gets color of the fill for the given position
     *
     * @param YiiImagePoint $position
     *
     * @return YiiImageColor
     */
    abstract public function getColor(YiiImagePoint $position);

}
