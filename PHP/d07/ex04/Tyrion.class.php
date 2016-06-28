<?php
class Tyrion extends Lannister
{
	public function sleepWith($inst){
		if ($inst instanceof Cersei || $inst instanceof Jaime)
			print "Not even if I'm drunk !".PHP_EOL;
		if ($inst instanceof Sansa)
			print "Let's do this.".PHP_EOL;
	}
	
}
?>
