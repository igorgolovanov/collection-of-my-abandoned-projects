Introduction of YiiImage
========================

Object-Event-Oriented Yii extension for Image manipulation 

Installation and Configuring 
============================

  1. Extract those files to folder "extention/yii-image"
  2. Set configuration in main config.

``` php

<?php
// protected/configs/main.php

return array(

    'import' => array(
        /**
        
        ...
        
        */
        'ext.yii-image.*',
    ),

    'components' => array(
        /**
        
        ...
        
        */
        'image' => array(
            'class' => 'YiiImage',
            'activeDriverName' => 'gd', // avaliable: gd, imagick, gimagick
        ),
    ),
);

```

  3. Available driver names:

    * gd
    * imagick
    * gmagick

Using
=====

``` php

<?php

$img = Yii::app()->image->create(new YiiImageBox(800, 600));

$drawer = $img->draw();
$drawer->onBeforeDrawPolygon = function (YiiImageDrawerEventOnDrawPolygon $event)
{
    var_dump($event->color);
};
$drawer->line(new YiiImagePoint(3, 3), new YiiImagePoint(50, 50), new YiiImageColor('#00FF00'))
       ->ellipse(new YiiImagePoint(300, 300), new YiiImageBox(200, 400), new YiiImageColor('#FF0000'))
       ->polygon(array(
            new YiiImagePoint(200, 400),
            new YiiImagePoint(300, 400),
            new YiiImagePoint(300, 410),
            new YiiImagePoint(200, 430),
            new YiiImagePoint(210, 330),
        ), new YiiImageColor('#0000FF'));

$img->save($path, array('format' => 'png'));

```

Events and Behaviors
====================

The names of all available event can be found in the following classes:
    
    * YiiImageDriverEvents
    * YiiImageProviderEvents
    * YiiImageDrawerEvents
    * YiiImageFontEvents

Events can be attached as:

  1. Closure/function/method 

``` php

<?php

$img = Yii::app()->image->create(new YiiImageBox(800, 600));

/**
 * Closure.
 */
$img->onBeforeSave = function(YiiImageProviderEventOnSave $event)
{
    if(file_exists($event->savePath)) {
        throw new Exception(sprintf('File "%s" already exists!', $event->savePath));
    }
};

/**
 * Object.
 */
$model = new UserModel();
$img->onBeforeSave = array($model, 'beforeSaveImageCheckFreeSpace');

```

  2. Behaviors.

To expand the existing base classes available behaviors:

    * YiiImageDriverBehavior
    * YiiImageProviderBehavior
    * YiiImageDrawerBehavior
    * YiiImageFontBehavior 
