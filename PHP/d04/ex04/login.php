<?php
	session_start();
	include ('auth.php');
	if (auth($_POST['login'], $_POST['passwd']))
	{
		$_REQUEST['login'] = $_POST['login'];
		echo '<html><body>
				<iframe src="chat.php" height="550" width="100%" frameborder="1"></iframe>
				<iframe src="speak.php" height="50" width="100%" frameborder="1"></iframe>
				</body></html>';
	}
	else
		$_REQUEST['loggued_on_user'] = "";
	//echo $_REQUEST['loggued_on_user'];
?>
