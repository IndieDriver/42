class dalek =
  object (self)

    val name:string =
      Random.self_init ();
      let max = Random.int 4 + 2 in
        let rec randchar i stracc =
          let rand_chr () = ("" ^ Char.escaped (char_of_int (97 + (Random.int 26)))) in
          if (i < max) then
            randchar (i + 1) (stracc ^ (rand_chr ()))
          else
            stracc
      in
      randchar 0 "Dalek"

    val mutable shield:bool = true
    val mutable hp:int = 100

    method to_string = "name = " ^ name ^ " and hp = " ^ (string_of_int hp) ^
      " and shield = " ^ (string_of_bool shield);

    method exterminate (people:People.people) =
      shield <- (not shield);
      people#die

    method talk = Random.self_init ();
      let strlst = ["Explain! Explain!";"Exterminate! Exterminate!";"I obey!";"You are the Doctor! You are the enemy of the Daleks!"]
      in
      print_endline (List.nth strlst (Random.int 4));

    method die = hp <- 0; print_endline "Emergency Temporal Shift!"

  end
