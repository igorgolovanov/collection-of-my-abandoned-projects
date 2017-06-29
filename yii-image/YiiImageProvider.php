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
 * 
 * @property-read YiiImageBox $size Current image size.
 * 
 * @property-write string|array|Closure $onBeforeSave Event {@link YiiImageProvider::onBeforeSave}
 * @property-read CList $onBeforeSave Event {@link YiiImageProvider::onBeforeSave}
 * @property-write string|array|Closure $onAfterSave Event {@link YiiImageProvider::onAfterSave}
 * @property-read CList $onAfterSave Event {@link YiiImageProvider::onAfterSave}
 * @property-write string|array|Closure $onBeforeResize Event {@link YiiImageProvider::onBeforeResize}
 * @property-read CList $onBeforeResize Event {@link YiiImageProvider::onBeforeResize}
 * @property-write string|array|Closure $onAfterResize Event {@link YiiImageProvider::onAfterResize}
 * @property-read CList $onAfterResize Event {@link YiiImageProvider::onAfterResize}
 * @property-write string|array|Closure $onBeforeCrop Event {@link YiiImageProvider::onBeforeCrop}
 * @property-read CList $onBeforeCrop Event {@link YiiImageProvider::onBeforeCrop}
 * @property-write string|array|Closure $onAfterCrop Event {@link YiiImageProvider::onAfterCrop}
 * @property-read CList $onAfterCrop Event {@link YiiImageProvider::onAfterCrop}
 * @property-write string|array|Closure $onBeforeRotate Event {@link YiiImageProvider::onBeforeRotate}
 * @property-read CList $onBeforeRotate Event {@link YiiImageProvider::onBeforeRotate}
 * @property-write string|array|Closure $onAfterRotate Event {@link YiiImageProvider::onAfterRotate}
 * @property-read CList $onAfterRotate Event {@link YiiImageProvider::onAfterRotate}
 * @property-write string|array|Closure $onBeforeCopy Event {@link YiiImageProvider::onBeforeCopy}
 * @property-read CList $onBeforeCopy Event {@link YiiImageProvider::onBeforeCopy}
 * @property-write string|array|Closure $onAfterCopy Event {@link YiiImageProvider::onAfterCopy}
 * @property-read CList $onAfterCopy Event {@link YiiImageProvider::onAfterCopy}
 * @property-write string|array|Closure $onBeforeFill Event {@link YiiImageProvider::onBeforeFill}
 * @property-read CList $onBeforeFill Event {@link YiiImageProvider::onBeforeFill}
 * @property-write string|array|Closure $onAfterFill Event {@link YiiImageProvider::onAfterFill}
 * @property-read CList $onAfterFill Event {@link YiiImageProvider::onAfterFill}
 * @property-write string|array|Closure $onBeforeApplyMask Event {@link YiiImageProvider::onBeforeApplyMask}
 * @property-read CList $onBeforeApplyMask Event {@link YiiImageProvider::onBeforeApplyMask}
 * @property-write string|array|Closure $onAfterApplyMask Event {@link YiiImageProvider::onAfterApplyMask}
 * @property-read CList $onAfterApplyMask Event {@link YiiImageProvider::onAfterApplyMask}
 * @property-write string|array|Closure $onBeforePaste Event {@link YiiImageProvider::onBeforePaste}
 * @property-read CList $onBeforePaste Event {@link YiiImageProvider::onBeforePaste}
 * @property-write string|array|Closure $onAfterPaste Event {@link YiiImageProvider::onAfterPaste}
 * @property-read CList $onAfterPaste Event {@link YiiImageProvider::onAfterPaste}
 * @property-write string|array|Closure $onBeforeFlipVertically Event {@link YiiImageProvider::onBeforeFlipVertically}
 * @property-read CList $onBeforeFlipVertically Event {@link YiiImageProvider::onBeforeFlipVertically}
 * @property-write string|array|Closure $onBeforeFlipHorizontally Event {@link YiiImageProvider::onBeforeFlipHorizontally}
 * @property-read CList $onBeforeFlipHorizontally Event {@link YiiImageProvider::onBeforeFlipHorizontally}
 * @property-write string|array|Closure $onAfterFlipVertically Event {@link YiiImageProvider::onAfterFlipVertically}
 * @property-read CList $onAfterFlipVertically Event {@link YiiImageProvider::onAfterFlipVertically}
 * @property-write string|array|Closure $onAfterFlipHorizontally Event {@link YiiImageProvider::onAfterFlipHorizontally}
 * @property-read CList $onAfterFlipHorizontally Event {@link YiiImageProvider::onAfterFlipHorizontally}
 * @property-write string|array|Closure $onBeforeShow Event {@link YiiImageProvider::onBeforeShow}
 * @property-read CList $onBeforeShow Event {@link YiiImageProvider::onBeforeShow}
 * @property-write string|array|Closure $onAfterShow Event {@link YiiImageProvider::onAfterShow}
 * @property-read CList $onAfterShow Event {@link YiiImageProvider::onAfterShow}
 * @property-write string|array|Closure $onBeforeMask Event {@link YiiImageProvider::onBeforeMask}
 * @property-read CList $onBeforeMask Event {@link YiiImageProvider::onBeforeMask}
 * @property-write string|array|Closure $onAfterMask Event {@link YiiImageProvider::onAfterMask}
 * @property-read CList $onAfterMask Event {@link YiiImageProvider::onAfterMask}
 * @property-write string|array|Closure $onAfterHistogram Event {@link YiiImageProvider::onAfterHistogram}
 * @property-read CList $onAfterHistogram Event {@link YiiImageProvider::onAfterHistogram}
 * @property-write string|array|Closure $onBeforeHistogram Event {@link YiiImageProvider::onBeforeHistogram}
 * @property-read CList $onBeforeHistogram Event {@link YiiImageProvider::onBeforeHistogram}
 * @property-write string|array|Closure $onBeforeBinary Event {@link YiiImageProvider::onBeforeBinary}
 * @property-read CList $onBeforeBinary Event {@link YiiImageProvider::onBeforeBinary}
 * @property-write string|array|Closure $onAfterBinary Event {@link YiiImageProvider::onAfterBinary}
 * @property-read CList $onAfterBinary Event {@link YiiImageProvider::onAfterBinary}
 * @property-write string|array|Closure $onBeforeThumbnail Event {@link YiiImageProvider::onBeforeThumbnail}
 * @property-read CList $onBeforeThumbnail Event {@link YiiImageProvider::onBeforeThumbnail}
 * @property-write string|array|Closure $onAfterThumbnail Event {@link YiiImageProvider::onAfterThumbnail}
 * @property-read CList $onAfterThumbnail Event {@link YiiImageProvider::onAfterThumbnail}
 */
