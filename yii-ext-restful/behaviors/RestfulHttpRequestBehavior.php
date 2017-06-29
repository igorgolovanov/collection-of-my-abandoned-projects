<?php

/**
 * @author Igor Golovanov <igor.golovanov@gmail.com>
 * @copyright (c) 2012, Igor Golovanov
 * @package yii-ext-restful
 * @category behaviors
 */
class RestfulHttpRequestBehavior extends CBehavior
{

    /**
     * PUT Params.
     * 
     * @var array
     */
    private $_putParams;

    /**
     * DELETE Params.
     * 
     * @var array
     */
    private $_deleteParams;

    /**
     * OPTIONS Params.
     * 
     * @var array
     */
    private $_optionsParams;

    /**
     * HEAD Params.
     * 
     * @var array
     */
    private $_headParams;

    /**
     * TRACE Params.
     * 
     * @var array
     */
    private $_traceParams;

    /**
     * CONNECT Params.
     * 
     * @var array
     */
    private $_connectParams;

    /**
     * PATCH Params.
     * 
     * @var array
     */
    private $_patchParams;

    /**
     * LINK Params.
     * 
     * @var array
     */
    private $_linkParams;

    /**
     * UNLINK Params.
     * 
     * @var array
     */
    private $_unlinkParams;

    /**
     * Returns whether this is a CONNECT request which was tunneled through POST.
     *
     * @return boolean
     */
    protected function getIsConnectViaPostRequest()
    {
        return isset($_POST['_method']) && !strcasecmp($_POST['_method'],
                                                       'CONNECT');
    }

    /**
     * Returns whether this is a CONNECT request which was tunneled through POST.
     *
     * @return boolean
     */
    protected function getIsPatchViaPostRequest()
    {
        return isset($_POST['_method']) && !strcasecmp($_POST['_method'],
                                                       'PATCH');
    }

    /**
     * Returns whether this is a TRACE request which was tunneled through POST.
     *
     * @return boolean
     */
    protected function getIsTraceViaPostRequest()
    {
        return isset($_POST['_method']) && !strcasecmp($_POST['_method'],
                                                       'TRACE');
    }

    /**
     * Returns whether this is a HEAD request which was tunneled through POST.
     *
     * @return boolean
     */
    protected function getIsHeadViaPostRequest()
    {
        return isset($_POST['_method']) && !strcasecmp($_POST['_method'], 'HEAD');
    }

    /**
     * Returns whether this is a OPTIONS request which was tunneled through POST.
     *
     * @return boolean
     */
    protected function getIsOptionsViaPostRequest()
    {
        return isset($_POST['_method']) && !strcasecmp($_POST['_method'],
                                                       'OPTIONS');
    }

    /**
     * Returns whether this is a LINK request which was tunneled through POST.
     *
     * @return boolean
     */
    protected function getIsLinkViaPostRequest()
    {
        return isset($_POST['_method']) && !strcasecmp($_POST['_method'], 'LINK');
    }

    /**
     * Returns whether this is a UNLINK request which was tunneled through POST.
     *
     * @return boolean
     */
    protected function getIsUnlinkViaPostRequest()
    {
        return isset($_POST['_method']) && !strcasecmp($_POST['_method'],
                                                       'UNLINK');
    }

    /**
     * Gets the all params of POST request.
     *
     * @return array
     */
    public function getPostMethodParams()
    {
        return $_POST;
    }

    /**
     * Gets the all params of GET request.
     *
     * @return array
     */
    public function getGetMethodParams()
    {
        return $_GET;
    }

    /**
     * Gets the all params of PUT request.
     *
     * @return array
     */
    public function getPutMethodParams()
    {
        if ($this->getIsPutViaPostRequest()) {
            return $this->getPostMethodParams();
        }
        if (null === $this->_putParams) {
            $this->_putParams = $this->getIsPutRequest() ? $this->getRestParams() : array();
        }
        return $this->_putParams;
    }

    /**
     * Gets the all params of DELETE request.
     *
     * @return array
     */
    public function getDeleteMethodParams()
    {
        if ($this->getIsDeleteViaPostRequest()) {
            return $this->getPostMethodParams();
        }
        if (null === $this->_deleteParams) {
            $this->_deleteParams = $this->getIsDeleteRequest() ? $this->getRestParams() : array();
        }
        return $this->_deleteParams;
    }

    /**
     * Gets the all params of HEAD request.
     *
     * @return array
     */
    public function getHeadMethodParams()
    {
        if ($this->getIsHeadViaPostRequest()) {
            return $this->getPostMethodParams();
        }
        if (null === $this->_headParams) {
            $this->_headParams = $this->getIsHeadRequest() ? $this->getRestParams() : array();
        }
        return $this->_headParams;
    }

