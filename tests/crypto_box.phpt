--TEST--
Check for libsodium box
--SKIPIF--
<?php if (!extension_loaded("libsodium")) print "skip"; ?>
--FILE--
<?php
$keypair = crypto_box_keypair();
var_dump(strlen($keypair) === CRYPTO_BOX_KEYPAIRBYTES);
$sk = crypto_box_secretkey($keypair);
var_dump(strlen($sk) === CRYPTO_BOX_SECRETKEYBYTES);
$pk = crypto_box_publickey($keypair);
var_dump(strlen($pk) === CRYPTO_BOX_PUBLICKEYBYTES);
var_dump($pk !== $sk);
$pk2 = crypto_box_publickey_from_secretkey($sk);
var_dump($pk === $pk2);
$keypair2 = crypto_box_keypair_from_secretkey_and_publickey($sk, $pk);
var_dump($keypair === $keypair2);

$nonce = randombytes_buf(CRYPTO_BOX_NONCEBYTES);

$a = crypto_box('test', $nonce, $keypair);
$x = crypto_box_open($a, $nonce, $keypair);
var_dump(bin2hex($x));
$y = crypto_box_open("\0" . $a, $nonce, $keypair);
var_dump($y);
?>
--EXPECT--
bool(true)
bool(true)
bool(true)
bool(true)
bool(true)
bool(true)
string(8) "74657374"
bool(false)

