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
 * Base bahavior for YiiImageDrawer.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiImageDrawerBehavior extends CBehavior
{

    public function events()
    {
        return array(
            YiiImageDrawerEvents::onAfterDrawArc       => 'afterDrawArc',
            YiiImageDrawerEvents::onAfterDrawChord     => 'afterDrawChord',
            YiiImageDrawerEvents::onAfterDrawDot       => 'afterDrawDot',
            YiiImageDrawerEvents::onAfterDrawEllipse   => 'afterDrawEllipse',
            YiiImageDrawerEvents::onAfterDrawLine      => 'afterDrawLine',
            YiiImageDrawerEvents::onAfterDrawPieSlice  => 'afterDrawPieSlice',
            YiiImageDrawerEvents::onAfterDrawPolygon   => 'afterDrawPolygon',
            YiiImageDrawerEvents::onAfterDrawText      => 'afterDrawText',
            YiiImageDrawerEvents::onBeforeDrawArc      => 'beforeDrawArc',
            YiiImageDrawerEvents::onBeforeDrawChord    => 'beforeDrawChord',
            YiiImageDrawerEvents::onBeforeDrawDot      => 'beforeDrawDot',
            YiiImageDrawerEvents::onBeforeDrawEllipse  => 'beforeDrawEllipse',
            YiiImageDrawerEvents::onBeforeDrawLine     => 'beforeDrawLine',
            YiiImageDrawerEvents::onBeforeDrawPieSlice => 'beforeDrawPieSlice',
            YiiImageDrawerEvents::onBeforeDrawPolygon  => 'beforeDrawPolygon',
            YiiImageDrawerEvents::onBeforeDrawText     => 'beforeDrawText',
        );
    }

    /**
     * This event will be raised before drawing the arc.
     * 
     * @param YiiImageDrawerEventOnDrawArc $event 
     */
    protected function beforeDrawArc(YiiImageDrawerEventOnDrawArc $event)
    {
        
    }

    /**
     * This event will be raised after drawing the arc.
     *
     * @param YiiImageDrawerEventOnDrawArc $event 
     */
    protected function afterDrawArc(YiiImageDrawerEventOnDrawArc $event)
    {
        
    }

    /**
     * This event will be raised before drawing the chord.
     *
     * @param YiiImageDrawerEventOnDrawChord $event 
     */
    protected function beforeDrawChord(YiiImageDrawerEventOnDrawChord $event)
    {
        
    }

    /**
     * This event will be raised after drawing the chord.
     *
     * @param YiiImageDrawerEventOnDrawChord $event 
     */
    protected function afterDrawChord(YiiImageDrawerEventOnDrawChord $event)
    {
        
    }

    /**
     * This event will be raised before drawing the ellipse.
     *
     * @param YiiImageDrawerEventOnDrawEllipse $event 
     */
    protected function beforeDrawEllipse(YiiImageDrawerEventOnDrawEllipse $event)
    {
        
    }

    /**
     * This event will be raised after drawing the ellipse.
     *
     * @param YiiImageDrawerEventOnDrawEllipse $event 
     */
    protected function afterDrawEllipse(YiiImageDrawerEventOnDrawEllipse $event)
    {
        
    }

    /**
     * This event will be raised before drawing the pie slice.
     *
     * @param YiiImageDrawerEventOnDrawPieSlice $event 
     */
    protected function beforeDrawPieSlice(YiiImageDrawerEventOnDrawPieSlice $event)
    {
        
    }

    /**
     * This event will be raised after drawing the pie slice.
     *
     * @param YiiImageDrawerEventOnDrawPieSlice $event 
     */
    protected function afterDrawPieSlice(YiiImageDrawerEventOnDrawPieSlice $event)
    {
        
    }

    /**
     * This event will be raised before drawing the dot.
     *
     * @param YiiImageDrawerEventOnDrawDot $event 
     */
    protected function beforeDrawDot(YiiImageDrawerEventOnDrawDot $event)
    {
        
    }

    /**
     * This event will be raised after drawing the dot.
     *
     * @param YiiImageDrawerEventOnDrawDot $event 
     */
    protected function afterDrawDot(YiiImageDrawerEventOnDrawDot $event)
    {
        
    }

    /**
     * This event will be raised before drawing the polygon.
     *
     * @param YiiImageDrawerEventOnDrawPolygon $event 
     */
    protected function beforeDrawPolygon(YiiImageDrawerEventOnDrawPolygon $event)
    {
        
    }

    /**
     * This event will be raised after drawing the polygon.
     *
     * @param YiiImageDrawerEventOnDrawPolygon $event 
     */
    protected function afterDrawPolygon(YiiImageDrawerEventOnDrawPolygon $event)
    {
        
    }

    /**
     * This event will be raised before drawing the line.
     *
     * @param YiiImageDrawerEventOnDrawLine $event 
     */
    protected function beforeDrawLine(YiiImageDrawerEventOnDrawLine $event)
    {
        
    }

    /**
     * This event will be raised after drawing the line.
     *
     * @param YiiImageDrawerEventOnDrawLine $event 
     */
    protected function afterDrawLine(YiiImageDrawerEventOnDrawLine $event)
    {
        
    }

    /**
     * This event will be raised before drawing the text.
     *
     * @param YiiImageDrawerEventOnDrawText $event 
     */
    protected function beforeDrawText(YiiImageDrawerEventOnDrawText $event)
    {
        
    }

    /**
     * This event will be raised after drawing the text.
     *
     * @param YiiImageDrawerEventOnDrawText $event 
     */
    protected function afterDrawText(YiiImageDrawerEventOnDrawText $event)
    {
        
    }

}