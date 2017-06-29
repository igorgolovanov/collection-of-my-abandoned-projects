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
 * Events for the image driver.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiImageDriverEvents extends CEnumerable
{
    /**
     * Name of the event, which will be called before the create a new image.
     */
    const onBeforeCreate = 'onBeforeCreate';

    /**
     * Name of the event, which will be called before the read image from string.
     */
    const onBeforeRead = 'onBeforeRead';

    /**
     * Name of the event, which will be called before the open image file.
     */
    const onBeforeOpen = 'onBeforeOpen';

    /**
     * Name of the event, which will be called before the load image.
     */
    const onBeforeLoad = 'onBeforeLoad';

    /**
     * Name of the event, which will be called after the create a new image.
     */
    const onAfterCreate = 'onAfterCreate';

    /**
     * Name of the event, which will be called after the read image from string.
     */
    const onAfterRead = 'onAfterRead';

    /**
     * Name of the event, which will be called after the open image file.
     */
    const onAfterOpen = 'onAfterOpen';

    /**
     * Name of the event, which will be called after the load image.
     */
    const onAfterLoad = 'onAfterLoad';

}
