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
 * @property-read YiiImageProvider $createdMask Created mask
 */
class YiiImageProviderEventOnAfterMask extends YiiImageProviderEventOnBeforeMask
{

    /**
     * Copied image.
     * 
     * @var YiiImageProvider
     */
    private $_mask;

    /**
     *
     * @param YiiImageProvider $copiedImage
     * @param YiiImageProvider $provider
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageProvider $createdMask,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->_mask = $createdMask;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Copied image.
     * 
     * @return YiiImageProvider 
     */
    public function getCreatedMask()
    {
        return $this->_mask;
    }

}

