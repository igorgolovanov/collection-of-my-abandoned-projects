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
 */
abstract class YiiImageDriver extends CComponent
{

    /**
     * Provider options.
     * 
     * @var array
     */
    public $providerOptions;

    /**
     * Font options.
     * 
     * @var array
     */
    public $fontOptions;

    /**
     * Creates a new empty image with an optional background color
     * This method is invoked by {@link create} method.
     *
     * @param YiiImageBox   $size Size.
     * @param YiiImageColor $color Color.
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doCreate(YiiImageBox $size,
                                         YiiImageColor $color = null);

    /**
     * Opens an existing image from $path
     * This method is invoked by {@link open} method.
     *
     * @param string $path
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doOpen($path);

    /**
     * Loads an image from a binary $string
     * This method is invoked by {@link load} method.
     *
     * @param string $string
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doLoad($string);

    /**
     * Loads an image from a resource $resource
     * This method is invoked by {@link read} method.
     *
     * @param resource $resource
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    abstract protected function doRead($resource);

    /**
     * Constructs a font with specified $file, $size and $color
     * The font size is to be specified in points (e.g. 10pt means 10)
     * This method is invoked by {@link fond} method.
     *
     * @param string        $file File.
     * @param integer       $size Size.
     * @param YiiImageColor $color YiiImageColor.
     *
     * @return YiiImageFont
     */
    abstract protected function doFont($file, $size, YiiImageColor $color);

    /**
     * Get new instance for provider.
     * Method can use args params.
     * 
     * @return YiiImageProvider 
     */
    protected function getProviderInstance()
    {
        if (func_num_args() > 0) {
            $args     = CMap::mergeArray((array) $this->provider,
                                         func_get_args());
            $provider = call_user_func_array(array('Yii', 'createComponent'),
                                             $args);
        } else {
            $provider = Yii::createComponent($this->provider);
        }

        if (!$provider instanceof YiiImageProvider) {
            throw new RuntimeException(
                    'Provider class must instanced of YiiImageProvider'
            );
        }
        return $provider;
    }

    /**
     * Get new instance for font.
     * Method can use args params.
     * 
     * @return YiiImageFont
     */
    protected function getFontInstance()
    {
        if (func_num_args() > 0) {
            $args = CMap::mergeArray((array) $this->font, func_get_args());
            $font = call_user_func_array(array('Yii', 'createComponent'), $args);
        } else {
            $font = Yii::createComponent($this->font);
        }

        if (!$font instanceof YiiImageFont) {
            throw new RuntimeException(
                    'Font class must instanced of YiiImageFont'
            );
        }
        return $font;
    }

    /**
     * Creates a new empty image with an optional background color
     *
     * @param YiiImageBox   $size Size.
     * @param YiiImageColor $color Color.
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function create(YiiImageBox $size, YiiImageColor $color = null)
    {
        if ($this->hasEventHandler(YiiImageDriverEvents::onBeforeCreate)) {
            $this->onBeforeCreate(new YiiImageEventOnBeforeCreate($size, $color, $this));
        }

        $provider = $this->doCreate($size, $color);

        if ($this->hasEventHandler(YiiImageDriverEvents::onAfterCreate)) {
            $this->onAfterCreate(new YiiImageEventOnBeforeCreate($provider, $size, $color, $this));
        }
        return $provider;
    }

    /**
     * Opens an existing image from $path
     *
     * @param string $path
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function open($path)
    {
        if ($this->hasEventHandler(YiiImageDriverEvents::onBeforeOpen)) {
            $event    = new YiiImageEventOnBeforeOpen($path);
            $this->onBeforeOpen($event);
            $path     = $event->path;
        }
        $provider = $this->doOpen($path);

        if ($this->hasEventHandler(YiiImageDriverEvents::onAfterOpen)) {
            $this->onBeforeOpen(new YiiImageEventOnAfterOpen($provider, $path));
        }
        return $provider;
    }

    /**
     * Loads an image from a binary $string
     *
     * @param string $string
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function load($string)
    {
        if ($this->hasEventHandler(YiiImageDriverEvents::onBeforeLoad)) {
            
        }
        $provider = $this->doLoad($string);

        if ($this->hasEventHandler(YiiImageDriverEvents::onAfterLoad)) {
            
        }
        return $provider;
    }

    /**
     * Loads an image from a resource $resource
     *
     * @param resource $resource
     *
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    final public function read($resource)
    {
        if ($this->hasEventHandler(YiiImageDriverEvents::onBeforeRead)) {
            $this->onBeforeRead($event);
        }
        $provider = $this->doRead($resource);

        if ($this->hasEventHandler(YiiImageDriverEvents::onAfterRead)) {
            $this->onAfterRead($event);
        }
        return $provider;
    }

    /**
     * Constructs a font with specified $file, $size and $color
     *
     * The font size is to be specified in points (e.g. 10pt means 10)
     *
     * @param string        $file File.
     * @param integer       $size Size.
     * @param YiiImageColor $color Color.
     *
     * @return YiiImageFont
     */
    final public function font($file, $size, YiiImageColor $color)
    {
        
    }

    final public function onBeforeRead(YiiImageDriverEventOnBeforeRead $event)
    {
        $this->raiseEvent(YiiImageDriverEvents::onBeforeRead, $event);
    }

    final public function onAfterRead(YiiImageDriverEventOnAfterRead $event)
    {
        $this->raiseEvent(YiiImageDriverEvents::onAfterRead, $event);
    }

    final public function onBeforeCreate(YiiImageEventOnBeforeCreate $event)
    {
        $this->raiseEvent(YiiImageDriverEvents::onBeforeCreate, $event);
    }

    final public function onAfterCreate(YiiImageEventOnAfterCreate $event)
    {
        $this->raiseEvent(YiiImageDriverEvents::onAfterCreate, $event);
    }

    final public function onBeforeOpen(YiiImageEventOnBeforeOpen $event)
    {
        $this->raiseEvent(YiiImageDriverEvents::onBeforeOpen, $event);
    }

    final public function onAfterOpen(YiiImageEventOnAfterOpen $event)
    {
        $this->raiseEvent(YiiImageDriverEvents::onAfterOpen, $event);
    }

    final public function onBeforeLoad(YiiImageEventOnBeforeLoad $event)
    {
        $this->raiseEvent(YiiImageDriverEvents::onBeforeLoad, $event);
    }

    final public function onAfterLoad(YiiImageEventOnAfterLoad $event)
    {
        $this->raiseEvent(YiiImageDriverEvents::onAfterLoad, $event);
    }

}
