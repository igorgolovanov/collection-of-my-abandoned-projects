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
 * @property-read YiiImageBox $size Size.
 */
class YiiImageProviderEventOnResize extends YiiImageProviderEvent
{

    /**
     * Size.
     * 
     * @var YiiImageBox 
     */
    private $_size;

    /**
     *
     * @param YiiImageBox $size
     * @param YiiImageProvider $provider
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageBox $size, YiiImageProvider $provider,
                                $sender = null, $params = null)
    {
        $this->_size = $size;

        parent::__construct($provider, $sender, $params);
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

}
