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
 * Base class for image drawer.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * 
 * @property-write array                $behaviors              Behaviors.
 * @property-write string|array|Closure $onBeforeDrawArc        Event {@link YiiImageDrawer::onBeforeDrawArc}
 * @property-write string|array|Closure $onBeforeDrawChord      Event {@link YiiImageDrawer::onBeforeDrawChord}
 * @property-write string|array|Closure $onBeforeDrawEllipse    Event {@link YiiImageDrawer::onBeforeDrawEllipse}
 * @property-write string|array|Closure $onBeforeDrawLine       Event {@link YiiImageDrawer::onBeforeDrawLine}
 * @property-write string|array|Closure $onBeforeDrawPieSlice   Event {@link YiiImageDrawer::onBeforeDrawPieSlice}
 * @property-write string|array|Closure $onBeforeDrawDot        Event {@link YiiImageDrawer::onBeforeDrawDot}
 * @property-write string|array|Closure $onBeforeDrawPolygon    Event {@link YiiImageDrawer::onBeforeDrawPolygon}
 * @property-write string|array|Closure $onBeforeDrawText       Event {@link YiiImageDrawer::onBeforeDrawText}
 * @property-write string|array|Closure $onAfterDrawArc         Event {@link YiiImageDrawer::onAfterDrawArc}
 * @property-write string|array|Closure $onAfterDrawChord       Event {@link YiiImageDrawer::onAfterDrawChord}
 * @property-write string|array|Closure $onAfterDrawEllipse     Event {@link YiiImageDrawer::onAfterDrawEllipse}
 * @property-write string|array|Closure $onAfterDrawLine        Event {@link YiiImageDrawer::onAfterDrawLine}
 * @property-write string|array|Closure $onAfterDrawPieSlice    Event {@link YiiImageDrawer::onAfterDrawPieSlice}
 * @property-write string|array|Closure $onAfterDrawDot         Event {@link YiiImageDrawer::onAfterDrawDot}
 * @property-write string|array|Closure $onAfterDrawPolygon     Event {@link YiiImageDrawer::onAfterDrawPolygon}
 * @property-write string|array|Closure $onAfterDrawText        Event {@link YiiImageDrawer::onAfterDrawText}
 * 
 * @property-read CList $onBeforeDrawArc        Event {@link YiiImageDrawer::onBeforeDrawArc}
 * @property-read CList $onBeforeDrawChord      Event {@link YiiImageDrawer::onBeforeDrawChord}
 * @property-read CList $onBeforeDrawEllipse    Event {@link YiiImageDrawer::onBeforeDrawEllipse}
 * @property-read CList $onBeforeDrawLine       Event {@link YiiImageDrawer::onBeforeDrawLine}
 * @property-read CList $onBeforeDrawPieSlice   Event {@link YiiImageDrawer::onBeforeDrawPieSlice}
 * @property-read CList $onBeforeDrawDot        Event {@link YiiImageDrawer::onBeforeDrawDot}
 * @property-read CList $onBeforeDrawPolygon    Event {@link YiiImageDrawer::onBeforeDrawPolygon}
 * @property-read CList $onBeforeDrawText       Event {@link YiiImageDrawer::onBeforeDrawText}
 * @property-read CList $onAfterDrawArc         Event {@link YiiImageDrawer::onAfterDrawArc}
 * @property-read CList $onAfterDrawChord       Event {@link YiiImageDrawer::onAfterDrawChord}
 * @property-read CList $onAfterDrawEllipse     Event {@link YiiImageDrawer::onAfterDrawEllipse}
 * @property-read CList $onAfterDrawLine        Event {@link YiiImageDrawer::onAfterDrawLine}
 * @property-read CList $onAfterDrawPieSlice    Event {@link YiiImageDrawer::onAfterDrawPieSlice}
 * @property-read CList $onAfterDrawDot         Event {@link YiiImageDrawer::onAfterDrawDot}
 * @property-read CList $onAfterDrawPolygon     Event {@link YiiImageDrawer::onAfterDrawPolygon}
 * @property-read CList $onAfterDrawText        Event {@link YiiImageDrawer::onAfterDrawText}
 */
