<?php
	session_start();
	include ('auth.php');
	if (auth($_POST['login'], $_POST['passwd']))
	{
		$_SESSION['loggued_on_user'] = $_POST['login'];
		include ("mysql.php");
		$con = mysqli_connect($mhost, $muser, $mpwd, "rush00");
		if (mysqli_connect_errno())
			echo "Failed to connect to server";
		$result = mysqli_query($con,
				"SELECT items FROM baskets WHERE user_id='".$_POST['login']."';");
		if (mysqli_num_rows($result) > 0)
		{
			$row = mysqli_fetch_assoc($result);
			$_SESSION['basket'] = unserialize($row['items']);
		}
		header('Location: index.php');
	}
	else
		$_SESSION['loggued_on_user'] = "";
?>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Account</title>
</head>
<body>
<?php include 'head.php' ?>
<form id="monForm" action="#" method="post">
	<fieldset>
    	<legend class="legendd" style="color: #ff8a00">Connexion</legend>
		<p>
        	<label class="label" style="color: #FFAB4A" for="form_login">Identifiant : </label>
        	<input type="text" id="form_login" name="login" />
    	</p>
		<p>
        	<label class="labell" for="form_genre">Mot de passe : </label>
        	<input type="password" id="passwd" name="passwd">
    	</p>
	</fieldset>
	<p>
    	<input type="submit" name="submit" value="OK"/>
	</p>
</form>
</body>
</html>
