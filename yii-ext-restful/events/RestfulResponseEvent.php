<?php

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category events
 */
class RestfulResponseEvent extends RestfulDataEvent
{

    /**
     * Reponse status code.
     * 
     * @var integet
     */
    public $code;

    /**
     * @param string $data Reponse data.
     * @param integer $code Response code.
     * @param type $sender
     * @param type $params
     */
    public function __construct($data, $code = 200, $sender = null,
                                $params = null)
    {
        parent::__construct($data, $sender, $params);

        $this->code = $code;
    }

}
