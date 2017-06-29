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
class YiiImageProviderBehavior extends CBehavior
{

    /**
     * Events.
     * 
     * @return array 
     */
    public function events()
    {
        return array(
            YiiImageProvider::onBeforeSave             => 'beforeSave',
            YiiImageProvider::onAfterSave              => 'afterSave',
            YiiImageProvider::onBeforeResize           => 'beforeResize',
            YiiImageProvider::onAfterResize            => 'afterResize',
            YiiImageProvider::onBeforeCrop             => 'beforeCrop',
            YiiImageProvider::onAfterCrop              => 'afterCrop',
            YiiImageProvider::onBeforeRotate           => 'beforeRotate',
            YiiImageProvider::onAfterRotate            => 'afterRotate',
            YiiImageProvider::onBeforeCopy             => 'beforeCopy',
            YiiImageProvider::onAfterCopy              => 'afterCopy',
            YiiImageProvider::onBeforeFill             => 'beforeFill',
            YiiImageProvider::onAfterFill              => 'afterFill',
            YiiImageProvider::onBeforeApplyMask        => 'beforeApplyMask',
            YiiImageProvider::onAfterApplyMask         => 'afterApplyMask',
            YiiImageProvider::onBeforePaste            => 'beforePaste',
            YiiImageProvider::onAfterPaste             => 'afterPaste',
            YiiImageProvider::onBeforeFlipVertically   => 'beforeFlipVertically',
            YiiImageProvider::onBeforeFlipHorizontally => 'beforeFlipHorizontally',
            YiiImageProvider::onAfterFlipVertically    => 'afterFlipVertically',
            YiiImageProvider::onAfterFlipHorizontally  => 'afterFlipHorizontally',
            YiiImageProvider::onBeforeShow             => 'beforeShow',
            YiiImageProvider::onAfterShow              => 'afterShow',
            YiiImageProvider::onBeforeMask             => 'beforeMask',
            YiiImageProvider::onAfterMask              => 'afterMask',
            YiiImageProvider::onAfterHistogram         => 'afterHistogram',
            YiiImageProvider::onBeforeHistogram        => 'beforeHistogram',
            YiiImageProvider::onBeforeBinary           => 'beforeBinary',
            YiiImageProvider::onAfterBinary            => 'afterBinary',
            YiiImageProvider::onBeforeThumbnail        => 'beforeThumbnail',
            YiiImageProvider::onAfterThumbnail         => 'afterThumbnail',
        );
    }

    /**
     * This event will be raised before crop
     * 
     * @param YiiImageProviderEventOnCrop $event 
     */
    protected function beforeCrop(YiiImageProviderEventOnCrop $event)
    {
        
    }

    /**
     * This event will be raised after crop
     * 
     * @param YiiImageProviderEventOnCrop $event 
     */
    protected function afterCrop(YiiImageProviderEventOnCrop $event)
    {
        
    }

    /**
     * This event will be raised before fill
     *
     * @param YiiImageProviderEventOnFill $event 
     */
    protected function beforeFill(YiiImageProviderEventOnFill $event)
    {
        
    }

    /**
     * This event will be raised after fill
     *
     * @param YiiImageProviderEventOnFill $event 
     */
    protected function afterFill(YiiImageProviderEventOnFill $event)
    {
        
    }

    /**
     * This event will be raised before rotate
     *
     * @param YiiImageProviderEventOnRotate $event 
     */
    protected function beforeRotate(YiiImageProviderEventOnRotate $event)
    {
        
    }

    /**
     * This event will be raised after rotate
     *
     * @param YiiImageProviderEventOnRotate $event 
     */
    protected function afterRotate(YiiImageProviderEventOnRotate $event)
    {
        
    }

    /**
     * This event will be raised before apply mask
     *
     * @param YiiImageProviderEventOnApplyMask $event 
     */
    protected function beforeApplyMask(YiiImageProviderEventOnApplyMask $event)
    {
        
    }

    /**
     * This event will be raised after apply mask
     *
     * @param YiiImageProviderEventOnApplyMask $event 
     */
    protected function afterApplyMask(YiiImageProviderEventOnApplyMask $event)
    {
        
    }

    /**
     * This event will be raised before flip vertically
     *
     * @param YiiImageProviderEventOnFlipVertically $event 
     */
    protected function beforeFlipVertically(YiiImageProviderEventOnFlipVertically $event)
    {
        
    }

    /**
     * This event will be raised after flip vertically
     *
     * @param YiiImageProviderEventOnFlipVertically $event 
     */
    protected function afterFlipVertically(YiiImageProviderEventOnFlipVertically $event)
    {
        
    }

