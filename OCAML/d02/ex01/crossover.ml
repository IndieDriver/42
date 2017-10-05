let crossover lst1 lst2 =
  let rev lst =
      let rec loop acc = function
        | [] -> acc
        | head::tail-> loop (head :: acc) tail in
      loop [] lst
  in
  let rec loop2 tofind lst2 = match lst2 with
    | [] -> false
    | head :: tail -> if head = tofind then true
                      else loop2 tofind tail
  in
  let rec loop lst1 lst2 acclst = match lst1 with
    | [] -> acclst
    | head :: tail -> if (loop2 head lst2) then
      loop tail lst2 (head :: acclst)
    else
      acclst
  in
  rev (loop lst1 lst2 [])

let main () =
    let rec print_list lst =
        match lst with
        | [] -> print_char '\n'
        | e::l -> print_char e ; print_string ";" ; print_list l
    in
    let lst1 = ['a';'b';'c'] in
    let lst2 = ['a';'b'] in
    print_list (crossover lst1 lst2);

    let lst1 = ['a';'b';'c'] in
    let lst2 = ['c';'b';'a'] in
    print_list (crossover lst1 lst2);

    let lst1 = ['z';'b';'e';'g';'h';'i';'j'] in
    let lst2 = ['a';'b';'c';'z';'h';'g';'e'] in
    print_list (crossover lst1 lst2);

    let lst1 = [] in
    let lst2 = ['c';'b';'a'] in
    print_list (crossover lst1 lst2);

    let lst1 = ['a';'b';'c'] in
    let lst2 = [] in
    print_list (crossover lst1 lst2);

    let lst1 = [] in
    let lst2 = [] in
    print_list (crossover lst1 lst2);
    print_string ""

let () = main ()
