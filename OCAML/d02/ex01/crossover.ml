let crossover lst1 lst2 =
  let rec loop lst1 lst2 acclst = match lst1 with
    | [] -> []
    | head :: tail -> if head = tail then
      begin
        (*
        let rec loop2 el lst2 = match lst2 with
          | [] -> []
          | head :: tail -> if head == el then head
            else loop2 (el tail)
        in
        loop2 head lst2 *)
      end
    in
    loop lst1 lst2 []

let main () =
    let rec print_list lst =
        match lst with
        | [] -> print_char '\n'
        | e::l -> print_char e ; print_string ";" ; print_list l
    in
    let lst1 = ['a';'a';'a';'b';'b';'b'] in
    let lst1 = ['a';'b';'a';'b';'b';'b'] in
    print_list (crossover lst1 lst2);
    print_string ""

let () = main ()
