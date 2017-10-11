let main() =
  let p = new People.people "someone" in
  p#talk;
  p#die;
  print_endline (p#to_string)

let () = main()
