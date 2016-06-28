<?php
	if (isset($_POST['id']))
	{
		$array = array();
		$handle = fopen("list.csv", "c+");
		$line = "";
		while (($data = fgetcsv($handle)) != FALSE)
		{
			$data = explode(";", $data[0]);
			if ($data[0] != $_POST['id']) {
				$line .= $data[0].";".$data[1]."\n";
			}
		}
		fclose($handle);
		file_put_contents('list.csv', $line);
	}
?>
