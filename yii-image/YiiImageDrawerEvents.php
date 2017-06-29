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
 * Name of events for the image drawer.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiImageDrawerEvents extends CEnumerable
{
    /**
     * Name of the event, which will be called before the drawing arc.
     */
    const onBeforeDrawArc = 'onBeforeDrawArc';

    /**
     * Name of the event, which will be called before the drawing chord.
     */
    const onBeforeDrawChord = 'onBeforeDrawChord';

    /**
     * Name of the event, which will be called before the drawing ellipse.
     */
    const onBeforeDrawEllipse = 'onBeforeDrawEllipse';

    /**
     * Name of the event, which will be called before the drawing line.
     */
    const onBeforeDrawLine = 'onBeforeDrawLine';

    /**
     * Name of the event, which will be called before the drawing pie slice.
     */
    const onBeforeDrawPieSlice = 'onBeforeDrawPieSlice';

    /**
     * Name of the event, which will be called before the drawing dot.
     */
    const onBeforeDrawDot = 'onBeforeDrawDot';

    /**
     * Name of the event, which will be called before the drawing polygon.
     */
    const onBeforeDrawPolygon = 'onBeforeDrawPolygon';

    /**
     * Name of the event, which will be called before the drawing text.
     */
    const onBeforeDrawText = 'onBeforeDrawText';

    /**
     * Name of the event, which will be called after the drawing arc. 
     */
    const onAfterDrawArc = 'onAfterDrawArc';

    /**
     * Name of the event, which will be called after the drawing chord. 
     */
    const onAfterDrawChord = 'onAfterDrawChord';

    /**
     * Name of the event, which will be called after the drawing ellipse. 
     */
    const onAfterDrawEllipse = 'onAfterDrawEllipse';

    /**
     * Name of the event, which will be called after the drawing line. 
     */
    const onAfterDrawLine = 'onAfterDrawLine';

    /**
     * Name of the event, which will be called after the drawing pie slice. 
     */
    const onAfterDrawPieSlice = 'onAfterDrawPieSlice';

    /**
     * Name of the event, which will be called after the drawing dot. 
     */
    const onAfterDrawDot = 'onAfterDrawDot';

    /**
     * Name of the event, which will be called after the drawing polygon. 
     */
    const onAfterDrawPolygon = 'onAfterDrawPolygon';

    /**
     * Name of the event, which will be called after the drawing text. 
     */
    const onAfterDrawText = 'onAfterDrawText';

}