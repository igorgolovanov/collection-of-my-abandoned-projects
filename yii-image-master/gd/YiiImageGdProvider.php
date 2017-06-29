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
 * Image provider which based on GD extension.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * 
 * @property-read resource $gdResource GD resource.
 */
class YiiImageGdProvider extends YiiImageProvider implements YiiImageGdAware
{

    /**
     * GD resource.
     * 
     * @var resource
     */
    private $_gdResource;

    /**
     * {@inheritdoc}
     */
    public $drawer = array(
        'class' => 'ext.yii-image.gd.YiiImageGdDrawer',
    );

    /**
     * Constructs a new Image instance using the result of
     * imagecreatetruecolor()
     *
     * @param resource $resource
     */
    public function __construct($resource)
    {
        $this->_gdResource = $resource;
    }

    /**
     * GD resource.
     * 
     * @return resource 
     */
    public function getGdResource()
    {
        return $this->_gdResource;
    }

    /**
     * {@inheritdoc} 
     */
    protected function doCopy()
    {
        $copy = $this->createGdImage($this->size, 'copy');

        if (false === imagecopy($copy, $this->gdResource, 0, 0, 0, 0,
                                $this->size->width, $this->size->height)) {
            throw new RuntimeException('Image copy operation failed');
        }
        return new YiiImageGdProvider($copy);
    }

