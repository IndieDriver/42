let main() =
  let dalek = new Dalek.dalek in
  print_endline (dalek#to_string);
  dalek#talk;
  dalek#talk;
  let human = new People.people "humanA" in
  print_endline (human#to_string);
  dalek#exterminate human;
  print_endline (human#to_string);
  print_string "\n\n";

  let doctor = new Doctor.doctor "who" 20 in
  doctor#talk;
  print_endline (doctor#to_string);
  dalek#die

let () = main()
