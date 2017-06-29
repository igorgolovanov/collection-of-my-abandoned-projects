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
 */
class YiiStorageBehavior extends CBehavior
{

    public function events()
    {
        return array(
            YiiStorageEvents::onBeforeRead => 'beforeRead',
        );
    }

    protected function beforeRead(YiiStorageEventOnRead $event)
    {
        
    }

    protected function afterRead(YiiStorageEventOnRead $event)
    {
        
    }

}
