--TEST--
Test variations in usage of sinh()
--INI--
precision = 10
--FILE--
<?php
/* 
 * proto float sinh(float number)
 * Function is implemented in ext/standard/math.c
*/ 


//Test sinh with a different input values

$values = array(23,
		-23,
		2.345e1,
		-2.345e1,
		0x17,
		027,
		"23",
		"23.45",
		"2.345e1",
		"nonsense",				
		"1000",
		"1000ABC",
		null,
		true,
		false);	

for ($i = 0; $i < count($values); $i++) {
	$res = sinh($values[$i]);
	var_dump($res);
}

?>
--EXPECTF--
float(4872401723)
float(-4872401723)
float(7641446995)
float(-7641446995)
float(4872401723)
float(4872401723)
float(4872401723)
float(7641446995)
float(7641446995)

Warning: sinh() expects parameter 1 to be double, string given in %s on line %d
NULL
float(INF)

Notice: A non well formed numeric value encountered in %s on line %d
float(INF)
float(0)
float(1.175201194)
float(0)
