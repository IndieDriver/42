<?php
class UnholyFactory{
	public $absorbed;

	public function __construct()
	{
		$this->absorbed = array();
	}
	
	public function contain_fighter($type)
	{
		foreach($this->absorbed as $val)
		{
			if ($val instanceof Fighter)
			{
				if ($val->type == $type)
					return True;
			}
		}
		return False;
	}
	
	public function absorb($fighter)
	{
		if ($fighter instanceof Fighter)
		{
			if ($this->contain_fighter($fighter->type))
				print "(Factory already absorbed a fighter of type ".$fighter->type.")".PHP_EOL;
			else
			{
				$this->absorbed[] = $fighter;
				print "(Factory absorbed a fighter of type ".$fighter->type.")".PHP_EOL;
			}
		}
		else
			print "(Factory can't absorb this, it's not a fighter)".PHP_EOL;
	}
	public function get_fighter($type)
	{
		foreach($this->absorbed as $val)
		{
			if ($val instanceof Fighter)
			{
				if ($val->type == $type)
					return $val;
			}
		}
		return null;
	}	
	public function fabricate($fighter)
	{
		if ($this->contain_fighter($fighter))
		{
			print "(Factory fabricates a fighter of type ".$fighter.")".PHP_EOL;
			return ($this->get_fighter($fighter));
		}
		else
		{
			print "(Factory hasn't absorbed any fighter of type ".$fighter.")".PHP_EOL;
		}
	}
	
}

?>
