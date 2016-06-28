#!/usr/bin/php
<?php
	if ($argc > 1)
	{
		$file_str = file_get_contents($argv[1]);
		$i = 0;
		$body = FALSE;
		$title = FALSE;
		$a = FALSE;
		$aclosed = FALSE;
		while ($file_str[$i])
		{
			if ($file_str[$i] == "<")
			{
				if ($file_str[$i + 1] == "a" || $file_str[$i + 1] == "s" || $file_str[$i + 1] == "d")
					$a = TRUE;
				else
					$a = FALSE;
				$aclosed = FALSE;
				if ($file_str[$i + 1] == "b" && $file_str[$i + 2] == "o")
					$body = TRUE;
			}
			if ($body)
			{
				if ($file_str[$i] == ">")
				{
					if ($a)
						$aclosed = TRUE;
					else
						$aclosed = FALSE;
				}
				if ($file_str[$i] == "\"")
				{
					if (!$title)
						$title = TRUE;
					else
						$title = FALSE;
				}
				if ($aclosed && $a)
					$file_str[$i] = strtoupper($file_str[$i]);
				if ($title)
					$file_str[$i] = strtoupper($file_str[$i]);
			}
			$i++;
		}
		print "$file_str";
	}
?>
