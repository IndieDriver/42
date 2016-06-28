<?php
class Jaime extends Lannister
{
	public function sleepWith($inst){
		if ($inst instanceof Cersei)
			print "With pleasure, but only in a tower in Winterfell, then.".PHP_EOL;
		if ($inst instanceof Tyrion)
			print "Not even if I'm drunk !".PHP_EOL;
		if ($inst instanceof Sansa)
			print "Let's do this.".PHP_EOL;
	}
	
}
?>
