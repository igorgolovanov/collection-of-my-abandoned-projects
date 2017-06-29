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
 */
class YiiImageProviderEventOnAfterBinary extends YiiImageProviderEventOnBeforeBinary
{

    /**
     * Binary content.
     * 
     * @var string
     */
    public $binaryContent;

    public function __construct($binaryContent, $binaryFormat,
                                array $binaryOptions,
                                YiiImageProvider $provider, $sender = null,
                                $params = null)
    {
        $this->binaryContent = $binaryContent;

        parent::__construct($binaryFormat, $binaryOptions, $provider, $sender,
                            $params);
    }

}
