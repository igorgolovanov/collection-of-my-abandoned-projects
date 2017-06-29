<?php

/**
 * Import class RestfulHttpRequestBehavior
 */
Yii::import('ext.restful.behaviors.RestfulHttpRequestBehavior');

/**
 * This filter reports an error if the applied action is receiving a non-DELETE request.
 * 
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category filters
 */
class RestfulDeleteOnlyFilter extends CFilter
{

    /**
     * Performs the pre-action filtering.
     * 
     * @param CFilterChain $filterChain the filter chain that the filter is on.
     * @return boolean whether the filtering process should continue and the action
     * should be executed.
     */
    protected function preFilter($filterChain)
    {
        $request = Yii::app()->getRequest();

        if (method_exists($request, 'getIsDeleteRequest')) {
            if ($request->getIsDeleteRequest()) {
                return true;
            }
        } elseif ($request instanceof CComponent && $request->asa('restful') instanceof RestfulHttpRequestBehavior) {
            if ($request->asa('restful')->getIsDeleteRequest()) {
                return true;
            }
        } elseif ('DELETE' === $request->getRequestType()) {
            return true;
        }
        throw new CHttpException(405, Yii::t('yii', 'Your request is invalid.'));
    }

}
