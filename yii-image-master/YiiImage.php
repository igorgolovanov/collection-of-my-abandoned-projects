<?php

/*
 * This file is part of the YiiImage package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

Yii::import('ext.yii-image.*');
Yii::import('ext.yii-image.gd.*');
Yii::import('ext.yii-image.imagick.*');
Yii::import('ext.yii-image.gmagick.*');
Yii::import('ext.yii-image.fills.*');

/**
 * YiiImage application component.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * 
 * @property-write  array           $driverMap      Drivers.
 * @property-read   array           $driverNames    List of driver names.
 * @property-read   YiiImageDriver  $driver         Driver.
 */
class YiiImage extends CApplicationComponent
{

    /**
     * Driver map.
     * 
     * @var array 
     */
    private $_driverMap = array(
        'gd' => array(
            'class'           => 'ext.yii-image.gd.YiiImageGdDriver',
            'providerOptions' => array(
                'class'         => 'ext.yii-image.gd.YiiImageGdProvider',
                'drawerOptions' => array(
                    'class'       => 'ext.yii-image.gd.YiiImageGdDrawer',
                ),
            ),
            'fontOptions' => array(
                'class'   => 'ext.yii-image.gd.YiiImageGdFont',
            ),
        ),
        'imagick' => array(
            'class'           => 'ext.yii-image.imagick.YiiImageImagickDriver',
            'providerOptions' => array(
                'class'         => 'ext.yii-image.imagick.YiiImageImagickProvider',
                'drawerOptions' => array(
                    'class'       => 'ext.yii-image.imagick.YiiImageImagickDrawer',
                ),
            ),
            'fontOptions' => array(
                'class'   => 'ext.yii-image.imagick.YiiImageImagickFont',
            ),
        ),
        'gmagick' => array(
            'class'           => 'ext.yii-image.gmagick.YiiImageGmagickDriver',
            'providerOptions' => array(
                'class'         => 'ext.yii-image.gmagick.YiiImageGmagickProvider',
                'drawerOptions' => array(
                    'class'       => 'ext.yii-image.gmagick.YiiImageGmagickDrawer',
                ),
            ),
            'fontOptions' => array(
                'class' => 'ext.yii-image.gmagick.YiiImageGmagickFont',
            ),
        ),
    );

    /**
     * Active driver.
     * 
     * @var string 
     */
    private $_activeDriverName;

    /**
     * Set drivers.
     * 
     * @param array $drivers 
     * 
     * @return YiiImage
     */
    public function setDriverMap(array $drivers)
    {
        $this->_driverMap = $drivers;

        return $this;
    }

    /**
     * List of driver names.
     * 
     * @return array
     */
    public function getDriverNames()
    {
        return array_keys($this->_driverMap);
    }

    /**
     * Get name of active driver.
     *
     * @throws RuntimeException
     * 
     * @return string
     */
    public function getActiveDriverName()
    {
        if (!$this->_activeDriverName) {
            if (count($this->driverNames) > 0) {
                $this->_activeDriverName = reset($this->driverNames);
            }
        }
        if (!$this->_activeDriverName) {
            throw new RuntimeException('Active driver name not setted!');
        }
        if (!$this->ensureDriverExists($this->_activeDriverName)) {
            throw new RuntimeException('Active driver not founded in driver map!');
        }

        return $this->_activeDriverName;
    }

    /**
     * Set active driver by name.
     * 
     * @param string $driverName Driver name.
     * 
     * @return YiiImage
     */
    public function setActiveDriverName($driverName)
    {
        $this->_activeDriverName = (string) $driverName;
        
        return $this;
    }

    /**
     * Ensure a driver exists.
     * 
     * @param string $driverName Name of driver.
     * 
     * @return boolean
     */
    public function ensureDriverExists($driverName)
    {
        return isset($this->_driverMap[$driverName]);
    }

    /**
     * Driver.
     * 
     * @return YiiImageDriver 
     */
    public function getDriver()
    {
        return Yii::createComponent($this->_driverMap[$this->activeDriverName]);
    }

    /**
     * Creates a new empty image with an optional background color
     *
     * @param YiiImageBox   $size   Size.
     * @param YiiImageColor $color  Color.
     *
     * @throws InvalidArgumentException
     * @throws RuntimeException
     *
     * @return YiiImageProvider
     */
    public function create(YiiImageBox $size, YiiImageColor $color = null)
    {
        return $this->driver->create($size, $color);
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
    public function open($path)
    {
        return $this->driver->open($path);
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
    public function load($string)
    {
        return $this->driver->load($string);
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
    public function read($resource)
    {
        return $this->driver->read($resource);
    }

    /**
     * Constructs a font with specified $file, $size and $color
     *
     * The font size is to be specified in points (e.g. 10pt means 10)
     *
     * @param string        $file   File.
     * @param integer       $size   Size.
     * @param YiiImageColor $color  Color.
     *
     * @return YiiImageFont
     */
    public function font($file, $size, YiiImageColor $color)
    {
        return $this->driver->font($file, $size, $color);
    }

}
