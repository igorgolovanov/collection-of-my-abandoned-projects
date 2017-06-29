<?php

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category actions
 */
class RestfulActiveCreateAction extends RestfulCreateAction
{
    /**
     * Model method for create.
     * 
     * @var string
     */
    public $modelCreateMethod = 'save';
    
    /**
     * Model refresh method.
     * 
     * @var string
     */
    public $modelRefreshMethod = 'refresh';
    
    public function run()
    {
        $model->attributes = $this->getRequestData();
        
        $status = call_user_func(array($model, $this->modelCreateMethod));
        
        if($status) {
            if($this->modelRefreshMethod) {
                call_user_func(array($model, $this->modelRefreshMethod));
            }
            $this->sendResponse(200, $model);
        } else {
            $this->sendResponse(200, array(
                'errors' => $model->errors,
            ));
        }
    }
}
