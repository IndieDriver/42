#!/usr/bin/php
<?php
	if ($argc == 2)
	{
		$str = $argv[1];
		$array = explode(" ", $str);
		$begin = FALSE;
		foreach($array as $value)
		{
			if (!$begin && !empty($value))
				$begin = TRUE;
			else if ($array[0] != $value && !empty($value))
				print " ";
			$trimed = trim($value);
			print "$trimed";
		}
		print("\n");
	}
?>