abstract class YiiImageProvider extends CComponent
{

    public $drawer = array();

    /**
     * Returns the image content as a PNG binary string
     *
     * @param string $format
     * @param array  $options
     *
     * @throws RuntimeException
     *
     * @return string binary
     */
    abstract public function __toString();

    /**
     * Get new instance for drawer.
     * Method can use args params.
     * 
     * @return YiiImageDrawer 
     */
    protected function getDrawerInstance()
    {
        if (func_num_args() > 0) {
            $args   = CMap::mergeArray((array) $this->drawer, func_get_args());
            $drawer = call_user_func_array(array('Yii', 'createComponent'),
                                           $args);
        } else {
            $drawer = Yii::createComponent($this->drawer);
        }

        if (!$drawer instanceof YiiImageDrawer) {
            throw new RuntimeException(sprintf(
                            'Drawer must be instance of YiiImageDrawer, %s given',
                            var_export($drawer)
            ));
        }
        return $drawer;
    }

    /**
     * Returns current image size
     *
     * @return YiiImageBox
     */
    abstract public function getSize();

    /**
     * Copies current source image into a new YiiImageProvider instance
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doCopy();

    /**
     * Transforms creates a grayscale mask from current image, returns a new
     * image, while keeping the existing image unmodified
     *
     * @return YiiImageProvider
     */
    abstract protected function doMask();

