<?php

/**
 * Import events classes.
 */
Yii::import('ext.restful.events.*');

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category actions
 * 
 * @property CList $onCollectRequestData List of event handlers for "onPrepareRequestData" event.
 * @property CList $onPrepareRequestData List of event handlers for "onPrepareRequestData" event.
 * @property CList $onPrepareResponseData List of event handlers for "onPrepareResponseData" event.
 * @property CList $onRenderResponseData List of event handlers for "onRenderResponseData" event.
 * @property CList $onSendResponseData List of event handlers for "onSendResponseData" event.
 * 
 * @property RestfulCollectRequestDataBehavior $collectRequestDataBehavior
 * 
 * @property-read array $requestData Request data.
 */
abstract class RestfulAction extends CAction
{

    /**
     * Default renderer.
     * 
     * @var callable
     */
    public $defaultRenderer = array('CJSON', 'encode');

    /**
     * Request data.
     * 
     * @var array
     */
    private $_requestData;

    /**
     * {@inheritdoc}
     */
    public function __construct($controller, $id)
    {
        parent::__construct($controller, $id);

        $this->attachBehaviors($this->behaviors());
    }

    /**
     * Behaviors.
     * 
     * @return array
     */
    public function behaviors()
    {
        return array(
            'collectRequestDataBehavior' => array(
                'class' => 'ext.restful.behaviors.RestfulCollectRequestDataBehavior',
            ),
        );
    }

    /**
     * Gets the request data.
     * 
     * @return array
     */
    public function getRequestData()
    {
        if (null === $this->_requestData) {
            $data               = $this->onCollectRequestData();
            $this->_requestData = $this->onPrepareRequestData($data);
        }
        return $this->_requestData;
    }

    /**
     * Gets the request param.
     * 
     * @param string $name
     * @param mixed $default
     * @return mixed
     */
    public function getRequestParam($name, $default = null)
    {
        $data = $this->getRequestData();
        
        return isset($data[$name])? $data[$name] : $default;
    }

    /**
     * Collect request data.
     * 
     * @return array
     */
    public function onCollectRequestData()
    {
        if ($this->hasEventHandler(__FUNCTION__)) {
            $this->raiseEvent(__FUNCTION__,
                              $event = new RestfulDataEvent(array(), $this));
            return (array) $event->data;
        }
        return array();
    }

    /**
     * Prepare request data.
     * 
     * @param mixed $data
     * @return mixed
     */
    public function onPrepareRequestData($data)
    {
        if ($this->hasEventHandler(__FUNCTION__)) {
            $this->raiseEvent(__FUNCTION__,
                              $event = new RestfulDoublyLinkedDataEvent($data, $this));
            return $event->data;
        }
        return $data;
    }

    /**
     * Prepare response data.
     * 
     * @param mixed $data
     * @return mixed
     */
    public function onPrepareResponseData($data)
    {
        if ($this->hasEventHandler(__FUNCTION__)) {
            $this->raiseEvent(__FUNCTION__,
                              $event = new RestfulDoublyLinkedDataEvent($data, $this));
            return $event->data;
        }
        return $data;
    }

    /**
     * Render reponse data.
     * 
     * @param mixed $data
     * @return string
     */
    public function onRenderResponseData($data)
    {
        if ($this->hasEventHandler(__FUNCTION__)) {
            $this->raiseEvent(__FUNCTION__,
                              $event = new RestfulDataEvent($data, $this));
            return $event->data;
        }
        /**
         * If data not rendering by event then use default renderer.
         */
        return call_user_func($this->defaultRenderer, $data);
    }

    /**
     * Send response data.
     * 
     * @param integer $status Response status.
     * @param mixed $data Response data.
     */
    public function onSendResponseData($status, $data = null)
    {
        if ($this->hasEventHandler(__FUNCTION__)) {
            $this->raiseEvent(__FUNCTION__,
                              new RestfulResponseEvent($data, $status, $this));
        }
    }
    
    /**
     * Send response data.
     * 
     * @param integer $status
     * @param mixed $data
     */
    public function sendResponse($status, $data)
    {
        $data = $this->onPrepareResponseData($data);
        $data = $this->onRenderResponseData($data);
        
        $this->onSendResponseData($status, $data);
    }

    /**
     * When invalid request data.
     * 
     * @param mixed $data
     */
    public function onInvalidRequestData($data)
    {
        if ($this->hasEventHandler(__FUNCTION__)) {
            $this->raiseEvent(__FUNCTION__, new RestfulDataEvent($data, $this));
        }
    }

}
