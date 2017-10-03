let rec hfs_f n =
    if n = 0 then 1
    else if n > 0 then
        n - hfs_m (hfs_f (n - 1))
and hfs_m n =
    if n = 0 then 0
    else if n > 0 then
        n - hfs_f (hfm_m (n - 1))

let main() =
    print_endline (string_of_int (hfs_m 0));
    print_endline (string_of_int (hfs_f 0));
    print_endline (string_of_int (hfs_m 4));
    print_endline (string_of_int (hfs_f 4))

let () = main()
