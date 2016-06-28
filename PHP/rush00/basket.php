<?php session_start();
	include ("mysql.php");
	$con = mysqli_connect($mhost, $muser, $mpwd, "rush00");
	if (mysqli_connect_errno())
		echo "Failed to connect to server";
	
	if ($_POST['arch'] == "Archive")
	{
		if ($_SESSION['loggued_on_user'])
		{
			$bask = serialize($_SESSION['basket']);
			mysqli_query($con, "INSERT INTO baskets (user_id, items) VALUES ('".$_SESSION['loggued_on_user'].
				"','".$bask."');");
		}
		else
			header('Location: add.php');
	}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="http://www.w3schools.com/lib/w3.css">
    <link rel="stylesheet" href="style.css" />
    <title>panier</title>
</head>
<body>
<div class="w3-row-padding">
    <div class="third">
		<?php include('head.php'); ?>
    </div>

<?php
	if ($_SESSION['basket'])
	{
		if ($_POST['elem'])
		{
			$i = 0;
			foreach ($_SESSION['basket'] as $val)
			{
				if ($val['item_id'] == $_POST['elem'])
				{
					$offset = $i;
				}
				$i++;
			}
			array_splice($_SESSION['basket'], $offset, 1);
		}
	echo '<div class="panier">';
	$total_price = 0;
	foreach($_SESSION['basket'] as $val)
	{
		$item_id = $val['item_id'];
		$quantity = $val['quantity'];
		include ("mysql.php");
		$con = mysqli_connect($mhost, $muser, $mpwd, "rush00");
		if (mysqli_connect_errno())
			echo "Failed to connect to server";
		$result = mysqli_query($con, "SELECT * FROM articles WHERE item_id='".$item_id."';");
		if (mysqli_num_rows($result) > 0)
		{
			$row = mysqli_fetch_assoc($result);
			$price = $row['price'] * $quantity;
			$total_price += $price;
			echo '<div class="panier_item">
				<img src="'.$row['img_path'].'">
				<p>'.$row['name'].' ('.$row['year'].')</p>
				<p>Quantite: '.$quantity.'</p>
				<p>Prix: '.$price.'&euro;</p>
				<form action="" method="post">
				<input type="image"
				src="http://icons.veryicon.com/ico/System/Icons8%20Metro%20Style/System%20Delete.ico"
				name="elem" value="'.$item_id.'">
				</form>
				</div>';
		}
	}
	echo '<p>Prix total: '.$total_price.'&euro;</p>
			<form action="" method="post">
				<input type="submit"
				name="arch" value="Archive">';
}
?>
</div>
</body>
</html>
