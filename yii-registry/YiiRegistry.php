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

Yii::import('ext.yii-registry.providers.*');
Yii::import('ext.yii-registry.events.*');

/**
 * YiiRegistry.
 * Application component.
 * 
 * @license     http://www.opensource.org/licenses/lgpl-license.php LGPL
 * @link        www.yiilabs.com
 * @copyright   Copyright (c) 2011 Yii Labs. (http://www.yiilabs.com)
 * @author      Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiRegistry extends CApplicationComponent 
implements ArrayAccess, Countable
{
    const EVENT_BEFORE_SET      = 'onBeforeSet';
    const EVENT_BEFORE_GET      = 'onBeforeGet';
    const EVENT_BEFORE_EXISTS   = 'onBeforeExists';
    const EVENT_BEFORE_REVOME   = 'onBeforeRevome';
    const EVENT_BEFORE_TOARRAY  = 'onBeforeToArray';
    const EVENT_BEFORE_COUNT    = 'onBeforeCount';
    const EVENT_AFTER_SET       = 'onAfterSet';
    const EVENT_AFTER_GET       = 'onAfterGet';
    const EVENT_AFTER_EXISTS    = 'onAfterExists';
    const EVENT_AFTER_REVOME    = 'onAfterRevome';
    const EVENT_AFTER_TOARRAY   = 'onAfterToArray';
    const EVENT_AFTER_COUNT     = 'onAfterCount';
    
    /**
     * Providers.
     * 
     * @var array
     */
    private $_providers = array();
    
    /**
     * Default provider.
     * 
     * @var string
     */
    private $_defaultProvider;


    /**
     * Set providers.
     * 
     * @param array $providers Providers.
     * 
     * @return YiiRegistry
     */
    public function setProviders(array $providers)
    {
        $this->_providers = $providers;
        
        return $this;
    }
    
    /**
     * Provider.
     * 
     * @param string $name Provider name.
     * 
     * @return YiiRegistryProvider
     */
    public function getProvider($name = null)
    {
        if(null === $name) {
            $name = $this->getDefaultProviderName();
        }
        if(!isset($this->_providers[$name])) {
            throw new CException(sprintf('YiiRegister does not contain a provider named "%s".', $name));
        }
        
        if(!$this->_provider[$name] instanceof YiiRegistryProvider) {
            $this->_provider[$name] = Yii::createComponent($this->_provider[$name]);
            
            if(!$this->_provider[$name] instanceof YiiRegistryProvider) {
                throw new CException(sprintf('Provider for YiiRegistry must be inherited from the "%s".', 'YiiRegistryProvider'));
            }
        }
        return $this->_provider[$name];
    }
    
    /**
     * Set default provider.
     * 
     * @param string $name Provider name.
     * 
     * @return YiiRegistry 
     */
    public function setDefaultProviderName($name)
    {
        if(!isset($this->_providers[$name])) {
            throw new CException(sprintf('YiiRegister does not contain a provider named "%s".', $name));
        }
        $this->_defaultProvider = $name;
        
        return $this;
    }
    
    /**
     * Get default provider.
     * 
     * @return string
     */
    public function getDefaultProviderName()
    {
        if(null === $this->_defaultProvider) {
            if(0 === count($this->_providers)) {
                throw new CException(sprintf('YiiRegister does not contain any providers.'));
            }
            reset($this->_providers);
            
            $this->_defaultProvider = key($this->_providers);
        }
        return $this->_defaultProvider;
    }
    
    /**
     * Get.
     * 
     * @param string $key Key.
     * @param string $providerName Provider name.
     * 
     * @return mixed
     */
    final public function get($key, $providerName = null)
    {
        $provider = $this->getProvider($providerName);
        
        if($this->hasEventHandler(self::EVENT_BEFORE_GET)) {
            $event = new YiiRegistryEventSetGet($provider, $key, $this);
            
            $this->raiseEvent(self::EVENT_BEFORE_GET, $event);
            
            if(false === $event->isValid) {
                return null;
            }
            if(null !== $event->value) {
                return $event->value;
            }
            $key = $event->key;
        }
        
        $value = $this->doGet($key, $provider);
        
        if($this->hasEventHandler(self::EVENT_AFTER_GET)) {
            $event = new YiiRegistryEventSetGet($provider, $key, $this);
            
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
     * @param YiiRegistryProvider $provider Provider.
     * 
     * @return mixed 
     */
    protected function doGet($key, YiiRegistryProvider $provider)
    {
        return $provider->get($key);
    }
    
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
     * @param string $providerName Provider name.
     * 
     * @return boolean 
     */
    final public function set($key, $value, $providerName = null)
    {
        $provider = $this->getProvider($providerName);
        
        if($this->hasEventHandler(self::EVENT_BEFORE_SET)) {
            $event = new YiiRegistryEventSetGet($provider, $key, $this);
            $event->value = $value;
            
            $this->raiseEvent(self::EVENT_BEFORE_SET, $event);
            
            if(null !== $event->isValid) {
                return $event->isValid;
            }
            $key    = $event->key;
            $value  = $event->value;
        }
        
        $result = $this->doSet($key, $value, $provider);
        
        if($this->hasEventHandler(self::EVENT_AFTER_SET)) {
            $event = new YiiRegistryEventSetGet($provider, $key, $this);
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
     * @param YiiRegistryProvider $provider Provider.
     * 
     * @return boolean
     */
    protected function doSet($key, $value, YiiRegistryProvider $provider)
    {
        return $provider->set($key, $value);
    }
    
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
     * @param string $providerName Provider name.
     * 
     * @return boolean
     */
    final public function exists($key, $providerName = null)
    {
        $provider = $this->getProvider($providerName);
        
        if($this->hasEventHandler(self::EVENT_BEFORE_EXISTS)) {
            $event = new YiiRegistryEventSetGet($provider, $key, $this);
            
            $this->raiseEvent(self::EVENT_BEFORE_EXISTS, $event);
            
            if(null !== $event->isValid) {
                return (boolean)$event->isValid;
            }
            if(null !== $event->value) {
                return (boolean)$event->value;
            }
        }
        
        $exists = $this->doExists($key, $provider);
        
        if($this->hasEventHandler(self::EVENT_AFTER_EXISTS)) {
            $event = new YiiRegistryEventSetGet($provider, $key, $this);
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
     * @param YiiRegistryProvider $provider Provider.
     * 
     * @return boolean
     */
    protected function doExists($key, YiiRegistryProvider $provider)
    {
        return $provider->exists($key);
    }
    
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
     * @param string $providerName Provider name.
     * 
     * @return array
     */
    final public function toArray($providerName = null)
    {
        $provider = $this->getProvider($providerName);
        
        if($this->hasEventHandler(self::EVENT_BEFORE_TOARRAY)) {
            $event = new YiiRegistryEventArray($provider, $this);
            
            $this->raiseEvent(self::EVENT_BEFORE_TOARRAY, $event);
            
            if(null !== $event->array) {
                return (array)$event->array;
            }
        }
        $array = $this->doToArray($provider);
        
        if($this->hasEventHandler(self::EVENT_AFTER_TOARRAY)) {
            $event = new YiiRegistryEventArray($provider, $this);
            $event->array = $array;
            
            $this->raiseEvent(self::EVENT_AFTER_TOARRAY, $event);
            
            $array = $event->array;
        }
        return $array;
    }
    
    /**
     * Do toArray.
     * 
     * @param YiiRegistryProvider $provider Provider.
     * 
     * @return array
     */
    protected function doToArray(YiiRegistryProvider $provider)
    {
        return $provider->toArray();
    }

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
     * @param string $providerName Provider name.
     * 
     * @return integer 
     */
    final public function count($providerName = null)
    {
        $provider = $this->getProvider($providerName);
        
        if($this->hasEventHandler(self::EVENT_BEFORE_COUNT)) {
            $event = new YiiRegistryEventCount($provider, $this);
            
            $this->raiseEvent(self::EVENT_BEFORE_COUNT, $event);
            
            if(false === $event->isValid) {
                return 0;
            }
            if(null !== $event->count) {
                return $event->count;
            }
        }
        
        $count = $this->doCount($provider);
        
        if($this->hasEventHandler(self::EVENT_AFTER_COUNT)) {
            $event = new YiiRegistryEventCount($provider, $this);
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
     * @param YiiRegistryProvider $provider Provider.
     * 
     * @return integer
     */
    protected function doCount(YiiRegistryProvider $provider)
    {
        return $provider->count();
    }
    
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