    /**
     * Crops a specified box out of the source image (modifies the source image)
     * Returns cropped self
     *
     * @param YiiImagePoint $start
     * @param YiiImageBox   $size
     *
     * @throws OutOfBoundsException
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doCrop(YiiImagePoint $start, YiiImageBox $size);

    /**
     * Resizes current image and returns self
     *
     * @param YiiImageBox $size
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doResize(YiiImageBox $size);

    /**
     * Rotates an image at the given angle.
     * Optional $background can be used to specify the fill color of the empty
     * area of rotated image.
     *
     * @param integer $angle
     * @param YiiImageColor $backgroundColor
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doRotate($angle, YiiImageColor $backgroundColor);

    /**
     * Pastes an image into a parent image
     * Throws exceptions if image exceeds parent image borders or if paste
     * operation fails
     *
     * Returns source image
     *
     * @param YiiImageProvider $image
     * @param YiiImagePoint $start
     *
     * @throws InvalidArgumentException
     * @throws OutOfBoundsException
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doPaste(YiiImageProvider $image,
                                        YiiImagePoint $start);

    /**
     * Saves the image at a specified path, the target file extension is used
     * to determine file format, only jpg, jpeg, gif, png, wbmp and xbm are
     * supported
     *
     * @param string $path
     * @param array  $options
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doSave($path, array $options);

    /**
     * Generates a thumbnail from a current image
     * Returns it as a new image, doesn't modify the current image
     *
     * @param YiiImageBox $size
     * @param string                     $mode
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doThumbnail(YiiImageBox $size, $mode);

    /**
     * Outputs the image content
     *
     * @param string $format
     * @param array  $options
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doShow($format, array $options);

    /**
     * Flips current image using horizontal axis
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doFlipHorizontally();

    /**
     * Flips current image using vertical axis
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doFlipVertically();

    /**
     * Applies a given mask to current image's alpha channel
     *
     * @param YiiImageProvider $mask
     *
     * @return YiiImageProvider
     */
    abstract protected function doApplyMask(YiiImageProvider $mask);

    /**
     * Fills image with provided filling, by replacing each pixel's color in
     * the current image with corresponding color from YiiImageFill, and
     * returns modified image
     *
     * @param YiiImageFill $fill
     *
     * @return YiiImageProvider
     */
    abstract protected function doFill(YiiImageFill $fill);

    /**
     * Returns the image content as a binary string
     *
     * @param string $format
     * @param array  $options
     *
     * @throws RuntimeException
     *
     * @return string binary
     */
    abstract protected function doBinary($format, array $options);

    /**
     * Returns array of image colors as YiiImageColor instances
     *
     * @return array
     */
    abstract protected function doHistogram();

    /**
     * Returns color at specified positions of current image
     *
     * @param YiiImagePoint $point
     *
     * @throws RuntimeException
     *
     * @return YiiImageColor
     */
    abstract public function getColorAt(YiiImagePoint $point);

