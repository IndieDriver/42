#!/usr/bin/php
<?php
	if ($argc > 1)
	{
		$list;
		$index = 0;
		foreach($argv as $arg)
		{
			if ($arg != $argv[0])
			{
				$str = $arg;
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
			}
		}
		sort($list, SORT_STRING);
		foreach($list as $val)
			print "$val\n";
	}
?>
