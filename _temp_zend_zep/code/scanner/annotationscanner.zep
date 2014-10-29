/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class AnnotationScanner extends \Zend\Code\Annotation\AnnotationCollection implements \IteratorAggregate, \Traversable, \ArrayAccess, \Serializable, \Countable, ScannerInterface
{
    const STD_PROP_LIST = 1;

    const ARRAY_AS_PROPS = 2;

    /**
     * @var bool
     */
    protected isScanned = false;

    /**
     * @var string
     */
    protected docComment;

    /**
     * @var NameInformation
     */
    protected nameInformation;

    /**
     * @var AnnotationManager
     */
    protected annotationManager;

    /**
     * @var array
     */
    protected annotations; // []

    /**
     * @param  AnnotationManager $annotationManager
     * @param  string $docComment
     * @param  NameInformation $nameInformation
     * @return AnnotationScanner
     */
    public function __construct(annotationManager, string docComment, nameInformation = null) -> <AnnotationScanner>
    {

    }

    /**
     * @param NameInformation $nameInformation
     */
    public function setNameInformation(nameInformation)
    {

    }

    /**
     * @param  array $tokens
     */
    protected function scan(array! tokens)
    {

    }

    /**
     * @return array
     */
    protected function tokenize() -> array
    {

    }

}
