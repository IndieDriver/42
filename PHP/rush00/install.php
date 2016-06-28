<?php
	include ("mysql.php");
	$con = mysqli_connect($mhost, $muser, $mpwd);
	//var_dump($con);
	if (mysqli_connect_errno())
		echo "Failed to connect to server";
	mysqli_query($con, "DROP DATABASE rush00");
	mysqli_query($con, "CREATE DATABASE rush00;");
	$con = mysqli_connect($mhost, $muser, $mpwd, "rush00");
	if (mysqli_connect_errno())
		echo "Failed to connect to server";
	mysqli_query($con, "CREATE TABLE users (user_id int NOT NULL AUTO_INCREMENT, login varchar(255), passwd varchar(255), basket_id int, name varchar(255), lastname varchar(255), PRIMARY KEY (user_id));");
	mysqli_query($con, "CREATE TABLE articles (item_id int NOT NULL AUTO_INCREMENT, price int,name varchar(255), remaining int, style varchar(255), year int,img_path varchar(255), PRIMARY KEY (item_id));");
	mysqli_query($con, "CREATE TABLE baskets (basket_id int NOT NULL AUTO_INCREMENT, user_id varchar(255),items varchar(1024), PRIMARY KEY (basket_id));");
	mysqli_query($con, "INSERT INTO articles (price, name, remaining, style, year, img_path) VALUES "
	."('5','Le Parrain', '42', 'Action', '1972', 'http://papystreaming.com/fr/files/2012/12/Le-Parrain-148x213.jpg')"
	.",('6','Le Parrain 2', '24', 'Action', '1974', 'http://i43.tower.com/images/mm109140829/godfather-part-ii-al-pacino-vhs-cover-art.jpg')"
	.",('6','Le Parrain 3', '24', 'Action', '1990', 'https://upload.wikimedia.org/wikipedia/en/5/55/GodfatherIII2.jpg')"
	.",('6','Pulp Fiction', '24', 'Action', '1994', 'http://papystreaming.com/fr/files/2012/06/Pulp-Fiction1-148x220.jpg')"
	.",('2','Taxi Driver', '24', 'ActionThriller', '1976', 'http://t1.gstatic.com/images?q=tbn:ANd9GcQ4QYpWCQ5pareSyOO3YNI3YsOmAeF4qcRDwHCDwf3-a3F0Y7N6')"
	.",('10','Film The Origin', '24', 'Action', '2012', 'https://upload.wikimedia.org/wikipedia/commons/d/d2/Question_mark.svg')"
	.",('4','Film The return', '24', 'Animation', '2000', 'https://upload.wikimedia.org/wikipedia/commons/d/d2/Question_mark.svg')"
	.",('3','Film resurection','3','AventureAction', '2001', 'https://upload.wikimedia.org/wikipedia/commons/d/d2/Question_mark.svg')"
	.",('2','Film','3','ThrillerAction', '1995', 'https://upload.wikimedia.org/wikipedia/commons/d/d2/Question_mark.svg')"
	.",('5','Fight Club', '3', 'Thriller', '1999','http://papystreaming.com/fr/files/2012/11/MV5BMTc1ODg1NTMxNV5BMl5BanBnXkFtZTYwOTg4Njk4._V1._SY317_CR40214317_-148x220.jpg');");
?>
