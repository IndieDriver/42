let crossover lst1 lst2 =
    let rec loop lst1 lst2 acclst = match lst1 with
        | [] -> []
        | head :: tail -> if head = tail then
            begin
                let rec loop2 el lst2 = match lst2 with
                    | [] -> []
                    | head :: tail ->
                            if head == el then head
                            else loop2 (el head ::)

                            loop (count+1) acc t
                            else loop 0 ((count+1,head) :: acc) t
            end
    in
    loop lst1 list2 []
