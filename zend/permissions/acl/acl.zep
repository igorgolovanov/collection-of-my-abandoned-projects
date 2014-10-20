/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Permissions\Acl;

class Acl implements AclInterface
{
    /**
     * Rule type: allow
     */
    const TYPE_ALLOW = "TYPE_ALLOW";

    /**
     * Rule type: deny
     */
    const TYPE_DENY = "TYPE_DENY";

    /**
     * Rule operation: add
     */
    const OP_ADD = "OP_ADD";

    /**
     * Rule operation: remove
     */
    const OP_REMOVE = "OP_REMOVE";

    /**
     * Role registry
     *
     * @var Role\Registry
     */
    protected roleRegistry;

    /**
     * Resource tree
     *
     * @var array
     */
    protected resources = [];

    /**
     * @var Role\RoleInterface
     */
    protected isAllowedRole;

    /**
     * @var Resource
     */
    protected isAllowedResource;

    /**
     * @var string
     */
    protected isAllowedPrivilege;

    /**
     * ACL rules; whitelist (deny everything to all) by default
     *
     * @var array
     */
    protected rules = []; // ["allResources": ["allRoles": ["allPrivileges": ["type": "TYPE_DENY", "assert": null], "byPrivilegeId": []], "byRoleId": []], "byResourceId": []]

    /**
     * Adds a Role having an identifier unique to the registry
     *
     * The $parents parameter may be a reference to, or the string identifier for,
     * a Role existing in the registry, or $parents may be passed as an array of
     * these - mixing string identifiers and objects is ok - to indicate the Roles
     * from which the newly added Role will directly inherit.
     *
     * In order to resolve potential ambiguities with conflicting rules inherited
     * from different parents, the most recently added parent takes precedence over
     * parents that were previously added. In other words, the first parent added
     * will have the least priority, and the last parent added will have the
     * highest priority.
     *
     * @param  Role\RoleInterface|string       $role
     * @param  Role\RoleInterface|string|array $parents
     * @throws Exception\InvalidArgumentException
     * @return Acl Provides a fluent interface
     */
    public function addRole(var role, var parents = null) -> self
    {
        var registry;

        if typeof role == "string" {
            let role = new Role\GenericRole(role);
        } else {
            if unlikely !(role instanceof Role\RoleInterface) {
                throw new Exception\InvalidArgumentException(
                    "addRole() expects $role to be of type Zend\Permissions\Acl\Role\RoleInterface"
                );
            }
        }

        let registry = <Role\Registry> this->getRoleRegistry();

        registry->add(role, parents);

        return this;
    }

    /**
     * Returns the identified Role
     *
     * The $role parameter can either be a Role or Role identifier.
     *
     * @param  Role\RoleInterface|string $role
     * @return Role\RoleInterface
     */
    public function getRole(var role) -> <Role\RoleInterface>
    {
        var registry, role;

        let registry = <Role\Registry> this->getRoleRegistry();
        let role = registry->get(role);

        return role;
    }

    /**
     * Returns true if and only if the Role exists in the registry
     *
     * The $role parameter can either be a Role or a Role identifier.
     *
     * @param  Role\RoleInterface|string $role
     * @return bool
     */
    public function hasRole(var role) -> boolean
    {
        var registry;

        let registry = <Role\Registry> this->getRoleRegistry();

        return registry->has(role);
    }

    /**
     * Returns true if and only if $role inherits from $inherit
     *
     * Both parameters may be either a Role or a Role identifier. If
     * $onlyParents is true, then $role must inherit directly from
     * $inherit in order to return true. By default, this method looks
     * through the entire inheritance DAG to determine whether $role
     * inherits from $inherit through its ancestor Roles.
     *
     * @param  Role\RoleInterface|string    $role
     * @param  Role\RoleInterface|string    $inherit
     * @param  bool                      $onlyParents
     * @return bool
     */
    public function inheritsRole(var role, var inherit, boolean onlyParents = false) -> boolean
    {
        var registry;
        
        let registry = <Role\Registry> this->getRoleRegistry();

        return registry->->inherits(role, inherit, onlyParents);
    }

