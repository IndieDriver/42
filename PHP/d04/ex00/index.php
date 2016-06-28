<?php	
	session_start();
	$login = $_SESSION['login'];
	$passwd = $_SESSION['passwd'];
	$submit;
	foreach ($_GET as $key=>$value)
	{
		if ($key == "login")
			$login = $value;
		if ($key == "passwd")
			$passwd = $value;
		if ($key == "submit")
			$submit = $value;
	}
	echo '<html><body>
<form action="index.php" method="get">
	Identifiant: <input type="text" name="login" value="'.$login.'"><br />
	Mot de passe: <input type="password" name="passwd" value="'.$passwd.'">
	<input type="submit" name="submit" value="OK">
</form>';
	if ($submit == "OK")
	{
		$_SESSION['login'] = $login;
		$_SESSION['passwd'] = $passwd;
	}
?>
</body></html>
