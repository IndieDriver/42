let rec ft_power n p =
    if p == 0 then 1
    else
        n * ft_power n (p - 1)

let main() =
    print_endline (string_of_int(ft_power 2 4));
    print_endline (string_of_int(ft_power 3 0));
    print_endline (string_of_int(ft_power 0 5))

let () = main()
