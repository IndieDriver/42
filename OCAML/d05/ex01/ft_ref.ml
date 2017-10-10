type 'a ft_ref = {mutable contents : 'a}

let return reference =
  {contents = reference}

let get reference =
  reference.contents

let set reference value =
  reference.contents <- value

let bind reference (f : 'a -> 'b ft_ref) =
  (f reference.contents)

let main() =
  let ref_1 = return 1
  in
  print_endline (string_of_int (get (ref_1)));

  set ref_1 3;
  print_endline (string_of_int (get (ref_1)));

  let ref_2 = bind ref_1 (fun x -> return(x * x))
  in
  print_endline (string_of_int (get (ref_2)));

  print_string ""

let () = main()
