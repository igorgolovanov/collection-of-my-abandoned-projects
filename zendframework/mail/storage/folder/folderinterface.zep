/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Mail\Storage\Folder;

interface FolderInterface
{
    /**
     * get root folder or given folder
     *
     * @param string $rootFolder get folder structure for given folder, else root
     * @return FolderInterface root or wanted folder
     */
    public function getFolders(string rootFolder = null) -> <FolderInterface>;

    /**
     * select given folder
     *
     * folder must be selectable!
     *
     * @param FolderInterface|string $globalName global name of folder or instance for subfolder
     * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
     */
    public function selectFolder(var globalName);

    /**
     * get Zend\Mail\Storage\Folder instance for current folder
     *
     * @return FolderInterface instance of current folder
     * @throws \Zend\Mail\Storage\Exception\ExceptionInterface
     */
    public function getCurrentFolder() -> <FolderInterface>;

}
