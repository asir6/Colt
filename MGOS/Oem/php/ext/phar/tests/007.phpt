--TEST--
Phar::mapPhar manifest too big
--SKIPIF--
<?php if (!extension_loaded("phar")) die("skip");?>
--FILE--
<?php
try {
Phar::mapPhar('hio');
} catch (Exception $e) {
echo $e->getMessage();
}
__HALT_COMPILER(); ?>~~~~
--EXPECTF--
manifest cannot be larger than 100 MB in phar "%s"