    /**
     * Removes the Role from the registry
     *
     * The $role parameter can either be a Role or a Role identifier.
     *
     * @param  Role\RoleInterface|string $role
     * @return Acl Provides a fluent interface
     */
    public function removeRole(var role) -> self
    {
        var registry, roleIdCurrent, rules, byRoleId, byResourceId,
            resourceIdCurrent, visitor;
        string roleId;

        if role instanceof Role\RoleInterface {
            let roleId = role->getRoleId();
        } else {
            let roleId = role;
        }
        
        let registry = <Role\Registry> this->getRoleRegistry();
        registry->remove(role);

        if fetch byRoleId, this->rules["allResources"]["byRoleId"] {
            for roleIdCurrent, rules in byRoleId {
                if roleId === roleIdCurrent {
                    unset this->rules["allResources"]["byRoleId"][roleIdCurrent];
                }
            }
        }

        if fetch byResourceId, this->rules["byResourceId"] {
            for resourceIdCurrent, visitor in byResourceId {
                if fetch byRoleId, visitor["byRoleId"] {
                    for roleIdCurrent, rules in byRoleId {
                        if roleId === roleIdCurrent {
                            unset this->rules["byResourceId"][resourceIdCurrent]["byRoleId"][roleIdCurrent];
                        }
                    }
                }
            }
        }
        

        return this;
    }

    /**
     * Removes all Roles from the registry
     *
     * @return Acl Provides a fluent interface
     */
    public function removeRoleAll() -> self
    {
        var registry, roleIdCurrent, rules, resourceIdCurrent, visitor,
            byRoleId, byResourceId;

        let registry = <Role\Registry> this->getRoleRegistry();

        registry->removeAll();

        if fetch byRoleId, this->rules["allResources"]["byRoleId"] {
            for roleIdCurrent, rules in byRoleId {
                unset this->rules["allResources"]["byRoleId"][roleIdCurrent];
            }
        }

        if fetch byResourceId, this->rules["byResourceId"] {
            for resourceIdCurrent, visitor in byResourceId {
                if fetch byRoleId, visitor["byRoleId"] {
                    for roleIdCurrent, rules in byRoleId {
                        unset this->rules["byResourceId"][resourceIdCurrent]["byRoleId"][roleIdCurrent];
                    }
                }
            }
        }

        return this;
    }

    /**
     * Adds a Resource having an identifier unique to the ACL
     *
     * The $parent parameter may be a reference to, or the string identifier for,
     * the existing Resource from which the newly added Resource will inherit.
     *
     * @param  Resource\ResourceInterface|string $resource
     * @param  Resource\ResourceInterface|string $parent
     * @throws Exception\InvalidArgumentException
     * @return Acl Provides a fluent interface
     */
    public function addResource(var $resource, var parent = null) -> self
    {

    }

    /**
     * Returns the identified Resource
     *
     * The $resource parameter can either be a Resource or a Resource identifier.
     *
     * @param  Resource\ResourceInterface|string $resource
     * @throws Exception\InvalidArgumentException
     * @return Resource
     */
    public function getResource(var $resource) -> resource
    {
        string resourceId, exceptionMsg;

        if $resource instanceof Resource\ResourceInterface {
            let resourceId = $resource->getResourceId();
        } else {
            let resourceId = $resource;
        }

        if unlikely !this->hasResource($resource) {
            let exceptionMsg = "Resource '" . resourceId . "' not found";
            throw new Exception\InvalidArgumentException(exceptionMsg);
        }

        return this->resources[resourceId]["instance"];
    }

    /**
     * Returns true if and only if the Resource exists in the ACL
     *
     * The $resource parameter can either be a Resource or a Resource identifier.
     *
     * @param  Resource\ResourceInterface|string $resource
     * @return bool
     */
    public function hasResource(var $resource) -> boolean
    {
        string resourceId;

        if $resource instanceof Resource\ResourceInterface {
            let resourceId = $resource->getResourceId();
        } else {
            let resourceId = $resource;
        }

        return isset this->resources[resourceId];
    }

