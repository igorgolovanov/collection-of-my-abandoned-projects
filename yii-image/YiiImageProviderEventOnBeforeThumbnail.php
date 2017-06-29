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
 * @property-read YiiImageBox $size Size
 * @property-read string $mode Mode {@link YiiImageThumbnailModes}
 */
class YiiImageProviderEventOnBeforeThumbnail extends YiiImageProviderEvent
{

    /**
     * Size.
     * 
     * @var YiiImageBox
     */
    private $_size;

    /**
     * Mode.
     * 
     * @var string
     */
    private $_mode;

    /**
     *
     * @param YiiImageBox $size
     * @param string $mode
     * @param YiiImageProvider $provider
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageBox $size, $mode,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->_size = $size;
        $this->_mode = $mode;

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

    /**
     * Mode.
     * 
     * {@link YiiImageThumbnailModes}
     * 
     * @return string
     */
    public function getMode()
    {
        return $this->_mode;
    }

}