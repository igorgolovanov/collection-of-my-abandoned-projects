<?php
/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

require_once __DIR__ . '/../../vendor/autoload.php';

function zephir_keyworks()
{
    $keywords = array();
    $file = __DIR__ . '/keywords.php';
    if(file_exists($file)) {
        $keywords = include $file;
    }
    return (array) $keywords;
}

/**
 * Checks the word is zephir keyword.
 *
 * @param string $word
 * @return bool
 */
function zephir_is_keyword($word)
{
    static $keywords;
    if(null === $keywords) {
        $keywords = array_map('strtolower', zephir_keyworks());
        $keywords = array_combine($keywords, $keywords);
    }
    $word = trim($word);
    $word = strtolower($word);
    return array_key_exists($word, $keywords);
}

/**
 * Print array as zephir array.
 *
 * @param array $arr
 * @return string
 */
function zephir_print_array(array $arr, $level = 0)
{
    $isSimple = (bool) count(array_filter(array_keys($arr), 'is_int'));

    $content = '[';
    $first = true;
    foreach($arr as $k => $v) {
        if(!$first) {
            $content .= ", ";
        }
        $content .= "\n\t\t";
        for ($i=0;$i<$level; $i++) {
            $content .= "\t";
        }

        if (!$isSimple) {
            $content .= is_int($k) ? $k : "\"$k\"";
            $content .= ": ";
        }
        if (is_null($v)) {
            $content .= 'null';
        } elseif(is_bool($v)) {
            $content .= $v? 'true' : 'false';
        } elseif(is_numeric($v)) {
            $content .= $v;
        } elseif(is_string($v)) {
            $content .= "\"$v\"";
        } elseif (is_array($v)) {
            $content .= zephir_print_array($v, $level + 1);
        } else {
            $content .= "\"\"";
        }
        $first = false;
    }
    if (!$first) {
        $content .= "\n\t";
        for ($i=0;$i<$level; $i++) {
            $content .= "\t";
        }
    }
    $content .= ']';
    return $content;
}

/**
 * Print value as zephir value.
 * @param $value
 * @return string
 */
function zephir_print_value($value)
{
    if (is_null($value)) {
        $value = 'null';
    } elseif (is_bool($value)) {
        $value = $value ? 'true' : 'false';
    } elseif (is_string($value)) {
        $value = "\"$value\"";
    } elseif (is_array($value)) {
        $value = zephir_print_array($value);
    }
    return $value;
}

function zephir_get_class_relative_name($className, $namespace)
{
    $className = ltrim($className, '\\');
    $namespace = ltrim($namespace, '\\');
    if(0 === strripos($className, $namespace)) {
        return substr($className, strlen($namespace) + 1);
    }
    return '\\' . $className;
}

/**
 * Gets the zephir types of returns by method.
 *
 * @param ReflectionMethod $method
 * @return array
 */
function zephir_get_method_return_types(ReflectionMethod $method)
{
    $docBlock = new phpDocumentor\Reflection\DocBlock($method);
    $docBlockReturn = $docBlock->getTagsByName('return');

    if (!count($docBlockReturn)) {
        return array();
    }
    $docBlockReturn = reset($docBlockReturn);
    $docBlockType = $docBlockReturn->getType();

    if(empty($docBlockType)) {
        return array();
    }
    $types = preg_split('/\|/', $docBlockType);
    if(in_array('mixed', $types)) {
        return array();
    }
    $returnTypes = array();

    foreach($types as $type) {
        switch(strtolower($type)) {
            case 'int':
            case 'integer':
                $returnTypes[] = 'int';
                break;
            case 'bool':
            case 'boolean':
                $returnTypes[] = 'boolean';
                break;
            case 'array':
            case 'string':
            case 'object':
            case 'void':
            case 'float':
            case 'double': // @todo: check
            case 'resource':
            case 'null':
            case 'callable':
                $returnTypes[] = strtolower($type);
                break;
            case 'self':
                $returnTypes[] = '<' . zephir_get_class_relative_name($method->getDeclaringClass()->getName(), $method->getDeclaringClass()->getNamespaceName()) . '>';
                break;
            default:
                if (strripos($type, '[]')) {
                    $returnTypes[] = 'array';
                    break;
                }
                $className = ltrim($type, '\\');
                $className2 = '\\' . $method->getDeclaringClass()->getNamespaceName() . '\\' . $className;
                if (!class_exists($className2) && !interface_exists($className2)) {
                    $className = '\\' . $className;
                    if (class_exists($className) || interface_exists($className)) {
                        $returnTypes[] = '<' . zephir_get_class_relative_name($className, $method->getDeclaringClass()->getNamespaceName()) . '>';
                    }
                } else {
                    $returnTypes[] = '<' . zephir_get_class_relative_name($className2, $method->getDeclaringClass()->getNamespaceName()) . '>';
                }
                break;
        }
    }
    return array_unique($returnTypes);
}

