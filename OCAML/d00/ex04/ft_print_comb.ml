let ft_print_comb () =
    let rec loop1 first =
        if first <= 9 then
            begin
                let rec loop2 second =
                    if second <= 9 then
                        begin
                            let rec loop3 third =
                                if third <= 9 then
                                    begin
                                        if first < second && second < third then
                                            begin
                                                if (first = 0 && second = 1 &&
                                                third = 2) then
                                                    print_string ""
                                                else
                                                    print_string ", ";
                                                print_int first;
                                                print_int second;
                                                print_int third
                                            end;
                                        loop3 (third + 1)
                                    end
                            in
                            loop3 0;
                            loop2 (second + 1)
                        end
                in
                loop2 0;
                loop1 (first + 1)
            end
    in
    loop1 0;
    print_string "\n"

let main() =
    ft_print_comb()

let () = main()
