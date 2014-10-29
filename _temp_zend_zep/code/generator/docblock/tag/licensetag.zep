/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator\DocBlock\Tag;

use Zend\Code\Generator\AbstractGenerator;
use Zend\Code\Generator\DocBlock\TagManager;
use Zend\Code\Reflection\DocBlock\Tag\TagInterface as ReflectionTagInterface;

class LicenseTag extends AbstractGenerator implements TagInterface
{
    /**
     * @var string
     */
    protected url;

    /**
     * @var string
     */
    protected licenseName;

    /**
     * @param string $url
     * @param string $licenseName
     */
    public function __construct(string url = null, string licenseName = null)
    {
        if !empty url {
            this->setUrl(url);
        }
        if !empty licenseName {
            this->setLicenseName(licenseName);
        }
    }

    /**
     * @param ReflectionTagInterface $reflectionTag
     * @return ReturnTag
     * @deprecated Deprecated in 2.3. Use TagManager::createTagFromReflection() instead
     */
    public static function fromReflection(<ReflectionTagInterface> reflectionTag) -> <TagInterface>
    {
        var manager, tag;

        let manager = new TagManager();
        manager->initializeDefaultTags();

        let tag = <TagInterface> manager->createTagFromReflection(reflectionTag);

        return tag;
    }

    /**
     * @return string
     */
    public function getName() -> string
    {
        return "license";
    }

    /**
     * @param string $url
     * @return LicenseTag
     */
    public function setUrl(string url) -> <LicenseTag>
    {
        let this->url = url;
        return this;
    }

    /**
     * @return string
     */
    public function getUrl() -> string
    {
        return this->url;
    }

    /**
     * @param  string $name
     * @return LicenseTag
     */
    public function setLicenseName(string name) -> <LicenseTag>
    {
        let this->licenseName = name;

        return this;
    }

    /**
     * @return string
     */
    public function getLicenseName() -> string
    {
        return this->licenseName;
    }

    /**
     * @return string
     */
    public function generate() -> string
    {
        string output = "@license";

        if !empty this->url {
            let output = output . " " . this->url;
        }
        if !empty this->licenseName {
            let output = output . " " . this->licenseName;
        }

        return output;
    }

}
