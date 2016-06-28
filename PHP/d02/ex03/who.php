#!/usr/bin/php
<?php
	$file_str = file_get_contents("/var/run/utmpx");
	$template = "a256a/a4b/a32c/id/ie/I2f";
	print "$template_size\n";
	$array = str_split($file_str, 628);
	print_r($array);
	foreach ($array as $val)
	{
		$lulz = unpack($template, $val);
		var_dump($lulz);
		//print_r($lulz);
	}
   //}
?>
