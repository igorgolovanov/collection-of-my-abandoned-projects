<?php

/**
 * This file is part of the OAuth package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace OAuth\Tests\Client;

use OAuth\Client\Curl as CurlClient;

class CurlTest extends \PHPUnit_Framework_TestCase
{
    /**
     *
     */
    public function testConstructCorrectInstance()
    {
        $client = new CurlClient();

        $this->assertInstanceOf('\\OAuth\\Client', $client);
    }

    /**
     * @covers OAuth\Client\Curl::setForceSSL3
     */
    public function testSetForceSSL3()
    {
        $client = new CurlClient();

        $this->assertInstanceOf('\\OAuth\\Client\\Curl', $client->setForceSSL3(true));
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     */
    public function testRetrieveThrowsExceptionOnGetRequestWithBody()
    {
        $this->setExpectedException('\\InvalidArgumentException');

        $client = new CurlClient();

        $client->retrieve(
            $this->getMock('\\OAuth\\UriInterface'),
            'foo',
            array(),
            'GET'
        );
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     */
    public function testRetrieveThrowsExceptionOnGetRequestWithBodyMethodConvertedToUpper()
    {
        $this->setExpectedException('\\InvalidArgumentException');

        $client = new CurlClient();

        $client->retrieve(
            $this->getMock('\\OAuth\\UriInterface'),
            'foo',
            array(),
            'get'
        );
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     * @covers OAuth\Client\Curl::generateStreamContext
     */
    public function testRetrieveDefaultUserAgent()
    {
        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('httpbin.org'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('http://httpbin.org/get'));

        $client = new CurlClient();

        $response = $client->retrieve(
            $endPoint,
            '',
            array(),
            'get'
        );

        $response = json_decode($response, true);

        $this->assertSame('PHPoAuthLib', $response['headers']['User-Agent']);
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     * @covers OAuth\Client\Curl::generateStreamContext
     */
    public function testRetrieveCustomUserAgent()
    {
        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('httpbin.org'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('http://httpbin.org/get'));

        $client = new CurlClient('My Super Awesome Http Client');

        $response = $client->retrieve(
            $endPoint,
            '',
            array(),
            'get'
        );

        $response = json_decode($response, true);

        $this->assertSame('My Super Awesome Http Client', $response['headers']['User-Agent']);
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     */
    public function testRetrieveWithCustomContentType()
    {
        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('httpbin.org'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('http://httpbin.org/get'));

        $client = new CurlClient();

        $response = $client->retrieve(
            $endPoint,
            '',
            array('Content-type' => 'foo/bar'),
            'get'
        );

        $response = json_decode($response, true);

        $this->assertSame('foo/bar', $response['headers']['Content-Type']);
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     */
    public function testRetrieveWithFormUrlEncodedContentType()
    {
        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('httpbin.org'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('http://httpbin.org/post'));

        $client = new CurlClient();

        $response = $client->retrieve(
            $endPoint,
            array('foo' => 'bar', 'baz' => 'fab'),
            array(),
            'POST'
        );

        $response = json_decode($response, true);

        $this->assertSame('application/x-www-form-urlencoded', $response['headers']['Content-Type']);
        $this->assertEquals(array('foo' => 'bar', 'baz' => 'fab'), $response['form']);
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     */
    public function testRetrieveHost()
    {
        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('httpbin.org'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('http://httpbin.org/post'));

        $client = new CurlClient();

        $response = $client->retrieve(
            $endPoint,
            array('foo' => 'bar', 'baz' => 'fab'),
            array(),
            'POST'
        );

        $response = json_decode($response, true);

        $this->assertSame('httpbin.org', $response['headers']['Host']);
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     */
    public function testRetrievePostRequestWithRequestBodyAsString()
    {
        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('httpbin.org'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('http://httpbin.org/post'));

        $client = new CurlClient();

        $response = $client->retrieve(
            $endPoint,
            'foo',
            array(),
            'POST'
        );

        $response = json_decode($response, true);

        $this->assertSame('foo', $response['data']);
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     */
    public function testRetrievePutRequestWithRequestBodyAsString()
    {
        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('httpbin.org'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('http://httpbin.org/put'));

        $client = new CurlClient();

        $response = $client->retrieve(
            $endPoint,
            'foo',
            array(),
            'PUT'
        );

        $response = json_decode($response, true);

        $this->assertSame('foo', $response['data']);
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     */
    public function testRetrievePutRequestWithRequestBodyAsStringNoRedirects()
    {
        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('httpbin.org'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('http://httpbin.org/put'));

        $client = new CurlClient();

        $client->setMaxRedirects(0);

        $response = $client->retrieve(
            $endPoint,
            'foo',
            array(),
            'PUT'
        );

        $response = json_decode($response, true);

        $this->assertSame('foo', $response['data']);
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     */
    public function testRetrieveWithForcedSsl3()
    {
        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('httpbin.org'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('https://httpbin.org/get'));

        $client = new CurlClient();

        $client->setForceSSL3(true);

        $response = $client->retrieve(
            $endPoint,
            '',
            array('Content-type' => 'foo/bar'),
            'get'
        );

        $response = json_decode($response, true);

        $this->assertSame('foo/bar', $response['headers']['Content-Type']);
    }

    /**
     * @covers OAuth\Client\Curl::retrieve
     */
    public function testRetrieveThrowsExceptionOnInvalidUrl()
    {
        $this->setExpectedException('\\OAuth\\TokenResponseException');

        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('jkehfkefcmekjhcnkerjh'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('jkehfkefcmekjhcnkerjh'));

        $client = new CurlClient();

        $client->setForceSSL3(true);

        $response = $client->retrieve(
            $endPoint,
            '',
            array('Content-type' => 'foo/bar'),
            'get'
        );

        $response = json_decode($response, true);

        $this->assertSame('foo/bar', $response['headers']['Content-Type']);
    }

    public function testAdditionalParameters()
    {
        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('httpbin.org'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('http://httpbin.org/gzip'));

        $client = new CurlClient();
        $client->setCurlParameters(array(
            CURLOPT_ENCODING => 'gzip',
        ));

        $response = $client->retrieve(
            $endPoint,
            '',
            array(),
            'get'
        );

        $response = json_decode($response, true);

        $this->assertNotNull($response);
        $this->assertSame('gzip', $response['headers']['Accept-Encoding']);
        $this->assertTrue($response['gzipped']);
    }
}