--TEST--
ldap_mod_add() - ldap_mod_add() operations that should fail
--CREDITS--
Patrick Allaert <patrickallaert@php.net>
# Belgian PHP Testfest 2009
--SKIPIF--
<?php require_once('skipif.inc'); ?>
<?php require_once('skipifbindfailure.inc'); ?>
--FILE--
<?php
require "connect.inc";

$link = ldap_connect_and_bind($host, $port, $user, $passwd, $protocol_version);

// Too few parameters
var_dump(ldap_mod_add());
var_dump(ldap_mod_add($link));
var_dump(ldap_mod_add($link, "dc=my-domain,dc=com"));

// Too many parameters
var_dump(ldap_mod_add($link, "dc=my-domain,dc=com", array(), "Additional data"));

// DN not found
var_dump(ldap_mod_add($link, "dc=my-domain,dc=com", array()));

// Invalid DN
var_dump(ldap_mod_add($link, "weirdAttribute=val", array()));

$entry = array(
	"objectClass"	=> array(
		"top",
		"dcObject",
		"organization"),
	"dc"			=> "my-domain",
	"o"				=> "my-domain",
);

ldap_add($link, "dc=my-domain,dc=com", $entry);

$entry2 = $entry;
$entry2["dc"] = "Wrong Domain";

var_dump(ldap_mod_add($link, "dc=my-domain,dc=com", $entry2));

$entry2 = $entry;
$entry2["weirdAttribute"] = "weirdVal";

var_dump(ldap_mod_add($link, "dc=my-domain,dc=com", $entry2));
?>
===DONE===
--CLEAN--
<?php
require "connect.inc";

$link = ldap_connect_and_bind($host, $port, $user, $passwd, $protocol_version);

ldap_delete($link, "dc=my-domain,dc=com");
?>
--EXPECTF--
Warning: ldap_mod_add() expects exactly 3 parameters, 0 given in %s on line %d
NULL

Warning: ldap_mod_add() expects exactly 3 parameters, 1 given in %s on line %d
NULL

Warning: ldap_mod_add() expects exactly 3 parameters, 2 given in %s on line %d
NULL

Warning: ldap_mod_add() expects exactly 3 parameters, 4 given in %s on line %d
NULL

Warning: ldap_mod_add(): Modify: No such object in %s on line %d
bool(false)

Warning: ldap_mod_add(): Modify: Invalid DN syntax in %s on line %d
bool(false)

Warning: ldap_mod_add(): Modify: Type or value exists in %s on line %d
bool(false)

Warning: ldap_mod_add(): Modify: Undefined attribute type in %s on line %d
bool(false)
===DONE===
