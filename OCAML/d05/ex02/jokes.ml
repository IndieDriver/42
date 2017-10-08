let main() =
  Random.self_init ();
  let jokes = Array.make 5 "";
  in
  jokes.(0) <- "generic jokes 1";
  jokes.(1) <- "generic jokes 2";
  jokes.(2) <- "generic jokes 3";
  jokes.(3) <- "generic jokes 4";
  jokes.(4) <- "generic jokes 5";
  let n = Random.int (Array.length jokes) in
    print_endline (Array.get jokes n)

let () = main()
