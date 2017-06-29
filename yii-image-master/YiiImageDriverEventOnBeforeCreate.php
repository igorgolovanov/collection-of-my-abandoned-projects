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
 * @property-read YiiImageColor $color Color
 * @property-read YiiImageBox $size Size
 */
class YiiImageDriverEventOnBeforeCreate extends YiiImageDriverEvent
{

    /**
     * Color.
     * 
     * @var YiiImageColor
     */
    private $_color;

    /**
     * Size.
     * 
     * @var YiiImageBox  
     */
    private $_size;

    /**
     * Constructor.
     * 
     * @param YiiImageBox $size Size.
     * @param YiiImageColor $color Color.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct(YiiImageBox $size, YiiImageColor $color = null,
                                $sender = null, $params = null)
    {
        $this->_size = $size;
        $this->_color = $color;

        parent::__construct($sender, $params);
    }

    /**
     * Size.
     * 
     * @return YiiImageBox 
     */
    public function getSize()
    {
        return $this->_size;
    }

    /**
     * Color.
     * 
     * @return YiiImageColor
     */
    public function getColor()
    {
        return $this->_color;
    }

}