    /**
     * Returns array of image colors as YiiImageColor instances
     *
     * @return array
     */
    final public function histogram()
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterHistogram)) {
            $event = new YiiImageProviderEventOnBeforeHistogram($this, $this);
            $this->onBeforeHistogram($event);

            $colors = $event->colors;
        }
        $colors = $this->doHistogram();

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterHistogram)) {
            $event = new YiiImageProviderEventOnAfterHistogram($colors, $this, $this);
            $this->onAfterHistogram($event);

            $colors = $event->colors;
        }
        return $colors;
    }

    /**
     * Returns the image content as a binary string
     *
     * @param string $format
     * @param array  $options
     *
     * @throws RuntimeException
     *
     * @return string binary
     */
    final public function binary($format, array $options = array())
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeBinary)) {
            $event = new YiiImageProviderEventOnBeforeBinary($format, $options, $this, $this);
            $this->onBeforeBinary($event);

            $format  = $event->binaryFormat;
            $options = $event->binaryOptions;
        }
        $binary  = $this->doBinary($format, $options);

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterBinary)) {
            $event = new YiiImageProviderEventOnAfterBinary($binary, $format, $options, $this, $this);
            $this->onAfterBinary($event);

            $binary = $event->binaryContent;
        }
        return $binary;
    }

    /**
     * Instantiates and returns a YiiImageDrawer instance for image drawing
     * 
     * @return type 
     */
    final public function draw()
    {
        return $this->getDrawerInstance();
    }
    
    /**
     * Copies current source image into a new YiiImageProvider instance
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function copy()
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeCopy)) {
            $this->onBeforeCopy(new YiiImageProviderEventOnBeforeCopy($this, $this));
        }
        $provider = $this->doCopy();

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterCopy)) {
            $this->onAfterCopy(new YiiImageProviderEventOnAfterCopy($provider, $this, $this));
        }
        return $provider;
    }

    /**
     * Transforms creates a grayscale mask from current image, returns a new
     * image, while keeping the existing image unmodified
     *
     * @return YiiImageProvider
     */
    final public function mask()
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeMask)) {
            $this->onBeforeMask(new YiiImageProviderEventOnBeforeMask($this, $this));
        }
        $mask = $this->doMask();

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterMask)) {
            $this->onAfterMask(new YiiImageProviderEventOnAfterMask($mask, $this, $this));
        }
        return $mask;
    }

    /**
     * Crops a specified box out of the source image (modifies the source image)
     * Returns cropped self
     *
     * @param YiiImagePoint $start
     * @param YiiImageBox   $size
     *
     * @throws OutOfBoundsException
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function crop(YiiImagePoint $start, YiiImageBox $size)
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeCrop)) {
            $this->onBeforeCrop(new YiiImageProviderEventOnCrop($start, $size, $this, $this));
        }
        $this->doCrop($start, $size);

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterCrop)) {
            $this->onAfterCrop(new YiiImageProviderEventOnCrop($start, $size, $this, $this));
        }
        return $this;
    }

    /**
     * Resizes current image and returns self
     *
     * @param YiiImageBox $size
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function resize(YiiImageBox $size)
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeResize)) {
            $this->onBeforeResize(new YiiImageProviderEventOnResize($size, $this, $this));
        }
        $this->doResize($size);

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterResize)) {
            $this->onAfterResize(new YiiImageProviderEventOnResize($size, $this, $this));
        }
        return $this;
    }

    /**
     * Rotates an image at the given angle.
     * Optional $background can be used to specify the fill color of the empty
     * area of rotated image.
     *
     * @param integer $angle
     * @param YiiImageColor $backgroundColor
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function rotate($angle, YiiImageColor $backgroundColor = null)
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeRotate)) {
            $event = new YiiImageProviderEventOnRotate($angle, $backgroundColor, $this, $this);
            $this->onBeforeRotate($event);

            $angle = $event->angle;
        }
        $this->doRotate($angle, $backgroundColor);

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterRotate)) {
            $this->onAfterRotate(new YiiImageProviderEventOnRotate($angle, $backgroundColor, $this, $this));
        }
        return $this;
    }

    /**
     * Pastes an image into a parent image
     * Throws exceptions if image exceeds parent image borders or if paste
     * operation fails
     *
     * Returns source image
     *
     * @param YiiImageProvider $image
     * @param YiiImagePoint $start
     *
     * @throws InvalidArgumentException
     * @throws OutOfBoundsException
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function paste(YiiImageProvider $image, YiiImagePoint $start)
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforePaste)) {
            $this->onBeforePaste(new YiiImageProviderEventOnPaste($image, $start, $this, $this));
        }
        $this->doPaste($image, $start);

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterPaste)) {
            $this->onAfterPaste(new YiiImageProviderEventOnPaste($image, $start, $this, $this));
        }
        return $this;
    }

    /**
     * Saves the image at a specified path, the target file extension is used
     * to determine file format, only jpg, jpeg, gif, png, wbmp and xbm are
     * supported
     *
     * @param string $path
     * @param array  $options
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function save($path, array $options = array())
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeSave)) {
            $event = new YiiImageProviderEventOnSave($path, $options, $this, $this);
            $this->onBeforeSave($event);

            $path    = $event->path;
            $options = $event->saveOptions;
        }
        $this->doSave($path, $options);

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterSave)) {
            $this->onAfterSave(new YiiImageProviderEventOnSave($path, $options, $this, $this));
        }
        return $this;
    }

    /**
     * Outputs the image content
     *
     * @param string $format
     * @param array  $options
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function show($format, array $options = array())
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeShow)) {
            $event = new YiiImageProviderEventOnShow($format, $options, $provider, $sender);
            $this->onBeforeSave($event);

            $format  = $event->showFormat;
            $options = $event->showOptions;
        }
        $this->doShow($format, $options);

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterShow)) {
            $this->onAfterShow(new YiiImageProviderEventOnShow($format, $options, $provider, $sender));
        }
        return $this;
    }

    /**
     * Flips current image using horizontal axis
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function flipHorizontally()
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeFlipHorizontally)) {
            $this->onBeforeFlipHorizontally(new YiiImageProviderEventOnFlipHorizontally($this, $this));
        }
        $this->doFlipVertically();

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterFlipHorizontally)) {
            $this->onAfterFlipHorizontally(new YiiImageProviderEventOnFlipHorizontally($this, $this));
        }
        return $this;
    }

    /**
     * Flips current image using vertical axis
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function flipVertically()
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeFlipVertically)) {
            $this->onBeforeFlipVertically(new YiiImageProviderEventOnFlipVertically($this, $this));
        }
        $this->doFlipVertically();

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterFlipVertically)) {
            $this->onAfterFlipVertically(new YiiImageProviderEventOnFlipVertically($this, $this));
        }
        return $this;
    }

    /**
     * Generates a thumbnail from a current image
     * Returns it as a new image, doesn't modify the current image
     *
     * @param YiiImageBox $size
     * @param string                     $mode
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function thumbnail(YiiImageBox $size,
                                    $mode = YiiImageThumbnailModes::Insert)
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeThumbnail)) {
            $this->onBeforeThumbnail(new YiiImageProviderEventOnBeforeThumbnail($size, $mode, $this, $this));
        }
        $thumbnail = $this->doThumbnail($size, $mode);

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterThumbnail)) {
            $this->onAfterThumbnail(new YiiImageProviderEventOnAfterThumbnail($thumbnail, $size, $mode, $this, $this));
        }
        return $thumbnail;
    }

    /**
     * Applies a given mask to current image's alpha channel
     *
     * @param YiiImageProvider $mask
     *
     * @return YiiImageProvider
     */
    final public function applyMask(YiiImageProvider $mask)
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeApplyMask)) {
            $this->onBeforeApplyMask(new YiiImageProviderEventOnApplyMask($mask, $this, $this));
        }
        $this->doApplyMask($mask);

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterApplyMask)) {
            $this->onAfterApplyMask(new YiiImageProviderEventOnApplyMask($mask, $this, $this));
        }
        return $this;
    }

    /**
     * Fills image with provided filling, by replacing each pixel's color in
     * the current image with corresponding color from YiiImageFill, and
     * returns modified image
     *
     * @param YiiImageFill $fill
     *
     * @return YiiImageProvider
     */
    final public function fill(YiiImageFill $fill)
    {
        if ($this->hasEventHandler(YiiImageProviderEvents::onBeforeFill)) {
            $this->onBeforeFill(new YiiImageProviderEventOnFill($fill, $this, $this));
        }
        $this->doFill($fill);

        if ($this->hasEventHandler(YiiImageProviderEvents::onAfterFill)) {
            $this->onAfterFill(new YiiImageProviderEventOnFill($fill, $this, $this));
        }
        return $this;
    }

    /**
     * This event will be raised before crop
     * 
     * @param YiiImageProviderEventOnCrop $event 
     */
    final public function onBeforeCrop(YiiImageProviderEventOnCrop $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeCrop, $event);
    }

    /**
     * This event will be raised after crop
     * 
     * @param YiiImageProviderEventOnCrop $event 
     */
    final public function onAfterCrop(YiiImageProviderEventOnCrop $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterCrop, $event);
    }

    /**
     * This event will be raised before fill
     *
     * @param YiiImageProviderEventOnFill $event 
     */
    final public function onBeforeFill(YiiImageProviderEventOnFill $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeFill, $event);
    }

    /**
     * This event will be raised after fill
     *
     * @param YiiImageProviderEventOnFill $event 
     */
    final public function onAfterFill(YiiImageProviderEventOnFill $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterFill, $event);
    }

    /**
     * This event will be raised before rotate
     *
     * @param YiiImageProviderEventOnRotate $event 
     */
    final public function onBeforeRotate(YiiImageProviderEventOnRotate $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeRotate, $event);
    }

    /**
     * This event will be raised after rotate
     *
     * @param YiiImageProviderEventOnRotate $event 
     */
    final public function onAfterRotate(YiiImageProviderEventOnRotate $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterRotate, $event);
    }

    /**
     * This event will be raised before apply mask
     *
     * @param YiiImageProviderEventOnApplyMask $event 
     */
    final public function onBeforeApplyMask(YiiImageProviderEventOnApplyMask $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeApplyMask, $event);
    }

    /**
     * This event will be raised after apply mask
     *
     * @param YiiImageProviderEventOnApplyMask $event 
     */
    final public function onAfterApplyMask(YiiImageProviderEventOnApplyMask $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterApplyMask, $event);
    }

    /**
     * This event will be raised before flip vertically
     *
     * @param YiiImageProviderEventOnFlipVertically $event 
     */
    final public function onBeforeFlipVertically(YiiImageProviderEventOnFlipVertically $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeFlipVertically, $event);
    }

    /**
     * This event will be raised after flip vertically
     *
     * @param YiiImageProviderEventOnFlipVertically $event 
     */
    final public function onAfterFlipVertically(YiiImageProviderEventOnFlipVertically $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterFlipVertically, $event);
    }

    /**
     * This event will be raised before flip horizontally
     *
     * @param YiiImageProviderEventOnFlipHorizontally $event 
     */
    final public function onBeforeFlipHorizontally(YiiImageProviderEventOnFlipHorizontally $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeFlipVertically, $event);
    }

    /**
     * This event will be raised after flip horizontally
     *
     * @param YiiImageProviderEventOnFlipHorizontally $event 
     */
    final public function onAfterFlipHorizontally(YiiImageProviderEventOnFlipHorizontally $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterFlipHorizontally,
                          $event);
    }

    /**
     * This event will be raised before save
     *
     * @param YiiImageProviderEventOnSave $event 
     */
    final public function onBeforeSave(YiiImageProviderEventOnSave $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeSave, $event);
    }

    /**
     * This event will be raised after save
     *
     * @param YiiImageProviderEventOnSave $event 
     */
    final public function onAfterSave(YiiImageProviderEventOnSave $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterSave, $event);
    }

    /**
     * This event will be raised before paste
     *
     * @param YiiImageProviderEventOnPaste $event 
     */
    final public function onBeforePaste(YiiImageProviderEventOnPaste $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforePaste, $event);
    }

    /**
     * This event will be raised after paste
     *
     * @param YiiImageProviderEventOnPaste $event 
     */
    final public function onAfterPaste(YiiImageProviderEventOnPaste $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterPaste, $event);
    }

    /**
     * This event will be raised before show
     *
     * @param YiiImageProviderEventOnShow $event 
     */
    final public function onBeforeShow(YiiImageProviderEventOnShow $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeShow, $event);
    }

    /**
     * This event will be raised after show
     *
     * @param YiiImageProviderEventOnShow $event 
     */
    final public function onAfterShow(YiiImageProviderEventOnShow $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterShow, $event);
    }

    /**
     * This event will be raised before copy
     *
     * @param YiiImageProviderEventOnBeforeCopy $event 
     */
    final public function onBeforeCopy(YiiImageProviderEventOnBeforeCopy $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeCopy, $event);
    }

    /**
     * This event will be raised after copy
     *
     * @param YiiImageProviderEventOnAfterCopy $event 
     */
    final public function onAfterCopy(YiiImageProviderEventOnAfterCopy $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterCopy, $event);
    }

    /**
     * This event will be raised before binary
     *
     * @param YiiImageProviderEventOnBeforeBinary $event 
     */
    final public function onBeforeBinary(YiiImageProviderEventOnBeforeBinary $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeBinary, $event);
    }

    /**
     * This event will be raised after binary
     *
     * @param YiiImageProviderEventOnAfterBinary $event 
     */
    final public function onAfterBinary(YiiImageProviderEventOnAfterBinary $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterBinary, $event);
    }

    /**
     * This event will be raised before resize
     *
     * @param YiiImageProviderEventOnResize $event 
     */
    final public function onBeforeResize(YiiImageProviderEventOnResize $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeResize, $event);
    }

    /**
     * This event will be raised after resize
     *
     * @param YiiImageProviderEventOnResize $event 
     */
    final public function onAfterResize(YiiImageProviderEventOnResize $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterResize, $event);
    }

    /**
     * This event will be raised before mask
     *
     * @param YiiImageProviderEventOnBeforeMask $event 
     */
    final public function onBeforeMask(YiiImageProviderEventOnBeforeMask $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeMask, $event);
    }

    /**
     * This event will be raised after mask
     *
     * @param YiiImageProviderEventOnAfterMask $event 
     */
    final public function onAfterMask(YiiImageProviderEventOnAfterMask $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterMask, $event);
    }

    /**
     * This event will be raised after histogram
     *
     * @param YiiImageProviderEventOnAfterHistogram $event 
     */
    final public function onAfterHistogram(YiiImageProviderEventOnAfterHistogram $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterHistogram, $event);
    }

    /**
     * This event will be raised before histogram
     *
     * @param YiiImageProviderEventOnBeforeHistogram $event 
     */
    final public function onBeforeHistogram(YiiImageProviderEventOnBeforeHistogram $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeHistogram, $event);
    }

    /**
     * This event will be raised before thumbnail
     *
     * @param YiiImageProviderEventOnBeforeThumbnail $event 
     */
    final public function onBeforeThumbnail(YiiImageProviderEventOnBeforeThumbnail $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onBeforeThumbnail, $event);
    }

    /**
     * This event will be raised after thumbnail
     *
     * @param YiiImageProviderEventOnAfterThumbnail $event 
     */
    final public function onAfterThumbnail(YiiImageProviderEventOnAfterThumbnail $event)
    {
        $this->raiseEvent(YiiImageProviderEvents::onAfterThumbnail, $event);
    }

}