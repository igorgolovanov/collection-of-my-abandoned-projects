<?php

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category events
 */
class RestfulDataEvent extends CEvent
{

    /**
     * Data.
     * 
     * @var mixed
     */
    public $data;

    /**
     * Constructor.
     * 
     * @param mixed $data Data.
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct($data, $sender = null, $params = null)
    {
        parent::__construct($sender, $params);
        
        $this->data = $data;
    }

}

