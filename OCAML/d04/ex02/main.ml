let main() =
  print_string "toString:\n";
  let rec loop lst = match lst with
  | [] -> print_char '\n'
  | head :: tail -> print_string (Card.toString head); print_string "|";
    loop tail
  in
  loop Card.all;

  print_string "\ntoStringVerbose:\n";
  let rec loop lst = match lst with
  | [] -> print_char '\n'
  | head :: tail -> print_string (Card.toStringVerbose head); print_string "|";
    loop tail
  in
  loop Card.allDiamonds;
  print_string "\n";

  let two_spade = Card.newCard Card.Value.T2 Card.Color.Spade
  in
  let as_diamond = Card.newCard Card.Value.As Card.Color.Diamond
  in
  print_string ("compare two_spade as_diamond: " ^ (string_of_int (Card.compare two_spade as_diamond)) ^ "\n");
  print_string ("compare as_diamond two_spade: " ^ (string_of_int (Card.compare as_diamond two_spade)) ^ "\n");
  print_string ("compare two_spade two_spade: " ^ (string_of_int (Card.compare two_spade two_spade)) ^ "\n");
  print_string "\n";

  print_string ("two_spade = spade: " ^ (string_of_bool (Card.isSpade two_spade)) ^ "\n");
  print_string ("as_diamond = spade: " ^ (string_of_bool (Card.isSpade as_diamond)) ^ "\n");
  print_string ("as_diamond = heart: " ^ (string_of_bool (Card.isHeart as_diamond)) ^ "\n");
  print_string "\n";

  let two_club = Card.newCard Card.Value.T2 Card.Color.Club
  in
  print_string ("min two_spade and as_diamond: " ^ (Card.toString (Card.min two_spade as_diamond)) ^ "\n");
  print_string ("min two_club and two_spade: " ^ (Card.toString (Card.min two_club two_spade)) ^ "\n");
  print_string ("max two_spade and as_diamond: " ^ (Card.toString (Card.max two_spade as_diamond)) ^ "\n");
  print_string "\n";

  print_string ("isOf two_spade spade: " ^ (string_of_bool (Card.isOf two_spade Card.Color.Spade)) ^ "\n");
  print_string ("isOf as_diamond spade: " ^ (string_of_bool (Card.isOf as_diamond Card.Color.Spade)) ^ "\n");
  print_string "\n";

  print_string ("best of two_spade and as_diamond: " ^ (Card.toString (Card.best [two_spade;as_diamond])) ^ "\n");
  print_string ("best of allClubs: " ^ (Card.toString (Card.best Card.allClubs)) ^ "\n");
  print_string "\n";


  ignore (as_diamond)

let () = main()
