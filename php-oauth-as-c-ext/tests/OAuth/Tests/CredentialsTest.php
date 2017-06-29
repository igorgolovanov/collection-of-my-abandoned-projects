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

use OAuth\Credentials;

/**
 * Test for OAuth\Credentials class
 */
class CredentialsTest extends \PHPUnit_Framework_TestCase
{
	/**
	 * @var OAuth\Credentials
	 */
	private $credentials;

	public function setUp()
	{
		$this->credentials = new Credentials('abc', 'def', 'http://oauth.local');
	}

	public function tearDown()
	{
		$this->credentials = null;
	}

	public function testInterfaceImplements()
	{
		$this->assertInstanceOf('\\OAuth\\CredentialsInterface', $this->credentials, sprintf('Class %s must implements interface OAuth\\CredentialsInterface', get_class($this->credentials)));
	}

	/**
	 * Test method getConsumerId
	 */
	public function testGetConsumerId()
    {
        $consumerId = $this->credentials->getConsumerId();

        $this->assertEquals('abc', $consumerId, 'Invalid consumer ID');
    }

    /**
	 * Test method getConsumerSecret
	 */
    public function testGetConsumerSecret()
    {
        $consumerSecret = $this->credentials->getConsumerSecret();

        $this->assertEquals('def', $consumerSecret, 'Invalid consumer secret');
    }

    /**
	 * Test method getCallbackUrl
	 */
    public function testGetCallbackUrl()
    {
        $callbackUrl = $this->credentials->getCallbackUrl();

        $this->assertEquals('http://oauth.local', $callbackUrl, 'Invalid callback url');
    }
}