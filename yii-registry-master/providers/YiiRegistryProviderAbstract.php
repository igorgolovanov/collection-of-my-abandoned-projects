<?php
/*
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This software consists of voluntary contributions made by many individuals
 * and is licensed under the LGPL. For more information, see
 * <http://www.yiilabs.com>.
 * 
 * @license     http://www.opensource.org/licenses/lgpl-license.php LGPL
 * @link        www.yiilabs.com
 * @copyright   Copyright (c) 2011 Yii Labs. (http://www.yiilabs.com)
 */

/**
 * Abstract class for YiiRegistry provider.
 * 
 * @license     http://www.opensource.org/licenses/lgpl-license.php LGPL
 * @link        www.yiilabs.com
 * @copyright   Copyright (c) 2011 Yii Labs. (http://www.yiilabs.com)
 * @author      Igor Golovanov <igor.golovanov@gmail.com>
 */
abstract class YiiRegistryProviderAbstract extends CComponent 
implements YiiRegistryProvider
{
    /**
     * Get.
     * 
     * @param string $key Key.
     * 
     * @return mixed
     */
    final public function get($key)
    {
        if($this->hasEventHandler(self::EVENT_BEFORE_GET)) {
            $event = new YiiRegistryEventSetGet($this, $key, $this);
            
            $this->raiseEvent(self::EVENT_BEFORE_GET, $event);
            
            if(false === $event->isValid) {
                return null;
            }
            if(null !== $event->value) {
                return $event->value;
            }
            $key = $event->key;
        }
        
        $value = $this->doGet($key);
        
        if($this->hasEventHandler(self::EVENT_AFTER_GET)) {
            $event = new YiiRegistryEventSetGet($this, $key, $this);
            
            $event->value = $value;
            
            $this->raiseEvent(self::EVENT_AFTER_GET, $event);
            
            if(false === $event->isValid) {
                return null;
            }
            $value = $event->value;
        }
        
        return $value;
    }
    
    /**
     * Do Get.
     * 
     * @param string $key Key.
     * 
     * @return mixed 
     */
    abstract protected function doGet($key);
    
    /**
     * This event is raised before value getted.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function onBeforeGet(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised after value getted.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function onAfterGet(YiiRegistryEventSetGet $event)
    {}


    /**
     * Set.
     * 
     * @param string $key Key.
     * @param mixed $value Value.
     * 
     * @return boolean 
     */
    final public function set($key, $value)
    {
        if($this->hasEventHandler(self::EVENT_BEFORE_SET)) {
            $event = new YiiRegistryEventSetGet($this, $key, $this);
            $event->value = $value;
            
            $this->raiseEvent(self::EVENT_BEFORE_SET, $event);
            
            if(null !== $event->isValid) {
                return $event->isValid;
            }
            $key    = $event->key;
            $value  = $event->value;
        }
        
        $result = $this->doSet($key, $value);
        
        if($this->hasEventHandler(self::EVENT_AFTER_SET)) {
            $event = new YiiRegistryEventSetGet($this, $key, $this);
            $event->value   = $value;
            $event->isValid = $result;
            
            $this->raiseEvent(self::EVENT_AFTER_SET, $event);
            
            $result = $event->isValid;
        }
        return $result;
    }
    
    /**
     * Do Set.
     * 
     * @param type $key Key.
     * @param type $value Value.
     * 
     * @return boolean
     */
    abstract protected function doSet($key, $value);
    
    /**
     * This event is raised before value setted.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function onBeforeSet(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised after value setted.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function onAfterSet(YiiRegistryEventSetGet $event)
    {}
    
    
    /**
     * Exists.
     * 
     * @param string $key Key.
     * 
     * @return boolean
     */
    final public function exists($key)
    {
        if($this->hasEventHandler(self::EVENT_BEFORE_EXISTS)) {
            $event = new YiiRegistryEventSetGet($this, $key, $this);
            
            $this->raiseEvent(self::EVENT_BEFORE_EXISTS, $event);
            
            if(null !== $event->isValid) {
                return (boolean)$event->isValid;
            }
            if(null !== $event->value) {
                return (boolean)$event->value;
            }
        }
        
        $exists = $this->doExists($key);
        
        if($this->hasEventHandler(self::EVENT_AFTER_EXISTS)) {
            $event = new YiiRegistryEventSetGet($this, $key, $this);
            $event->value = $exists;
            
            $this->raiseEvent(self::EVENT_AFTER_EXISTS, $event);
            
            if(null !== $event->isValid) {
                return (boolean)$event->isValid;
            }
            $exists = (boolean)$event->value;
        }
        
        return $exists;
    }
    
    /**
     * Do exists.
     * 
     * @param string $key Key.
     * 
     * @return boolean
     */
    abstract protected function doExists($key);
    
    /**
     * This event is raised before exists.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function onBeforeExists(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised after exists.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function onAfterExists(YiiRegistryEventSetGet $event)
    {}

    /**
     * To Array.
     * 
     * @return array
     */
    final public function toArray()
    {
        if($this->hasEventHandler(self::EVENT_BEFORE_TOARRAY)) {
            $event = new YiiRegistryEventArray($this, $this);
            
            $this->raiseEvent(self::EVENT_BEFORE_TOARRAY, $event);
            
            if(null !== $event->array) {
                return (array)$event->array;
            }
        }
        $array = $this->doToArray();
        
        if($this->hasEventHandler(self::EVENT_AFTER_TOARRAY)) {
            $event = new YiiRegistryEventArray($this, $this);
            $event->array = $array;
            
            $this->raiseEvent(self::EVENT_AFTER_TOARRAY, $event);
            
            $array = $event->array;
        }
        return $array;
    }
    
    /**
     * Do toArray.
     * 
     * @return array
     */
    abstract protected function doToArray();

    /**
     * This event is raised before compiled to array.
     * 
     * @param YiiRegistryEventArray $event Event.
     */
    public function onBeforeToArray(YiiRegistryEventArray $event)
    {}
    
    /**
     * This event is raised after compiled to array.
     * 
     * @param YiiRegistryEventArray $event Event.
     */
    public function onAfterToArray(YiiRegistryEventArray $event)
    {}
    
    
    /**
     * Count.
     * 
     * @return integer 
     */
    final public function count()
    {
        if($this->hasEventHandler(self::EVENT_BEFORE_COUNT)) {
            $event = new YiiRegistryEventCount($this, $this);
            
            $this->raiseEvent(self::EVENT_BEFORE_COUNT, $event);
            
            if(false === $event->isValid) {
                return 0;
            }
            if(null !== $event->count) {
                return $event->count;
            }
        }
        
        $count = $this->doCount();
        
        if($this->hasEventHandler(self::EVENT_AFTER_COUNT)) {
            $event = new YiiRegistryEventCount($this, $this);
            $event->count = $count;
            
            $this->raiseEvent(self::EVENT_AFTER_COUNT, $event);
            
            if(false === $event->isValid) {
                return 0;
            }
            $count = $event->count;
        }
        return $count;
    }
    
    /**
     * Do count.
     * 
     * @return integer
     */
    abstract protected function doCount();
    
    /**
     * This event is raised before count.
     * 
     * @param YiiRegistryEventCount $event Event.
     */
    public function onBeforeCount(YiiRegistryEventCount $event)
    {}
    
    /**
     * This event is raised after count.
     * 
     * @param YiiRegistryEventCount $event Event.
     */
    public function onAfterCount(YiiRegistryEventCount $event)
    {}
    
    
    /**
     * Exists.
     * 
     * @param string $key Key.
     * 
     * @return boolean
     */
    public function offsetExists($key)
    {
        return $this->exists($key);
    }
    
    /**
     * Get.
     * 
     * @param string $key Key.
     * 
     * @return mixed 
     */
    public function offsetGet($key)
    {
        return $this->get($key);
    }
    
    /**
     * Set.
     *
     * @param string $key Key.
     * @param mixed $value Value.
     * 
     * @return boolean 
     */
    public function offsetSet($key, $value)
    {
        return $this->set($key, $value);
    }
    
    /**
     * Remove.
     * 
     * @param string $key Key.
     * 
     * @return boolean 
     */
    public function offsetUnset($key)
    {
        return $this->remove($key);
    }
}
