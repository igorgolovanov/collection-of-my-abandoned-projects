/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

class FileGeneratorRegistry
{
    /**
     * @var array $fileCodeGenerators
     */
    private static fileCodeGenerators; // []

    /**
     * Registry for the Zend\Code package.
     *
     * @param  FileGenerator $fileCodeGenerator
     * @param  string $fileName
     * @throws RuntimeException
     */
    public static function registerFileCodeGenerator(<FileGenerator> fileCodeGenerator, string fileName = null)
    {

    }

}
