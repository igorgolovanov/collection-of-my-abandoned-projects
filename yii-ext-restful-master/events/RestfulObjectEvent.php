<?php

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category events
 * 
 * @property-read boolean $isAllowNull Is allow null value.
 * @property object $object Object.
 * @property-read boolean $isTyped Is typed object.
 * @property-read string|null $allowedType Allowed type of object.
 */
class RestfulObjectEvent extends CEvent
{
    /**
     * Object.
     * 
     * @var object
     */
    private $_object;
    
    /**
     * Is allow null value.
     * 
     * @var boolean
     */
    private $_isAllowNull = true;
        
    /**
     * Type: Class name of Interface name.
     * 
     * @var string
     */
    private $_type;
    
    /**
     * Constructor.
     * 
     * @param object $object Object.
     * @param string|null $objectType Type of object.
     * @param boolean $isAllowNull
     * @param mixed $sender sender of the event
     * @param mixed $params additional parameters for the event
     */
    public function __construct($object, $objectType = null, $isAllowNull = true, $sender = null,
                                $params = null)
    {
        parent::__construct($sender, $params);

        $this->_isAllowNull = $isAllowNull;
        $this->_type = $objectType;
        $this->setObject($object);
    }
    
    /**
     * Is typed.
     * 
     * @return string
     */
    public function getIsTyped()
    {
        return null !== $this->getAllowedType();
    }
    
    /**
     * Gets the type of object.  
     * Class name of Interface name.
     * 
     * @return string|null
     */
    public function getAllowedType()
    {
        return $this->_type;
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
     * Gets the object.
     * 
     * @return object
     */
    public function getObject()
    {
        return $this->_object;
    }
    
    /**
     * Sets the object.
     * 
     * @param object $object
     * @return RestfulObjectEvent
     * @throws CException
     */
    public function setObject($object)
    {
        if(!is_object($object) && !(null === $object && $this->getIsAllowNull())) {
            throw new CException();
        }
        
        if($this->getIsTyped() && !is_a($object, $this->getAllowedType())) {
            throw new CException();
        }
        $this->_object = $object;
        return $this;
    }
}
