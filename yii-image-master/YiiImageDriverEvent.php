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
 * @property-read YiiImageDriver $driver Driver.
 */
class YiiImageDriverEvent extends CEvent
{

    /**
     * Driver.
     *
     * @var YiiImageDriver
     */
    private $_driver;

    public function __construct(YiiImageDriver $driver, $sender = null,
                                $params = null)
    {
        $this->_driver = $driver;

        parent::__construct($sender, $params);
    }

    /**
     * Driver.
     * 
     * @return YiiImageDriver
     */
    public function getDriver()
    {
        return $this->_driver;
    }

}
