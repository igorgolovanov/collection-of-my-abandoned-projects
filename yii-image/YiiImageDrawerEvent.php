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
 * Base event for YiiImageDrawer.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiImageDrawerEvent extends CEvent
{

    /**
     * Drawer.
     * 
     * @var YiiImageDrawer 
     */
    private $_drawer;

    /**
     * Constructor.
     * 
     * @param YiiImageDrawer $drawer Drawer.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct(YiiImageDrawer $drawer, $sender = null,
                                $params = null)
    {
        $this->_drawer = $drawer;

        parent::__construct($sender, $params);
    }

    /**
     * Drawer.
     * 
     * @return YiiImageDrawer
     */
    public function getDrawer()
    {
        return $this->_drawer;
    }

}