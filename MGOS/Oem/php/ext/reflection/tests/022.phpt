--TEST--
ReflectionClass::getConstant
--SKIPIF--
<?php extension_loaded('reflection') or die('skip'); ?>
--FILE--
<?php
class Foo {
	const c1 = 1;
}
$class = new ReflectionClass("Foo");
var_dump($class->getConstant("c1"));
var_dump($class->getConstant("c2"));
?>
--EXPECT--	
int(1)
bool(false)
