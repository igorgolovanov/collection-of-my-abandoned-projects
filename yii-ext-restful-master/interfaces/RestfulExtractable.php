<?php

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category interfaces
 */
interface RestfulExtractable
{
    /**
     * Extract object to array.
     * 
     * @param string $scenario
     * @return array
     */
    public function extract($scenario = null);
}
