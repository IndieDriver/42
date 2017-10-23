let main() =
  let hydrogen = new Atom.hydrogen in
  print_endline (hydrogen#to_string);
  let carbon = new Atom.carbon in
  print_endline (carbon#to_string);
  let oxygen = new Atom.oxygen in
  print_endline (oxygen#to_string);
  let chlorine = new Atom.chlorine in
  print_endline (chlorine#to_string);
  let neon = new Atom.neon in
  print_endline (neon#to_string);
  let argon = new Atom.argon in
  print_endline (argon#to_string)


let () = main()
