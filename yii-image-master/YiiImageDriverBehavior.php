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
 * @property-read YiiImageDriver $driver Driver.
 */
class YiiImageDriverBehavior extends CBehavior
{

    /**
     * Driver.
     * 
     * @return YiiImageDriver 
     */
    public function getDriver()
    {
        return $this->owner;
    }

    /**
     * Attaches the behavior object to the component.
     * The default implementation will set the {@link owner} property
     * and attach event handlers as declared in {@link events}.
     * Make sure you call the parent implementation if you override this method.
     * 
     * @param YiiImageDriver $owner the component that this behavior is to be attached to.
     */
    public function attach($owner)
    {
        if (!$owner instanceof YiiImageDriver) {
            throw new RuntimeException(sprintf(
                            'Behavior owner must YiiImageDriver, %s given.',
                            get_class($owner)));
        }
        parent::attach($owner);
    }

    /**
     * {@inheritDoc}
     */
    public function events()
    {
        return array(
        );
    }

}
