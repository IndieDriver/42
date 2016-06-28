<?php
	$style = $_POST['style'];
	$order = $_POST['order'];
	$years = $_POST['years'];
	if ($_POST['bask'])
	{
		$item_id = $_POST['bask'];
		$quantity = 1;
		$found = FALSE;
		if ($_SESSION['basket'])
		{
			foreach ($_SESSION['basket'] as &$val)
			{
				if ($val['item_id'] == $item_id)
				{
					$found = TRUE;
					$quantity = $val['quantity'] + 1;
					$val['quantity'] = $quantity;
				
				}
			}
			if (!$found)
			{
				$_SESSION['basket'][] = array(
					"item_id" => $item_id,
					"quantity" => $quantity
				);
			}
		}
		else
		{
			$_SESSION['basket'][] = array(
				"item_id" => $item_id,
				"quantity" => $quantity
			);
		}
	}
?>

<link rel="stylesheet" href="style.css" />
<nav>
    <form action="" method="post">
        <p>
        	<label class="labell "for="form_genre" style="margin-left: 1%">Par prix</label>
            <select class="checkbox" id="form_genre" name="order" onchange='this.form.submit()'>
                <option <?php if ($order == "ASC" || $order == "") echo " selected "; ?> value="ASC">ordre croissant</option>
                <option <?php if ($order == "DESC") echo " selected "; ?> value="DESC">ordre decroissant</option>
            </select>
			<label class="labell" for="form_genre">Par genre</label>
            <select class="checkbox" id="form_genre" name="style" onchange='this.form.submit()'>
				<option <?php if ($style == "all") echo " selected ";?> value="all">Tous</option>
        		<option <?php if ($style == "Action") echo " selected ";?> value="Action">Action</option>
        		<option <?php if ($style == "Aventure") echo " selected ";?> value="Aventure">Aventure</option>
        		<option <?php if ($style == "Animation") echo " selected ";?> value="Animation">Animation</option>
        		<option <?php if ($style == "Thriller") echo " selected ";?> value="Thriller">Thriller</option>
            </select>
			<label class="labell" for="form_genre">Par annees</label>
			<select class="checkbox" id="form_genre" name="years" onchange='this.form.submit()'>
				<option <?php if ($years == "all") echo " selected ";?> value="all">Toutes</option>
				<option <?php if ($years == "1970") echo " selected ";?> value="1970">1970-1979</option>
        		<option <?php if ($years == "1980") echo " selected ";?> value="1980">1980-1989</option>
        		<option <?php if ($years == "1990") echo " selected ";?> value="1990">1990-1999</option>
        		<option <?php if ($years == "2000") echo " selected ";?> value="2000">2000-2009</option>
        		<option <?php if ($years == "2010") echo " selected ";?> value="2010">2010-2019</option>
            </select>
		</p>
    </form>
    <hr class="line1">
</nav>
<div style="display: block">
<?php
	include ("mysql.php");
	$con = mysqli_connect($mhost, $muser, $mpwd, "rush00");
	if (mysqli_connect_errno())
		echo "Failed to connect to server";
	$years2 = $years + 9;
	if ($style == "" || $style == "all")
	{
		if ($years == "all" || $years == "")
		{
			if ($order == "" || $order == "ASC")
				$result = mysqli_query($con,
				"SELECT item_id, price, name, remaining, style, img_path FROM articles ORDER BY item_id ASC;");
			else
				$result = mysqli_query($con,
				"SELECT item_id, price, name, remaining, style, img_path FROM articles ORDER BY item_id DESC;");
		}
		else
		{
			if ($order == "" || $order == "ASC")
				$result = mysqli_query($con,
				"SELECT item_id, price, name, remaining, style, img_path FROM articles WHERE year BETWEEN ".$years." AND ".$years2." ORDER BY item_id ASC;");
			else
				$result = mysqli_query($con,
				"SELECT item_id, price, name, remaining, style, img_path FROM articles WHERE year BETWEEN ".$years." AND ".$years2." ORDER BY item_id DESC;");
		}
	}
	else
	{
		if ($years == "all" || $years == "")
		{
			if ($order == "" || $order == "ASC")
				$result = mysqli_query($con,
				"SELECT item_id, price, name, remaining, style, img_path FROM articles WHERE style LIKE '%".$style."%' ORDER BY item_id ASC;");
			else
				$result = mysqli_query($con,
				"SELECT item_id, price, name, remaining, style, img_path FROM articles WHERE style LIKE '%".$style."%' ORDER BY item_id DESC;");
		}
		else
		{
			if ($order == "" || $order == "ASC")
				$result = mysqli_query($con,
				"SELECT item_id, price, name, remaining, style, img_path FROM articles WHERE year BETWEEN ".$years." AND ".$years2." AND style LIKE '%".$style."%' ORDER BY item_id ASC;");
			else
				$result = mysqli_query($con,
				"SELECT item_id, price, name, remaining, style, img_path FROM articles WHERE year BETWEEN ".$years." AND ".$years2." AND style LIKE '%".$style."%' ORDER BY item_id DESC;");
		}
	}
	if (mysqli_num_rows($result) > 0)
	{
		while ($row = mysqli_fetch_assoc($result))
		{
			echo '<div class="dvd">
					<form action="" method="post">
						<img class="imga" src="'.$row['img_path'].'">
						<p style="margin-top: 9%">'.$row['name'].' ('.$row['price'].'&euro;)
						<input type="image" class=basket src="basket.png" name="bask" value="'.$row['item_id'].'"></p>
					</form>
				</div>';
		}
		mysqli_free_result($result);
	}
?>
</div>
