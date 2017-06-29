<?php

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category events
 * 
 * @property-read boolean $isAllowNull Is allow null value.
 * @property boolean $state State.
 */
class RestfulStateEvent extends CEvent
{

    /**
     * State.
     * 
     * @var boolean
     */
    private $_state;

    /**
     * Is allow null value.
     * 
     * @var boolean
     */
    private $_isAllowNull = true;

    /**
     * Constructor.
     * 
     * @param boolean $state State.
     * @param boolean $isAllowNull
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct($state, $isAllowNull = true, $sender = null,
                                $params = null)
    {
        parent::__construct($sender, $params);

        $this->_isAllowNull = $isAllowNull;
        $this->setState($state);
    }

    /**
     * Gets is allow null value.
     * 
     * @return boolean
     */
    public function getIsAllowNull()
    {
        return $this->_status;
    }

    /**
     * Sets the state.
     * 
     * @param boolean $state
     * @return RestfulStatusEvent
     */
    public function setState($state)
    {
        if (!is_bool($state) && !(null === $state && $this->getIsAllowNull())) {
            $state = (bool) $state;
        }

        $this->_state = $state;
        return $this;
    }

    /**
     * Gets the state.
     * 
     * @return boolean
     */
    public function getState()
    {
        return $this->_state;
    }

}
