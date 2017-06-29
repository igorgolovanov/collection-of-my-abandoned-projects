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
 * @property-read YiiImageProvider $provider Provider.
 */
class YiiImageProviderEvent extends CEvent
{

    /**
     * Provider.
     *
     * @var YiiImageProvider
     */
    private $_provider;

    /**
     * @param YiiImageProvider $provider Provider.
     * @param mixed $sender
     * @param mixed $params 
     */
    public function __construct(YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->_provider = $provider;

        parent::__construct($sender, $params);
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
