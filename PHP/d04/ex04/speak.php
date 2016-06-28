<?php
	session_start();
	var_dump($_REQUEST);
	print $_REQUEST['login'] . "ntm amathias\n";
	echo '<html><body>';
	//if ($_REQUEST['loggued_on_user'])
	//{
		echo '<form action="speak.php" method="post">
				<input type="text" name="msg" value=""><br />
			</form>';
	$login;
	$time;
	$msg;
	foreach ($_POST as $key=>$value)
	{
		if ($key == "msg")
			$msg = $value;
	}
	if (!file_exists("../htdocs"))
		mkdir ("../htdocs");
	if (!file_exists("../htdocs/private"))
		mkdir ("../htdocs/private");
	if (file_exists("../htdocs/private/chat"))
	$array = unserialize(file_get_contents("../htdocs/private/chat"));
	$hash_pwd = hash("whirlpool", $passwd);
	$time = time();
	$append = array (
		"login" => $login,
		"time" => $time,
		"msg" => $msg);
	$array[] = $append;
	$array = serialize($array);
	file_put_contents("../htdocs/private/chat", $array);

	//}
?>
</body></html>