    /**
     * Returns true if and only if $resource inherits from $inherit
     *
     * Both parameters may be either a Resource or a Resource identifier. If
     * $onlyParent is true, then $resource must inherit directly from
     * $inherit in order to return true. By default, this method looks
     * through the entire inheritance tree to determine whether $resource
     * inherits from $inherit through its ancestor Resources.
     *
     * @param  Resource\ResourceInterface|string    $resource
     * @param  Resource\ResourceInterface|string    inherit
     * @param  bool                              $onlyParent
     * @throws Exception\InvalidArgumentException
     * @return bool
     */
    public function inheritsResource(var $resource, inherit, boolean onlyParent = false) -> boolean
    {

    }

    /**
     * Removes a Resource and all of its children
     *
     * The $resource parameter can either be a Resource or a Resource identifier.
     *
     * @param  Resource\ResourceInterface|string $resource
     * @throws Exception\InvalidArgumentException
     * @return Acl Provides a fluent interface
     */
    public function removeResource(var $resource) -> self
    {

    }

    /**
     * Removes all Resources
     *
     * @return Acl Provides a fluent interface
     */
    public function removeResourceAll() -> self
    {
        var resourceId, val, resourceIdCurrent, rules, byResourceId;

        if fetch byResourceId, this->rules["byResourceId"] {
            for resourceId, val in this->resources {
                for resourceIdCurrent, rules in byResourceId {
                    if resourceId === resourceIdCurrent {
                        unset this->rules["byResourceId"][resourceIdCurrent];
                    }
                }
            }
        }
        
        let this->resources = [];

        return this;
    }

    /**
     * Adds an "allow" rule to the ACL
     *
     * @param  Role\RoleInterface|string|array          $roles
     * @param  Resource\ResourceInterface|string|array  $resources
     * @param  string|array                             $privileges
     * @param  Assertion\AssertionInterface             $assert
     * @return Acl Provides a fluent interface
     */
    public function allow(var roles = null, var resources = null, var privileges = null, <Assertion\AssertionInterface> assert = null) -> self
    {
        return this->setRule(self::OP_ADD, self::TYPE_ALLOW, roles, resources, privileges, assert);
    }

    /**
     * Adds a "deny" rule to the ACL
     *
     * @param  Role\RoleInterface|string|array          $roles
     * @param  Resource\ResourceInterface|string|array  $resources
     * @param  string|array                             $privileges
     * @param  Assertion\AssertionInterface             $assert
     * @return Acl Provides a fluent interface
     */
    public function deny(var roles = null, var resources = null, var privileges = null, <Assertion\AssertionInterface> assert = null) -> self
    {
        return this->setRule(self::OP_ADD, self::TYPE_DENY, roles, resources, privileges, assert);
    }

    /**
     * Removes "allow" permissions from the ACL
     *
     * @param  Role\RoleInterface|string|array          $roles
     * @param  Resource\ResourceInterface|string|array  $resources
     * @param  string|array                             $privileges
     * @return Acl Provides a fluent interface
     */
    public function removeAllow(var roles = null, var resources = null, var privileges = null) -> self
    {
        return this->setRule(self::OP_REMOVE, self::TYPE_ALLOW, roles, $esources, privileges);
    }

    /**
     * Removes "deny" restrictions from the ACL
     *
     * @param  Role\RoleInterface|string|array         $roles
     * @param  Resource\ResourceInterface|string|array $resources
     * @param  string|array                            $privileges
     * @return Acl Provides a fluent interface
     */
    public function removeDeny(var roles = null, var resources = null, var privileges = null) -> self
    {
        return this->setRule(self::OP_REMOVE, self::TYPE_DENY, roles, resources, privileges);
    }

