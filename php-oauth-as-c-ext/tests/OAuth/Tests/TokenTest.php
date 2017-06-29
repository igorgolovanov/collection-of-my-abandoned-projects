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

use OAuth\Token;

class TokenTest extends \PHPUnit_Framework_TestCase
{
    /**
     * @covers OAuth\Token::__construct
     */
    public function testConstructCorrectInterface()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token');

        $this->assertInstanceOf('\\OAuth\\TokenInterface', $token);
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::getAccessToken
     */
    public function testGetAccessTokenNotSet()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token');

        $this->assertNull($token->getAccessToken());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::getAccessToken
     */
    public function testGetAccessTokenSet()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token', array('foo'));

        $this->assertSame('foo', $token->getAccessToken());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::getAccessToken
     * @covers OAuth\Token::setAccessToken
     */
    public function testSetAccessToken()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token');

        $token->setAccessToken('foo');

        $this->assertSame('foo', $token->getAccessToken());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::getRefreshToken
     */
    public function testGetRefreshToken()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token');

        $this->assertNull($token->getRefreshToken());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::getRefreshToken
     */
    public function testGetRefreshTokenSet()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token', array('foo', 'bar'));

        $this->assertSame('bar', $token->getRefreshToken());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::getRefreshToken
     * @covers OAuth\Token::setRefreshToken
     */
    public function testSetRefreshToken()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token');

        $token->setRefreshToken('foo');

        $this->assertSame('foo', $token->getRefreshToken());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::getExtraParams
     */
    public function testGetExtraParamsNotSet()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token');

        $this->assertSame(array(), $token->getExtraParams());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::getExtraParams
     */
    public function testGetExtraParamsSet()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token', array('foo', 'bar', null, array('foo', 'bar')));

        $this->assertEquals(array('foo', 'bar'), $token->getExtraParams());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::setExtraParams
     * @covers OAuth\Token::getExtraParams
     */
    public function testSetExtraParams()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token');

        $token->setExtraParams(array('foo', 'bar'));

        $this->assertSame(array('foo', 'bar'), $token->getExtraParams());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::setLifetime
     * @covers OAuth\Token::getEndOfLife
     */
    public function testGetEndOfLifeNotSet()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token');

        $this->assertSame(Token::LIFETIME_UNKNOWN, $token->getEndOfLife());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::setLifetime
     * @covers OAuth\Token::getEndOfLife
     */
    public function testGetEndOfLifeZero()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token', array('foo', 'bar', 0));

        $this->assertSame(Token::LIFETIME_NEVER_EXPIRES, $token->getEndOfLife());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::setLifetime
     * @covers OAuth\Token::getEndOfLife
     */
    public function testGetEndOfLifeNeverExpires()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token', array('foo', 'bar', Token::LIFETIME_NEVER_EXPIRES));

        $this->assertSame(Token::LIFETIME_NEVER_EXPIRES, $token->getEndOfLife());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::setLifetime
     * @covers OAuth\Token::getEndOfLife
     */
    public function testGetEndOfLifeNeverExpiresFiveMinutes()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token', array('foo', 'bar', 5 * 60));

        $this->assertSame(time() + (5 * 60), $token->getEndOfLife());
    }

    /**
     * @covers OAuth\Token::__construct
     * @covers OAuth\Token::setLifetime
     * @covers OAuth\Token::getEndOfLife
     * @covers OAuth\Token::setEndOfLife
     */
    public function testSetEndOfLife()
    {
        $token = $this->getMockForAbstractClass('\\OAuth\\Token');

        $token->setEndOfLife(10);

        $this->assertSame(10, $token->getEndOfLife());
    }
}