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
 * Image drawer which based on GD extension.
 * 
 * @author  Igor Golovanov <igor.golovanov@gmail.com>
 * 
 * @property-read resource $gdResource GD resource.
 */
class YiiImageGdDrawer extends YiiImageDrawer implements YiiImageGdAware
{

    /**
     * @var resource
     */
    private $_resource;

    /**
     * Constructs Drawer with a given gd image resource
     *
     * @param resource $resource
     */
    public function __construct($resource)
    {
        parent::__construct();

        if (!is_resource($resource)) {
            throw new RuntimeException('Resource image is not a resource.');
        }
        $this->_resource = $resource;
    }

    /**
     * Get GD resource.
     * 
     * @return resource
     */
    public function getGdResource()
    {
        return $this->_resource;
    }

    /**
     * {@inheritDoc}
     */
    protected function drawArc(YiiImagePoint $center, YiiImageBox $size, $start,
                               $end, YiiImageColor $color)
    {
        if (false === imagearc(
                        $this->gdResource, $center->x, $center->y, $size->width,
                        $size->height, $start, $end,
                        $this->createGdColor($color)
        )) {
            throw new RuntimeException('Draw arc operation failed');
        }
    }

    /**
     * {@inheritDoc}
     */
    protected function drawChord(YiiImagePoint $center, YiiImageBox $size,
                                 $start, $end, YiiImageColor $color,
                                 $fill = false)
    {
        if ($fill) {
            $style = IMG_ARC_CHORD;
        } else {
            $style = IMG_ARC_CHORD | IMG_ARC_NOFILL;
        }

        /**
         * This function doesn't work properly because of a bug in GD 
         */
        if (false === imagefilledarc(
                        $this->gdResource, $center->x, $center->y, $size->width,
                        $size->height, $start, $end,
                        $this->createGdColor($color), $style
        )) {
            throw new RuntimeException('Draw chord operation failed');
        }
    }

    /**
     * {@inheritDoc}
     */
    protected function drawEllipse(YiiImagePoint $center, YiiImageBox $size,
                                   YiiImageColor $color, $fill = false)
    {
        if ($fill) {
            $callback = 'imagefilledellipse';
        } else {
            $callback = 'imageellipse';
        }

        if (false === $callback(
                        $this->gdResource, $center->x, $center->y, $size->width,
                        $size->height, $this->createGdColor($color))
        ) {
            throw new RuntimeException('Draw ellipse operation failed');
        }
    }

    /**
     * {@inheritDoc}
     */
    protected function drawLine(YiiImagePoint $start, YiiImagePoint $end,
                                YiiImageColor $color)
    {
        if (false === imageline(
                        $this->gdResource, $start->x, $start->y, $end->x,
                        $end->y, $this->createGdColor($color)
        )) {
            throw new RuntimeException('Draw line operation failed');
        }
    }

    /**
     * {@inheritDoc}
     */
    protected function drawPieSlice(YiiImagePoint $center, YiiImageBox $size,
                                    $start, $end, YiiImageColor $color,
                                    $fill = false)
    {
        if ($fill) {
            $style = IMG_ARC_EDGED;
        } else {
            $style = IMG_ARC_EDGED | IMG_ARC_NOFILL;
        }

        if (false === imagefilledarc(
                        $this->gdResource, $center->x, $center->y, $size->width,
                        $size->h, $start, $end, $this->createGdColor($color),
                                                                     $style
        )) {
            throw new RuntimeException('Draw chord operation failed');
        }
    }

    /**
     * {@inheritDoc}
     */
    protected function drawDot(YiiImagePoint $position, YiiImageColor $color)
    {
        if (false === imagesetpixel(
                        $this->gdResource, $position->x, $position->y,
                        $this->createGdColor($color)
        )) {
            throw new RuntimeException('Draw point operation failed');
        }
    }

    /**
     * {@inheritDoc}
     */
    protected function drawPolygon(array $coordinates, YiiImageColor $color,
                                   $fill = false)
    {
        if (count($coordinates) < 3) {
            throw new InvalidArgumentException(sprintf(
                            'A polygon must consist of at least 3 points, %d given',
                            count($coordinates)
            ));
        }

        $points = array();

        foreach ($coordinates as $coordinate) {
            if (!$coordinate instanceof YiiImagePoint) {
                throw new InvalidArgumentException(sprintf(
                                'Each entry in coordinates array must be instance of ' .
                                'YiiImagePoint, %s given',
                                var_export($coordinate, true)
                ));
            }

            $points[] = $coordinate->x;
            $points[] = $coordinate->y;
        }

        if ($fill) {
            $callback = 'imagefilledpolygon';
        } else {
            $callback = 'imagepolygon';
        }

        if (false === $callback(
                        $this->gdResource, $points, count($coordinates),
                                                          $this->createGdColor($color)
        )) {
            throw new RuntimeException('Draw polygon operation failed');
        }
    }

    /**
     * {@inheritDoc}
     */
    protected function drawText($string, YiiImageFont $font,
                                YiiImagePoint $position, $angle = 0)
    {
        $angle    = -1 * $angle;
        $fontsize = $font->size;
        $fontfile = $font->file;
        $info     = imageftbbox($fontsize, $angle, $fontfile, $string);
        $xs       = array($info[0], $info[2], $info[4], $info[6]);
        $ys = array($info[1], $info[3], $info[5], $info[7]);

        $xdiff = 0 - min($xs) + $position->x;
        $ydiff = 0 - min($ys) + $position->y;

        foreach ($xs as &$x) {
            $x += $xdiff;
        }

        foreach ($ys as &$y) {
            $y += $ydiff;
        }

        if (false === imagealphablending($this->gdResource, true)) {
            throw new RuntimeException('Font mask operation failed');
        }

        if (false === imagefttext(
                        $this->gdResource, $fontsize, $angle, $xs[0], $ys[0],
                        $this->createGdColor($font->color), $fontfile, $string
        )) {
            throw new RuntimeException('Font mask operation failed');
        }

        if (false === imagealphablending($this->gdResource, false)) {
            throw new RuntimeException('Font mask operation failed');
        }
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
        $color = imagecolorallocatealpha(
                $this->gdResource, $color->red, $color->green, $color->blue,
                round(127 * $color->alpha / 100)
        );
        if (false === $color) {
            throw new RuntimeException(sprintf(
                            'Unable to allocate color "RGB(%s, %s, %s)" with ' .
                            'transparency of %d percent', $color->red,
                            $color->green, $color->blue, $color->alpha
            ));
        }

        return $color;
    }

}