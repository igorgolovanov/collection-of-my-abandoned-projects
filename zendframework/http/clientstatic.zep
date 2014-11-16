/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Http;

/**
 * Http static client
 */
class ClientStatic
{
    protected static client;

    /**
     * Get the static HTTP client
     *
     * @return Client
     */
    protected static function getStaticClient() -> <Client>
    {
        var className, client = null;

        let className = get_called_class();
        %{
            zephir_read_static_property(&client, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("client") TSRMLS_CC);
        }%

        if client === null {
            let client = new {className}();
            %{
                zephir_update_static_property(Z_STRVAL_P(className), Z_STRLEN_P(className), SL("client"), &client TSRMLS_CC);
            }%
        }
        return client;
    }

    /**
     * HTTP GET METHOD (static)
     *
     * @param  string $url
     * @param  array $query
     * @param  array $headers
     * @param  mixed $body
     * @return Response|bool
     */
    public static function get(string url, array query = [], array headers = [], var body = null) -> <Response>|boolean
    {
        var request, response, client;

        if empty url {
            return false;
        }

        let request = new Request();

        request->setUri(url);
        request->setMethod(Request::METHOD_GET);

        if count(query) > 0 {
            request->getQuery()->fromArray(query);
        }
        if count(headers) > 0 {
            request->getHeaders()->addHeaders(headers);
        }
        if !empty body {
            request->setContent(body);
        }

        let client = <Client> static::getStaticClient();
        let response = client->send(request);

        return response;
    }

    /**
     * HTTP POST METHOD (static)
     *
     * @param  string $url
     * @param  array $params
     * @param  array $headers
     * @param  mixed $body
     * @throws Exception\InvalidArgumentException
     * @return Response|bool
     */
    public static function post(string url, var params, array headers = [], var body = null) -> <Response>|boolean
    {
        var request, response, client;

        if empty url {
            return false;
        }

        let request = new Request();

        request->setUri(url);
        request->setMethod(Request::METHOD_POST);

        if unlikely empty params && typeof params != "array" {
            throw new Exception\InvalidArgumentException("The array of post parameters is empty");
        }
        request->getPost()->fromArray(params);

        if !isset headers["Content-Type"] {
            let headers["Content-Type"] = Client::ENC_URLENCODED;
        }
        if count(headers) {
            request->getHeaders()->addHeaders(headers);
        }
        if !empty body {
            request->setContent(body);
        }

        let client = <Client> static::getStaticClient();
        let response = client->send(request);

        return response;
    }

}
