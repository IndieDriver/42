<?php
	function ft_split($str){
		$tab = explode(" ", $str);
        $i = 0;
        $tab2;
        while ($i < count($tab)) {
            $tab[$i] = str_replace(" ", "", $tab[$i]);
            $i++;
        }
        $i = 0;
        while ($i < count($tab)) {
            if (!empty($tab[$i])) {
                $tab2[] = $tab[$i];
            }
            $i++;
        }
        sort($tab2);
        return ($tab2);
	}
?>
