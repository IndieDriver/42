<?php
	if ($_POST['value'])
	{
		$handle = fopen("list.csv", "c+");
		rewind($handle);
		$data = fgetcsv($handle);
		$id = 0;
		if ($data)
		{
			$new = explode(";", $data[0]);
			$id = $new[0] + 1;
		}
		fclose($handle);
		$line = $id.";".$_POST['value']."\n";
		$line .= file_get_contents("list.csv");
		file_put_contents("list.csv", $line);
		echo $id;
	}
?>
