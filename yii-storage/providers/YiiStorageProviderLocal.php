<?php

/*
 * This file is part of the YiiStorage package.
 *
 * (c) Igor Golovanov <igor.golovanov@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

/**
 * @author  Igor Golovanov <igor.golovanov@gmail.com> 
 */
class YiiStorageProviderLocal extends YiiStorageProvider
{
    /**
     * @var string 
     */
    private $_directory;


    
    /**
     * Computes the path from the specified key
     *
     * @param  string $key The key which for to compute the path
     * 
     * @return string A path
     */
    public function computePath($key)
    {
        return $this->normalizePath($this->directory . DIRECTORY_SEPARATOR . $key);
    }
    
    /**
     * Computes the key from the specified path
     *
     * @param  string $path
     * 
     * @return string
     */
    public function computeKey($path)
    {
        $path = $this->normalizePath($path);        
        $key  = array_pop(explode('/', $path));
        
        return $key;
    }
    
    /**
     * Ensures the specified directory exists, creates it if it does not
     *
     * @param  string  $directory Path of the directory to test
     * @param  boolean $create    Whether to create the directory if it does
     *                            not exist
     * @return boolean
     */
    protected function createIfNotExistsDirectory($directory)
    {
        if(!is_dir($directory)) {
            $umask = umask(0);
            $created = mkdir($directory, 0777, true);
            umask($umask);
            return $created;
        }
        return true;
    }
    
    /**
     * Normalizes the given path
     *
     * @param  string $path Path.
     * 
     * @return string
     */
    protected function normalizePath($path)
    {
        $path   = str_replace('\\', '/', $path);
        
        preg_match('|^(?<prefix>([a-zA-Z]:)?/)|', $path, $matches);

        $prefix = empty($matches['prefix'])? '' : strtolower($matches['prefix']);
        $path   = substr($path, strlen($prefix));
        $parts  = array_filter(explode('/', $path), 'strlen');
        $tokens = array();

        foreach ($parts as $part) {
            switch ($part) {
                case '.':
                    continue;
                case '..':
                    if (0 !== count($tokens)) {
                        array_pop($tokens);
                        continue;
                    } else if (!empty($prefix)) {
                        continue;
                    }
                default:
                    $tokens[] = $part;
            }
        }

        return $prefix . implode('/', $tokens);
    }
}