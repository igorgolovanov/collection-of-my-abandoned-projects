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
 * Image drawer which based on Gmagick extension.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiImageGmagickDrawer extends YiiImageDrawer
        implements YiiImageGmagickAware
{

    /**
     * @var Gmagick
     */
    private $_gmagick;

    /**
     * @param Gmagick $gmagick
     */
    public function __construct(Gmagick $gmagick)
    {
        $this->_gmagick = $gmagick;
    }

    /**
     * Gmagick.
     * 
     * @return Gmagick
     */
    public function getGmagick()
    {
        return $this->_gmagick;
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
    protected function drawArc(YiiImagePoint $center, YiiImageBox $size, $start,
                               $end, YiiImageColor $color)
    {
        $x      = $center->x;
        $y      = $center->y;
        $width  = $size->width;
        $height = $size->height;

        try {
            $pixel = $this->createGmagickColor($color);
            $arc   = new GmagickDraw();

            $arc->setstrokecolor($pixel);
            $arc->setstrokewidth(1);
            $arc->setfillcolor('transparent');
            $arc->arc(
                    $x - $width / 2, $y - $height / 2, $x + $width / 2,
                    $y + $height / 2, $start, $end
            );

            $this->gmagick->drawImage($arc);

            $pixel = null;
            $arc   = null;
        } catch (GmagickException $e) {
            throw new RuntimeException(
                    'Draw arc operation failed', $e->getCode(), $e
            );
        }
        return $this;
    }

    /**
     * {@inheritDoc}
     */
    protected function drawChord(YiiImagePoint $center, YiiImageBox $size,
                                 $start, $end, YiiImageColor $color,
                                 $fill = false)
    {
        $x      = $center->x;
        $y      = $center->y;
        $width  = $size->width;
        $height = $size->height;

        try {
            $pixel = $this->createGmagickColor($color);
            $chord = new GmagickDraw();

            $chord->setstrokecolor($pixel);
            $chord->setstrokewidth(1);

            if ($fill) {
                $chord->setfillcolor($pixel);
            } else {
                $x1 = round($x + $width / 2 * cos(deg2rad($start)));
                $y1 = round($y + $height / 2 * sin(deg2rad($start)));
                $x2 = round($x + $width / 2 * cos(deg2rad($end)));
                $y2 = round($y + $height / 2 * sin(deg2rad($end)));

                $this->doLine(new YiiImagePoint($x1, $y1),
                              new YiiImagePoint($x2, $y2), $color);

                $chord->setfillcolor('transparent');
            }

            $chord->arc($x - $width / 2, $y - $height / 2, $x + $width / 2,
                        $y + $height / 2, $start, $end);

            $this->gmagick->drawImage($chord);

            $pixel = null;
            $chord = null;
        } catch (GmagickException $e) {
            throw new RuntimeException(
                    'Draw chord operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc}
     */
    protected function drawEllipse(YiiImagePoint $center, YiiImageBox $size,
                                   YiiImageColor $color, $fill = false)
    {
        try {
            $pixel   = $this->createGmagickColor($color);
            $ellipse = new GmagickDraw();

            $ellipse->setstrokecolor($pixel);
            $ellipse->setstrokewidth(1);

            if ($fill) {
                $ellipse->setfillcolor($pixel);
            } else {
                $ellipse->setfillcolor('transparent');
            }

            $ellipse->ellipse(
                    $center->x, $center->y, $size->width / 2, $size->height / 2,
                    0, 360
            );

            $this->gmagick->drawImage($ellipse);

            $pixel   = null;
            $ellipse = null;
        } catch (GmagickException $e) {
            throw new RuntimeException(
                    'Draw ellipse operation failed', $e->getCode(), $e
            );
        }
        return $this;
    }

    /**
     * {@inheritDoc}
     */
    protected function drawLine(YiiImagePoint $start, YiiImagePoint $end,
                                YiiImageColor $color)
    {
        try {
            $pixel = $this->createGmagickColor($color);
            $line  = new GmagickDraw();

            $line->setstrokecolor($pixel);
            $line->setstrokewidth(1);
            $line->line(
                    $start->x, $start->y, $end->x, $end->y
            );

            $this->gmagick->drawImage($line);

            $pixel = null;
            $line  = null;
        } catch (GmagickException $e) {
            throw new RuntimeException(
                    'Draw line operation failed', $e->getCode(), $e
            );
        }

        return $this;
    }

    /**
     * {@inheritDoc}
     */
    protected function drawPieSlice(YiiImagePoint $center, YiiImageBox $size,
                                    $start, $end, YiiImageColor $color,
                                    $fill = false)
    {
        $width  = $size->width;
        $height = $size->height;

        $x1 = round($center->x + $width / 2 * cos(deg2rad($start)));
        $y1 = round($center->y + $height / 2 * sin(deg2rad($start)));
        $x2 = round($center->x + $width / 2 * cos(deg2rad($end)));
        $y2 = round($center->y + $height / 2 * sin(deg2rad($end)));

        if ($fill) {
            $this->doChord($center, $size, $start, $end, $color, true);
            $this->doPolygon(
                    array(
                $center,
                new YiiImagePoint($x1, $y1),
                new YiiImagePoint($x2, $y2),
                    ), $color, true
            );
        } else {
            $this->doArc($center, $size, $start, $end, $color);
            $this->doLine($center, new YiiImagePoint($x1, $y1), $color);
            $this->doLine($center, new YiiImagePoint($x2, $y2), $color);
        }

        return $this;
    }

    /**
     * {@inheritDoc}
     */
    protected function drawDot(YiiImagePoint $position, YiiImageColor $color)
    {
        try {
            $pixel = $this->createGmagickColor($color);
            $point = new GmagickDraw();

            $point->setfillcolor($pixel);
            $point->point($position->x, $position->y);

            $this->gmagick->drawimage($point);

            $pixel = null;
            $point = null;
        } catch (GmagickException $e) {
            throw new RuntimeException(
                    'Draw point operation failed', $e->getCode(), $e
            );
        }
        return $this;
    }

    /**
     * {@inheritDoc}
     */
    protected function drawPolygon(array $coordinates, YiiImageColor $color,
                                   $fill = false)
    {
        if (count($coordinates) < 3) {
            throw new InvalidArgumentException(sprintf(
                            'Polygon must consist of at least 3 coordinates, %d given',
                            count($coordinates)
            ));
        }

        $points = array();
        foreach ($coordinates as $point) {
            $points[] = array(
                'x' => $point->x,
                'y' => $point->y
            );
        }

        try {
            $pixel   = $this->createGmagickColor($color);
            $polygon = new GmagickDraw();

            $polygon->setstrokecolor($pixel);
            $polygon->setstrokewidth(1);

            if ($fill) {
                $polygon->setfillcolor($pixel);
            } else {
                $polygon->setfillcolor('transparent');
            }

            $polygon->polygon($points);

            $this->gmagick->drawImage($polygon);

            $pixel   = null;
            $polygon = null;
        } catch (GmagickException $e) {
            throw new RuntimeException(
                    'Draw polygon operation failed', $e->getCode(), $e
            );
        }
        return $this;
    }

    /**
     * {@inheritDoc}
     */
    protected function drawText($string, YiiImageFont $font,
                                YiiImagePoint $position, $angle = 0)
    {
        try {
            $pixel = $this->createGmagickColor($font->color);
            $text  = new GmagickDraw();

            $text->setfont($font->file);
            $text->setfontsize($font->size);
            $text->setfillcolor($pixel);

            $info = $this->gmagick->queryfontmetrics($text, $string);
            $rad  = deg2rad($angle);
            $cos  = cos($rad);
            $sin  = sin($rad);

            $x1 = round(0 * $cos - 0 * $sin);
            $x2 = round($info['textWidth'] * $cos - $info['textHeight'] * $sin);
            $y1 = round(0 * $sin + 0 * $cos);
            $y2 = round($info['textWidth'] * $sin + $info['textHeight'] * $cos);

            $xdiff = 0 - min($x1, $x2);
            $ydiff = 0 - min($y1, $y2);

            $this->gmagick->annotateimage(
                    $text, $position->getX() + $x1 + $xdiff,
                    $position->getY() + $y2 + $ydiff, $angle, $string
            );

            $pixel = null;
            $text  = null;
        } catch (GmagickException $e) {
            throw new RuntimeException(
                    'Draw text operation failed', $e->getCode(), $e
            );
        }
    }

    /**
     * Gets specifically formatted color string from Color instance
     *
     * @param YiiImageColor $color
     *
     * @return string
     */
    private function createGmagickColor(YiiImageColor $color)
    {
        if (!$color->isOpaque) {
            throw new InvalidArgumentException('Gmagick doesn\'t support transparency');
        }

        $pixel = new GmagickPixel((string) $color);

        $pixel->setColorValue(
                Gmagick::COLOR_OPACITY,
                number_format(abs(round($color->alpha / 100, 1)), 1)
        );

        return $pixel;
    }

}
