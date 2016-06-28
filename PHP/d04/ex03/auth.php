<?php
function auth($login, $passwd)
{
	$array = unserialize(file_get_contents("../htdocs/private/passwd"));
	$hashed = hash("whirlpool", $passwd);
	foreach ($array as $val)
	{
		if ($val['login'] == $login)
		{
			if ($val['passwd'] == $hashed)
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}
?>
