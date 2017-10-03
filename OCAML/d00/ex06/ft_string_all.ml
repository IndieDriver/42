let ft_string_all predicate str =
    let len = String.length str in
    let rec loop n =
        if n < len then
            predicate(String.get str n) && loop (n + 1)
        else
            true
    in
    loop (0)


let is_digit c =
    c >= '0' && c <= '9'

let main() =
    print_endline (string_of_bool(ft_string_all is_digit "0123456789"));
    print_endline (string_of_bool(ft_string_all is_digit "O12EAS67B9"))

let () = main()
