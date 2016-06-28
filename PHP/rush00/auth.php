<?php
function auth($login, $passwd)
{
	include ("mysql.php");
	$hashed = hash("whirlpool", $passwd);
	$con = mysqli_connect($mhost, $muser, $mpwd, "rush00");
	if (mysqli_connect_errno())
		echo "Failed to connect to server";
	$result = mysqli_query($con,
				"SELECT login, passwd FROM users WHERE login='".$login."' AND passwd='".$hashed."';");
	if (mysqli_num_rows($result) > 0)
		return TRUE;
	return FALSE;
}
?>
