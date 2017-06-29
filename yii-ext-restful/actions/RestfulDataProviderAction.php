<?php

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category actions
 * 
 * @property IDataProvider $dataProvider Data Provider.
 * @property CList $onPrepareSort List of event handlers for "onPrepareSort" event.
 * @property CList $onPrepareDataProvider List of event handlers for "onPrepareDataProvider" event.
 * @property CList $onPreparePagination List of event handlers for "onPreparePagination" event.
 */
class RestfulDataProviderAction extends RestfulAction
{

    /**
     * Data provider.
     *
     * @var IDataProvider
     */
    private $_dataProvider;
    
    /**
     * Gets the data provider.
     * 
     * @return IDataProvider
     */
    public function getDataProvider()
    {
        if (!$this->_dataProvider instanceof IDataProvider) {
            if ($this->_dataProvider instanceof Closure) {
                $this->_dataProvider = $this->_dataProvider($this);
            } else {
                $this->_dataProvider = Yii::createComponent($this->_dataProvider);
            }
        }
        return $this->_dataProvider;
    }

    /**
     * Sets the data provider.
     * 
     * @param IDataProvider|Closure|array|string $dataProvider
     * @return RestfulDataProviderAction
     */
    public function setDataProvider($dataProvider)
    {
        $this->_dataProvider = $dataProvider;
        return $this;
    }

    /**
     * Prepare sort.
     * 
     * @param CSort $sort
     * @return CSort
     */
    public function onPrepareSort(CSort $sort = null)
    {
        if ($this->hasEventHandler(__FUNCTION__)) {
            $this->raiseEvent(__FUNCTION__,
                              $event = new RestfulObjectEvent($sort, 'CSort', true, $this));
            return $event->object;
        }
        return $sort;
    }
    
    /**
     * Prepare data provider.
     * 
     * @param IDataProvider $dataProvider
     * @return IDataProvider
     */
    public function onPrepareDataProvider(IDataProvider $dataProvider)
    {
        if ($this->hasEventHandler(__FUNCTION__)) {
            $this->raiseEvent(__FUNCTION__,
                              $event = new RestfulObjectEvent($dataProvider, 'IDataProvider', false, $this));
            return $event->object;
        }
        return $dataProvider;
    }
    
    /**
     * Prepare pagination.
     * 
     * @param CPagination $pagination
     * @return CPagination
     */
    public function onPreparePagination(CPagination $pagination = null)
    {
        if ($this->hasEventHandler(__FUNCTION__)) {
            $this->raiseEvent(__FUNCTION__,
                              $event = new RestfulObjectEvent($pagination, 'CPagination', true, $this));
            return $event->object;
        }
        return $pagination;
    }
    
    

    public function run()
    {
        $dp = $this->getDataProvider();
        
        $this->onPrepareDataProvider($dp);
        $this->onPreparePagination($dp->getPagination());
        $this->onPrepareSort($dp->getSort());
        
        $this->sendResponse(200, $dp);
    }

}
