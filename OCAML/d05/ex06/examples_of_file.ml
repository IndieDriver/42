let examples_of_file filename =
  let line_split_to_array line_split =
    let arr = ref (Array.make 0 (0.0)) in
    let letter = ref "" in
    for i = 0 to (List.length line_split - 1) do
      if (i = (List.length line_split - 1)) then
        letter := List.nth line_split i
      else
        arr := Array.append !arr (Array.make 1 (float_of_string (List.nth line_split i)))
    done;
    (!arr, !letter)
  in
  let examples = ref ([]) in
  let ic = open_in filename in
  try
  while true; do
    let line = input_line ic in
    let line_split = String.split_on_char ',' line in
    let data_set = line_split_to_array line_split in
    examples := (List.append (!examples) (data_set :: []))
  done; !examples;
  with End_of_file -> close_in ic;
  !examples

let tests argv =
  let examples = examples_of_file (Array.get argv 1)
  in
  let rec print_example (lst, letter) =
    for i = 0 to (Array.length lst - 1) do
      print_float lst.(i); print_string ";";
    done;
    print_string letter; print_char '\n';
  in
  let rec loop lst = match lst with
  | [] -> print_char '\n'
  | head :: tail -> print_example (head);
    loop tail
  in
  loop examples

let main argc argv =
  Random.self_init ();
  try (tests argv) with
  | _ -> print_endline "Usage ./a.out <example_file>"

let () =
  let argv = Sys.argv
  in main (Array.length argv) argv
