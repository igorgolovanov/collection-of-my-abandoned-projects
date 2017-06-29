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
 * @property string $path
 * @property-read YiiImageProvider $provider Provider
 */
class YiiImageDriverEventOnAfterOpen extends YiiImageDriverEventOnBeforeOpen
{

    /**
     * Provider.
     * 
     * @var YiiImageProvider 
     */
    private $_provider;

    /**
     * Constructor.
     * 
     * @param YiiImageProvider $provider
     * @param string $path Path.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct(YiiImageProvider $provider, $path,
                                $sender = null, $params = null)
    {
        $this->_provider = $provider;

        parent::__construct($path, $sender, $params);
    }

    /**
     * Provider.
     * 
     * @return YiiImageProvider 
     */
    public function getProvider()
    {
        return $this->_provider;
    }

}
