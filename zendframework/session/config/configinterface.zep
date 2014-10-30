/*

This file is part of the php-ext-zendframework package.

For the full copyright and license information, please view the LICENSE
file that was distributed with this source code.

*/

namespace Zend\Session\Config;

// todo: types

/**
 * Standard session configuration
 */
interface ConfigInterface
{
    public function setOptions(options);

    public function getOptions();

    public function setOption(option, value);

    public function getOption(option);

    public function hasOption(option);

    public function toArray();

    public function setName(name);

    public function getName();

    public function setSavePath(savePath);

    public function getSavePath();

    public function setCookieLifetime(cookieLifetime);

    public function getCookieLifetime();

    public function setCookiePath(cookiePath);

    public function getCookiePath();

    public function setCookieDomain(cookieDomain);

    public function getCookieDomain();

    public function setCookieSecure(cookieSecure);

    public function getCookieSecure();

    public function setCookieHttpOnly(cookieHttpOnly);

    public function getCookieHttpOnly();

    public function setUseCookies(useCookies);

    public function getUseCookies();

    public function setRememberMeSeconds(rememberMeSeconds);

    public function getRememberMeSeconds();

}