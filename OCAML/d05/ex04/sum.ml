let sum (f1:float) (f2:float) =
  (f1 +. f2)

let main() =
  print_endline (string_of_float (sum 4.0 0.2));
  print_endline (string_of_float (sum (-4.2) 566.0));
  print_endline (string_of_float (sum (-4.0) (-0.2)))

let () = main()
