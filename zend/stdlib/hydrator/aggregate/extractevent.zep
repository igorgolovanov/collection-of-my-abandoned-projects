/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib\Hydrator\Aggregate;

use Zend\EventManager\Event;

/**
 * Event triggered when the {@see \Zend\Stdlib\Hydrator\Aggregate\AggregateHydrator} extracts
 * data from an object
 */
class ExtractEvent extends Event
{
    const EVENT_EXTRACT = "extract";

    /**
     * {@inheritDoc}
     */
    protected name = self::EVENT_EXTRACT;

    /**
     * @var object
     */
    protected extractionObject;

    /**
     * @var array
     */
    protected extractedData; // []

    /**
     * @param object $target
     * @param object $extractionObject
     */
    public function __construct(object target, object extractionObject)
    {
        let this->target = target;
        let this->extractionObject = extractionObject;
    }

    /**
     * Retrieves the object from which data is extracted
     *
     * @return object
     */
    public function getExtractionObject() -> object
    {
        return this->extractionObject;
    }

    /**
     * @param object $extractionObject
     *
     * @return void
     */
    public function setExtractionObject(object extractionObject) -> void
    {
        let this->extractionObject = extractionObject;
    }

    /**
     * Retrieves the data that has been extracted
     *
     * @return array
     */
    public function getExtractedData() -> array
    {
        return this->extractedData;
    }

    /**
     * @param array $extractedData
     *
     * @return void
     */
    public function setExtractedData(array! extractedData) -> void
    {
        let this->extractedData = extractedData;
    }

    /**
     * Merge provided data with the extracted data
     *
     * @param array $additionalData
     *
     * @return void
     */
    public function mergeExtractedData(array! additionalData) -> void
    {
        array merged;

        let merged = array_merge(this->extractedData, additionalData);
        let this->extractedData = merged;
    }

}
