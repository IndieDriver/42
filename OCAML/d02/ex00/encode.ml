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
    let lst = ['a'; 'a'; 'a'; 'b'; 'b'; 'b';] in
    encode lst;
    print_string ""

let () = main ()
