<?php
	$action;
	$name;
	$val;
	foreach ($_GET as $key=>$value)
	{
		if ($key == "action")
			$action = $value;
		if ($key == "name")
			$name = $value;
		if ($key == "value")
			$val = $value;
	}
	if ($action == "set")
		setcookie($name, $value, time()+3600);
	if ($action == "get")
		echo $_COOKIE[$name]."\n";
	if ($action == "del")
		setcookie($name);
?>
