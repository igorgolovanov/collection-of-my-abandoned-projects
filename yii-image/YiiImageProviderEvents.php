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
 * Events for the image provider.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiImageProviderEvents extends CEnumerable
{
    
    /**
     * Name of the event, which will be called before save image.
     */
    const onBeforeSave = 'onBeforeSave';

    /**
     * Name of the event, which will be called after save image.
     */
    const onAfterSave = 'onAfterSave';

    /**
     * Name of the event, which will be called before resize image.
     */
    const onBeforeResize = 'onBeforeResize';

    /**
     * Name of the event, which will be called after resize image.
     */
    const onAfterResize = 'onAfterResize';

    /**
     * Name of the event, which will be called before crop image.
     */
    const onBeforeCrop = 'onBeforeCrop';

    /**
     * Name of the event, which will be called after crop image.
     */
    const onAfterCrop = 'onAfterCrop';

    /**
     * Name of the event, which will be called before rotate image.
     */
    const onBeforeRotate = 'onBeforeRotate';

    /**
     * Name of the event, which will be called after rotate image.
     */
    const onAfterRotate = 'onAfterRotate';

    /**
     * Name of the event, which will be called before copy image.
     */
    const onBeforeCopy = 'onBeforeCopy';

    /**
     * Name of the event, which will be called after copy image.
     */
    const onAfterCopy = 'onAfterCopy';

    /**
     * Name of the event, which will be called before fill image.
     */
    const onBeforeFill = 'onBeforeFill';

    /**
     * Name of the event, which will be called after fill image.
     */
    const onAfterFill = 'onAfterFill';

    /**
     * Name of the event, which will be called before apply mask.
     */
    const onBeforeApplyMask = 'onBeforeApplyMask';

    /**
     * Name of the event, which will be called after apply mask.
     */
    const onAfterApplyMask = 'onAfterApplyMask';

    /**
     * Name of the event, which will be called before paste image to image.
     */
    const onBeforePaste = 'onBeforePaste';

    /**
     * Name of the event, which will be called after paste image to image.
     */
    const onAfterPaste = 'onAfterPaste';

    /**
     * Name of the event, which will be called before flip verticaly.
     */
    const onBeforeFlipVertically = 'onBeforeFlipVertically';

    /**
     * Name of the event, which will be called after flip verticaly.
     */
    const onBeforeFlipHorizontally = 'onBeforeFlipHorizontally';

    /**
     * Name of the event, which will be called before flip horizontaly.
     */
    const onAfterFlipVertically = 'onAfterFlipVertically';

    /**
     * Name of the event, which will be called after flip horizontaly.
     */
    const onAfterFlipHorizontally = 'onAfterFlipHorizontally';

    /**
     * Name of the event, which will be called before show image.
     */
    const onBeforeShow = 'onBeforeShow';

    /**
     * Name of the event, which will be called after show image.
     */
    const onAfterShow = 'onAfterShow';

    /**
     * Name of the event, which will be called before do mask of image.
     */
    const onBeforeMask = 'onBeforeMask';

    /**
     * Name of the event, which will be called after do mask of image.
     */
    const onAfterMask = 'onAfterMask';

    /**
     * Name of the event, which will be called before the do histogram of image.
     */
    const onAfterHistogram = 'onAfterHistogram';

    /**
     * Name of the event, which will be called after do histogram of image.
     */
    const onBeforeHistogram = 'onBeforeHistogram';

    /**
     * Name of the event, which will be called before get as binary.
     */
    const onBeforeBinary = 'onBeforeBinary';

    /**
     * Name of the event, which will be called after get as binary.
     */
    const onAfterBinary = 'onAfterBinary';

    /**
     * Name of the event, which will be called before create thumbnail of image.
     */
    const onBeforeThumbnail = 'onBeforeThumbnail';

    /**
     * Name of the event, which will be called after create thumbnail of image.
     */
    const onAfterThumbnail = 'onAfterThumbnail';

}