    /**
     * {@inheritdoc} 
     */
    protected function doApplyMask(YiiImageProvider $mask)
    {
        if (!$mask instanceof self) {
            throw new InvalidArgumentException('Cannot mask non-gd images');
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

        for ($x     = 0, $width = $size->width; $x < $width; $x++) {
            for ($y      = 0, $height = $size->height; $y < $height; $y++) {
                $position  = new YiiImagePoint($x, $y);
                $color     = $this->getColorAt($position);
                $maskColor = $mask->getColorAt($position);
                $round     = (int) round(max($color->alpha,
                                             (100 - $color->alpha) * $maskColor->red / 255));

                if (false === imagesetpixel(
                                $this->_gdResource, $x, $y,
                                $this->createGdColor($color->dissolve($round - $color->alpha))
                )) {
                    throw new RuntimeException('Apply mask operation failed');
                }
            }
        }

        return $this;
    }

    /**
     * {@inheritdoc} 
     */
    public function __toString()
    {
        return $this->doBinary('png', array());
    }

    /**
     * {@inheritdoc} 
     */
    protected function doBinary($format, array $options)
    {
        ob_start();
        $this->saveOrOutput($format, $options);
        return ob_get_clean();
    }

    /**
     * {@inheritdoc} 
     */
    protected function doCrop(YiiImagePoint $start, YiiImageBox $size)
    {
        if (!$start->in($this->size)) {
            throw new OutOfBoundsException(
                    'Crop coordinates must start at minimum 0, 0 position from ' .
                    'top  left corner, crop height and width must be positive ' .
                    'integers and must not exceed the current image borders'
            );
        }

        $dest = $this->createGdImage($size, 'crop');

        if (false === imagecopy($dest, $this->_gdResource, 0, 0, $start->x,
                                $start->y, $size->width, $size->height)) {
            throw new RuntimeException('Image crop operation failed');
        }

        imagedestroy($this->_gdResource);

        $this->_gdResource = $dest;

        return $this;
    }

    /**
     * {@inheritdoc} 
     */
    protected function doFill(YiiImageFill $fill)
    {
        for ($x     = 0, $width = $this->size->width; $x < $width; $x++) {
            for ($y      = 0, $height = $this->size->height; $y < $height; $y++) {
                if (false === imagesetpixel(
                                $this->_gdResource, $x, $y,
                                $this->createGdColor($fill->getColor(new YiiImagePoint($x, $y))))
                ) {
                    throw new RuntimeException('Fill operation failed');
                }
            }
        }

        return $this;
    }

    /**
     * {@inheritdoc} 
     */
    protected function doFlipHorizontally()
    {
        $size = $this->getSize();
        $dest = $this->createGdImage($size, 'flip');

        for ($i = 0; $i < $size->width; $i++) {
            if (false === imagecopy($dest, $this->_gdResource, $i, 0,
                                    ($size->width - 1) - $i, 0, 1, $size->height)) {
                throw new RuntimeException('Horizontal flip operation failed');
            }
        }
        imagedestroy($this->_gdResource);

        $this->_gdResource = $dest;

        return $this;
    }

    /**
     * {@inheritdoc} 
     */
    protected function doFlipVertically()
    {
        $size = $this->getSize();
        $dest = $this->createGdImage($size, 'flip');

        for ($i = 0; $i < $size->height; $i++) {
            if (false === imagecopy($dest, $this->_gdResource, 0, $i, 0,
                                    ($size->height - 1) - $i, $size->width, 1)) {
                throw new RuntimeException('Vertical flip operation failed');
            }
        }

        imagedestroy($this->_gdResource);

        $this->_gdResource = $dest;

        return $this;
    }

    /**
     * {@inheritdoc}
     */
    protected function doHistogram()
    {
        $colors = array();

        for ($x     = 0, $width = $this->size->width; $x < $width; $x++) {
            for ($y      = 0, $height = $this->size->height; $y < $height; $y++) {
                $colors[] = $this->getColorAt(new YiiImagePoint($x, $y));
            }
        }

        return array_unique($colors);
    }

    /**
     * {@inheritdoc} 
     */
    protected function doMask()
    {
        $mask = $this->doCopy();

        if (false === imagefilter($mask->gdResource, IMG_FILTER_GRAYSCALE)) {
            throw new RuntimeException('Mask operation failed');
        }

        return $mask;
    }

    /**
     * {@inheritdoc} 
     */
    protected function doPaste(YiiImageProvider $image, YiiImagePoint $start)
    {
        if (!$image instanceof self) {
            throw new InvalidArgumentException(sprintf(
                            'YiiImageGdProvider can only paste() YiiImageGdProvider instances, %s given',
                            get_class($image)
            ));
        }

        if (!$this->getSize()->contains($image->size, $start)) {
            throw new OutOfBoundsException(
                    'Cannot paste image of the given size at the specified ' .
                    'position, as it moves outside of the current image\'s box'
            );
        }

        imagealphablending($this->_gdResource, true);
        imagealphablending($image->_gdResources, true);

        if (false === imagecopy($this->_gdResource, $image->_gdResource,
                                $start->x, $start->y, 0, 0, $image->size->width,
                                $image->size->height)) {
            throw new RuntimeException('Image paste operation failed');
        }

        imagealphablending($this->_gdResource, false);
        imagealphablending($image->_gdResource, false);

        return $this;
    }

    /**
     * {@inheritdoc} 
     */
    protected function doResize(YiiImageBox $size)
    {
        $dest = $this->createGdImage($size, 'resize');

        imagealphablending($this->_gdResource, true);
        imagealphablending($dest, true);

        if (false === imagecopyresampled($dest, $this->_gdResource, 0, 0, 0, 0,
                                         $size->width, $size->height,
                                         imagesx($this->_gdResource),
                                                 imagesy($this->_gdResource)
        )) {
            throw new RuntimeException('Image resize operation failed');
        }

        imagealphablending($this->_gdResource, false);
        imagealphablending($dest, false);

        imagedestroy($this->_gdResource);

        $this->_gdResource = $dest;

        return $this;
    }

    /**
     * {@inheritdoc} 
     */
    protected function doRotate($angle, YiiImageColor $backgroundColor)
    {
        $color = $backgroundColor ? $backgroundColor : new YiiImageColor('fff');

        $resource = imagerotate($this->_gdResource, $angle,
                                $this->createGdColor($color));

        if (false === $resource) {
            throw new RuntimeException('Image rotate operation failed');
        }

        imagedestroy($this->_gdResource);

        $this->_gdResource = $resource;

        return $this;
    }

    /**
     * {@inheritdoc} 
     */
    protected function doSave($path, array $options)
    {
        $format = isset($options['format']) ? $options['format'] : pathinfo($path,
                                                                            \PATHINFO_EXTENSION);

        $this->saveOrOutput($format, $options, $path);

        return $this;
    }

    /**
     * {@inheritdoc} 
     */
    protected function doShow($format, array $options)
    {
        header('Content-type: ' . $this->getMimeType($format));

        $this->saveOrOutput($format, $options);

        return $this;
    }

    /**
     * {@inheritdoc}  
     */
    protected function doThumbnail(YiiImageBox $size, $mode)
    {
        if ($mode !== YiiImageThumbnailModes::Insert &&
                $mode !== YiiImageThumbnailModes::Outbound) {
            throw new InvalidArgumentException('Invalid mode specified');
        }

        $width  = $size->width;
        $height = $size->height;

        $ratios = array(
            $width / imagesx($this->_gdResource),
            $height / imagesy($this->_gdResource)
        );

        $thumbnail = $this->copy();

        if ($mode === YiiImageThumbnailModes::Insert) {
            $ratio = min($ratios);
        } else {
            $ratio = max($ratios);
        }

        $thumbnailSize = $thumbnail->size->scale($ratio);
        $thumbnail->resize($thumbnailSize);

        if ($mode === YiiImageThumbnailModes::Outbound) {
            $thumbnail->crop(new Point(
                            max(0, round(($thumbnailSize->width - $width) / 2)),
                            max(0, round(($thumbnailSize->height - $height) / 2))
                    ), $size);
        }

        return $thumbnail;
    }

    /**
     * {@inheritdoc}  
     */
    public function getSize()
    {
        return new YiiImageBox(imagesx($this->_gdResource), imagesy($this->_gdResource));
    }

    /**
     * {@inheritdoc} 
     */
    public function getColorAt(YiiImagePoint $point)
    {
        if (!$point->in($this->size)) {
            throw new RuntimeException(sprintf(
                            'Error getting color at point [%s,%s]. 
                                The point must be inside the image of size [%s,%s]',
                            $point->x, $point->y, $this->size->width,
                            $this->size->height
            ));
        }
        $index = imagecolorat($this->_gdResource, $point->x, $point->y);
        $info  = imagecolorsforindex($this->_gdResource, $index);
        return new YiiImageColor(array(
                    $info['red'],
                    $info['green'],
                    $info['blue'],
                        ),
                        (int) round($info['alpha'] / 127 * 100)
        );
    }

    /**
     * {@inheritdoc}  
     */
    protected function getDrawerInstance()
    {
        return parent::getDrawerInstance($this->gdResource);
    }

    /**
     * Internal
     *
     * Generates a GD image
     *
     * @param  YiiImageBox  $size      Size
     * @param  string       $operation The operation initiating the creation
     *
     * @return resource
     *
     * @throws RuntimeException
     */
    private function createGdImage(YiiImageBox $size, $operation)
    {
        $resource = imagecreatetruecolor($size->width, $size->height);

        if (false === $resource) {
            throw new RuntimeException('Image ' . $operation . ' failed');
        }

        if (false === imagealphablending($resource, false) ||
                false === imagesavealpha($resource, true)) {
            throw new RuntimeException('Image ' . $operation . ' failed');
        }

        if (function_exists('imageantialias')) {
            imageantialias($resource, true);
        }

        $transparent = imagecolorallocatealpha($resource, 255, 255, 255, 127);
        imagefill($resource, 0, 0, $transparent);
        imagecolortransparent($resource, $transparent);

        return $resource;
    }

    /**
     * Internal
     *
     * Performs save or show operation using one of GD's image... functions
     *
     * @param string $format
     * @param array  $options
     * @param string $filename
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     */
    private function saveOrOutput($format, array $options, $filename = null)
    {

        if (!$this->supported($format)) {
            throw new InvalidArgumentException(sprintf(
                            'Saving image in "%s" format is not supported, please use one ' .
                            'of the following extension: "%s"', $format,
                            implode('", "', $this->supported())
            ));
        }

        $save = 'image' . $format;
        $args = array($this->gdResource, $filename);

        if (($format === 'jpeg' || $format === 'png') &&
                isset($options['quality'])) {
            // Png compression quality is 0-9, so here we get the value from percent.
            // Beaware that compression level for png works the other way around.
            // For PNG 0 means no compression and 9 means highest compression level.
            if ($format === 'png') {
                $options['quality'] = round((100 - $options['quality']) * 9 / 100);
            }
            $args[]             = $options['quality'];
        }

        if ($format === 'png' && isset($options['filters'])) {
            $args[] = $options['filters'];
        }

        if (($format === 'wbmp' || $format === 'xbm') &&
                isset($options['foreground'])) {
            $args[] = $options['foreground'];
        }

        $this->setExceptionHandler();

        if (false === call_user_func_array($save, $args)) {
            throw new RuntimeException('Save operation failed');
        }

        $this->resetExceptionHandler();
    }

    /**
     * Internal
     *
     * Generates a GD color from Color instance
     *
     * @param YiiImageColor $color
     *
     * @return resource
     *
     * @throws RuntimeException
     */
    private function createGdColor(YiiImageColor $color)
    {
        $index = imagecolorallocatealpha(
                $this->_gdResource, $color->red, $color->green, $color->blue,
                round(127 * $color->alpha / 100)
        );

        if (false === $index) {
            throw new RuntimeException(sprintf(
                            'Unable to allocate color "RGB(%s, %s, %s)" with transparency ' .
                            'of %d percent', $color->red, $color->green,
                            $color->blue, $color->alpha
            ));
        }

        return $index;
    }

    /**
     * Internal
     *
     * Checks whether a given format is supported by GD library
     *
     * @param string $format
     *
     * @return boolean
     */
    private function supported(&$format = null)
    {
        $formats = array('gif', 'jpeg', 'png', 'wbmp', 'xbm');

        if (null === $format) {
            return $formats;
        }

        $format = strtolower($format);

        if ('jpg' === $format || 'pjpeg' === $format) {
            $format = 'jpeg';
        }

        return in_array($format, $formats);
    }

    private function setExceptionHandler()
    {
        set_error_handler(function($errno, $errstr, $errfile, $errline, array $errcontext) {

                    if (0 === error_reporting()) {
                        return;
                    }

                    throw new RuntimeException(
                            $errstr, $errno,
                            new ErrorException($errstr, 0, $errno, $errfile, $errline)
                    );
                }, E_WARNING | E_NOTICE);
    }

    private function resetExceptionHandler()
    {
        restore_error_handler();
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
        if (!$this->supported($format)) {
            throw new RuntimeException('Invalid format');
        }

        static $mimeTypes = array(
    'jpeg' => 'image/jpeg',
    'jpg'  => 'image/jpeg',
    'gif'  => 'image/gif',
    'png'  => 'image/png',
    'wbmp' => 'image/vnd.wap.wbmp',
    'xbm'  => 'image/xbm',
        );

        return $mimeTypes[$format];
    }

}
