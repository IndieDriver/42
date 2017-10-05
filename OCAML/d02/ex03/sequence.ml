let sequence n =
  let encode lst =
    let rev lst =
        let rec loop acc = function
          | [] -> acc
          | head::tail-> loop (head::acc) tail in
        loop [] lst
    in
    let rec enc count acc lst = match lst with
        | [] -> [1]
        | [x] -> x :: (count + 1) :: acc
        | head :: (tail :: _ as t) -> if head = tail then
          enc (count + 1) acc t
          else enc 0 (head :: (count + 1) :: acc) t
    in
    rev (enc 0 [] lst)
  in
  let rec loop count max lstminus =
    if count >= 0 && count < max then
      loop (count + 1) max (encode lstminus)
    else
      lstminus
  in
  let rec list_to_string lst str =
    match lst with
    | [] -> (str ^ "\n")
    | head :: tail -> list_to_string tail (str ^ string_of_int head)
  in
  list_to_string (loop 0 n []) ""

let main() =
  print_string (sequence 1);
  print_string (sequence 2);
  print_string (sequence 3);
  print_string (sequence 4);
  print_string (sequence 5);
  print_string (sequence 6);
  print_string (sequence 7);
  print_string (sequence 12);
  print_string (sequence 0);
  print_string (sequence (-1))

let () = main()
