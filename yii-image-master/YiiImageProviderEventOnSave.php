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
 * @property string $savePath Save path.
 * @property array $saveOptions Save options.
 * @property-read YiiImageProvider $provider Provider.
 */
class YiiImageProviderEventOnSave extends YiiImageProviderEvent
{

    /**
     * Save path.
     * 
     * @var string
     */
    private $_savePath;

    /**
     * Save options.
     * 
     * @var array
     */
    private $_saveOptions;

    /**
     * Constructor.
     *
     * @param string $savePath Save path.
     * @param array $saveOptions Save options.
     * @param YiiImageProvider $provider Provider.
     * @param mixed $sender Sender.
     * @param mixed $params Params.
     */
    public function __construct($savePath, array $saveOptions,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->savePath = $savePath;
        $this->saveOptions = $saveOptions;

        parent::__construct($provider, $sender, $params);
    }

    /**
     * Driwer.
     * 
     * @return YiiImageDrawer
     */
    public function getProvider()
    {
        return $this->_provider;
    }

    /**
     * Set save options.
     *
     * @param array $options 
     */
    public function setSaveOptions(array $options)
    {
        $this->_saveOptions = $options;
    }

    /**
     * Get save options.
     * 
     * @return array
     */
    public function getSaveOptions()
    {
        return $this->_saveOptions;
    }

    /**
     * Get save path.
     * 
     * @return string 
     */
    public function getSavePath()
    {
        return $this->_savePath;
    }

    /**
     * Set save path.
     * 
     * @param string $path
     * 
     * @throws InvalidArgumentException 
     */
    public function setSavePath($path)
    {
        $path = CPropertyValue::ensureString($path);

        if (0 === strlen(trim($path))) {
            throw new InvalidArgumentException('Path can\'t be empty!');
        }
        $this->_savePath = $path;
    }

}