    /**
     * Gets the all params of TRACE request.
     *
     * @return array
     */
    public function getTraceMethodParams()
    {
        if ($this->getIsTraceViaPostRequest()) {
            return $this->getPostMethodParams();
        }
        if (null === $this->_traceParams) {
            $this->_traceParams = $this->getIsTraceRequest() ? $this->getRestParams() : array();
        }
        return $this->_traceParams;
    }

    /**
     * Gets the all params of CONNECT request.
     *
     * @return array
     */
    public function getConnectMethodParams()
    {
        if ($this->getIsConnectViaPostRequest()) {
            return $this->getPostMethodParams();
        }
        if (null === $this->_connectParams) {
            $this->_connectParams = $this->getIsConnectRequest() ? $this->getRestParams() : array();
        }
        return $this->_connectParams;
    }

    /**
     * Gets the all params of PATCH request.
     *
     * @return array
     */
    public function getPatchMethodParams()
    {
        if ($this->getIsPatchViaPostRequest()) {
            return $this->getPostMethodParams();
        }
        if (null === $this->_patchParams) {
            $this->_patchParams = $this->getIsPatchRequest() ? $this->getRestParams() : array();
        }
        return $this->_patchParams;
    }

    /**
     * Gets the all params of OPTIONS request.
     *
     * @return array
     */
    public function getOptionsMethodParams()
    {
        if ($this->getIsOptionsViaPostRequest()) {
            return $this->getPostMethodParams();
        }
        if (null === $this->_optionsParams) {
            $this->_optionsParams = $this->getIsOptionsRequest() ? $this->getRestParams() : array();
        }
        return $this->_optionsParams;
    }

    /**
     * Gets the all params of LINK request.
     *
     * @return array
     */
    public function getLinkMethodParams()
    {
        if ($this->getIsLinkViaPostRequest()) {
            return $this->getPostMethodParams();
        }
        if (null === $this->_linkParams) {
            $this->_linkParams = $this->getIsLinkRequest() ? $this->getRestParams() : array();
        }
        return $this->_linkParams;
    }

    /**
     * Gets the all params of LINK request.
     *
     * @return array
     */
    public function getUnlinkMethodParams()
    {
        if ($this->getIsUnlinkViaPostRequest()) {
            return $this->getPostMethodParams();
        }
        if (null === $this->_unlinkParams) {
            $this->_unlinkParams = $this->getIsUnlinkRequest() ? $this->getRestParams() : array();
        }
        return $this->_unlinkParams;
    }

    /**
     * Returns whether this is a OPTIONS request.
     *
     * @return boolean
     */
    public function getIsOptionsRequest()
    {
        return (isset($_SERVER['REQUEST_METHOD']) && !strcasecmp($_SERVER['REQUEST_METHOD'],
                                                                 'OPTIONS')) || $this->getIsOptionsViaPostRequest();
    }

    /**
     * Returns whether this is a GET request.
     *
     * @return boolean
     */
    public function getIsGetRequest()
    {
        return isset($_SERVER['REQUEST_METHOD']) && !strcasecmp($_SERVER['REQUEST_METHOD'],
                                                                'GET');
    }

    /**
     * Returns whether this is a HEAD request.
     *
     * @return boolean
     */
    public function getIsHeadRequest()
    {
        return (isset($_SERVER['REQUEST_METHOD']) && !strcasecmp($_SERVER['REQUEST_METHOD'],
                                                                 'HEAD')) || $this->getIsHeadViaPostRequest();
    }

    /**
     * Returns whether this is a TRACE request.
     *
     * @return boolean
     */
    public function getIsTraceRequest()
    {
        return (isset($_SERVER['REQUEST_METHOD']) && !strcasecmp($_SERVER['REQUEST_METHOD'],
                                                                 'TRACE')) || $this->getIsTraceViaPostRequest();
    }

    /**
     * Returns whether this is a CONNECT request.
     *
     * @return boolean
     */
    public function getIsConnectRequest()
    {
        return (isset($_SERVER['REQUEST_METHOD']) && !strcasecmp($_SERVER['REQUEST_METHOD'],
                                                                 'CONNECT')) || $this->getIsConnectViaPostRequest();
    }

    /**
     * Returns whether this is a PATCH request.
     *
     * @return boolean
     */
    public function getIsPatchRequest()
    {
        return (isset($_SERVER['REQUEST_METHOD']) && !strcasecmp($_SERVER['REQUEST_METHOD'],
                                                                 'PATCH')) || $this->getIsPatchViaPostRequest();
    }

    /**
     * Returns whether this is a LINK request.
     *
     * @return boolean
     */
    public function getIsLinkRequest()
    {
        return (isset($_SERVER['REQUEST_METHOD']) && !strcasecmp($_SERVER['REQUEST_METHOD'],
                                                                 'LINK')) || $this->getIsLinkViaPostRequest();
    }

