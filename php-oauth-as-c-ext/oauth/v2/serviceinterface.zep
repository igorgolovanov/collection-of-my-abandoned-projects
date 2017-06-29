
/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\V2;

interface ServiceInterface extends OAuth\ServiceInterface
{
    const AUTHORIZATION_METHOD_HEADER_OAUTH    = 0;
    const AUTHORIZATION_METHOD_HEADER_BEARER   = 1;
    const AUTHORIZATION_METHOD_QUERY_STRING    = 2;
    const AUTHORIZATION_METHOD_QUERY_STRING_V2 = 3;
    const AUTHORIZATION_METHOD_QUERY_STRING_V3 = 4;

    /**
     * Retrieves and stores/returns the OAuth2 access 
     * token after a successful authorization.
     *
     * @param string code The access code from the callback
     * @return OAuth\V2\TokenInterface token
     * @throws OAuth\TokenResponseException
     */
    public function requestAccessToken(string code) -> <OAuth\V2\TokenInterface>;
}