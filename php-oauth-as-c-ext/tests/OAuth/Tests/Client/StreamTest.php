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

use OAuth\Client\Stream as StreamClient;

class StreamTest extends \PHPUnit_Framework_TestCase
{
    public function testConstructCorrectInstance()
    {
        $client = new StreamClient();

        $this->assertInstanceOf('\\OAuth\\Client', $client);
    }

    /**
     * @covers OAuth\Client\Stream::retrieve
     */
    public function testRetrieveThrowsExceptionOnGetRequestWithBody()
    {
        $this->setExpectedException('\\InvalidArgumentException');

        $client = new StreamClient();

        $client->retrieve(
            $this->getMock('\\OAuth\\UriInterface'),
            'foo',
            array(),
            'GET'
        );
    }

    /**
     * @covers OAuth\Client\Stream::retrieve
     */
    public function testRetrieveThrowsExceptionOnGetRequestWithBodyMethodConvertedToUpper()
    {
        $this->setExpectedException('\\InvalidArgumentException');

        $client = new StreamClient();

        $client->retrieve(
            $this->getMock('\\OAuth\\UriInterface'),
            'foo',
            array(),
            'get'
        );
    }

    /**
     * @covers OAuth\Client\Stream::retrieve
     * @covers OAuth\Client\Stream::generateStreamContext
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

        $client = new StreamClient();

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
     * @covers OAuth\Client\Stream::retrieve
     * @covers OAuth\Client\Stream::generateStreamContext
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

        $client = new StreamClient('My Super Awesome Http Client');

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
     * @covers OAuth\Client\Stream::retrieve
     * @covers OAuth\Client\Stream::generateStreamContext
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

        $client = new StreamClient();

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
     * @covers OAuth\Client\Stream::retrieve
     * @covers OAuth\Client\Stream::generateStreamContext
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

        $client = new StreamClient();

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
     * @covers OAuth\Client\Stream::retrieve
     * @covers OAuth\Client\Stream::generateStreamContext
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

        $client = new StreamClient();

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
     * @covers OAuth\Client\Stream::retrieve
     * @covers OAuth\Client\Stream::generateStreamContext
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

        $client = new StreamClient();

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
     * @covers OAuth\Client\Stream::retrieve
     * @covers OAuth\Client\Stream::generateStreamContext
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

        $client = new StreamClient();

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
     * @covers OAuth\Client\Stream::retrieve
     * @covers OAuth\Client\Stream::generateStreamContext
     */
    public function testRetrieveThrowsExceptionOnInvalidRequest()
    {
        $this->setExpectedException('\\OAuth\\TokenResponseException');

        $endPoint = $this->getMock('\\OAuth\\UriInterface');
        $endPoint->expects($this->any())
            ->method('getHost')
            ->will($this->returnValue('dskjhfckjhekrsfhkehfkreljfrekljfkre'));
        $endPoint->expects($this->any())
            ->method('getAbsoluteUri')
            ->will($this->returnValue('dskjhfckjhekrsfhkehfkreljfrekljfkre'));

        $client = new StreamClient();

        $response = $client->retrieve(
            $endPoint,
            '',
            array('Content-type' => 'foo/bar'),
            'get'
        );

        $response = json_decode($response, true);

        $this->assertSame('foo/bar', $response['headers']['Content-Type']);
    }
}