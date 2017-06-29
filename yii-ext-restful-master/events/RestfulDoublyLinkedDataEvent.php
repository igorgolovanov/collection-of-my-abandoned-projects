<?php

/**
 * Import class RestfulDataEvent
 */
Yii::import('ext.restful.events.RestfulDataEvent');

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category events
 * 
 * @property-read mixed $source Source data.
 */
class RestfulDoublyLinkedDataEvent extends RestfulDataEvent
{

    /**
     * Source.
     * 
     * @var mixed
     */
    private $_source;

    /**
     * {@inheritdoc}
     */
    public function __construct($data, $sender = null, $params = null)
    {
        parent::__construct($data, $sender, $params);

        $this->_source = $data;
    }

    /**
     * Gets the source data.
     * 
     * @return mixed
     */
    public function getSource()
    {
        return $this->_source;
    }

}
