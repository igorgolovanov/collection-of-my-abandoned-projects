/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

abstract class AbstractMemberGenerator extends AbstractGenerator implements GeneratorInterface
{
    const FLAG_ABSTRACT = 1;

    const FLAG_FINAL = 2;

    const FLAG_STATIC = 4;

    const FLAG_PUBLIC = 16;

    const FLAG_PROTECTED = 32;

    const FLAG_PRIVATE = 64;

    const VISIBILITY_PUBLIC = "public";

    const VISIBILITY_PROTECTED = "protected";

    const VISIBILITY_PRIVATE = "private";

    const LINE_FEED = "
";

    /**
     * @var DocBlockGenerator
     */
    protected docBlock;

    /**
     * @var string
     */
    protected name;

    /**
     * @var int
     */
    protected flags = 16;

    /**
     * @param  int|array $flags
     * @return AbstractMemberGenerator
     */
    public function setFlags(var flags) -> <AbstractMemberGenerator>
    {

    }

    /**
     * @param  int $flag
     * @return AbstractMemberGenerator
     */
    public function addFlag(int flag) -> <AbstractMemberGenerator>
    {

    }

    /**
     * @param  int $flag
     * @return AbstractMemberGenerator
     */
    public function removeFlag(int flag) -> <AbstractMemberGenerator>
    {

    }

    /**
     * @param  bool $isAbstract
     * @return AbstractMemberGenerator
     */
    public function setAbstract(boolean isAbstract) -> <AbstractMemberGenerator>
    {

    }

    /**
     * @return bool
     */
    public function isAbstract() -> boolean
    {

    }

    /**
     * @param  bool $isFinal
     * @return AbstractMemberGenerator
     */
    public function setFinal(boolean isFinal) -> <AbstractMemberGenerator>
    {

    }

    /**
     * @return bool
     */
    public function isFinal() -> boolean
    {

    }

    /**
     * @param  bool $isStatic
     * @return AbstractMemberGenerator
     */
    public function setStatic(boolean isStatic) -> <AbstractMemberGenerator>
    {

    }

    /**
     * @return bool
     */
    public function isStatic() -> boolean
    {

    }

    /**
     * @param  string $visibility
     * @return AbstractMemberGenerator
     */
    public function setVisibility(string visibility) -> <AbstractMemberGenerator>
    {

    }

    /**
     * @return string
     */
    public function getVisibility() -> string
    {

    }

    /**
     * @param  string $name
     * @return AbstractMemberGenerator
     */
    public function setName(string name) -> <AbstractMemberGenerator>
    {

    }

    /**
     * @return string
     */
    public function getName() -> string
    {

    }

    /**
     * @param  DocBlockGenerator|string $docBlock
     * @throws Exception\InvalidArgumentException
     * @return AbstractMemberGenerator
     */
    public function setDocBlock(var docBlock) -> <AbstractMemberGenerator>
    {

    }

    /**
     * @return DocBlockGenerator
     */
    public function getDocBlock() -> <DocBlockGenerator>
    {

    }

}
