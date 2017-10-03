let ft_print_rev str =
    let len = String.length str in
    let rec loop n =
        if n > -1 then
            let character = String.get str n in
            print_char character;
            loop (n - 1)
    in
    loop (len - 1);
    print_char '\n'


let main() =
    ft_print_rev "Hello world!";
    ft_print_rev "24";
    ft_print_rev ""


let () = main()
