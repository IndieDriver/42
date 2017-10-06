let main() =
  let rec loop lst = match lst with
  | [] -> print_string ""
  | head :: tail -> print_string (Color.toString head);
    print_char '\n';
    loop tail
  in
  loop Color.all;

  let rec loop lst = match lst with
  | [] -> print_string ""
  | head :: tail -> print_string (Color.toStringVerbose head);
    print_char '\n';
    loop tail
  in
  loop Color.all

let () = main()
