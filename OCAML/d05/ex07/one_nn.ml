type radar = float array * string

let eu_dist (a:float array) (b: float array) =
  let max_size = max (Array.length a) (Array.length b) in
  let sum = ref 0.0 in
  for i = 0 to max_size - 1 do
    let a_nb = if i < Array.length a then a.(i) else 0.0 in
    let b_nb = if i < Array.length b then b.(i) else 0.0 in
    let diff = (a_nb -. b_nb) in
    sum := (!sum +. (diff *. diff))
  done;
  sqrt(!sum)

let one_nn (radar_list:radar list) ((radar_lst,radar_value):radar) =
  let rec loop lst (nearest_lst, nearest_value) = match lst with
    | [] -> (nearest_lst, nearest_value)
    | (farr, cl) :: tail ->
        begin
            if ((eu_dist farr radar_lst) < (eu_dist nearest_lst radar_lst)) then
              loop tail (farr, cl)
            else
              loop tail (nearest_lst, nearest_value)
        end
  in
  let nearest = loop radar_list (List.hd radar_list) in
  match nearest with
  | (lst,value) -> value



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
  let examples = examples_of_file (Array.get argv 1) in
  print_endline ((one_nn examples (List.hd examples)))

let main argc argv =
  Random.self_init ();
  try (tests argv) with
  | _ -> print_endline "Usage ./a.out <example_file>"

let () =
  let argv = Sys.argv
  in main (Array.length argv) argv