/**
 * Gets the zephir types of parameter.
 *
 * @param ReflectionMethod $methodRef
 * @param int|string $parameter
 * @return array
 */
function zephir_get_method_parameter_types(ReflectionMethod $methodRef, $parameter = 0)
{
    if (is_integer($parameter)) {
        if ($parameter > $methodRef->getNumberOfParameters() - 1) {
            return array();
        }
        $paramsRefs = array_filter($methodRef->getParameters(), function ($v) use ($parameter) {
            return $v->getPosition() == $parameter;
        });
    } else {
        $paramsRefs = array_filter($methodRef->getParameters(), function ($v) use ($parameter) {
            return $v->getName() == $parameter;
        });
    }
    if (!count($paramsRefs)) {
        return array();
    }
    $parameterRef = reset($paramsRefs);

    if ($parameterRef->isArray()) {
        return array('array!');
    }
    $parameter = $parameterRef->getName();
    $parameterTypes = array();
    $methodDocBlock = new phpDocumentor\Reflection\DocBlock($methodRef);
    $parameterDocBlock = $methodDocBlock->getTagsByName('param');
    $parameterDocBlock = array_filter($parameterDocBlock, function ($docBlock) use ($parameter) {
        return in_array($docBlock->getVariableName(), [$parameter, '$' . $parameter]);
    });

    if (count($parameterDocBlock)) {
        $parameterDocBlock = reset($parameterDocBlock);
        $types = preg_split('/\|/', $parameterDocBlock->getType());
        if(in_array('mixed', $types)) {
            return array();
        }
        foreach($types as $type) {
            if (empty($type)) {
                continue;
            }
            switch(strtolower($type)) {
                case 'null':
                    break;
                case 'int':
                case 'integer':
                    $parameterTypes[] = 'int';
                    break;
                case 'true':
                case 'false':
                case 'bool':
                case 'boolean':
                    $parameterTypes[] = 'boolean';
                    break;
                case 'callable':
                    $parameterTypes[] = 'callable';
                    break;
                case 'array':
                case 'string':
                case 'object':
                case 'resource':
                    $parameterTypes[] = strtolower($type);
                    break;
                case 'float':
                case 'double':
                    $parameterTypes[] = 'float';
                    break;
                default:
                    if (strripos($type, '[]')) {
                        $parameterTypes[] = 'array';
                        break;
                    }
                    $className = ltrim($type, '\\');
                    $className2 = '\\' . $methodRef->getDeclaringClass()->getNamespaceName() . '\\' . $className;
                    if (!class_exists($className2) && !interface_exists($className2)) {
                        $className = '\\' . $className;
                        if (class_exists($className) || interface_exists($className)) {
                            $parameterTypes[] = '<' . $className . '>';
                        }
                    } else {
                        $parameterTypes[] = '<' . zephir_get_class_relative_name($className2, $methodRef->getDeclaringClass()->getNamespaceName()) . '>';
                    }
                    break;
            }
        }
    }

    if (!count($parameterTypes) && $parameterRef->isDefaultValueAvailable()) {
        if (!$parameterRef->isDefaultValueConstant()) {
            $value = $parameterRef->getDefaultValue();
            switch (gettype($value)) {
                case 'boolean':
                case 'integer':
                case 'string':
                case 'array':
                case 'object':
                case 'array':
                case 'resource':
                    $parameterTypes[] = gettype($value);
                    break;
                case 'float':
                case 'double':
                    $parameterTypes[] = 'float';
                    break;
            }
        }
    }
    $parameterTypes = array_unique($parameterTypes);

    if (count($parameterTypes) > 1) { // multi-types not supported yet
      return array('var');
    }
    return $parameterTypes;
}

function zephir_generate_property(ReflectionProperty $property)
{
    $content = "    ";
    if($doc = $property->getDocComment()) {
        $content .= "$doc\n    ";
    }
    if ($property->isPrivate()) {
        $content .= "private ";
    } elseif ($property->isProtected()) {
        $content .= "protected ";
    } else {
        $content .= "public ";
    }
    if ($property->isStatic()) {
        $content .= "static ";
    }
    $name = $property->getName();
    if(zephir_is_keyword($name)) {
        $name = '$' . $name;
    }
    $content .= $name;

    $defaults = $property->getDeclaringClass()->getDefaultProperties();
    if(isset($defaults[$property->getName()])) {
        // if (is_array($defaults[$property->getName()])) {
        //     // not supported yet
        //     $content .= '; // ' . zephir_print_value($defaults[$property->getName()]);
        // } else {
        //     $content .= ' = ' . zephir_print_value($defaults[$property->getName()]) . ';';
        // }
        $content .= ' = ' . zephir_print_value($defaults[$property->getName()]) . ';';
    } else {
        $content .= ';';
    }

    return $content;
}

