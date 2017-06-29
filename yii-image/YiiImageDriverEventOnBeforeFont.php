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
 * @property-read YiiImageColor $color Color.
 * @property string $file File.
 * @property integer $size Size. 
 */
class YiiImageDriverEventOnBeforeFont extends YiiImageDriverEvent
{

    /**
     * Font File.
     * 
     * @var string
     */
    private $_file;

    /**
     * Size.
     * 
     * @var integer
     */
    private $_size;

    /**
     * Color.
     *
     * @var YiiImageColor 
     */
    private $_color;

    public function __construct($file, $size, YiiImageColor $color,
                                YiiImageDriver $driver, $sender = null,
                                $params = null)
    {
        $this->file = $file;
        $this->size = $size;
        $this->_color = $color;

        parent::__construct($driver, $sender, $params);
    }

    /**
     * Get file.
     * 
     * @return string
     */
    public function getFile()
    {
        return $this->_file;
    }

    /**
     * Set file.
     * 
     * @param string $file File.
     * 
     * @return YiiImageDriverEventOnBeforeFont 
     */
    public function setFile($file)
    {
        $this->_file = CPropertyValue::ensureString($file);
        return $this;
    }

    /**
     * Get size.
     * 
     * @return ineteger 
     */
    public function getSize()
    {
        return $this->_size;
    }

    /**
     * Set size.
     * 
     * @param integer $size Size.
     * 
     * @return YiiImageDriverEventOnBeforeFont 
     */
    public function setSize($size)
    {
        $this->_size = CPropertyValue::ensureInteger($size);
        return $this;
    }

    /**
     * Color.
     * 
     * @return YiiImageColor 
     */
    public function getColor()
    {
        return $this->_color;
    }

}
