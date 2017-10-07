let my_sleep time = Unix.sleep time

let micronap argv =
  let time = int_of_string (Array.get argv 1)
  in my_sleep time

let main argc argv =
  try (micronap argv) with
  | _ -> print_endline "Usage ./a.out <time in second>"

let () =
  let argv = Sys.argv
  in main (Array.length argv) argv
