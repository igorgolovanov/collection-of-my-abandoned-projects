/*
* This file is part of the php-ext-zf2 package.
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

namespace Zend\Stdlib;

/**
 * Wrapper for glob with fallback if GLOB_BRACE is not available.
 */
abstract class Glob
{
    const GLOB_MARK = 1;
    const GLOB_NOSORT = 2;
    const GLOB_NOCHECK = 4;
    const GLOB_NOESCAPE = 8;
    const GLOB_BRACE = 16;
    const GLOB_ONLYDIR = 32;
    const GLOB_ERR = 64;

    /**
     * Find pathnames matching a pattern.
     *
     * @see    http://docs.php.net/glob
     * @param  string  $pattern
     * @param  int $flags
     * @param  bool $forceFallback
     * @return array
     * @throws Exception\RuntimeException
     */
    public static function glob(string pattern, int flags = 0, boolean forceFallback = false) -> array
    {
        if defined("CLOB_BRACE") || forceFallback {
            return static::fallbackGlob(pattern, flags);
        }
        return static::systemGlob(pattern, flags);
    }

    /**
     * Use the glob function provided by the system.
     *
     * @param  string  $pattern
     * @param  int     $flags
     * @return array
     * @throws Exception\RuntimeException
     */
    protected static function systemGlob(string pattern, int flags) -> array
    {
        array flagMap;
        string exceptionMsg;
        int globFlags = 0, internatFlag, globFlag;
        var result, error;

        if flags {
            let flagMap = [
                self::GLOB_MARK : GLOB_MARK,
                self::GLOB_NOSORT : GLOB_NOSORT,
                self::GLOB_NOCHECK : GLOB_NOCHECK,
                self::GLOB_NOESCAPE : GLOB_NOESCAPE,
                self::GLOB_BRACE : GLOB_BRACE,
                self::GLOB_ONLYDIR : GLOB_ONLYDIR,
                self::GLOB_ERR : GLOB_ERR,
            ];

            for globFlag, internatFlag in flagMap {
                if flags & internatFlag {
                    let globFlags = globFlags | globFlag;
                }
            }
        }

        ErrorHandler::start();

        let result = glob(pattern, globFlags);
        let error = ErrorHandler::stop();

        if unlikely result === false {
            let exceptionMsg = "glob('%s', %d) failed";
            let exceptionMsg = sprintf(exceptionMsg, pattern, globFlags);

            throw new Exception\RuntimeException(exceptionMsg, 0, error);
        }

        return result;
    }

    /**
     * Expand braces manually, then use the system glob.
     *
     * @param  string  $pattern
     * @param  int     $flags
     * @return array
     * @throws Exception\RuntimeException
     */
    protected static function fallbackGlob(string pattern, int flags) -> array
    {
        int length;
        var begin = 0, next, rest, p;
        array paths = [], result;
        string subPattern;

        // todo: change self -> static
        if !flags & self::GLOB_BRACE {
            return static::systemGlob(pattern, flags);
        }

        let flags = flags & ~self::GLOB_BRACE;
        let length = pattern->length();

        if flags & self::GLOB_NOESCAPE {
            let begin = strpos(pattern, '{');
        } else {
            loop {
                if begin === length {
                    let begin = false;
                    break;
                }
                let p = begin + 1;
                if pattern[begin] === "\\\\" && p < length {
                    let begin = begin + 1;
                } else {
                    if pattern[begin] === "{" {
                        break;
                    }
                }
                let begin = begin + 1;
            }
        }

        if begin === false {
            return static::systemGlob(pattern, flags);
        }

        let p = begin + 1;
        let next = static::nextBraceSub(pattern, p, flags);
        if next === null {
            return static::systemGlob(pattern, flags);
        }

        let rest = next;

        while pattern[rest] !== "}" {
            let p = rest + 1;
            let rest = static::nextBraceSub(pattern, p, flags);
            if rest === null {
                return static::systemGlob(pattern, flags);
            }
        }

        let p = begin + 1;

        loop {
            let subPattern = substr(pattern, 0, begin);
            let subPattern = subPattern + substr(pattern, p, next - p);
            let subPattern = subPattern + substr(pattern, rest + 1);

            let result = static::fallbackGlob(subPattern, flags | self::GLOB_BRACE);

            if !empty result {
                let paths = array_merge(paths, result);
            }

            if pattern[next] === "}" {
                break;
            }

            let p = next + 1;
            let next = static::nextBraceSub(pattern, p, flags);
        }

        return array_unique(paths);
    }

    /**
     * Find the end of the sub-pattern in a brace expression.
     *
     * @param  string  $pattern
     * @param  int $begin
     * @param  int $flags
     * @return int|null
     */
    protected static function nextBraceSub(string pattern, int begin, int flags) -> int|null
    {
        int length, depth = 0, current;

        let current = begin;
        let length = pattern->length();

        while current < length {
            if !flags & self::GLOB_NOESCAPE && pattern[current] === "\\\\" {
                let current = current + 1;
                if current === length {
                    break;
                }
                let current = current + 1;
            } else {
                if pattern[current] === "}" && depth === 0 {
                    let depth = depth - 1;
                    break;
                }
                if pattern[current] === "," && depth === 0 {
                    break;
                }
                if pattern[current] === "{" {
                    let depth = depth + 1;
                }
                let current = current + 1;
            }
        }

        return current < length ? current : null;
    }

}
