<?php
	$login;
	$oldpw;
	$newpw;
	$submit;
	$error = FALSE;
	$found = FALSE;
	foreach ($_POST as $key=>$value)
	{
		if ($key == "login")
			$login = $value;
		if ($key == "oldpw")
			$oldpw = $value;
		if ($key == "newpw")
			$newpw = $value;
		if ($key == "submit")
			$submit = $value;
	}
	if ($login == "" || $oldpw == "" || $newpw == "" || $submit != "OK")
		echo "ERROR\n";
	else
	{
		$array = unserialize(file_get_contents("../htdocs/private/passwd"));
		$hash_oldpw = hash("whirlpool", $oldpw);	
		foreach ($array as &$val)
		{
			if ($val['login'] == $login)
			{
				$found = TRUE;
				if ($val['passwd'] == $hash_oldpw)
				{
					$hash_newpw = hash("whirlpool", $newpw);
					$val['passwd'] = $hash_newpw;
				}
				else
					$error = TRUE;
			}
		}
		if (!$error && $found)
		{
			$array = serialize($array);
			file_put_contents("../htdocs/private/passwd", $array);
			echo "OK\n";
		}
		else
			echo "ERROR\n";
	}
?>
