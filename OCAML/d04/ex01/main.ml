let main() =
  let rec loop lst = match lst with
  | [] -> print_char '\n'
  | head :: tail -> print_int (Value.toInt head); print_string " ; ";
    loop tail
  in
  loop Value.all;

  let rec loop lst = match lst with
  | [] -> print_char '\n'
  | head :: tail -> print_string (Value.toString head); print_string " ; ";
    loop tail
  in
  loop Value.all;

  let rec loop lst = match lst with
  | [] -> print_char '\n'
  | head :: tail -> print_string (Value.toStringVerbose head); print_string " ; ";
    loop tail
  in
  loop Value.all;

  (*
  let rec loop lst = match lst with
  | [] -> print_char '\n'
  | head :: tail -> print_string (Value.toString (Value.previous head));
    print_string " ; ";
    loop tail
  in
  loop Value.all; *)

  let rec loop lst = match lst with
  | [] -> print_char '\n'
  | head :: tail -> print_string (Value.toString (Value.next head)); print_string " ; ";
    loop tail
  in
  loop Value.all

let () = main()
