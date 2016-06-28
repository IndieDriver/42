#!/usr/bin/php
<?php
	if ($argc > 1)
	{
		$list;
		$listalpha;
		$listnum;
		$listautre;
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
						$value = addslashes($value);
						$trimed = trim($value);
						$list[$index] = $trimed;
						$index++;
					}
				}
			}
		}


		foreach ($list as $o) {
           if (is_numeric($o[0])) {
               $listnum[] = $o;
           }
           elseif (ctype_alpha($o[0])) {
               $listalpha[] = $o;
           }
           else {
               $listautre[] = $o;
           }
       }
       if ($listalpha){
           natcasesort($listalpha);
           foreach ($listalpha as $i) {
               print($i . "\n");
           }
       }
       if ($listnum) {
           sort($listnum, SORT_STRING);
           foreach ($listnum as $i) {
               print($i . "\n");
           }
       }
       if ($listautre) {
           sort($listautre);
           foreach ($listautre as $i) {
               print($i . "\n");
           }
       }
	}
?>
