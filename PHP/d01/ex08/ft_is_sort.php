<?php
	function ft_is_sort($tab)
	{
		$i = 0;
		$sorted = $tab;
		sort($sorted);
		if ($sorted == $tab)
			return (TRUE);
		else
			return (FALSE);
	}
?>
