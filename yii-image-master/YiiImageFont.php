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
 * @property-read   string          $file       File.
 * @property-read   integer         $size       Size.
 * @property-read   YiiImageColor   $color      Color.
 * @property-write  array           $behaviors  Behaviors.
 * 
 * @property-write string|array|Closure $onAfterBox     Event {@link YiiImageFont::onAfterBox}
 * @property-write string|array|Closure $onBeforeBox    Event {@link YiiImageFont::onAfterBox}
 * 
 * @property-read CList $onAfterBox     Event {@link YiiImageFont::onAfterBox}
 * @property-read CList $onBeforeBox    Event {@link YiiImageFont::onAfterBox}
 */
abstract class YiiImageFont extends CComponent
{

    /**
     * File.
     * 
     * @var string
     */
    private $_file;

    /**
     * Size.
     * 
     * @var integer
     */
    private $size;

    /**
     * Color.
     * 
     * @var YiiImageColor
     */
    private $color;

    /**
     * Constructs a font with specified $file, $size and $color
     *
     * The font size is to be specified in points (e.g. 10pt means 10)
     *
     * @param string              $file
     * @param integer             $size
     * @param YiiImageColor $color
     */
    public function __construct($file, $size, YiiImageColor $color)
    {
        $this->_file = $file;
        $this->_size = $size;
        $this->_color = $color;

        $this->attachBehaviors($this->defaultBehaviors());
    }

    /**
     * Default drawer's behaviors.
     * 
     * @return array
     */
    protected function defaultBehaviors()
    {
        return array();
    }

    /**
     * Set behaviors.
     * 
     * @see CComponent::attachBehaviors();
     * 
     * @param array $behaviors Behaviors.
     * 
     * @return YiiImageDrawer
     */
    public function setBehaviors(array $behaviors)
    {
        $this->attachBehaviors($behaviors);
    }

    /**
     * File.
     * 
     * @return string
     */
    final public function getFile()
    {
        return $this->_file;
    }

    /**
     * Size.
     * 
     * @return integer 
     */
    final public function getSize()
    {
        return $this->_size;
    }

    /**
     * Color.
     * 
     * @return YiiImageColor
     */
    final public function getColor()
    {
        return $this->_color;
    }

    /**
     * Gets YiiImageBox of font size on the image based on string and angle
     *
     * @param string  $string
     * @param integer $angle
     *
     * @return YiiImageBox
     */
    final public function box($string, $angle = 0)
    {
        $string = (string) $string;
        $angle  = (integer) $angle;

        if ($this->hasEventHandler(YiiImageFontEvents::onAfterFontBox)) {
            $event = new YiiImageFontEventOnBeforeBox($string, $angle, $this, $this);
            $this->onBeforeBox($event);

            $string = $event->text;
            $angle  = $event->angle;
        }
        $box    = $this->doBox($string, $angle);

        if ($this->hasEventHandler(YiiImageFontEvents::onBeforeFontBox)) {
            $this->onAfterBox(new YiiImageFontEventOnAfterBox($box, $string, $angle, $this, $this));
        }
        return $box;
    }

    /**
     * Gets YiiImageBox of font size on the image based on string and angle
     *
     * @param string  $string
     * @param integer $angle
     *
     * @return YiiImageBox
     */
    abstract protected function doBox($string, $angle);

    /**
     * This event will be raised after calculate font box.
     * 
     * @param YiiImageEventOnAfterFontBox $event 
     */
    final public function onAfterBox(YiiImageFontEventOnAfterBox $event)
    {
        $this->raiseEvent(YiiImageFontEvents::onAfterBox, $event);
    }

    /**
     * This event will be raised before calculate font box.
     * 
     * @param YiiImageEventOnBeforeFontBox $event 
     */
    final public function onBeforeBox(YiiImageFontEventOnBeforeBox $event)
    {
        $this->raiseEvent(YiiImageFontEvents::onBeforeBox, $event);
    }

}