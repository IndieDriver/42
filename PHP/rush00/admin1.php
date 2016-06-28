<?php
	include 'head.php';
	include ("mysql.php");
	$style;
	if ($_POST['Action'])
		$style.="Action";
	if ($_POST['Aventure'])
		$style.="Aventure";
	if ($_POST['Animation'])
		$style.="Animation";
	if ($_POST['Thriller'])
		$style.="Thriller";
	$con = mysqli_connect($mhost, $muser, $mpwd, "rush00");
	if (mysqli_connect_errno())
		echo "Failed to connect to server";
	if ($_POST['submit'] == "OK")
	{
		$query = "INSERT INTO articles (price, name, remaining, style, year, img_path) VALUES ('".$_POST['price']."', '".$_POST['film']."', '42', '".$style."', '".$_POST['year']."', '".$_POST['img_path']."');";
		mysqli_query($con, $query);
	}
?>
<form id="monForm" action="admin1.php" method="POST" enctype="multipart/form-data">
    <fieldset>
        <legend class="legendd" >Update</legend>
        <p>
            <label class="labell" for="form_film">Nom du Film : </label>
            <input type="text" id="form_film" name="film"/>
        </p>
        <p>
            <label name="form_genre" for="form_genre">Genre : </br></label>
            <input name="Action" type="checkbox"/> <label>Action</label><br />
            <input name="Aventure" type="checkbox"/> <label>Aventure</label><br />
            <input name="Animation" type="checkbox"/> <label >Animation</label><br />
            <input name="Thriller" type="checkbox"/> <label >Thriller</label></br>
			</br>
			<label class="labell" for="form_film">Image du Film :</label>
            <input type="text" id="form_film" name="img_path"/> </br>
			<p>
				<label class="labell" for="form_film">Annee :</label>
            	<input type="text" id="form_film" name="year"/> </br>
			</p>
			<p>
				<label class="labell" for="form_film">Prix :</label>
            	<input type="text" id="form_film" name="price"/> </br>
			</p>

		</p>	
		<input type="submit" name="submit" value="OK">

    </fieldset>
</form>
<?php

	include ("mysql.php");
	$con = mysqli_connect($mhost, $muser, $mpwd, "rush00");
	if (mysqli_connect_errno())
		echo "Failed to connect to server";
	$result = mysqli_query($con, "SELECT * FROM users;");
	echo '<table>';
	while ($row = mysqli_fetch_assoc($result))
	{
		echo '<tr>
				<td>'.$row['login'].'</td>
				<td><form action="" method="post">
						<input type="image"
						src="http://icons.veryicon.com/ico/System/Icons8%20Metro%20Style/System%20Delete.ico"
						name="delete" value="'.$row['user_id'].'">
					</form>
				</td>
			</tr>';
	}
	echo '</table>';
?>
