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
 * @property-read YiiImageProvider $copiedImage Copied image.
 */
class YiiImageProviderEventOnAfterCopy extends YiiImageProviderEventOnBeforeCopy
{

    /**
     * Copied image.
     * 
     * @var YiiImageProvider
     */
    private $_copiedImage;

    /**
     *
     * @param YiiImageProvider $copiedImage
     * @param YiiImageProvider $provider
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageProvider $copiedImage,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->_copiedImage = $copiedImage;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Copied image.
     * 
     * @return YiiImageProvider 
     */
    public function getCopiedImage()
    {
        return $this->_copiedImage;
    }

}

