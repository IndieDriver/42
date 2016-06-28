<?php
	$login;
	$passwd;
	$passwd1;
	$first_name;
	$last_name;
	$submit;
	foreach ($_POST as $key=>$value)
	{
		if ($key == "login")
			$login = $value;
		if ($key == "password")
			$passwd = $value;
		if ($key == "password2")
			$passwd1 = $value;
		if ($key == "firstname")
			$first_name = $value;
		if ($key == "lastname")
			$last_name = $value;
		if ($key == "submit")
			$submit = $value;
	}
	if ($passwd == $passwd1)
		$login == "";
	if ($login != "" && $passwd != "" && $submit == "OK" && $first_name != "" && $last_name != "")
	{
		include ("mysql.php");
		$con = mysqli_connect($mhost, $muser, $mpwd, "rush00");
		if (mysqli_connect_errno())
				echo "Failed to connect to server";
		$stmt = mysqli_prepare($con,"SELECT login FROM users WHERE login=?");
		mysqli_stmt_bind_param($stmt, "s", $login);
		mysqli_stmt_execute($stmt);
		$result = mysqli_stmt_get_result($stmt);
		if (mysqli_num_rows($result) == 0)
		{
			$hash_pwd = hash("whirlpool", $passwd);
			mysqli_query($con, "INSERT INTO users (login, passwd, name, lastname) VALUES ('".$login."','".$hash_pwd."','".$first_name."','".$last_name."')");
			header('Location: index.php');
		}
		else
			echo "USER ALREADY EXISTS\n";
	}
	
?>
<?php include('head.php'); ?>
<form id="monForm" action="#" method="post">
    <fieldset>
        <legend class="legendd">Informations personnelles</legend>
        <p>
            <label class="labell" for="form_firstname">Prénom : </label>
            <input type="text" id="form_firstname" name="firstname" />
        </p>
        <p>
            <label class="labell" for="form_lastname">Nom : </label>
            <input type="text" id="form_lastname" name="lastname" />
        </p>
    </fieldset>

    <fieldset>
        <legend class="legendd">Compte</legend>
        <p>
            <label class="labell" for="form_login">Identifiant : </label>
            <input type="text" id="form_login" name="login" />
        </p>
        <p>
            <label class="labell" for="form_password">Mot de passe : </label>
            <input type="password" id="form_password" name="password" />
        </p>
        <p>
            <label class="labell" for="form_password2">Confirmer le mot de passe : </label>
            <input type="password" id="form_password2" name="password2" />
        </p>
    </fieldset>

    <p>
        <input type="submit" name="submit" value="OK"/>
    </p>
</form>

