class doctor name age sidekick =
  object (self)
    initializer print_endline "A doctor has been initialized"

    val name:string = name
    val mutable age:int = age
    val sidekick = sidekick
    val mutable hp:int = 100

    method to_string = "name = " ^ name ^ " and hp = " ^ (string_of_int hp) ^
      " and age = " ^ (string_of_int age) ^ " and sidekick = (" ^
      sidekick#to_string ^ ")"

    method talk = print_endline ("Hi! I’m the Doctor!")

    method travel_in_time start arrival =
      age <- (age + (arrival - start));
      print_endline ("╔═══╩═══╗ \n╠╦╦╦═╦╦╦╣ \n╠╬╬╣ ╠╬╬╣ \n╠╩╩╣ ╠╩╩╣ \n" ^
      "║░░║ ║  ║\n╠══╣ ╠══╣ \n║  ║ ║  ║\n╩══╩═╩══╩ ");

    method use_sonic_screwdriver =
      print_endline "Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii Whiiiiwhiiiwhiii"

    method private regenerate = hp <- 100
  end