abstract class YiiImageDrawer extends CComponent
{

    /**
     * Constructor. 
     */
    public function __construct()
    {
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
     * Draws an arc on a starting at a given x, y coordinates under a given
     * start and end angles
     *
     * @param YiiImagePoint $center
     * @param YiiImageBox   $size
     * @param integer       $start
     * @param integer       $end
     * @param YiiImageColor $color
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    abstract protected function drawArc(YiiImagePoint $center,
                                        YiiImageBox $size, $start, $end,
                                        YiiImageColor $color);

    /**
     * Same as arc, but also connects end points with a straight line
     *
     * @param YiiImagePoint $center
     * @param YiiImageBox   $size
     * @param integer       $start
     * @param integer       $end
     * @param YiiImageColor $color
     * @param boolean       $fill
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    abstract protected function drawChord(YiiImagePoint $center,
                                          YiiImageBox $size, $start, $end,
                                          YiiImageColor $color, $fill = false);

    /**
     * Draws and ellipse with center at the given x, y coordinates, and given
     * width and height
     *
     * @param YiiImagePoint $center
     * @param YiiImageBox   $size
     * @param YiiImageColor $color
     * @param boolean       $fill
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    abstract protected function drawEllipse(YiiImagePoint $center,
                                            YiiImageBox $size,
                                            YiiImageColor $color, $fill = false);

    /**
     * Draws a line from start(x, y) to end(x, y) coordinates
     *
     * @param YiiImagePoint $start
     * @param YiiImagePoint $end
     * @param YiiImageColor $color
     *
     * @return YiiImageDriwer
     */
    abstract protected function drawLine(YiiImagePoint $start,
                                         YiiImagePoint $end,
                                         YiiImageColor $color);

    /**
     * Same as arc, but connects end points and the center
     *
     * @param YiiImagePoint $center
     * @param YiiImageBox   $size
     * @param integer       $start
     * @param integer       $end
     * @param YiiImageColor $color
     * @param boolean       $fill
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    abstract protected function drawPieSlice(YiiImagePoint $center,
                                             YiiImageBox $size, $start, $end,
                                             YiiImageColor $color, $fill = false);

    /**
     * Places a one pixel point at specific coordinates and fills it with
     * specified color
     *
     * @param YiiImagePoint $position
     * @param YiiImageColor $color
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    abstract protected function drawDot(YiiImagePoint $position,
                                        YiiImageColor $color);

    /**
     * Draws a polygon using array of x, y coordinates. Must contain at least
     * three coordinates
     *
     * @param array         $coordinates
     * @param YiiImageColor $color
     * @param Boolean       $fill
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    abstract protected function drawPolygon(array $coordinates,
                                            YiiImageColor $color, $fill = false);

    /**
     * Annotates image with specified text at a given position starting on the
     * top left of the final text box
     *
     * The rotation is done CW
     *
     * @param string        $string
     * @param YiiImageFont  $font
     * @param YiiImagePoint $position
     * @param integer       $angle
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    abstract protected function drawText($string, YiiImageFont $font,
                                         YiiImagePoint $position, $angle = 0);

    /**
     * Draws an arc on a starting at a given x, y coordinates under a given
     * start and end angles
     *
     * @param YiiImagePoint $center
     * @param YiiImageBox   $size
     * @param integer       $start
     * @param integer       $end
     * @param YiiImageColor $color
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    final public function arc(YiiImagePoint $center, YiiImageBox $size, $start,
                              $end, YiiImageColor $color)
    {
        if ($this->hasEventHandler(YiiImageDrawerEvents::onBeforeDrawArc)) {
            $event = new YiiImageDrawerEventOnDrawArc($center, $size, $start, $end, $color, $this, $this);
            $this->onBeforeDrawArc($event);

            $start = $event->start;
            $end   = $event->end;
        }
        $this->drawArc($center, $size, $start, $end, $color);

        if ($this->hasEventHandler(YiiImageDrawerEvents::onAfterDrawArc)) {
            $this->onAfterDrawArc(new YiiImageDrawerEventOnDrawArc($center, $size, $start, $end, $color, $this, $this));
        }
        return $this;
    }

    /**
     * Same as arc, but also connects end points with a straight line
     *
     * @param YiiImagePoint $center
     * @param YiiImageBox   $size
     * @param integer       $start
     * @param integer       $end
     * @param YiiImageColor $color
     * @param boolean       $fill
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    final public function chord(YiiImagePoint $center, YiiImageBox $size,
                                $start, $end, YiiImageColor $color,
                                $fill = false)
    {
        if ($this->hasEventHandler(YiiImageDrawerEvents::onBeforeDrawChord)) {
            $event = new YiiImageDrawerEventOnDrawChord($center, $size, $start, $end, $color, $fill, $this, $this);
            $this->onBeforeDrawChord($event);

            $start = $event->start;
            $end   = $event->end;
            $fill  = $event->fill;
        }
        $this->drawChord($center, $size, $start, $end, $color, $fill);

        if ($this->hasEventHandler(YiiImageDrawerEvents::onAfterDrawChord)) {
            $this->onAfterDrawChord(new YiiImageDrawerEventOnDrawChord($center, $size, $start, $end, $color, $fill, $this, $this));
        }
        return $this;
    }

    /**
     * Draws and ellipse with center at the given x, y coordinates, and given
     * width and height
     *
     * @param YiiImagePoint $center
     * @param YiiImageBox   $size
     * @param YiiImageColor $color
     * @param boolean       $fill
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    final public function ellipse(YiiImagePoint $center, YiiImageBox $size,
                                  YiiImageColor $color, $fill = false)
    {
        if ($this->hasEventHandler(YiiImageDrawerEvents::onBeforeDrawEllipse)) {
            $event = new YiiImageDrawerEventOnDrawEllipse($center, $size, $color, $fill, $this, $this);
            $this->onBeforeDrawEllipse($event);

            $fill = $event->fill;
        }
        $this->drawEllipse($center, $size, $color, $fill);

        if ($this->hasEventHandler(YiiImageDrawerEvents::onAfterDrawEllipse)) {
            $this->onAfterDrawEllipse(new YiiImageDrawerEventOnDrawEllipse($center, $size, $color, $fill, $this, $this));
        }
        return $this;
    }

    /**
     * Draws a line from start(x, y) to end(x, y) coordinates
     *
     * @param YiiImagePoint $start
     * @param YiiImagePoint $end
     * @param YiiImageColor $color
     *
     * @return YiiImageDriwer
     */
    final public function line(YiiImagePoint $start, YiiImagePoint $end,
                               YiiImageColor $color)
    {
        if ($this->hasEventHandler(YiiImageDrawerEvents::onBeforeDrawLine)) {
            $this->onBeforeDrawLine(new YiiImageDrawerEventOnDrawLine($start, $end, $color, $this, $this));
        }
        $this->drawLine($start, $end, $color);

        if ($this->hasEventHandler(YiiImageDrawerEvents::onAfterDrawLine)) {
            $this->onAfterDrawLine(new YiiImageDrawerEventOnDrawLine($start, $end, $color, $this, $this));
        }
        return $this;
    }

    /**
     * Same as arc, but connects end points and the center
     *
     * @param YiiImagePoint $center
     * @param YiiImageBox   $size
     * @param integer                      $start
     * @param integer                      $end
     * @param YiiImageColor          $color
     * @param Boolean                      $fill
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    final public function pieSlice(YiiImagePoint $center, YiiImageBox $size,
                                   $start, $end, YiiImageColor $color,
                                   $fill = false)
    {
        if ($this->hasEventHandler(YiiImageDrawerEvents::onBeforeDrawPieSlice)) {
            $event = new YiiImageDrawerEventOnDrawPieSlice($center, $size, $start, $end, $color, $fill, $this, $this);
            $this->onBeforeDrawPieSlice($event);

            $start = $event->start;
            $end   = $event->end;
            $fill  = $event->fill;
        }
        $this->drawPieSlice($center, $size, $start, $end, $color, $fill);

        if ($this->hasEventHandler(YiiImageDrawerEvents::onAfterDrawPieSlice)) {
            $this->onAfterDrawPieSlice(new YiiImageDrawerEventOnDrawPieSlice($center, $size, $start, $end, $color, $fill, $this, $this));
        }
        return $this;
    }

    /**
     * Places a one pixel point at specific coordinates and fills it with
     * specified color
     *
     * @param YiiImagePoint $position
     * @param YiiImageColor $color
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    final public function dot(YiiImagePoint $position, YiiImageColor $color)
    {
        if ($this->hasEventHandler(YiiImageDrawerEvents::onBeforeDrawDot)) {
            $this->onBeforeDrawDot(new YiiImageDrawerEventOnDrawDot($position, $color, $this, $this));
        }
        $this->drawDot($position, $color);

        if ($this->hasEventHandler(YiiImageDrawerEvents::onAfterDrawDot)) {
            $this->onAfterDrawDot(new YiiImageDrawerEventOnDrawDot($position, $color, $this, $this));
        }
        return $this;
    }

    /**
     * Draws a polygon using array of x, y coordinates. Must contain at least
     * three coordinates
     *
     * @param array $coordinates
     * @param YiiImageColor $color
     * @param boolean $fill
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    final public function polygon(array $coordinates, YiiImageColor $color,
                                  $fill = false)
    {
        if ($this->hasEventHandler(YiiImageDrawerEvents::onBeforeDrawPolygon)) {
            $event = new YiiImageDrawerEventOnDrawPolygon($coordinates, $color, $fill, $this, $this);
            $this->onBeforeDrawPolygon($event);

            $fill        = $event->fill;
            $coordinates = $event->coordinates;
        }
        $this->drawPolygon($coordinates, $color, $fill);

        if ($this->hasEventHandler(YiiImageDrawerEvents::onAfterDrawPolygon)) {
            $this->onAfterDrawPolygon(new YiiImageDrawerEventOnDrawPolygon($coordinates, $color, $fill, $this, $this));
        }
        return $this;
    }

    /**
     * Annotates image with specified text at a given position starting on the
     * top left of the final text box
     *
     * The rotation is done CW
     *
     * @param string                       $string
     * @param YiiImageFont   $font
     * @param YiiImagePoint $position
     * @param integer                      $angle
     *
     * @throws RuntimeException
     *
     * @return YiiImageDrawer
     */
    final public function text($string, YiiImageFont $font,
                               YiiImagePoint $position, $angle = 0)
    {
        if ($this->hasEventHandler(YiiImageDrawerEvents::onBeforeDrawText)) {
            $event = new YiiImageDrawerEventOnDrawText($string, $font, $position, $angle, $this, $this);
            $this->onBeforeDrawText($event);

            $string = $event->text;
            $angle  = $event->angle;
        }
        $this->drawText($string, $font, $position, $angle);

        if ($this->hasEventHandler(YiiImageDrawerEvents::onAfterDrawText)) {
            $this->onAfterDrawText(new YiiImageDrawerEventOnDrawText($string, $font, $position, $angle, $this, $this));
        }
        return $this;
    }

    /**
     * This event will be raised before drawing the arc.
     * 
     * @param YiiImageDrawerEventOnDrawArc $event 
     */
    final public function onBeforeDrawArc(YiiImageDrawerEventOnDrawArc $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onBeforeDrawArc, $event);
    }

