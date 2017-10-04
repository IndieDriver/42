let iter (f : int -> int) x n =
    let rec loop acc n =
        if n > 0 then loop (f acc) (n - 1)
        else acc
    in
    loop x n


let main() =
    print_endline (string_of_int (iter (fun x -> x * x) 2 4)); (* - : int = 65536 *)
    print_endline (string_of_int (iter (fun x -> x * 2) 2 4)) (* - : int = 32 *)

let () = main()
