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
 * @property-read YiiImageProvider $thumbnail Thumbnail.
 */
class YiiImageProviderEventOnAfterThumbnail extends YiiImageProviderEventOnBeforeThumbnail
{

    /**
     * Thumbnail.
     * 
     * @var YiiImageProvider 
     */
    private $_thumbnail;

    /**
     *
     * @param YiiImageProvider $thumbnail
     * @param YiiImageBox $size
     * @param string $mode
     * @param YiiImageProvider $provider
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageProvider $thumbnail, YiiImageBox $size,
                                $mode, YiiImageProvider $provider,
                                $sender = null, $params = null)
    {
        $this->_thumbnail = $thumbnail;

        parent::__construct($size, $mode, $provider, $sender, $params);
    }

    /**
     * Thumbnail.
     * 
     * @return YiiImageProvider 
     */
    public function getThumbnail()
    {
        return $this->_thumbnail;
    }

}