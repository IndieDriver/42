let repeat_x nb =
    let rec loop n str =
        if n < 0 then "Error"
        else if n = 0 then str
        else loop (n - 1)(str ^ "x")
    in
    loop nb ""

let main() =
    print_endline(repeat_x (-1));
    print_endline(repeat_x 0);
    print_endline(repeat_x 1);
    print_endline(repeat_x 2);
    print_endline(repeat_x 5)

let () = main()
