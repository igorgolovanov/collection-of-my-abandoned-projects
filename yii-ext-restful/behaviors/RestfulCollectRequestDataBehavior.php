<?php

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category behaviors
 */
class RestfulCollectRequestDataBehavior extends CBehavior
{

    /**
     * Use request method insteadof other method.
     * 
     * @var array
     */
    public $useRequestMethodInsteadOf = array();

    /**
     * {@inheritdoc}
     */
    public function events()
    {
        return array(
            'onCollectRequestData' => 'collectRequestDataByEvent',
        );
    }

    /**
     * @param RestfulDataEvent $event
     */
    protected function collectRequestDataByEvent(RestfulDataEvent $event)
    {
        $event->data = array_merge((array) $event->data,
                                   $this->internalCollectRequestData());
    }

    /**
     * Collect request data.
     * 
     * @return array
     */
    public function collectRequestData()
    {
        $request = Yii::app()->getRequest();
        $type = $request->getRequestType();

        if (isset($this->useRequestMethodInsteadOf[$type])) {
            $type = $this->useRequestMethodInsteadOf[$type];
        }
        
        return (array) $request->getMethodParams($type);
    }

    /**
     * @return array
     */
    public function __invoke()
    {
        return $this->collectRequestData();
    }

}