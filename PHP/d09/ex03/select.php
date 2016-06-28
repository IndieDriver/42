<?php
	$array = array();
	$handle = fopen("list.csv", "r");
	while (($data = fgetcsv($handle)) != FALSE)
	{
		$data = explode(";", $data[0]);
		$array[] = array(
		"id" => $data[0],
		"todo" => $data[1]
		);
	}
	fclose($handle);
	echo json_encode($array);
?>
