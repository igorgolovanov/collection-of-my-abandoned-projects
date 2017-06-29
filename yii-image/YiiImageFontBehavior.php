<?php

/*
 * This file is part of the YiiImage package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

/**
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 */
class YiiImageFontBehavior extends CBehavior
{

    /**
     * {@inheritDoc}
     */
    public function events()
    {
        return array(
            YiiImageFontEvents::onBeforeBox => 'beforeBox',
            YiiImageFontEvents::onAfterBox  => 'afterBox',
        );
    }

    /**
     * This event will be raised after calculate font box.
     * 
     * @param YiiImageEventOnAfterFontBox $event 
     */
    protected function afterBox(YiiImageFontEventOnAfterBox $event)
    {
        
    }

    /**
     * This event will be raised before calculate font box.
     * 
     * @param YiiImageEventOnBeforeFontBox $event 
     */
    protected function beforeBox(YiiImageFontEventOnBeforeBox $event)
    {
        
    }

}