<?php
class NightsWatch implements IFighter
{
	private $recruited = array();
	
	public function recruit($inst)
	{
		$this->recruited[] = $inst;
	}
	public function fight()
	{
		foreach($this->recruited as $inst)
		{
			if ($inst instanceof IFighter)
				$inst->fight();
		}
	}
}
?>
