module MyString =
       struct
         type t = string
         let compare str1 str2 =
           Pervasives.compare str1 str2
       end

module StringSet = Set.Make(MyString)

let () =
  let set = List.fold_right StringSet.add [ "foo"; "bar"; "baz"; "qux" ] StringSet.empty in
  StringSet.iter print_endline set;
  print_endline (StringSet.fold ( ^ ) set "")
