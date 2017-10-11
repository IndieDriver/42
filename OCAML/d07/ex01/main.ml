let main() =
  let doctor = new Doctor.doctor "who" 20 in
  doctor#talk;
  doctor#use_sonic_screwdriver;
  print_endline (doctor#to_string);
  doctor#travel_in_time 2017 2032;
  print_endline (doctor#to_string)

let () = main()