    /**
     * This event will be raised after drawing the arc.
     *
     * @param YiiImageDrawerEventOnDrawArc $event 
     */
    final public function onAfterDrawArc(YiiImageDrawerEventOnDrawArc $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onAfterDrawArc, $event);
    }

    /**
     * This event will be raised before drawing the chord.
     *
     * @param YiiImageDrawerEventOnDrawChord $event 
     */
    final public function onBeforeDrawChord(YiiImageDrawerEventOnDrawChord $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onBeforeDrawChord, $event);
    }

    /**
     * This event will be raised after drawing the chord.
     *
     * @param YiiImageDrawerEventOnDrawChord $event 
     */
    final public function onAfterDrawChord(YiiImageDrawerEventOnDrawChord $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onAfterDrawChord, $event);
    }

    /**
     * This event will be raised before drawing the ellipse.
     *
     * @param YiiImageDrawerEventOnDrawEllipse $event 
     */
    final public function onBeforeDrawEllipse(YiiImageDrawerEventOnDrawEllipse $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onBeforeDrawEllipse, $event);
    }

    /**
     * This event will be raised after drawing the ellipse.
     *
     * @param YiiImageDrawerEventOnDrawEllipse $event 
     */
    final public function onAfterDrawEllipse(YiiImageDrawerEventOnDrawEllipse $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onAfterDrawEllipse, $event);
    }

    /**
     * This event will be raised before drawing the pie slice.
     *
     * @param YiiImageDrawerEventOnDrawPieSlice $event 
     */
    final public function onBeforeDrawPieSlice(YiiImageDrawerEventOnDrawPieSlice $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onBeforeDrawPieSlice, $event);
    }

    /**
     * This event will be raised after drawing the pie slice.
     *
     * @param YiiImageDrawerEventOnDrawPieSlice $event 
     */
    final public function onAfterDrawPieSlice(YiiImageDrawerEventOnDrawPieSlice $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onAfterDrawPieSlice, $event);
    }

    /**
     * This event will be raised before drawing the dot.
     *
     * @param YiiImageDrawerEventOnDrawDot $event 
     */
    final public function onBeforeDrawDot(YiiImageDrawerEventOnDrawDot $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onBeforeDrawDot, $event);
    }

    /**
     * This event will be raised after drawing the dot.
     *
     * @param YiiImageDrawerEventOnDrawDot $event 
     */
    final public function onAfterDrawDot(YiiImageDrawerEventOnDrawDot $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onAfterDrawDot, $event);
    }

    /**
     * This event will be raised before drawing the polygon.
     *
     * @param YiiImageDrawerEventOnDrawPolygon $event 
     */
    final public function onBeforeDrawPolygon(YiiImageDrawerEventOnDrawPolygon $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onBeforeDrawPolygon, $event);
    }

    /**
     * This event will be raised after drawing the polygon.
     *
     * @param YiiImageDrawerEventOnDrawPolygon $event 
     */
    final public function onAfterDrawPolygon(YiiImageDrawerEventOnDrawPolygon $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onAfterDrawPolygon, $event);
    }

    /**
     * This event will be raised before drawing the line.
     *
     * @param YiiImageDrawerEventOnDrawLine $event 
     */
    final public function onBeforeDrawLine(YiiImageDrawerEventOnDrawLine $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onBeforeDrawLine, $event);
    }

    /**
     * This event will be raised after drawing the line.
     *
     * @param YiiImageDrawerEventOnDrawLine $event 
     */
    final public function onAfterDrawLine(YiiImageDrawerEventOnDrawLine $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onAfterDrawLine, $event);
    }

    /**
     * This event will be raised before drawing the text.
     *
     * @param YiiImageDrawerEventOnDrawText $event 
     */
    final public function onBeforeDrawText(YiiImageDrawerEventOnDrawText $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onBeforeDrawText, $event);
    }

    /**
     * This event will be raised after drawing the text.
     *
     * @param YiiImageDrawerEventOnDrawText $event 
     */
    final public function onAfterDrawText(YiiImageDrawerEventOnDrawText $event)
    {
        $this->raiseEvent(YiiImageDrawerEvents::onAfterDrawText, $event);
    }

}