/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Scanner;

class FileScanner extends TokenArrayScanner implements ScannerInterface
{
    /**
     * @var string
     */
    protected file;

    /**
     * @param  string $file
     * @param  null|AnnotationManager $annotationManager
     * @throws Exception\InvalidArgumentException
     */
    public function __construct(string file, annotationManager = null)
    {

    }

    /**
     * @return string
     */
    public function getFile() -> string
    {

    }

}
