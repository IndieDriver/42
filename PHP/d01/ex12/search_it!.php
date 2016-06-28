#!/usr/bin/php
<?php
if ($argc > 2)
{
	$value;
	$key;
	$tmp;
	$i = 2;
	$e = 0;
	while ($argv[$i])
	{
		if (!strstr($argv[$i], ":"))
		{
			print("Error in key:value declaration\n");
			$e = 1;
			break;
		}
		$tmp = explode(":", $argv[$i]);
		if (count($tmp) != 2)
		{
			print("Error in key:value declaration\n");
			$e = 1;
			break;
		}
		$key[] = $tmp[0];
		$value[] = $tmp[1];
		$i++;
	}
	if ($e == 0)
	{
		$ret;
		$u = 0;
		$i = 0;
		foreach ($key as $o)
		{
			if ($argv[1] == $o)
			{
				$ret = $value[$i];
				$u = 1;
			}
			$i++;
		}
		if ($u)
		{
			print($ret);
			print("\n");
		}
	}
}
?>
