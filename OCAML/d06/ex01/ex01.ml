module StringHash =
  struct
    type t = string

    let hash str = (* djb2 *)
      let rec loop i hash_acc =
        if (i < String.length str) then
          loop (i + 1) (((hash_acc lsl 5) + hash_acc) + (int_of_char (String.get str i)))
        else
          hash_acc
      in
      loop 0 5381

    let equal i j =
      i = j

  end

module StringHashtbl = Hashtbl.Make(StringHash)

let () =
  let ht = StringHashtbl.create 5 in
  let values = [ "Hello"; "world"; "42"; "Ocaml"; "H" ] in
  let pairs = List.map (fun s -> (s, String.length s)) values in
  List.iter (fun (k,v) -> StringHashtbl.add ht k v) pairs;
  StringHashtbl.iter (fun k v -> Printf.printf "k = \"%s\", v = %d\n" k v) ht
