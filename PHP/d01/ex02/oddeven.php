#!/usr/bin/php
<?php
	while (1){
		print("Entrez un nombre: ");
		$num = fgets(STDIN);
		if (feof(STDIN))
			break;
		$num = trim($num);
		if (is_numeric($num)){
			if ($num % 2 == 0)
				print "Le chiffre $num est Pair\n";
			else
				print "Le chiffre $num est Impair\n";
		}else{
			print "'$num' n'est pas un chiffre\n";
		}
	}
?>
