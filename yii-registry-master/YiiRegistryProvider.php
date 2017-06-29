<?php
/*
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This software consists of voluntary contributions made by many individuals
 * and is licensed under the LGPL. For more information, see
 * <http://www.yiilabs.com>.
 * 
 * @license     http://www.opensource.org/licenses/lgpl-license.php LGPL
 * @link        www.yiilabs.com
 * @copyright   Copyright (c) 2011 Yii Labs. (http://www.yiilabs.com)
 */

/**
 * YiiRegistry provider interface.
 * 
 * @license     http://www.opensource.org/licenses/lgpl-license.php LGPL
 * @link        www.yiilabs.com
 * @copyright   Copyright (c) 2011 Yii Labs. (http://www.yiilabs.com)
 * @author      Igor Golovanov <igor.golovanov@gmail.com>
 */
interface YiiRegistryProvider extends ArrayAccess, Countable
{
    /**
     * Set.
     * 
     * @param string $key Key.
     * @param mixed $value Value.
     * 
     * @return boolean
     */
    function set($key, $value);
    
    /**
     * Get.
     * 
     * @param string $key Key.
     * 
     * @return mixed
     */
    function get($key);
    
    /**
     * Exists.
     * 
     * @param string $key Key.
     * 
     * @return boolean
     */
    function exists($key);
    
    /**
     * To array.
     * 
     * @return array
     */
    function toArray();
    
    /**
     * Remove.
     * 
     * @param string $key Key.
     * 
     * @return boolean
     */
    function remove($key);
    
}