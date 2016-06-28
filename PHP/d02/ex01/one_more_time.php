#!/usr/bin/php
<?php
	if ($argc > 1)
	{
		$str = $argv[1];
		if (!preg_match("/(LUNDI |MARDI |MERCREDI |JEUDI |VENDREDI |SAMEDI |DIMANCHE )/i", $str)
			|| !preg_match("/ [0-9]{1,2} /i", $str)
			|| !preg_match("/( JANVIER | FEVRIER | MARS | AVRIL | MAI | JUIN | JUILLET | AOUT | SEPTEMBRE | OCTOBRE | NOVEMBRE | DECEMBRE )/i", $str)
			|| !preg_match("/ [0-9]{4} /", $str)
			|| !preg_match("/ [0-9]{2}:[0-9]{2}:[0-9]{2}/", $str))
		{
			print "Wrong Format\n";
		}else{
			if (!preg_match("/(undi|ardi|ercredi|eudi|endredi|amedi|imanche)/", $str)
			|| !preg_match("/(anvier|evrier|ars|vril|ai|uin|uillet|out|eptembre|ctobre|ovembre|ecembre)/",$str))
			{
				print "Wrong Format\n";
			}
			else
			{
				$str = explode(" ", $argv[1]);
				$str2 = explode(":", $str[4]);
				date_default_timezone_set(UTC);
				$day = $str[0];
				$day_nb = $str[1];
				if (!strcasecmp($str[2], "janvier")){
					$month = 1;
				}elseif (!strcasecmp($str[2], "fevrier")) {
					$month = 2;
				}elseif (!strcasecmp($str[2], "mars")) {
					$month = 3;
				}elseif (!strcasecmp($str[2], "avril")) {
					$month = 4;
				}elseif (!strcasecmp($str[2], "mai")) {
					$month = 5;
				}elseif (!strcasecmp($str[2], "juin")) {
					$month = 6;
				}elseif (!strcasecmp($str[2], "juillet")) {
					$month = 7;
				}elseif (!strcasecmp($str[2], "aout")) {
					$month = 8;
				}elseif (!strcasecmp($str[2], "septembre")) {
					$month = 9;
				}elseif (!strcasecmp($str[2], "octobre")) {
					$month = 10;
				}elseif (!strcasecmp($str[2], "novembre")) {
					$month = 11;
				}elseif (!strcasecmp($str[2], "decembre")) {
					$month = 12;
				}
				$year = $str[3];
				$hour = $str2[0];
				$minute = $str2[1];
				$second = $str2[2];
				$time = mktime($hour, $minute, $second, $month, $day_nb, $year, 1);
				print "$time\n";
			}
		}
	}
?>
