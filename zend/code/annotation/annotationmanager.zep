/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Annotation;

use Zend\Code\Annotation\Parser\ParserInterface;
use Zend\EventManager\Event;
use Zend\EventManager\EventManager;
use Zend\EventManager\EventManagerAwareInterface;
use Zend\EventManager\EventManagerInterface;
use Zend\EventManager\ResponseCollection;

/**
 * Pluggable annotation manager
 *
 * Simply composes an EventManager. When createAnnotation() is called, it fires
 * off an event of the same name, passing it the resolved annotation class, the
 * annotation content, and the raw annotation string; the first listener to
 * return an object will halt execution of the event, and that object will be
 * returned as the annotation.
 */
class AnnotationManager implements EventManagerAwareInterface
{
    const EVENT_CREATE_ANNOTATION = "createAnnotation";

    /**
     * @var EventManagerInterface
     */
    protected events;

    /**
     * Set the event manager instance
     *
     * @param  EventManagerInterface $events
     * @return AnnotationManager
     */
    public function setEventManager(<EventManagerInterface> events) -> <AnnotationManager>
    {
        array identifiers;

        let identifiers = [__CLASS__, get_class(this)];
        events->setIdentifiers(identifiers);

        let this->events = events;

        return this;
    }

    /**
     * Retrieve event manager
     *
     * Lazy loads an instance if none registered.
     *
     * @return EventManagerInterface
     */
    public function getEventManager() -> <EventManagerInterface>
    {
        if this->events === null {
            thsi->setEventManager(new EventManager());
        }
        return this->events;
    }

    /**
     * Attach a parser to listen to the createAnnotation event
     *
     * @param  ParserInterface $parser
     * @return AnnotationManager
     */
    public function attach(<ParserInterface> parser) -> <AnnotationManager>
    {
        var events;
        array callback;

        let events = <EventManagerInterface> this->getEventManager();
        let callback = [parser, "onCreateAnnotation"];

        events->attach(self::EVENT_CREATE_ANNOTATION, callback);

        return this;
    }

    /**
     * Create Annotation
     *
     * @param  string[] $annotationData
     * @return false|\stdClass
     */
    public function createAnnotation(array! annotationData) -> object|boolean
    {
        var event, events, results, annotation;
        array params;

        let event = new Event();
        let params = [
            "class" : annotationData[0],
            "content" : annotationData[1],
            "raw" : annotationData[2]
        ];

        event->setName(self::EVENT_CREATE_ANNOTATION);
        event->setTarget(this);
        event->setParams(params);

        let events = <EventManagerInterface> this->getEventManager();
        let results = <ResponseCollection> events->trigger(event, [this, "_eventCallaback"]);
        let annotation = results->last();

        if typeof annotation == "object" {
            return annotation;
        }
        return false;
    }

    private function _eventCallaback(var v) -> boolean
    {
        return typeof v == "object";
    }
}
