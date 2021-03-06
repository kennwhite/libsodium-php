/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_LIBSODIUM_H
#define PHP_LIBSODIUM_H

extern zend_module_entry libsodium_module_entry;
#define phpext_libsodium_ptr &libsodium_module_entry

#define PHP_LIBSODIUM_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#       define PHP_LIBSODIUM_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#       define PHP_LIBSODIUM_API __attribute__ ((visibility("default")))
#else
#       define PHP_LIBSODIUM_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(libsodium);
PHP_MSHUTDOWN_FUNCTION(libsodium);
PHP_RINIT_FUNCTION(libsodium);
PHP_RSHUTDOWN_FUNCTION(libsodium);
PHP_MINFO_FUNCTION(libsodium);

PHP_FUNCTION(sodium_version_string);
PHP_FUNCTION(sodium_library_version_major);
PHP_FUNCTION(sodium_library_version_minor);
PHP_FUNCTION(sodium_memzero);
PHP_FUNCTION(sodium_memcmp);
PHP_FUNCTION(randombytes_buf);
PHP_FUNCTION(randombytes_random16);
PHP_FUNCTION(randombytes_uniform);
PHP_FUNCTION(crypto_shorthash);
PHP_FUNCTION(crypto_secretbox);
PHP_FUNCTION(crypto_secretbox_open);
PHP_FUNCTION(crypto_generichash);
PHP_FUNCTION(crypto_box_keypair);
PHP_FUNCTION(crypto_box_keypair_from_secretkey_and_publickey);
PHP_FUNCTION(crypto_box_secretkey);
PHP_FUNCTION(crypto_box_publickey);
PHP_FUNCTION(crypto_box_publickey_from_secretkey);
PHP_FUNCTION(crypto_box);
PHP_FUNCTION(crypto_box_open);

#ifdef ZTS
#define LIBSODIUM_G(v) TSRMG(libsodium_globals_id, zend_libsodium_globals *, v)
#else
#define LIBSODIUM_G(v) (libsodium_globals.v)
#endif

#endif  /* PHP_LIBSODIUM_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