    /**
     * Performs operations on ACL rules
     *
     * The $operation parameter may be either OP_ADD or OP_REMOVE, depending on whether the
     * user wants to add or remove a rule, respectively:
     *
     * OP_ADD specifics:
     *
     *      A rule is added that would allow one or more Roles access to [certain $privileges
     *      upon] the specified Resource(s).
     *
     * OP_REMOVE specifics:
     *
     *      The rule is removed only in the context of the given Roles, Resources, and privileges.
     *      Existing rules to which the remove operation does not apply would remain in the
     *      ACL.
     *
     * The $type parameter may be either TYPE_ALLOW or TYPE_DENY, depending on whether the
     * rule is intended to allow or deny permission, respectively.
     *
     * The $roles and $resources parameters may be references to, or the string identifiers for,
     * existing Resources/Roles, or they may be passed as arrays of these - mixing string identifiers
     * and objects is ok - to indicate the Resources and Roles to which the rule applies. If either
     * $roles or $resources is null, then the rule applies to all Roles or all Resources, respectively.
     * Both may be null in order to work with the default rule of the ACL.
     *
     * The $privileges parameter may be used to further specify that the rule applies only
     * to certain privileges upon the Resource(s) in question. This may be specified to be a single
     * privilege with a string, and multiple privileges may be specified as an array of strings.
     *
     * If $assert is provided, then its assert() method must return true in order for
     * the rule to apply. If $assert is provided with $roles, $resources, and $privileges all
     * equal to null, then a rule having a type of:
     *
     *      TYPE_ALLOW will imply a type of TYPE_DENY, and
     *
     *      TYPE_DENY will imply a type of TYPE_ALLOW
     *
     * when the rule's assertion fails. This is because the ACL needs to provide expected
     * behavior when an assertion upon the default ACL rule fails.
     *
     * @param  string                                   $operation
     * @param  string                                   $type
     * @param  Role\RoleInterface|string|array          $roles
     * @param  Resource\ResourceInterface|string|array  $resources
     * @param  string|array                             $privileges
     * @param  Assertion\AssertionInterface             $assert
     * @throws Exception\InvalidArgumentException
     * @return Acl Provides a fluent interface
     */
    public function setRule(string operation, string type, var roles = null, var resources = null, var privileges = null, <Assertion\AssertionInterface> assert = null) -> self
    {

    }

    /**
     * Returns all child resources from the given resource.
     *
     * @param  Resource\ResourceInterface|string    $resource
     * @return Resource\ResourceInterface[]
     */
    protected function getChildResources(var $resource) -> array
    {

    }

    /**
     * Returns true if and only if the Role has access to the Resource
     *
     * The $role and $resource parameters may be references to, or the string identifiers for,
     * an existing Resource and Role combination.
     *
     * If either $role or $resource is null, then the query applies to all Roles or all Resources,
     * respectively. Both may be null to query whether the ACL has a "blacklist" rule
     * (allow everything to all). By default, Zend\Permissions\Acl creates a "whitelist" rule (deny
     * everything to all), and this method would return false unless this default has
     * been overridden (i.e., by executing $acl->allow()).
     *
     * If a $privilege is not provided, then this method returns false if and only if the
     * Role is denied access to at least one privilege upon the Resource. In other words, this
     * method returns true if and only if the Role is allowed all privileges on the Resource.
     *
     * This method checks Role inheritance using a depth-first traversal of the Role registry.
     * The highest priority parent (i.e., the parent most recently added) is checked first,
     * and its respective parents are checked similarly before the lower-priority parents of
     * the Role are checked.
     *
     * @param  Role\RoleInterface|string            $role
     * @param  Resource\ResourceInterface|string    $resource
     * @param  string                               $privilege
     * @return bool
     */
    public function isAllowed(var role = null, var $resource = null, string privilege = null) -> boolean
    {

    }

    /**
     * Returns the Role registry for this ACL
     *
     * If no Role registry has been created yet, a new default Role registry
     * is created and returned.
     *
     * @return Role\Registry
     */
    protected function getRoleRegistry() -> <Role\Registry>
    {
        if this->roleRegistry === null {
            let this->roleRegistry = new Role\Registry();
        }
        return this->roleRegistry;
    }

    /**
     * Performs a depth-first search of the Role DAG, starting at $role, in order to find a rule
     * allowing/denying $role access to all privileges upon $resource
     *
     * This method returns true if a rule is found and allows access. If a rule exists and denies access,
     * then this method returns false. If no applicable rule is found, then this method returns null.
     *
     * @param  Role\RoleInterface           $role
     * @param  Resource\ResourceInterface   $resource
     * @return bool|null
     */
    protected function roleDFSAllPrivileges(<Role\RoleInterface> role, <Resource\ResourceInterface> $resource = null) -> boolean
    {

    }

