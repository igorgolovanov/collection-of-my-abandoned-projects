/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\ProgressBar\Upload;

/**
 * Interface for Upload Progress Handlers
 */
interface UploadHandlerInterface
{
    /**
     * @param  string $id
     * @return array
     */
    public function getProgress(string id) -> array;

}
