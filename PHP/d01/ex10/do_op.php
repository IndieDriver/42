#!/usr/bin/php
<?php
	if ($argc == 4)
	{
		$nb1 = trim($argv[1]);
		$sign = trim($argv[2]);
		$nb2 = trim($argv[3]);
		$result;
		if ($sign == "+")
			$result = $nb1 + $nb2;
		else if ($sign == "-")
			$result = $nb1 - $nb2;
		else if ($sign == "*")
			$result = $nb1 * $nb2;
		else if ($sign == "/")
			$result = $nb1 / $nb2;
		else if ($sign == "%")
			$result = $nb1 % $nb2;
		print ("$result\n");
	}
	else
		print "Incorrect Parameters\n";
?>
