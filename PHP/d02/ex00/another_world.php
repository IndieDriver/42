#!/usr/bin/php
<?php
	if ($argc > 1)
	{
		$str = $argv[1];
		$str = preg_replace("/[ \t]+/"," ", $str);
		$str = preg_replace("/^ /","", $str);
		$str = preg_replace("/ $/","", $str);
		print "$str\n";
	}
?>
