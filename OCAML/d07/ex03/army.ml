class ['a] army =
  object (self)

  val mutable lstarmy:'a list = []

  method add (element:'a) =
    lstarmy <- (element :: lstarmy)

  method remove =
    if (List.length lstarmy > 0) then
      lstarmy <- List.tl lstarmy

  end
