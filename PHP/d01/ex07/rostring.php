#!/usr/bin/php
<?php
	$list;
	$index = 0;
	$begin = FALSE;
	if ($argc > 1)
	{
		$str = $argv[1];
		$array = explode(" ", $str);
		foreach($array as $value)
		{
				if(!empty($value))
				{
					$trimed = trim($value);
					$list[$index] = $trimed;
					$index++;
				}
		}
		foreach($list as $val)
		{
			if ($val == $list[1])
				$begin = TRUE;
			elseif ($begin)
				print " ";
			if ($val != $list[0])
				print "$val";
		}
		if ($begin)
			print " ";
		print "$list[0]\n";
	}
?>