    /**
     * Visits an $role in order to look for a rule allowing/denying $role access to all privileges upon $resource
     *
     * This method returns true if a rule is found and allows access. If a rule exists and denies access,
     * then this method returns false. If no applicable rule is found, then this method returns null.
     *
     * This method is used by the internal depth-first search algorithm and may modify the DFS data structure.
     *
     * @param  Role\RoleInterface           $role
     * @param  Resource\ResourceInterface   $resource
     * @param  array                        $dfs
     * @return bool|null
     * @throws Exception\RuntimeException
     */
    protected function roleDFSVisitAllPrivileges(<Role\RoleInterface> role, <Resource\ResourceInterface> $resource = null, array dfs = null) -> boolean
    {

    }

    /**
     * Performs a depth-first search of the Role DAG, starting at $role, in order to find a rule
     * allowing/denying $role access to a $privilege upon $resource
     *
     * This method returns true if a rule is found and allows access. If a rule exists and denies access,
     * then this method returns false. If no applicable rule is found, then this method returns null.
     *
     * @param  Role\RoleInterface           $role
     * @param  Resource\ResourceInterface   $resource
     * @param  string                       $privilege
     * @return bool|null
     * @throws Exception\RuntimeException
     */
    protected function roleDFSOnePrivilege(<Role\RoleInterface> role, <Resource\ResourceInterface> $resource = null, string privilege = null) -> boolean
    {

    }

    /**
     * Visits an $role in order to look for a rule allowing/denying $role access to a $privilege upon $resource
     *
     * This method returns true if a rule is found and allows access. If a rule exists and denies access,
     * then this method returns false. If no applicable rule is found, then this method returns null.
     *
     * This method is used by the internal depth-first search algorithm and may modify the DFS data structure.
     *
     * @param  Role\RoleInterface           $role
     * @param  Resource\ResourceInterface   $resource
     * @param  string                       $privilege
     * @param  array                        $dfs
     * @return bool|null
     * @throws Exception\RuntimeException
     */
    protected function roleDFSVisitOnePrivilege(<Role\RoleInterface> role, <Resource\ResourceInterface> $resource = null, string privilege = null, array dfs = null) -> boolean
    {

    }

    /**
     * Returns the rule type associated with the specified Resource, Role, and privilege
     * combination.
     *
     * If a rule does not exist or its attached assertion fails, which means that
     * the rule is not applicable, then this method returns null. Otherwise, the
     * rule type applies and is returned as either TYPE_ALLOW or TYPE_DENY.
     *
     * If $resource or $role is null, then this means that the rule must apply to
     * all Resources or Roles, respectively.
     *
     * If $privilege is null, then the rule must apply to all privileges.
     *
     * If all three parameters are null, then the default ACL rule type is returned,
     * based on whether its assertion method passes.
     *
     * @param  null|Resource\ResourceInterface  $resource
     * @param  null|Role\RoleInterface          $role
     * @param  null|string                      $privilege
     * @return string|null
     */
    protected function getRuleType(<Resource\ResourceInterface> $resource = null, <Role\RoleInterface> role = null, string privilege = null) -> string
    {

    }

    /**
     * Returns the rules associated with a Resource and a Role, or null if no such rules exist
     *
     * If either $resource or $role is null, this means that the rules returned are for all Resources or all Roles,
     * respectively. Both can be null to return the default rule set for all Resources and all Roles.
     *
     * If the $create parameter is true, then a rule set is first created and then returned to the caller.
     *
     * @param  Resource\ResourceInterface $resource
     * @param  Role\RoleInterface         $role
     * @param  bool                    $create
     * @return array|null
     */
    protected function getRules(<Resource\ResourceInterface> $resource = null, <Role\RoleInterface> role = null, boolean create = false) -> array
    {

    }

    /**
     * @return array of registered roles
     */
    public function getRoles() -> array
    {
        var registry;
        array roles, names;

        let registry = <Role\Registry> this->getRoleRegistry();
        let roles = registry->getRoles();
        let names = array_keys(roles);

        return names;
    }

    /**
     * @return array of registered resources
     */
    public function getResources() -> array
    {
        array resources;

        let resources = array_keys(this->resources);

        return resources;
    }

}
