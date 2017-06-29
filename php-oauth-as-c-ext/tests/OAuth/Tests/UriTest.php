<?php

/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
 
namespace OAuth\Tests;

use OAuth\Uri;

/**
 * Test for \OAuth\Uri class
 */
class UriTest extends \PHPUnit_Framework_TestCase
{
    /**
     * @covers OAuth\Uri::__construct
     */
    public function testConstructCorrectInterfaceWithoutUri()
    {
        $uri = new Uri();

        $this->assertInstanceOf('\\OAuth\\UriInterface', $uri);
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     */
    public function testConstructThrowsExceptionOnInvalidUri()
    {
        $this->setExpectedException('\\InvalidArgumentException');

        // http://lxr.php.net/xref/PHP_5_4/ext/standard/tests/url/urls.inc#92
        $uri = new Uri('http://@:/');
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     */
    public function testConstructThrowsExceptionOnUriWithoutScheme()
    {
        $this->setExpectedException('\\InvalidArgumentException');

        $uri = new Uri('www.pieterhordijk.com');
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getScheme
     */
    public function testGetScheme()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('http', $uri->getScheme());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getUserInfo
     */
    public function testGetUserInfo()
    {
        $uri = new Uri('http://peehaa@example.com');

        $this->assertSame('peehaa', $uri->getUserInfo());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getUserInfo
     */
    public function testGetUserInfoWithPass()
    {
        $uri = new Uri('http://peehaa:pass@example.com');

        $this->assertSame('peehaa:********', $uri->getUserInfo());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getRawUserInfo
     */
    public function testGetRawUserInfo()
    {
        $uri = new Uri('http://peehaa@example.com');

        $this->assertSame('peehaa', $uri->getRawUserInfo());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getRawUserInfo
     */
    public function testGetRawUserInfoWithPass()
    {
        $uri = new Uri('http://peehaa:pass@example.com');

        $this->assertSame('peehaa:pass', $uri->getRawUserInfo());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getHost
     */
    public function testGetHost()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('example.com', $uri->getHost());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getPort
     */
    public function testGetPortImplicitHttp()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame(80, $uri->getPort());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getPort
     */
    public function testGetPortImplicitHttps()
    {
        $uri = new Uri('https://example.com');

        $this->assertSame(443, $uri->getPort());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getPort
     */
    public function testGetPortExplicit()
    {
        $uri = new Uri('http://example.com:21');

        $this->assertSame(21, $uri->getPort());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getPath
     */
    public function testGetPathNotSupplied()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('/', $uri->getPath());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getPath
     */
    public function testGetPathSlash()
    {
        $uri = new Uri('http://example.com/');

        $this->assertSame('/', $uri->getPath());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getPath
     */
    public function testGetPath()
    {
        $uri = new Uri('http://example.com/foo');

        $this->assertSame('/foo', $uri->getPath());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getQuery
     */
    public function testGetQueryWithParams()
    {
        $uri = new Uri('http://example.com?param1=first&param2=second');

        $this->assertSame('param1=first&param2=second', $uri->getQuery());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getQuery
     */
    public function testGetQueryWithoutParams()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('', $uri->getQuery());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getFragment
     */
    public function testGetFragmentExists()
    {
        $uri = new Uri('http://example.com#foo');

        $this->assertSame('foo', $uri->getFragment());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getFragment
     */
    public function testGetFragmentNotExists()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('', $uri->getFragment());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getAuthority
     */
    public function testGetAuthorityWithoutUserInfo()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('example.com', $uri->getAuthority());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getAuthority
     */
    public function testGetAuthorityWithoutUserInfoWithExplicitPort()
    {
        $uri = new Uri('http://example.com:21');

        $this->assertSame('example.com:21', $uri->getAuthority());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getAuthority
     */
    public function testGetAuthorityWithUsernameWithExplicitPort()
    {
        $uri = new Uri('http://peehaa@example.com:21');

        $this->assertSame('peehaa@example.com:21', $uri->getAuthority());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getAuthority
     */
    public function testGetAuthorityWithUsernameAndPassWithExplicitPort()
    {
        $uri = new Uri('http://peehaa:pass@example.com:21');

        $this->assertSame('peehaa:********@example.com:21', $uri->getAuthority());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getAuthority
     */
    public function testGetAuthorityWithUsernameAndPassWithoutExplicitPort()
    {
        $uri = new Uri('http://peehaa:pass@example.com');

        $this->assertSame('peehaa:********@example.com', $uri->getAuthority());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getRawAuthority
     */
    public function testGetRawAuthorityWithoutUserInfo()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('example.com', $uri->getRawAuthority());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getRawAuthority
     */
    public function testGetRawAuthorityWithoutUserInfoWithExplicitPort()
    {
        $uri = new Uri('http://example.com:21');

        $this->assertSame('example.com:21', $uri->getRawAuthority());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getRawAuthority
     */
    public function testGetRawAuthorityWithUsernameWithExplicitPort()
    {
        $uri = new Uri('http://peehaa@example.com:21');

        $this->assertSame('peehaa@example.com:21', $uri->getRawAuthority());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getRawAuthority
     */
    public function testGetRawAuthorityWithUsernameAndPassWithExplicitPort()
    {
        $uri = new Uri('http://peehaa:pass@example.com:21');

        $this->assertSame('peehaa:pass@example.com:21', $uri->getRawAuthority());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getRawAuthority
     */
    public function testGetRawAuthorityWithUsernameAndPassWithoutExplicitPort()
    {
        $uri = new Uri('http://peehaa:pass@example.com');

        $this->assertSame('peehaa:pass@example.com', $uri->getRawAuthority());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testGetAbsoluteUriBare()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('http://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getRawAuthority
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testGetAbsoluteUriWithAuthority()
    {
        $uri = new Uri('http://peehaa:pass@example.com');

        $this->assertSame('http://peehaa:pass@example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testGetAbsoluteUriWithPath()
    {
        $uri = new Uri('http://example.com/foo');

        $this->assertSame('http://example.com/foo', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testGetAbsoluteUriWithoutPath()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('http://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testGetAbsoluteUriWithoutPathExplicitTrailingSlash()
    {
        $uri = new Uri('http://example.com/');

        $this->assertSame('http://example.com/', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testGetAbsoluteUriWithQuery()
    {
        $uri = new Uri('http://example.com?param1=value1');

        $this->assertSame('http://example.com?param1=value1', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testGetAbsoluteUriWithFragment()
    {
        $uri = new Uri('http://example.com#foo');

        $this->assertSame('http://example.com#foo', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getRelativeUri
     */
    public function testGetRelativeUriWithoutPath()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('', $uri->getRelativeUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getRelativeUri
     */
    public function testGetRelativeUriWithPath()
    {
        $uri = new Uri('http://example.com/foo');

        $this->assertSame('/foo', $uri->getRelativeUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::getRelativeUri
     */
    public function testGetRelativeUriWithExplicitTrailingSlash()
    {
        $uri = new Uri('http://example.com/');

        $this->assertSame('/', $uri->getRelativeUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::__toString
     */
    public function testToStringBare()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('http://example.com', (string) $uri);
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getRawAuthority
     * @covers OAuth\Uri::__toString
     */
    public function testToStringWithAuthority()
    {
        $uri = new Uri('http://peehaa:pass@example.com');

        $this->assertSame('http://peehaa:********@example.com', (string) $uri);
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::__toString
     */
    public function testToStringWithPath()
    {
        $uri = new Uri('http://example.com/foo');

        $this->assertSame('http://example.com/foo', (string) $uri);
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::__toString
     */
    public function testToStringWithoutPath()
    {
        $uri = new Uri('http://example.com');

        $this->assertSame('http://example.com', (string) $uri);
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::__toString
     */
    public function testToStringWithoutPathExplicitTrailingSlash()
    {
        $uri = new Uri('http://example.com/');

        $this->assertSame('http://example.com/', (string) $uri);
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::__toString
     */
    public function testToStringWithQuery()
    {
        $uri = new Uri('http://example.com?param1=value1');

        $this->assertSame('http://example.com?param1=value1', (string) $uri);
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::__toString
     */
    public function testToStringWithFragment()
    {
        $uri = new Uri('http://example.com#foo');

        $this->assertSame('http://example.com#foo', (string) $uri);
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setPath
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetPathEmpty()
    {
        $uri = new Uri('http://example.com');
        $uri->setPath('');

        $this->assertSame('http://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setPath
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetPathWithPath()
    {
        $uri = new Uri('http://example.com');
        $uri->setPath('/foo');

        $this->assertSame('http://example.com/foo', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setPath
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetPathWithOnlySlash()
    {
        $uri = new Uri('http://example.com');
        $uri->setPath('/');

        $this->assertSame('http://example.com/', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setQuery
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetQueryEmpty()
    {
        $uri = new Uri('http://example.com');
        $uri->setQuery('');

        $this->assertSame('http://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setQuery
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetQueryFilled()
    {
        $uri = new Uri('http://example.com');
        $uri->setQuery('param1=value1&param2=value2');

        $this->assertSame('http://example.com?param1=value1&param2=value2', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::addToQuery
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testAddToQueryAppend()
    {
        $uri = new Uri('http://example.com?param1=value1');
        $uri->addToQuery('param2', 'value2');

        $this->assertSame('http://example.com?param1=value1&param2=value2', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::addToQuery
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testAddToQueryCreate()
    {
        $uri = new Uri('http://example.com');
        $uri->addToQuery('param1', 'value1');

        $this->assertSame('http://example.com?param1=value1', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setFragment
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetFragmentEmpty()
    {
        $uri = new Uri('http://example.com');
        $uri->setFragment('');

        $this->assertSame('http://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setFragment
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetFragmentWithData()
    {
        $uri = new Uri('http://example.com');
        $uri->setFragment('foo');

        $this->assertSame('http://example.com#foo', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setScheme
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetSchemeWithEmpty()
    {
        $uri = new Uri('http://example.com');
        $uri->setScheme('');

        $this->assertSame('://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setScheme
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetSchemeWithData()
    {
        $uri = new Uri('http://example.com');
        $uri->setScheme('foo');

        $this->assertSame('foo://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetUserInfoEmpty()
    {
        $uri = new Uri('http://example.com');
        $uri->setUserInfo('');

        $this->assertSame('http://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setUserInfo
     * @covers OAuth\Uri::protectUserInfo
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetUserInfoWithData()
    {
        $uri = new Uri('http://example.com');
        $uri->setUserInfo('foo:bar');

        $this->assertSame('http://foo:bar@example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setPort
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetPortCustom()
    {
        $uri = new Uri('http://example.com');
        $uri->setPort('21');

        $this->assertSame('http://example.com:21', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setPort
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetPortHttpImplicit()
    {
        $uri = new Uri('http://example.com');
        $uri->setPort(80);

        $this->assertSame('http://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setPort
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetPortHttpsImplicit()
    {
        $uri = new Uri('https://example.com');
        $uri->setPort(443);

        $this->assertSame('https://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setPort
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetPortHttpExplicit()
    {
        $uri = new Uri('http://example.com');
        $uri->setPort(443);

        $this->assertSame('http://example.com:443', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setPort
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetPortHttpsExplicit()
    {
        $uri = new Uri('https://example.com');
        $uri->setPort(80);

        $this->assertSame('https://example.com:80', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::setHost
     * @covers OAuth\Uri::getAbsoluteUri
     */
    public function testSetHost()
    {
        $uri = new Uri('http://example.com');
        $uri->setHost('pieterhordijk.com');

        $this->assertSame('http://pieterhordijk.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::hasExplicitTrailingHostSlash
     */
    public function testHasExplicitTrailingHostSlashTrue()
    {
        $uri = new Uri('http://example.com/');

        $this->assertTrue($uri->hasExplicitTrailingHostSlash());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::hasExplicitTrailingHostSlash
     */
    public function testHasExplicitTrailingHostSlashFalse()
    {
        $uri = new Uri('http://example.com/foo');

        $this->assertFalse($uri->hasExplicitTrailingHostSlash());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::hasExplicitPortSpecified
     */
    public function testHasExplicitPortSpecifiedTrue()
    {
        $uri = new Uri('http://example.com:8080');

        $this->assertTrue($uri->hasExplicitPortSpecified());
    }

    /**
     * @covers OAuth\Uri::__construct
     * @covers OAuth\Uri::parseUri
     * @covers OAuth\Uri::hasExplicitPortSpecified
     */
    public function testHasExplicitPortSpecifiedFalse()
    {
        $uri = new Uri('http://example.com');

        $this->assertFalse($uri->hasExplicitPortSpecified());
    }
    
//	public function testInterfaceImplements()
//	{
//		 $uri = new Uri();
//         $this->assertInstanceOf('\\OAuth\\UriInterface', $uri, sprintf('Class %s must implements interface OAuth\\UriInterface', get_class($uri)));
//	}
//
//    /**
//     * Data provider for testConstructor
//     *
//     * @return array
//     */
//    public function dataProviderConstructor()
//    {
//        return array(
//            array(
//                'http://someoauth.local',
//                array(
//                    'scheme' => 'http',
//                    'host' => 'someoauth.local',
//                    'port' => 80,
//                    'path' => '/'
//                ),
//            ),
//            array(
//                'https://somelogin:somepass@somehost.com:777/some/path/hehe?param1=value1&param2=value2#somefragment-blabla',
//                array(
//                    'scheme' => 'https',
//                    'host' => 'somehost.com',
//                    'port' => 777,
//                    'path' => '/some/path/hehe',
//                    'query' => 'param1=value1&param2=value2',
//                    'fragment' => 'somefragment-blabla',
//                    'userInfo' => 'somelogin:somepass',
//                    'authority' => 'not_completed_yet',
//                    'rawAuthority' => 'not_completed_yet',
//                    'rawUserInfo' => 'not_completed_yet',
//                    'explicitTrailingHostSlash' => 10,
//                    'explicitPortSpecified' => 10,
//                    'relativeUri' => 'not_completed_yet',
//                    'absoluteUri' => 'not_completed_yet',
//                ),
//            )
//        );
//    }
//
//    /**
//     * Test constructor in \OAuth\Uri
//     *
//     * @dataProvider dataProviderConstructor
//     */
//    public function testConstructor($url, array $expected)
//    {
//        $uri = new Uri($url);
//
//        $scheme = $uri->getScheme();
//        $this->assertNotEmpty($scheme);
//        $this->assertInternalType('string', $scheme);
//        $this->assertEquals($expected['scheme'], $scheme);
//
//        $host = $uri->getHost();
//        $this->assertNotEmpty($host);
//        $this->assertInternalType('string', $host);
//        $this->assertEquals($expected['host'], $host);
//
//        $port = $uri->getPort();
//        $this->assertNotEmpty($port);
//        $this->assertInternalType('int', $port);
//        $this->assertEquals($expected['port'], $port);
//
//        $path = $uri->getPath();
//        $this->assertNotEmpty($path);
//        $this->assertInternalType('string', $path);
//        $this->assertEquals($expected['path'], $path);
//
//        if(isset($expected['query'])) {
//            $query = $uri->getQuery();
//            if(!empty($expected['query'])) {
//                $this->assertNotEmpty($query);
//            }
//            $this->assertInternalType('string', $query);
//            $this->assertEquals($expected['query'], $query);
//        }
//
//        if(isset($expected['fragment'])) {
//            $fragment = $uri->getFragment();
//            if(!empty($expected['fragment'])) {
//                $this->assertNotEmpty($fragment);
//            }
//            $this->assertInternalType('string', $fragment);
//            $this->assertEquals($expected['fragment'], $fragment);
//        }
//
//        if(isset($expected['userInfo'])) {
//            $userInfo = $uri->getUserInfo();
//            if(!empty($expected['userInfo'])) {
//                $this->assertNotEmpty($userInfo);
//            }
//            $this->assertInternalType('string', $userInfo);
//            $this->assertEquals($expected['userInfo'], $userInfo);
//        }
//
//        if(isset($expected['authority'])) {
//            $authority = $uri->getAuthority();
//            if(!empty($expected['authority'])) {
//                $this->assertNotEmpty($authority);
//            }
//            $this->assertInternalType('string', $authority);
//            $this->assertEquals($expected['authority'], $authority);
//        }
//
//        if(isset($expected['rawAuthority'])) {
//            $rawAuthority = $uri->getRawAuthority();
//            if(!empty($expected['rawAuthority'])) {
//                $this->assertNotEmpty($rawAuthority);
//            }
//            $this->assertInternalType('string', $rawAuthority);
//            $this->assertEquals($expected['rawAuthority'], $rawAuthority);
//        }
//
//        if(isset($expected['rawUserInfo'])) {
//            $rawUserInfo = $uri->getRawUserInfo();
//            if(!empty($expected['rawUserInfo'])) {
//                $this->assertNotEmpty($rawUserInfo);
//            }
//            $this->assertInternalType('string', $rawUserInfo);
//            $this->assertEquals($expected['rawUserInfo'], $rawUserInfo);
//        }
//
//        if(isset($expected['explicitTrailingHostSlash'])) {
//            $explicitTrailingHostSlash = $uri->hasExplicitTrailingHostSlash();
//            $this->assertInternalType('boolean', $explicitTrailingHostSlash);
//            $this->assertEquals($expected['explicitTrailingHostSlash'], $explicitTrailingHostSlash);
//        }
//
//        if(isset($expected['explicitPortSpecified'])) {
//            $explicitPortSpecified = $uri->hasExplicitPortSpecified();
//            $this->assertInternalType('boolean', $explicitPortSpecified);
//            $this->assertEquals($expected['explicitPortSpecified'], $explicitPortSpecified);
//        }
//
//        if(isset($expected['relativeUri'])) {
//            $relativeUri = $uri->getRelativeUri();
//            if(!empty($expected['relativeUri'])) {
//                $this->assertNotEmpty($relativeUri);
//            }
//            $this->assertInternalType('string', $relativeUri);
//            $this->assertEquals($expected['relativeUri'], $relativeUri);
//        }
//
//        $absoluteUri = $uri->getAbsoluteUri();
//        $this->assertNotEmpty($absoluteUri);
//        $this->assertInternalType('string', $absoluteUri);
//
//        if(isset($expected['absoluteUri'])) {
//            $this->assertEquals($expected['absoluteUri'], $absoluteUri);
//        }
//    }
//
//    /**
//     * Data provider for testGetScheme
//     *
//     * @return array
//     */
//    public function dataProviderGetScheme()
//    {
//        return array(
//            array(
//                'http://oauth.local/bla',
//                'http',
//            ),
//            array(
//                'https://otheroauth.com',
//                'https',
//            ),
//            array(
//                'ftp://someftphost.net',
//                'ftp',
//            ),
//        );
//    }
}