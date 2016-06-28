<?php
	$login;
	$passwd;
	$submit;
	$error = FALSE;
	foreach ($_POST as $key=>$value)
	{
		if ($key == "login")
			$login = $value;
		if ($key == "passwd")
			$passwd = $value;
		if ($key == "submit")
			$submit = $value;
	}
	if ($login == "" || $passwd == "" || $submit != "OK")
		echo "ERROR\n";
	else
	{
		if (!file_exists("../htdocs"))
			mkdir ("../htdocs");
		if (!file_exists("../htdocs/private"))
			mkdir ("../htdocs/private");
		if (file_exists("../htdocs/private/passwd"))
		{
			$array = unserialize(file_get_contents("../htdocs/private/passwd"));
			foreach ($array as $val)
			{
				if ($val['login'] == $login)
					$error = TRUE;
			}
		}
		if (!$error)
		{
			$hash_pwd = hash("whirlpool", $passwd);
			$append = array (
				"login" => $login,
				"passwd" => $hash_pwd);
			$array[] = $append;
			$array = serialize($array);
			file_put_contents("../htdocs/private/passwd", $array);
			echo "OK\n";
		}
		else
			echo "ERROR\n";
	}
?>