    /**
     * Returns whether this is a UNLINK request.
     *
     * @return boolean
     */
    public function getIsUnlinkRequest()
    {
        return (isset($_SERVER['REQUEST_METHOD']) && !strcasecmp($_SERVER['REQUEST_METHOD'],
                                                                 'UNLINK')) || $this->getIsUnlinkViaPostRequest();
    }

    /**
     * Returns the named DELETE parameter value.
     *
     * @param string $name the DELETE parameter name
     * @param mixed $defaultValue the default parameter value if the DELETE parameter does not exist.
     * @return mixed the DELETE parameter value
     */
    public function getDelete($name, $defaultValue = null)
    {
        $params = $this->getDeleteMethodParams();

        return isset($params[$name]) ? $params[$name] : $defaultValue;
    }

    /**
     * Returns the named PUT parameter value.
     *
     * @param string $name the PUT parameter name
     * @param mixed $defaultValue the default parameter value if the PUT parameter does not exist.
     * @return mixed the PUT parameter value
     */
    public function getPut($name, $defaultValue = null)
    {
        $params = $this->getPutMethodParams();

        return isset($params[$name]) ? $params[$name] : $defaultValue;
    }

    /**
     * Returns the named OPTIONS parameter value.
     *
     * @param string $name the OPTIONS parameter name
     * @param mixed $defaultValue the default parameter value if the OPTIONS parameter does not exist.
     * @return mixed the OPTIONS parameter value
     */
    public function getOptions($name, $defaultValue = null)
    {
        $params = $this->getOptionsMethodParams();

        return isset($params[$name]) ? $params[$name] : $defaultValue;
    }

    /**
     * Returns the named CONNECT parameter value.
     *
     * @param string $name the CONNECT parameter name
     * @param mixed $defaultValue the default parameter value if the CONNECT parameter does not exist.
     * @return mixed the CONNECT parameter value
     */
    public function getConnect($name, $defaultValue = null)
    {
        $params = $this->getConnectMethodParams();

        return isset($params[$name]) ? $params[$name] : $defaultValue;
    }

    /**
     * Returns the named HEAD parameter value.
     *
     * @param string $name the HEAD parameter name
     * @param mixed $defaultValue the default parameter value if the HEAD parameter does not exist.
     * @return mixed the HEAD parameter value
     */
    public function getHead($name, $defaultValue = null)
    {
        $params = $this->getHeadMethodParams();

        return isset($params[$name]) ? $params[$name] : $defaultValue;
    }

    /**
     * Returns the named TRACE parameter value.
     *
     * @param string $name the TRACE parameter name
     * @param mixed $defaultValue the default parameter value if the TRACE parameter does not exist.
     * @return mixed the TRACE parameter value
     */
    public function getTrace($name, $defaultValue = null)
    {
        $params = $this->getTraceMethodParams();

        return isset($params[$name]) ? $params[$name] : $defaultValue;
    }

    /**
     * Returns the named PATCH parameter value.
     *
     * @param string $name the PATCH parameter name
     * @param mixed $defaultValue the default parameter value if the PATCH parameter does not exist.
     * @return mixed the PATCH parameter value
     */
    public function getPatch($name, $defaultValue = null)
    {
        $params = $this->getPatchMethodParams();

        return isset($params[$name]) ? $params[$name] : $defaultValue;
    }

    /**
     * Returns the named LINK parameter value.
     *
     * @param string $name the LINK parameter name
     * @param mixed $defaultValue the default parameter value if the LINK parameter does not exist.
     * @return mixed the LINK parameter value
     */
    public function getLink($name, $defaultValue = null)
    {
        $params = $this->getLinkMethodParams();

        return isset($params[$name]) ? $params[$name] : $defaultValue;
    }

    /**
     * Returns the named UNLINK parameter value.
     *
     * @param string $name the UNLINK parameter name
     * @param mixed $defaultValue the default parameter value if the UNLINK parameter does not exist.
     * @return mixed the UNLINK parameter value
     */
    public function getUnlink($name, $defaultValue = null)
    {
        $params = $this->getUnlinkMethodParams();

        return isset($params[$name]) ? $params[$name] : $defaultValue;
    }

    /**
     * Returns REST request parameters.
     * @return array the request parameters
     */
    protected function getRestParams()
    {
        $result = array();
        if (function_exists('mb_parse_str')) {
            mb_parse_str(file_get_contents('php://input'), $result);
        } else {
            parse_str(file_get_contents('php://input'), $result);
        }
        return $result;
    }

    /**
     * Gets the params by method.
     * 
     * @param string $method
     * @return array
     */
    public function getMethodParams($method)
    {
        $methodName = 'get' . ucfirst(strtolower($method)) . 'MethodParams';
        
        return $this->owner->$methodName();
    }
}