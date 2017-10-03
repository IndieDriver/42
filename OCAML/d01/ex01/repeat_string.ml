let repeat_string ?(str = "x") nb =
    let rec loop n acc =
        if n < 0 then "Error"
        else if n = 0 then acc
        else loop (n - 1)(acc ^ str)
    in
    loop nb ""

let main() =
    print_endline(repeat_string (-1));
    print_endline(repeat_string 0);
    print_endline(repeat_string ~str:"Toto" 1);
    print_endline(repeat_string 2);
    print_endline(repeat_string ~str:"a" 5);
    print_endline(repeat_string ~str:"what" 3)

let () = main()
