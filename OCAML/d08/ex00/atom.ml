class virtual atom =
  object (self)
    method virtual name : string
    method virtual symbol : string
    method virtual atomic_number : int
    method to_string = ("name: " ^ self#name ^ " & symbol: " ^ self#symbol
      ^ " & atomic_number: " ^ (string_of_int self#atomic_number));
    method equal (rhs:atom) =
      (self#atomic_number = rhs#atomic_number)
  end

class hydrogen =
  object
    inherit atom
    method name = "Hydrogen"
    method symbol = "H"
    method atomic_number = 1
  end

class carbon =
  object
    inherit atom
    method name = "Carbon"
    method symbol = "C"
    method atomic_number = 6
  end

class oxygen =
  object
    inherit atom
    method name = "Oxygen"
    method symbol = "O"
    method atomic_number = 8
  end

class chlorine =
  object
    inherit atom
    method name = "Chlorine"
    method symbol = "Cl"
    method atomic_number = 17
  end

class neon =
  object
    inherit atom
    method name = "Neon"
    method symbol = "Ne"
    method atomic_number = 10
  end

class argon =
  object
    inherit atom
    method name = "Argon"
    method symbol = "Ar"
    method atomic_number = 18
  end
