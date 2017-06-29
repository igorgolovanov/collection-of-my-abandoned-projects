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
 * @property-read Imagick $imagick Imagick
 */
class YiiImageImagickProvider extends YiiImageProvider
        implements YiiImageImagickAware
{

    /**
     * Imagick.
     * 
     * @var Imagick
     */
    private $_imagick;
    
    /**
     * {@inheritDoc}
     */
    public $drawer = array(
        'class' => 'ext.yii-image.imagick.YiiImageImagickDrawer',
    );

    /**
     * Constructor.
     *
     * @param Imagick $imagick Imagick
     */
    public function __construct(Imagick $imagick)
    {
        $this->_imagick = $imagick;
    }

    /**
     * Destroys allocated imagick resources
     */
    public function __destruct()
    {
        if (null !== $this->imagick && $this->imagick instanceof \Imagick) {
            $this->imagick->clear();
            $this->imagick->destroy();
        }
    }

    /**
     * Imagick.
     * 
     * @return Imagick
     */
    public function getImagick()
    {
        return $this->_imagick;
    }

    /**
     * {@inheritDoc} 
     */
    public function getSize()
    {
        try {
            $width  = $this->imagick->getImageWidth();
            $height = $this->imagick->getImageHeight();
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Could not get size', $e->getCode(), $e
            );
        }

        return new YiiImageBox($width, $height);
    }

    /**
     * {@inheritDoc} 
     */
    protected function getDrawerInstance()
    {
        parent::getDrawerInstance($this->imagick);
    }

    /**
     * {@inheritDoc} 
     */
    public function __toString()
    {
        return $this->doBinary('png');
    }

    /**
     * {@inheritDoc} 
     */
    protected function doCopy()
    {
        try {
            $clone = $this->imagick->clone();
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Copy operation failed', $e->getCode(), $e
            );
        }
        return new self($clone);
    }

    /**
     * {@inheritDoc} 
     */
    protected function doApplyMask(YiiImageProvider $mask)
    {
        if (!$mask instanceof self) {
            throw new InvalidArgumentException(
                    'Can only apply instances of YiiImageProvider as masks'
            );
        }

        $size     = $this->size;
        $maskSize = $mask->size;

        if ($size != $maskSize) {
            throw new InvalidArgumentException(sprintf(
                            'The given mask doesn\'t match current image\'s size, Current ' .
                            'mask\'s dimensions are %s, while image\'s dimensions are %s',
                            $maskSize, $size
            ));
        }

        $mask = $mask->mask();

        $mask->imagick->negateImage(true);

        try {
            // remove transparent areas of the original from the mask
            $mask->imagick->compositeImage(
                    $this->imagick, Imagick::COMPOSITE_DSTIN, 0, 0
            );

            $this->imagick->compositeImage(
                    $mask->imagick, Imagick::COMPOSITE_COPYOPACITY, 0, 0
            );

            $mask->imagick->clear();
            $mask->imagick->destroy();
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Apply mask operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doBinary($format, array $options)
    {
        try {
            $this->applyImageOptions($this->imagick, $options);
            $this->imagick->setImageFormat($format);
        } catch (ImagickException $e) {
            throw new InvalidArgumentException(
                    'Show operation failed', $e->getCode(), $e
            );
        }

        return (string) $this->imagick;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doCrop(YiiImagePoint $start, YiiImageBox $size)
    {
        if (!$start->in($this->size)) {
            throw new OutOfBoundsException('Crop coordinates must start at ' .
                    'minimum 0, 0 position from top left corner, crop height and ' .
                    'width must be positive integers and must not exceed the ' .
                    'current image borders');
        }

        try {
            $this->imagick->cropImage(
                    $size->width, $size->height, $start->x, $start->y
            );
            // Reset canvas for gif format
            $this->imagick->setImagePage(0, 0, 0, 0);
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Crop operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doFill(YiiImageFill $fill)
    {
        try {
            if ($this->isLinearOpaque($fill)) {
                $this->applyFastLinear($fill);
            } else {
                $iterator = $this->imagick->getPixelIterator();

                foreach ($iterator as $y => $pixels) {
                    foreach ($pixels as $x => $pixel) {
                        $color = $fill->getColor(new YiiImagePoint($x, $y));

                        $pixel->setColor((string) $color);
                        $pixel->setColorValue(
                                Imagick::COLOR_OPACITY,
                                number_format(abs(round($color->alpha / 100, 1)),
                                                        1)
                        );
                    }

                    $iterator->syncIterator();
                }
            }
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Fill operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doFlipHorizontally()
    {
        try {
            $this->imagick->flopImage();
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Horizontal Flip operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doFlipVertically()
    {
        try {
            $this->imagick->flipImage();
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Vertical flip operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doHistogram()
    {
        $pixels = $this->imagick->getImageHistogram();

        foreach ($pixels as $i => $pixel) {
            $info       = $pixel->getColor();
            $pixels[$i] = new YiiImageColor(
                            array(
                                $info['r'],
                                $info['g'],
                                $info['b'],
                            ),
                            (int) round($info['a'] * 100)
            );
        }
        return $pixels;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doMask()
    {
        $mask = $this->doCopy();

        try {
            $mask->imagick->modulateImage(100, 0, 100);
            $mask->imagick->setImageMatte(false);
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Mask operation failed', $e->getCode(), $e
            );
        }

        return $mask;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doPaste(YiiImageProvider $image, YiiImagePoint $start)
    {
        if (!$image instanceof self) {
            throw new InvalidArgumentException(sprintf('Imagick\Image can ' .
                            'only paste() Imagick\Image instances, %s given',
                                                       get_class($image)
            ));
        }

        if (!$this->size->contains($image->size, $start)) {
            throw new OutOfBoundsException(
                    'Cannot paste image of the given size at the specified ' .
                    'position, as it moves outside of the current image\'s box'
            );
        }

        try {

            $this->imagick->compositeImage(
                    $image->imagick, Imagick::COMPOSITE_DEFAULT, $start->x,
                    $start->y
            );
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Paste operation failed', $e->getCode(), $e
            );
        }

        try {
            $this->imagick->flattenImages();
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Paste operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doResize(YiiImageBox $size)
    {
        try {
            $this->imagick->thumbnailImage($size->width, $size->height);
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Resize operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doRotate($angle, YiiImageColor $backgroundColor)
    {
        $color = $background ? $background : new YiiImageColor('fff');

        try {
            $pixel = $this->createImagickColor($color);

            $this->imagick->rotateimage($pixel, $angle);

            $pixel->clear();
            $pixel->destroy();
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Rotate operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doSave($path, array $options)
    {
        try {
            if (isset($options['format'])) {
                $this->imagick->setimageformat($options['format']);
            }

            $this->applyImageOptions($this->imagick, $options);
            $this->imagick->writeImage($path);
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Save operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doShow($format, array $options)
    {
        header('Content-type: ' . $this->getMimeType($format));
        echo $this->doBinary($format, $options);

        return $this;
    }

    /**
     * {@inheritDoc} 
     */
    protected function doThumbnail(YiiImageBox $size, $mode)
    {
        if ($mode !== YiiImageThumbnailModes::Insert &&
                $mode !== YiiImageThumbnailModes::Outbound) {
            throw new InvalidArgumentException('Invalid mode specified');
        }

        $width     = $size->width;
        $height    = $size->height;
        $thumbnail = $this->doCopy();

        try {
            if ($mode === YiiImageThumbnailModes::Insert) {
                $thumbnail->imagick->thumbnailImage(
                        $width, $height, true
                );
            } else if ($mode === YiiImageThumbnailModes::Outbound) {
                $thumbnail->imagick->cropThumbnailImage(
                        $width, $height
                );
            }
        } catch (ImagickException $e) {
            throw new RuntimeException(
                    'Thumbnail operation failed', $e->getCode(), $e
            );
        }

        return $thumbnail;
    }

    /**
     * {@inheritDoc} 
     */
    public function getColorAt(YiiImagePoint $point)
    {
        if (!$point->in($this->size)) {
            throw new RuntimeException(sprintf(
                            'Error getting color at point [%s,%s]. The point must be inside the image of size [%s,%s]',
                            $point->x, $point->y, $this->size->width,
                            $this->size->height
            ));
        }
        $pixel = $this->imagick->getImagePixelColor($point->x, $point->y);
        return new YiiImageColor(array(
                    $pixel->getColorValue(Imagick::COLOR_RED) * 255,
                    $pixel->getColorValue(Imagick::COLOR_GREEN) * 255,
                    $pixel->getColorValue(Imagick::COLOR_BLUE) * 255,
                        ),
                        (int) round($pixel->getColorValue(Imagick::COLOR_ALPHA) * 100)
        );
    }

    /**
     * Internal
     *
     * Applies options before save or output
     *
     * @param Imagick $image
     * @param array $options
     */
    private function applyImageOptions(Imagick $image, array $options)
    {
        if (isset($options['quality'])) {
            $image->setImageCompressionQuality($options['quality']);
        }
    }

    /**
     * Gets specifically formatted color string from Color instance
     *
     * @param YiiImageColor $color
     *
     * @return string
     */
    private function createImagickColor(YiiImageColor $color)
    {
        $pixel = new ImagickPixel((string) $color);
        $pixel->setColorValue(
                Imagick::COLOR_OPACITY,
                number_format(abs(round($color->alpha / 100, 1)), 1)
        );
        return $pixel;
    }

    /**
     * Checks whether given $fill is linear and opaque
     *
     * @param YiiImageFill $fill
     *
     * @return boolean
     */
    private function isLinearOpaque(YiiImageFill $fill)
    {
        return $fill instanceof YiiImageFillGradientLineral &&
                ($fill->start->isOpaque && $fill->end->isOpaque);
    }

    /**
     * Performs optimized gradient fill for non-opaque linear gradients
     *
     * @param YiiImageFillGradientLinear $fill
     */
    private function applyFastLinear(YiiImageFillGradientLineral $fill)
    {
        $gradient = new Imagick();
        $size     = $this->size;
        $color    = sprintf(
                'gradient:%s-%s', (string) $fill->start, (string) $fill->end
        );

        if ($fill instanceof YiiImageFillGradientLineralHorizontal) {
            $gradient->newPseudoImage(
                    $size->height, $size->width, $color
            );

            $gradient->rotateImage(new ImagickPixel(), 90);
        } else {
            $gradient->newPseudoImage(
                    $size->width, $size->height, $color
            );
        }

        $this->imagick->compositeImage(
                $gradient, Imagick::COMPOSITE_OVER, 0, 0
        );

        $gradient->clear();
        $gradient->destroy();
    }

    /**
     * Internal
     * 
     * Get the mime type based on format.
     * 
     * @param string $format
     * 
     * @return string mime-type
     * 
     * @throws RuntimeException
     */
    private function getMimeType($format)
    {
        static $mimeTypes = array(
    'jpeg' => 'image/jpeg',
    'jpg'  => 'image/jpeg',
    'gif'  => 'image/gif',
    'png'  => 'image/png',
    'wbmp' => 'image/vnd.wap.wbmp',
    'xbm'  => 'image/xbm',
        );

        if (!isset($mimeTypes[$format])) {
            throw new RuntimeException(sprintf(
                            'Unsupported format given. Only %s are supported, %s given',
                            implode(", ", array_keys($mimeTypes)), $format
            ));
        }

        return $mimeTypes[$format];
    }

}
