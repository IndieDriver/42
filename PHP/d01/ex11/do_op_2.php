#!/usr/bin/php
<?php
function error()
{
	print("Syntax Error\n");
	exit ();
}
if ($argc == 2)
{
	$argv[1] = trim($argv[1]);
	$j = 0;
	$str;
	$op = 0x0;
	while ($argv[1][$j])
	{
		if ($argv[1][$j] != ' ' && $argv[1][$j] != '\t')
			$str = $str . $argv[1][$j];
		if (ctype_alpha($argv[1][$j]))
			error ();
		if ($argv[1][$j] == '/' || $argv[1][$j] == '*' || $argv[1][$j] == '%' || $argv[1][$j] == '+' || $argv[1][$j] == '-')
		{
			if ($op != 0x0)
				error ();
			$op = $argv[1][$j];
		}
		$j++;
	}
	$j = 0;
	$a;
	if ($str[$j] == '/' || $str[$j] == '*' || $str[$j] == '%' || $str[$j] == '+' || $str[$j] == '-')
		error ();
	while (is_numeric($str[$j]))
	{
		$a = $a . $str[$j];
		$j++;
	}
	if ($j == 0)
		error ();
	if ($str[$j] != '/' && $str[$j] != '*' && $str[$j] != '%' && $str[$j] != '+' && $str[$j] != '-')
		error ();
	$j++;
	$tmp = $j;
	$b;
	while (is_numeric($str[$j]))
	{
		$b = $b . $str[$j];
		$j++;
	}
	if ($j == $tmp)
		error ();
	if ($str[$j] == '/' || $str[$j] == '*' || $str[$j] == '%' || $str[$j] == '+' || $str[$j] == '-')
		error ();
	if ($op == '/')
		print($a / $b);
	else if ($op == '+')
		print($a + $b);
	else if ($op == '-')
		print($a - $b);
	else if ($op == '%')
		print($a % $b);
	else if ($op == '*')
		print($a * $b);
	print("\n");
}
else
{
	print("Incorrect Parameters\n");
	exit ();
}
?>
