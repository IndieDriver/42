let read_file filename =
  let ic = open_in filename in
  let jokes = ref (Array.make 0 "") in
  try
  while true; do
    jokes := Array.append !jokes (Array.make 1 (input_line ic));
  done; !jokes
  with End_of_file -> close_in ic;
  !jokes

let print_jokes argv =
  let jokes = read_file (Array.get argv 1)
  in
  let n = Random.int (Array.length jokes) in
    print_endline (Array.get jokes n)

let main argc argv =
  Random.self_init ();
  try (print_jokes argv) with
  | _ -> print_endline "Usage ./a.out <jokes_file>"

let () =
  let argv = Sys.argv
  in main (Array.length argv) argv
