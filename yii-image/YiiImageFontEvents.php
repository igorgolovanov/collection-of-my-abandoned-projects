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
 * Events for the image font.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiImageFontEvents extends CEnumerable
{
    /**
     * Name of the event, which will be called after calculate font box.
     */
    const onAfterBox  = 'onAfterBox';
    
    /**
     * Name of the event, which will be called before calculate font box.
     */
    const onBeforeBox = 'onBeforeBox';

}
