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
 * @property string $showFormat  Show format.
 * @property array  $showOptions Show options.
 */
class YiiImageProviderEventOnShow extends YiiImageProviderEvent
{

    /**
     * Show format.
     * 
     * @var string 
     */
    private $_showFormat;

    /**
     * Show options.
     * 
     * @var array
     */
    private $_showOptions;

    public function __construct($showFormat, array $showOptions,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->showFormat = $showFormat;
        $this->showOptions = $showOptions;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Show options.
     * 
     * @return array
     */
    public function getShowOptions()
    {
        return $this->_showOptions;
    }

    /**
     * Show format.
     * 
     * @return string
     */
    public function getShowFormat()
    {
        return $this->_showFormat;
    }

    /**
     * Set show format.
     * 
     * @param string $format Format.
     * 
     * @return YiiImageProviderEventOnShow 
     */
    public function setShowFormat($format)
    {
        $this->_showFormat = (string) $format;
        return $this;
    }

    /**
     * Set show options.
     * 
     * @param array $options Options.
     * 
     * @return YiiImageProviderEventOnShow 
     */
    public function setShowOptions(array $options)
    {
        $this->_showOptions = $options;
        return $this;
    }

}
