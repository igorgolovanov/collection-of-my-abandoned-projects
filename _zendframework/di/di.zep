
namespace Zend\Di;

class Di
{
    /**
         * Resolve method policy
         *
         * EAGER: explore type preference or go through
         */
        const RESOLVE_EAGER = 1;

        /**
         * Resolve method policy
         *
         * STRICT: explore type preference or throw exception
         */
        const RESOLVE_STRICT = 2;

        /**
         * use only specified parameters
         */
        const METHOD_IS_OPTIONAL = 0;

        /**
         * resolve mode RESOLVE_EAGER
         */
        const METHOD_IS_AWARE = 1;

        /**
         * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
         */
        const METHOD_IS_CONSTRUCTOR = 3;

        /**
         * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
         */
        const METHOD_IS_INSTANTIATOR = 3;

        /**
         * resolve mode RESOLVE_EAGER | RESOLVE_STRICT
         */
        const METHOD_IS_REQUIRED = 3;

        /**
         * resolve mode RESOLVE_EAGER
         */
        const METHOD_IS_EAGER = 1;
}