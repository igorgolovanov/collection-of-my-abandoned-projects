<?php

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category actions
 */
class RestfulActiveUpdateAction extends RestfulUpdateAction
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

    
    
}
