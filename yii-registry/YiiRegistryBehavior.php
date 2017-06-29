<?php
/*
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This software consists of voluntary contributions made by many individuals
 * and is licensed under the LGPL. For more information, see
 * <http://www.yiilabs.com>.
 * 
 * @license     http://www.opensource.org/licenses/lgpl-license.php LGPL
 * @link        www.yiilabs.com
 * @copyright   Copyright (c) 2011 Yii Labs. (http://www.yiilabs.com)
 */

/**
 * YiiRegistry behavior class.
 * 
 * @license     http://www.opensource.org/licenses/lgpl-license.php LGPL
 * @link        www.yiilabs.com
 * @copyright   Copyright (c) 2011 Yii Labs. (http://www.yiilabs.com)
 * @author      Igor Golovanov <igor.golovanov@gmail.com>
 */
class YiiRegistryBehavior extends CBehavior
{
    /**
     * Declares events and the corresponding event handler methods.
     * The events are defined by the {@link owner} component, while the handler
     * methods by the behavior class. The handlers will be attached to the corresponding
     * events when the behavior is attached to the {@link owner} component; and they
     * will be detached from the events when the behavior is detached from the component.
     * 
     * @return array events (array keys) and the corresponding event handler methods (array values).
     */
    public function events()
    {
        return array(
            YiiRegistry::EVENT_BEFORE_GET       => 'beforeGet',   
            YiiRegistry::EVENT_BEFORE_SET       => 'beforeSet',   
            YiiRegistry::EVENT_BEFORE_EXISTS    => 'beforeExists',   
            YiiRegistry::EVENT_BEFORE_REVOME    => 'beforeRemove',   
            YiiRegistry::EVENT_BEFORE_TOARRAY   => 'beforeToArray',   
            YiiRegistry::EVENT_BEFORE_COUNT     => 'beforeCount',
            YiiRegistry::EVENT_AFTER_GET        => 'afterGet',   
            YiiRegistry::EVENT_AFTER_SET        => 'afterSet',   
            YiiRegistry::EVENT_AFTER_EXISTS     => 'afterExists',   
            YiiRegistry::EVENT_AFTER_REVOME     => 'afterRemove',   
            YiiRegistry::EVENT_AFTER_TOARRAY    => 'afterToArray',   
            YiiRegistry::EVENT_AFTER_COUNT      => 'afterCount',
        );
    }
    
    /**
     * This event is raised before value getted.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function beforeGet(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised before value setted.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function beforeSet(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised before exists.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function beforeExists(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised before romeve.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function beforeRemove(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised before to array.
     *
     * @param YiiRegistryEventArray $event Event.
     */
    public function beforeToArray(YiiRegistryEventArray $event)
    {}
    
    /**
     * This event is raised before count.
     *
     * @param YiiRegistryEventCount $event Event.
     */
    public function beforeCount(YiiRegistryEventCount $event)
    {}
    
    /**
     * This event is raised after value getted.
     *
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function afterGet(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised after value setted.
     *
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function afterSet(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised after exists.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function afterExists(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised after value removed.
     * 
     * @param YiiRegistryEventSetGet $event Event.
     */
    public function afterRemove(YiiRegistryEventSetGet $event)
    {}
    
    /**
     * This event is raised after to array.
     * 
     * @param YiiRegistryEventArray $event Event.
     */
    public function afterToArray(YiiRegistryEventArray $event)
    {}
    
    /**
     * This event is raised after count.
     * 
     * @param YiiRegistryEventCount $event Event.
     */
    public function afterCount(YiiRegistryEventCount $event)
    {}
}
