<?php

/*
 * This file is part of the YiiStorage package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

Yii::import('ext.yii-storage.*');
Yii::import('ext.yii-storage.providers.*');

/**
 * YiiStorage application component.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com> 
 */
class YiiStorage extends YiiStorageProvider implements IApplicationComponent
{
    /**
     * 
     * @var type 
     */
    private $_storages;
    
    /**
     * 
     * @var type 
     */
    private $_initializedStorages;
    
    /**
     * Initializes the application component.
     * This method is invoked after the application completes configuration.
     */
    public function init()
    {
        
    }
    
    
    /**
     * Set storages.
     * 
     * @param array $storages Storages
     * 
     * @return YiiStorage 
     */
    public function setStorages(array $storages)
    {
        $this->_storages = $storages;
        
        return $this;
    }
    
    /**
     * Names of storages.
     * 
     * @return array 
     */
    public function getStorageNames()
    {
        return array_keys($this->_storages);
    }
    
    /**
     * Get storage by name.
     * 
     * @param string $name Name of storage.
     * 
     * @return YiiStorageProvider
     */
    public function storage($name)
    {
        if(!isset($this->_storages[$name])) {
            throw new InvalidArgumentException(sprintf('Storage with name "%s" not found', $name));
        }
        if(!is_object($this->_storages[$name])) {
            $this->_storages[$name] = Yii::createComponent($this->_storages[$name]);
            $this->_storages[$name]->init();
        }
        return $this->_storages[$name];
    }
    

    /**
     * Whether the {@link IApplicationComponent::init()} method has been invoked.
     * 
     * @return boolean
     */
    public function getIsInitialized()
    {
        
    }
    
    protected function doRead($key)
    {
        
    }

}

$storage = new YiiStorage();
Yii::app()->storage->storage('main')->read($key);