    /**
     * This event will be raised before flip horizontally
     *
     * @param YiiImageProviderEventOnFlipHorizontally $event 
     */
    protected function beforeFlipHorizontally(YiiImageProviderEventOnFlipHorizontally $event)
    {
        
    }

    /**
     * This event will be raised after flip horizontally
     *
     * @param YiiImageProviderEventOnFlipHorizontally $event 
     */
    protected function afterFlipHorizontally(YiiImageProviderEventOnFlipHorizontally $event)
    {
        
    }

    /**
     * This event will be raised before save
     *
     * @param YiiImageProviderEventOnSave $event 
     */
    protected function beforeSave(YiiImageProviderEventOnSave $event)
    {
        
    }

    /**
     * This event will be raised after save
     *
     * @param YiiImageProviderEventOnSave $event 
     */
    protected function afterSave(YiiImageProviderEventOnSave $event)
    {
        
    }

    /**
     * This event will be raised before paste
     *
     * @param YiiImageProviderEventOnPaste $event 
     */
    protected function beforePaste(YiiImageProviderEventOnPaste $event)
    {
        
    }

    /**
     * This event will be raised after paste
     *
     * @param YiiImageProviderEventOnPaste $event 
     */
    protected function afterPaste(YiiImageProviderEventOnPaste $event)
    {
        
    }

    /**
     * This event will be raised before show
     *
     * @param YiiImageProviderEventOnShow $event 
     */
    protected function beforeShow(YiiImageProviderEventOnShow $event)
    {
        
    }

    /**
     * This event will be raised after show
     *
     * @param YiiImageProviderEventOnShow $event 
     */
    protected function afterShow(YiiImageProviderEventOnShow $event)
    {
        
    }

    /**
     * This event will be raised before copy
     *
     * @param YiiImageProviderEventOnBeforeCopy $event 
     */
    protected function beforeCopy(YiiImageProviderEventOnBeforeCopy $event)
    {
        
    }

    /**
     * This event will be raised after copy
     *
     * @param YiiImageProviderEventOnAfterCopy $event 
     */
    protected function afterCopy(YiiImageProviderEventOnAfterCopy $event)
    {
        
    }

    /**
     * This event will be raised before binary
     *
     * @param YiiImageProviderEventOnBeforeBinary $event 
     */
    protected function beforeBinary(YiiImageProviderEventOnBeforeBinary $event)
    {
        
    }

    /**
     * This event will be raised after binary
     *
     * @param YiiImageProviderEventOnAfterBinary $event 
     */
    protected function afterBinary(YiiImageProviderEventOnAfterBinary $event)
    {
        
    }

    /**
     * This event will be raised before resize
     *
     * @param YiiImageProviderEventOnResize $event 
     */
    protected function beforeResize(YiiImageProviderEventOnResize $event)
    {
        
    }

    /**
     * This event will be raised after resize
     *
     * @param YiiImageProviderEventOnResize $event 
     */
    protected function afterResize(YiiImageProviderEventOnResize $event)
    {
        
    }

    /**
     * This event will be raised before mask
     *
     * @param YiiImageProviderEventOnBeforeMask $event 
     */
    protected function beforeMask(YiiImageProviderEventOnBeforeMask $event)
    {
        
    }

    /**
     * This event will be raised after mask
     *
     * @param YiiImageProviderEventOnAfterMask $event 
     */
    protected function afterMask(YiiImageProviderEventOnAfterMask $event)
    {
        
    }

    /**
     * This event will be raised after histogram
     *
     * @param YiiImageProviderEventOnAfterHistogram $event 
     */
    protected function afterHistogram(YiiImageProviderEventOnAfterHistogram $event)
    {
        
    }

    /**
     * This event will be raised before histogram
     *
     * @param YiiImageProviderEventOnBeforeHistogram $event 
     */
    protected function beforeHistogram(YiiImageProviderEventOnBeforeHistogram $event)
    {
        
    }

    /**
     * This event will be raised before thumbnail
     *
     * @param YiiImageProviderEventOnBeforeThumbnail $event 
     */
    protected function beforeThumbnail(YiiImageProviderEventOnBeforeThumbnail $event)
    {
        
    }

    /**
     * This event will be raised after thumbnail
     *
     * @param YiiImageProviderEventOnAfterThumbnail $event 
     */
    protected function afterThumbnail(YiiImageProviderEventOnAfterThumbnail $event)
    {
        
    }

}
