/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class DocBlockScanner implements ScannerInterface
{
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
     * @var string
     */
    protected shortDescription;

    /**
     * @var string
     */
    protected longDescription = "";

    /**
     * @var array
     */
    protected tags; // []

    /**
     * @var array
     */
    protected annotations; // []

    /**
     * @param  string $docComment
     * @param null|NameInformation $nameInformation
     */
    public function __construct(string docComment, nameInformation = null)
    {

    }

    /**
     * @return string
     */
    public function getShortDescription() -> string
    {

    }

    /**
     * @return string
     */
    public function getLongDescription() -> string
    {

    }

    /**
     * @return array
     */
    public function getTags() -> array
    {

    }

    /**
     * @return array
     */
    public function getAnnotations() -> array
    {

    }

    /**
     * @return void
     */
    protected function scan() -> void
    {

    }

    /**
     * @return array
     */
    protected function tokenize() -> array
    {

    }

}
