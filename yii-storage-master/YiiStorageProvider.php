<?php

/*
 * This file is part of the YiiStorage package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

/**
 * @author  Igor Golovanov <igor.golovanov@gmail.com> 
 *
 * @property-read CList $onBeforeRead Event {@link YiiStorageProvider::onBeforeRead} 
 * @property-write string|array|Closure $onBeforeRead Event {@link YiiStorageProvider::onBeforeRead} 
 * 
 * @property-read boolean   $isWebAccessAvaliable 
 * @property-read array     $keys Keys.
 * 
 * @property-write array $behaviors
 */
abstract class YiiStorageProvider extends CComponent implements ArrayAccess, Countable, IteratorAggregate
{
    /**
     * Set behaviors.
     * 
     * @param array $behaviors 
     */
    public function setBehaviors(array $behaviors)
    {
        $this->attachBehaviors($behaviors);
    }
    
    /**
     * Offset exists. Alias for method "exists".
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
     * Offset get. Alias for method "read".
     * 
     * @param string $key Key.
     * 
     * @return string
     */
    public function offsetGet($key)
    {
        return $this->read($key);
    }
    
    /**
     * Offset set. Alias for method "write".
     * 
     * @param string $key Key.
     * @param string $content Content.
     */
    public function offsetSet($key, $content)
    {
        $this->write($key, $content);
    }
    
    /**
     * Offset unset. Alias for method "delete".
     * 
     * @param string $key Key.
     */
    public function offsetUnset($key)
    {
        $this->delete($key);
    }
    
    /**
     * Count of keys.
     * 
     * @return integer
     */
    public function count()
    {
        return count($this->keys);
    }
    
    /**
     * Iterator.
     * 
     * @return ArrayIterator 
     */
    public function getIterator()
    {
        return new ArrayIterator($this->keys);
    }
    
    /**
     * Read content from storage.
     * 
     * @param string $key Key.
     * 
     * @return string
     */
    final public function read($key)
    {
        if($this->hasEventHandler(YiiStorageEvents::onBeforeRead)) {
            $event = new YiiStorageEventOnRead($key, $this, $this);
            $this->onBeforeRead($event);
            /**
             * If the content was set at event then it will be returned.
             */
            if(null !== $event->content) {
                return $event->content;
            }
            $key = $event->key;
        }
        $content = $this->doRead($key); 
        
        if($this->hasEventHandler(YiiStorageEvents::onAfterRead)) {
            $event = new YiiStorageEventOnRead($key, $this, $this);
            $event->content = $content;
            
            $this->onAfterRead($event);
            
            return $event->content;
        }
        return $content;
    }
    
    final public function write($key, $content)
    {
        if($this->hasEventHandler(YiiStorageEvents::onBeforeWrite)) {
            
        }
    }
    
    /**
     * Collect all exists keys.
     * 
     * @return array
     */
    final public function collectKeys()
    {
        if($this->hasEventHandler(YiiStorageEvents::onBeforeCollectKeys)) {
            $event = new YiiStorageEventOnCollectKeys($this, $this);
            $this->onBeforeCollectKeys($event);
            /**
             * If the keys was set at event then it will be returned.
             */
            if(null !== $event->keys && is_array($event->keys)) {
                return $event->keys;
            }
        }
        $keys = $this->doCollectKeys();
        
        if($this->hasEventHandler(YiiStorageEvents::onAfterCollectKeys)) {
            $event = new YiiStorageEventOnCollectKeys($this, $this);
            $event->keys = $keys;
            
            $this->onBeforeCollectKeys($event);
            
            return $event->keys;
        }
        return $keys;
    }
    
    /**
     * Alias for method "collectKeys".
     * 
     * @return array
     */
    final public function getKeys()
    {
        return $this->collectKeys();
    }
    
    
    final public function rename($currentKey, $newKey)
    {
        
    }
    
    final public function delete($key)
    {
        if($this->hasEventHandler(YiiStorageEvents::onBeforeDelete)) {
            $event = new YiiStorageEventOnDelete($key, $this, $this);
            $this->onBeforeDelete($event);
            
            $key = $event->key;
        }
        $this->doDelete($key);
        
        if($this->hasEventHandler(YiiStorageEvents::onAfterDelete)) {
            $this->onAfterDelete(new YiiStorageEventOnDelete($key, $this, $this));
        }
        return $this;
    }
    
    final public function getLastModifiedTime($key)
    {
        
    }
    
    final public function exists($key)
    {
        if($this->hasEventHandler(YiiStorageEvents::onBeforeExists)) {
            
        }
        
        
        if($this->hasEventHandler(YiiStorageEvents::onAfterExists)) {
            
        }
    }
    
    final public function read($key)
    {
        if($this->hasEventHandler(YiiStorageEvents::onBeforeRead)) {
            $event = new YiiStorageEventOnRead($this, $key, $this);
            $this->raiseEvent(YiiStorageEvents::onBeforeRead, $event);
        }
        $content = $this->doRead($key);
        
        if($this->hasEventHandler(YiiStorageEvents::onAfterRead)) {
            
        }
    }
    
    final public function onBeforeCollectKeys(YiiStorageEventOnCollectKeys $event)
    {
        $this->raiseEvent(YiiStorageEvents::onBeforeCollectKeys, $event);
    }
    
    final public function onAfterCollectKeys(YiiStorageEventOnCollectKeys $event)
    {
        $this->raiseEvent(YiiStorageEvents::onAfterCollectKeys, $event);
    }
    
    final public function onBeforeRead(YiiImageProviderEventOnRead $event)
    {
        $this->raiseEvent(YiiStorageEvents::onBeforeRead, $event);
    }
    
    final public function onAfterRead(YiiImageProviderEventOnRead $event)
    {
        $this->raiseEvent(YiiStorageEvents::onAfterRead, $event);
    }
    
    final public function onBeforeDelete(YiiImageProviderEventOnDelete $event)
    {
        $this->raiseEvent(YiiStorageEvents::onBeforeDelete, $event);
    }
    
    final public function onAfterDelete(YiiImageProviderEventOnDelete $event)
    {
        $this->raiseEvent(YiiStorageEvents::onAfterDelete, $event);
    }
    
    final public function onBeforeRename(YiiImageProviderEventOnRename $event)
    {
        $this->raiseEvent(YiiStorageEvents::onBeforeRename, $event);
    }
    
    final public function onAfterRename(YiiImageProviderEventOnRename $event)
    {
        $this->raiseEvent(YiiStorageEvents::onAfterRename, $event);
    }
    
    final public function onBeforeWrite(YiiImageProviderEventOnWrite $event)
    {
        $this->raiseEvent(YiiStorageEvents::onBeforeWrite, $event);
    }
    
    final public function onAfterWrite(YiiImageProviderEventOnWrite $event)
    {
        $this->raiseEvent(YiiStorageEvents::onAfterWrite, $event);
    }
    
    final public function onBeforeExists(YiiImageProviderEventOnExists $event)
    {
        $this->raiseEvent(YiiStorageEvents::onBeforeExists, $event);
    }
    
    final public function onAfterExists(YiiImageProviderEventOnExists $event)
    {
        $this->raiseEvent(YiiStorageEvents::onAfterExists, $event);
    }
}