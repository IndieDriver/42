let ft_test_sign a =
    if a >= 0 then print_endline "positive"
    else print_endline "negative"

let main () =
    ft_test_sign (12);
    ft_test_sign (-12);
    ft_test_sign (0)

let () = main ()
