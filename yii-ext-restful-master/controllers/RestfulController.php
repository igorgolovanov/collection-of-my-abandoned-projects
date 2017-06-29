<?php

Yii::import('ext.restful.actions.*');
Yii::import('ext.restful.filters.*');

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category controllers
 */
class RestfulController extends CExtController
{

    /**
     * Model class.
     * 
     * @var string
     */
    public $modelClass;

    /**
     * {@inheritdoc}
     */
    public function actions()
    {
        return array(
            'get' => array(
                'class'  => 'ext.restful.actions.RestfulActiveGetAction',
                'findByCallback' => array($this, 'findModel'),
            ),
            'create' => array(
                'class'  => 'ext.restful.actions.RestfulActiveCreateAction',
                'createByCallback' => array($this, 'createModel'),
            ),
            'delete' => array(
                'class'  => 'ext.restful.actions.RestfulActiveDeleteAction',
                'findByCallback' => array($this, 'findModel'),
            ),
            'update' => array(
                'class' => 'ext.restful.actions.RestfulActiveUpdateAction',
                'findByCallback' => array($this, 'findModel'),
            ),
        );
    }

    /**
     * {@inheritdoc}
     */
    public function filters()
    {
        $filters = parent::filters();
        
        if(!YII_DEBUG) {
            $filters[] = 'ajaxOnly + get, delete, create, update';
            $filters[] = 'postOnly + create';
            $filters[] = 'RestfulGetOnlyFilter + get';
            $filters[] = 'RestfulDeleteOnlyFilter + delete';
            $filters[] = 'RestfulPutOnlyFilter + update';
        }
        return $filters;
    }

    /**
     * Find model.
     * 
     * @param mixed $id
     * @return CModel|null
     */
    public function findModel($id)
    {
        return CActiveRecord::model($this->modelClass)->findByPk($id);
    }

    /**
     * Create model.
     * 
     * @return CModel
     */
    public function createModel()
    {
        $class = $this->modelClass;

        return new $class();
    }

}
