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
class YiiStorageEvents extends CEnumerable
{
    /**
     * 
     */

    const onBeforeRead = 'onBeforeRead';
    const onAfterRead  = 'onAfterRead';
    const onBeforeWrite = 'onBeforeWrite';
    const onAfterWrite  = 'onAfterWrite';
    const onBeforeRename = 'onBeforeRename';
    const onAfterRename  = 'onAfterRename';
    const onBeforeDelete = 'onBeforeDelete';
    const onAfterDelete  = 'onAfterDelete';
    
    const onBeforeChecksum = 'onBeforeChecksum';
    const onAfterChecksum = 'onAfterChecksum';
    
    const onBeforeCheckExists = 'onBeforeCheckExists';
    const onAfterCheckExists = 'onAfterCheckExists';
    
    const onBeforeCollectKeys = 'onBeforeCollectKeys';
    const onAfterCollectKeys = 'onAfterCollectKeys';
    
}
