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

let main() =
  let array1 = (Array.create_float 6) in
  let array2 = (Array.create_float 5) in
  array1.(0) <- 1.0;
  array1.(1) <- 2.0;
  array1.(2) <- 3.0;
  array1.(3) <- 4.0;
  array1.(4) <- 5.0;
  array1.(5) <- 6.0;

  array2.(0) <- 0.0;
  array2.(1) <- 0.0;
  array2.(2) <- 0.0;
  array2.(3) <- 0.0;
  array2.(4) <- 0.0;
  print_endline (string_of_float (eu_dist array1 array2))

let () = main()
