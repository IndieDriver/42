class people name =
  object (self)
    initializer print_endline ("People named " ^ name ^ " has been initialized")
    val name:string = name
    val hp = 100
    method to_string = "name = " ^ name ^ " and hp = " ^ (string_of_int hp)
    method talk = print_endline ("I’m " ^ name ^"! Do you know the Doctor")
    method die = print_endline "Aaaarghh!"
  end
