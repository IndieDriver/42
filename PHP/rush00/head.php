<link rel="stylesheet" href="style.css" xmlns="http://www.w3.org/1999/html"/>
<hr class="line1" >
<header>
<?php
	if ($_SESSION['loggued_on_user'] != "")
	{
		echo '<div id="header_log"><span class="insc">Bienvenue '.$_SESSION['loggued_on_user']
		.'<a class="insc" href="logout.php">(logout)</a>';
		if ($_SESSION['perm'] == "lulz")
			echo '| </span><a class="insc" href="admin1.php">Admin</a></div>';
		else
			echo '</span></div>';
	}
	else
	{
		echo '
		<div>
    		<a style="margin-left: 75%" class="insc" href="add.php"> <p>Inscription |</p></a>
			<a class="insc" href="connect.php"><p>Connexion</p></a><a class="insc" href="admin1.php"><p> | Admin		</p></a>
		</div>';
	}	
?>
    <a href="index.php">
    <img src="http://www.iconarchive.com/download/i94996/mahm0udwally/all-flat/DVD-CD.ico" width="10%"
			style="float: left"></a>
		<h1 class="headd"><a href="index.php">Accueil</a> | <a href="basket.php">Panier
<?php
	if ($_SESSION['basket'])
	{
		$count = 0;
		$total_price = 0;
		foreach($_SESSION['basket'] as $val)
		{
			$count++;
		}
		echo '(articles: '.$count.')';
	}
?>
	</a></h1>
    <hr class="line1">
</header>
