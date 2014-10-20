/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Code\Generator;

use Traversable;

abstract class AbstractGenerator implements GeneratorInterface
{
    const LINE_FEED = "\n";

    /**
     * @var bool
     */
    protected isSourceDirty = true;

    /**
     * @var int|string 4 spaces by default
     */
    protected indentation = "    ";

    /**
     * @var string
     */
    protected sourceContent;

    /**
     * @param  array $options
     */
    public function __construct(var options = [])
    {
        if !empty options {
            this->setOptions(options);
        }
    }

    /**
     * @param  bool $isSourceDirty
     * @return AbstractGenerator
     */
    public function setSourceDirty(boolean isSourceDirty = true) -> self
    {
        let this->isSourceDirty = isSourceDirty;

        return this;
    }

    /**
     * @return bool
     */
    public function isSourceDirty() -> boolean
    {
        return this->isSourceDirty;
    }

    /**
     * @param  string $indentation
     * @return AbstractGenerator
     */
    public function setIndentation(string indentation) -> self
    {
        let this->indentation = indentation;
        return this;
    }

    /**
     * @return string
     */
    public function getIndentation() -> string
    {
        return this->indentation;
    }

    /**
     * @param  string $sourceContent
     * @return AbstractGenerator
     */
    public function setSourceContent(string sourceContent) -> self
    {
        let this->sourceContent = sourceContent;

        return this;
    }

    /**
     * @return string
     */
    public function getSourceContent() -> string
    {
        return this->sourceContent;
    }

    /**
     * @param  array|Traversable $options
     * @throws Exception\InvalidArgumentException
     * @return AbstractGenerator
     */
    public function setOptions(var options) -> self
    {
        string type, exceptionMsg, methodName;
        var name, value;

        let type = typeof options;
        if unlikely type != "array" && !(options instanceof Traversable) {
            if type == "object" {
                let type = get_class(options);
            }
            let exceptionMsg = __METHOD__ . "expects an array or Traversable object; received \"" . type . "\"";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        for name, value in options {
            let methodName = "set" . name;
            if method_exists(this, methodName) {
                this->{methodName}(value);
            }
        }

        return this;
    }

}
