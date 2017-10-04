let encode lst =
    let rev lst =
        let rec loop acc = function
          | [] -> acc
          | head::tail-> loop (head::acc) tail in
        loop [] lst
    in
    let rec loop count acc lst = match lst with
        | [] -> []
        | [x] -> (count+1, x) :: acc
        | head :: (tail :: _ as t) -> if head = tail then
            loop (count+1) acc t
            else loop 0 ((count+1,head) :: acc) t
    in
    rev (loop 0 [] lst)

let main () =
    let rec print_list lst =
        let print_pair (a, b) =
          print_string "(";
          print_int a;
          print_string ",";
          print_char b;
          print_string ")"
        in
        match lst with
        | [] -> print_char '\n'
        | e::l -> print_pair e ; print_string ";" ; print_list l
    in
    let lst = ['a';'a';'a';'b';'b';'b'] in
    print_list (encode lst);
    let lst = ['a';'b';'c'] in
    print_list (encode lst);
    let lst = ['a';'b';'b';'b';'b';'b';'b';'b';'a';'a';'b'] in
    print_list (encode lst);
    let lst = ['a'] in
    print_list (encode lst);
    let lst = [] in
    print_list (encode lst);
    print_string ""

let () = main ()