function zephir_is_native_type($type)
{
    return in_array(strtolower($type), array(
        'null',
        'int',
        'integer',
        'bool',
        'boolean',
        'float',
        'double',
        'null',
        'string',
        'resource',
        'object',
        'array',
    ));
}

function zephir_convert_type($type)
{
    switch(strtolower($type)) {
        case 'int':
        case 'integer':
            return 'int';
        case 'bool':
        case 'boolean':
            return 'boolean';
        case 'array':
        case 'null':
        case 'float':
        case 'double':
        case 'string':
        case 'resource':
        case 'object':
        case 'array':
        case 'callable':
            return $type;
    }
    return false;
}

function zephir_convert_return_type($type)
{
    switch(strtolower($type)) {
        case 'void':
            return 'void';
    }
    return zephir_convert_type($type);
}

function zephir_is_all_native_types(array $types)
{
    $types = array_map('trim', $types);
    $typesFiltered = array_filter($types, 'zephir_is_native_type');

    return count($typesFiltered) === count($types);
}



function zephir_generate_method(ReflectionMethod $method)
{
    $content = "    ";
    if ($doc = $method->getDocComment()) {
        $content .= "$doc\n    ";
    }
    if (!$method->getDeclaringClass()->isInterface()) {
        if ($method->isFinal()) {
            $content .= "final ";
        } elseif ($method->isAbstract()) {
            $content .= "abstract ";
        }
        if ($method->isPrivate()) {
            $content .= "private ";
        } elseif ($method->isProtected()) {
            $content .= "protected ";
        } else {
            $content .= "public ";
        }
    } else {
        $content .= "public ";
    }

    if ($method->isStatic()) {
        $content .= "static ";
    }

    $name = $method->getName();
    if(zephir_is_keyword($name)) {
        $name = '$' . $name;
    }
    $content .= "function $name(";


    foreach($method->getParameters() as $parameter) {
        if ($parameter->getPosition() != 0) {
            $content .= ", ";
        }

        $parameterName = $parameter->getName();
        $parameterTypes  = zephir_get_method_parameter_types($method, $parameterName);

        if ($parameter->isDefaultValueAvailable()) {
            if ($parameter->isDefaultValueConstant()) {
                $paramDefault = $parameter->getDefaultValueConstantName();
            } else {
                $value = $parameter->getDefaultValue();
                $paramDefault = zephir_print_value($value);
            }
        }

        if(count($parameterTypes)) {
            $content .= implode('|', $parameterTypes) . ' ';
        }
        $content .= zephir_is_keyword($parameterName) ? '$' . $parameterName : $parameterName;
        if(isset($paramDefault)) {
            $content .= " = $paramDefault";
            unset($paramDefault);
        }
    }
    $content .= ")";

    $returnTypes = zephir_get_method_return_types($method);
    if(count($returnTypes)) {
        $content .= ' -> ' . implode('|', $returnTypes);
    }
    if($method->isAbstract()) {
        $content .= ";";
    } else {
        $content .= "\n    {\n\n    }";
    }
    return $content;
}

function zephir_generate_constant($name, $value)
{
    return "    const $name = " . zephir_print_value($value) . ';';
}

function zephir_is_interface_in_parent($currentClassOrInterface, $interface)
{
    $ref = ($currentClassOrInterface instanceof \ReflectionClass) ? $currentClassOrInterface : new \ReflectionClass($currentClassOrInterface);

    foreach ($ref->getInterfaces() as $i) {
        if ($i->isSubclassOf($interface)) {
            return true;
        }
    }
    if (!$ref->isInterface() && $refParent = $ref->getParentClass()) {
        return $refParent->isSubclassOf($interface);
    }
    return false;
}

function zephir_get_implements_interfaces($currentClassOrInterface)
{
    $ref = ($currentClassOrInterface instanceof \ReflectionClass) ? $currentClassOrInterface : new \ReflectionClass($currentClassOrInterface);
    $interfaces = [];
    foreach($ref->getInterfaces() as $i) {
        if (!zephir_is_interface_in_parent($ref->getName(), $i->getName())) {
            $interfaces[] = $i;
        }
    }
    return $interfaces;
}
