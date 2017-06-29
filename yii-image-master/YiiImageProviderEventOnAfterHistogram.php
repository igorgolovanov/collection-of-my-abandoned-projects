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
 * @property array $colors Colors of histogram 
 */
class YiiImageProviderEventOnAfterHistogram extends YiiImageProviderEventOnBeforeHistogram
{

    /**
     * Colors.
     * 
     * @var array
     */
    private $_colors;

    /**
     *
     * @param array $color
     * @param YiiImageProvider $provider
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(array $colors, YiiImageProvider $provider,
                                $sender = null, $params = null)
    {
        $this->colors = $colors;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Set colors.
     * 
     * @param array $colors Color.
     * @return YiiImageProviderEventOnAfterHistogram 
     */
    public function setColors(array $colors)
    {
        $this->_colors = $colors;
        return $this;
    }

    /**
     * Colors.
     * 
     * @return array
     */
    public function getColors()
    {
        return $this->_colors;
    }

}
