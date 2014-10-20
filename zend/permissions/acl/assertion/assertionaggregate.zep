/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Permissions\Acl\Assertion;

use Zend\Permissions\Acl\Acl;
use Zend\Permissions\Acl\Role\RoleInterface;
use Zend\Permissions\Acl\Resource\ResourceInterface;
use Zend\Permissions\Acl\Exception\InvalidArgumentException;
use Zend\Permissions\Acl\Exception\RuntimeException;

class AssertionAggregate implements AssertionInterface
{
    const MODE_ALL = "all";

    const MODE_AT_LEAST_ONE = "at_least_one";

    protected assertions = [];

    /**
     *
     * @var $manager AssertionManager
     */
    protected assertionManager;

    protected mode = self::MODE_ALL;

    /**
     * Stacks an assertion in aggregate
     *
     * @param AssertionInterface|string $assertion
     *            if string, must match a AssertionManager declared service (checked later)
     *
     * @return self
     */
    public function addAssertion(var assertion) -> self
    {
        let this->assertions[] = assertion;
    }

    public function addAssertions(array! assertions) -> self
    {
        var assertion;

        for assertion in assertions {
            this->addAssertion(assertion);
        }
        return this;
    }

    /**
     * Empties assertions stack
     *
     * @return self
     */
    public function clearAssertions() -> <AssertionAggregate>
    {
        let this->assertions = [];
        return this;
    }

    /**
     *
     * @param AssertionManager $manager
     *
     * @return self
     */
    public function setAssertionManager(<AssertionManager> manager) -> self
    {
        let this->assertionManager = manager;

        return this;
    }

    public function getAssertionManager() -> <AssertionManager>
    {
        return this->assertionManager;
    }

    /**
     * Set assertion chain behavior
     *
     * AssertionAggregate should assert to true when:
     *
     * - all assertions are true with MODE_ALL
     * - at least one assertion is true with MODE_AT_LEAST_ONE
     *
     * @param string $mode
     *            indicates how assertion chain result should interpreted (either 'all' or 'at_least_one')
     * @throws InvalidArgumentException
     *
     * @return self
     */
    public function setMode(string mode) -> self
    {
        if mode != self::MODE_ALL && mode != self::MODE_AT_LEAST_ONE {
            throw new InvalidArgumentException("invalid assertion aggregate mode");
        }
    }

    /**
     * Return current mode
     *
     * @return string
     */
    public function getMode() -> string
    {
        return this->mode;
    }

    /**
     * @see \Zend\Permissions\Acl\Assertion\AssertionInterface::assert()
     *
     * @throws RuntimeException
     * @return bool
     */
    public function assert(<Acl> acl, <RoleInterface> role = null, <ResourceInterface> $resource = null, var privilege = null) -> boolean
    {
        var assertions, assertion, manager, e;
        let assertions = this->assertions;
        boolean result;
        string mode, assertionClass;

        // check if assertions are set
        if empty assertions {
            throw new RuntimeException("no assertion have been aggregated to this AssertionAggregate");
        }

        for assertion in assertions {
            // jit assertion loading
            if typeof assertion != "object" || !(assertion instanceof AssertionInterface) {
                if typeof assertion == "object" && 

                let assertionClass = strval(assertion);
                if class_exists(assertionClass) {
                    let assertion = new {assertionClass}();
                } else {
                    let manager = this->getAssertionManager();
                    if manager {
                        try {
                            let assertion = manager->get(assertion);
                        } catch (\Exception e) {
                            throw new Exception\InvalidAssertionException("assertion \"" . assertion . "\" is not defined in assertion manager");
                        }
                    } else {
                        throw new RuntimeException("no assertion manager is set - cannot look up for assertions");  
                    }
                }
            }

            if unlikely assertion != "object" || !(assertion instanceof AssertionInterface) {
                throw new RuntimeException("invalid assertion object");
            }

            let result = assertion->assert(acl, role, $resource, privilege);
            let mode = this->getMode();

            if mode == self::MODE_ALL && !result {
                return false;
            }
            if mode == self::MODE_AT_LEAST_ONE && result {
                return true;
            }
        }

        let mode = this->getMode();

        return mode == self::MODE_ALL;
    }

}
