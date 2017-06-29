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
 * @property array $coordinates Coordinates.
 * @property-read YiiImageColor $color Color.
 * @property boolean $fill Fill.
 */
class YiiImageDrawerEventOnDrawPolygon extends YiiImageDrawerEvent
{

    /**
     * Coordinates.
     * 
     * @var array 
     */
    private $_coordinates;

    /**
     * Color.
     * 
     * @var YiiImageColor
     */
    private $_color;

    /**
     * Fill.
     * 
     * @var boolean
     */
    private $_fill;

    /**
     * Constructor.
     * 
     * @param array $coordinates Coordinates.
     * @param YiiImageColor $color Color.
     * @param boolean $fill Fill.
     * @param YiiImageDrawer $drawer
     * @param type $sender
     * @param type $params 
     */
    public function __construct(array $coordinates, YiiImageColor $color, $fill,
                                YiiImageDrawer $drawer, $sender = null,
                                $params = null)
    {
        $this->fill = $fill;
        $this->coordinates = $coordinates;
        $this->_color = $color;

        parent::__construct($drawer, $sender, $params);
    }

    /**
     * Set coordinates.
     * 
     * @param array $coordinates 
     */
    public function setCoordinates(array $coordinates)
    {
        $this->_coordinates = $coordinates;
    }

    /**
     * Get coordinates.
     * 
     * @return array
     */
    public function getCoordinates()
    {
        return $this->_coordinates;
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

    /**
     * Get fill.
     * 
     * @return boolean
     */
    public function getFill()
    {
        return $this->_fill;
    }

    /**
     * Set fill.
     * 
     * @param boolean $fill
     */
    public function setFill($fill)
    {
        $this->_fill = (boolean) $fill;
    }

}

