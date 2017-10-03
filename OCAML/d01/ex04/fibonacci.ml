let rec fibonacci n =
    let rec aux n acc1 acc2 =
        if n < 0 then -1
        else if n = 0 then acc1
        else aux (n - 1) acc2 (acc1 + acc2)

    in
    aux n 0 1

let main() =
    print_endline (string_of_int (fibonacci (-42)));
    print_endline (string_of_int (fibonacci 1));
    print_endline (string_of_int (fibonacci 3));
    print_endline (string_of_int (fibonacci 6))

let () = main()
