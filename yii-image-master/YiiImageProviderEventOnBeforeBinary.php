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
 * @property string $binaryFormat Binary format.
 * @property array $binaryOptions Binary options.
 */
class YiiImageProviderEventOnBeforeBinary extends YiiImageProviderEvent
{

    /**
     * Binary format.
     * 
     * @var string 
     */
    private $_binaryFormat;

    /**
     * Binary options.
     * 
     * @var array
     */
    private $_binaryOptions;

    public function __construct($binaryFormat, array $binaryOptions,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->binaryFormat = $binaryFormat;
        $this->binaryOptions = $binaryOptions;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Set binary options.
     * 
     * @return array
     */
    public function getBinaryOptions()
    {
        return $this->_binaryOptions;
    }

    /**
     * Set binary format.
     * 
     * @return string
     */
    public function getBinaryFormat()
    {
        return $this->_binaryFormat;
    }

    /**
     * Set binary format.
     * 
     * @param string $format Format.
     * 
     * @return YiiImageProviderEventOnBeforeBinary 
     */
    public function setBinaryFormat($format)
    {
        $this->_binaryFormat = (string) $format;
        return $this;
    }

    /**
     * Set binary options.
     * 
     * @param array $options Options.
     * 
     * @return YiiImageProviderEventOnBeforeBinary
     */
    public function setBinaryOptions(array $options)
    {
        $this->_binaryOptions = $options;
        return $this;
    }

}
