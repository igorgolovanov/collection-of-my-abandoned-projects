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

class ServiceTest extends \PHPUnit_Framework_TestCase
{
    /**
     * @covers OAuth\Service::__construct
     */
    public function testConstructCorrectInterface()
    {
        $service = $this->getMockForAbstractClass(
            '\\OAuth\\Service',
            array(
                $this->getMock('\\OAuth\\CredentialsInterface'),
                $this->getMock('\\OAuth\\ClientInterface'),
                $this->getMock('\\OAuth\\TokenStorageInterface')
            )
        );

        $this->assertInstanceOf('\\OAuth\\Common\\Service\\ServiceInterface', $service);
    }

    /**
     * @covers OAuth\Service::__construct
     * @covers OAuth\Service::getStorage
     */
    public function testGetStorage()
    {
        $service = $this->getMockForAbstractClass(
            '\\OAuth\\Service',
            array(
                $this->getMock('\\OAuth\\CredentialsInterface'),
                $this->getMock('\\OAuth\\ClientInterface'),
                $this->getMock('\\OAuth\\TokenStorageInterface')
            )
        );

        $this->assertInstanceOf('\\OAuth\\TokenStorageInterface', $service->getTokenStorage());
    }

    /**
     * @covers OAuth\Service::__construct
     * @covers OAuth\Service::getServiceId
     */
    public function testGetServiceId()
    {
        $service = new Mock(
            $this->getMock('\\OAuth\\CredentialsInterface'),
            $this->getMock('\\OAuth\\ClientInterface'),
            $this->getMock('\\OAuth\\TokenStorageInterface')
        );

        $this->assertSame('Mock', $service->getServiceId());
    }

    /**
     * @covers OAuth\Service::__construct
     * @covers OAuth\Service::determineRequestUriFromPath
     */
    public function testDetermineRequestUriFromPathUsingUriObject()
    {
        $service = new Mock(
            $this->getMock('\\OAuth\\CredentialsInterface'),
            $this->getMock('\\OAuth\\ClientInterface'),
            $this->getMock('\\OAuth\\TokenStorageInterface')
        );

        $this->assertInstanceOf(
            '\\OAuth\\UriInterface',
            $service->testDetermineRequestUriFromPath($this->getMock('\\OAuth\\UriInterface'))
        );
    }

    /**
     * @covers OAuth\Service::__construct
     * @covers OAuth\Service::determineRequestUriFromPath
     */
    public function testDetermineRequestUriFromPathUsingHttpPath()
    {
        $service = new Mock(
            $this->getMock('\\OAuth\\CredentialsInterface'),
            $this->getMock('\\OAuth\\ClientInterface'),
            $this->getMock('\\OAuth\\TokenStorageInterface')
        );

        $uri = $service->testDetermineRequestUriFromPath('http://example.com');

        $this->assertInstanceOf('\\OAuth\\UriInterface', $uri);
        $this->assertSame('http://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Service::__construct
     * @covers OAuth\Service::determineRequestUriFromPath
     */
    public function testDetermineRequestUriFromPathUsingHttpsPath()
    {
        $service = new Mock(
            $this->getMock('\\OAuth\\CredentialsInterface'),
            $this->getMock('\\OAuth\\ClientInterface'),
            $this->getMock('\\OAuth\\TokenStorageInterface')
        );

        $uri = $service->testDetermineRequestUriFromPath('https://example.com');

        $this->assertInstanceOf('\\OAuth\\UriInterface', $uri);
        $this->assertSame('https://example.com', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Service::__construct
     * @covers OAuth\Service::determineRequestUriFromPath
     */
    public function testDetermineRequestUriFromPathThrowsExceptionOnInvalidUri()
    {
        $this->setExpectedException('\\OAuth\\Common\\Exception\\Exception');

        $service = new Mock(
            $this->getMock('\\OAuth\\CredentialsInterface'),
            $this->getMock('\\OAuth\\ClientInterface'),
            $this->getMock('\\OAuth\\TokenStorageInterface')
        );

        $uri = $service->testDetermineRequestUriFromPath('example.com');
    }

    /**
     * @covers OAuth\Service::__construct
     * @covers OAuth\Service::determineRequestUriFromPath
     */
    public function testDetermineRequestUriFromPathWithQueryString()
    {
        $service = new Mock(
            $this->getMock('\\OAuth\\CredentialsInterface'),
            $this->getMock('\\OAuth\\ClientInterface'),
            $this->getMock('\\OAuth\\TokenStorageInterface')
        );

        $uri = $service->testDetermineRequestUriFromPath(
            'path?param1=value1',
            new Uri('https://example.com')
        );

        $this->assertInstanceOf('\\OAuth\\UriInterface', $uri);
        $this->assertSame('https://example.com/path?param1=value1', $uri->getAbsoluteUri());
    }

    /**
     * @covers OAuth\Service::__construct
     * @covers OAuth\Service::determineRequestUriFromPath
     */
    public function testDetermineRequestUriFromPathWithLeadingSlashInPath()
    {
        $service = new Mock(
            $this->getMock('\\OAuth\\CredentialsInterface'),
            $this->getMock('\\OAuth\\ClientInterface'),
            $this->getMock('\\OAuth\\TokenStorageInterface')
        );

        $uri = $service->testDetermineRequestUriFromPath(
            '/path',
            new Uri('https://example.com')
        );

        $this->assertInstanceOf('\\OAuth\\UriInterface', $uri);
        $this->assertSame('https://example.com/path', $uri->getAbsoluteUri());
    }
}