type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None

type nucleotide = {
  phosphate : phosphate;
  deoxyribose : deoxyribose;
  nucleobase : nucleobase
}

type helix = nucleotide list

let generate_nucleotides nucleobase =
  let convert_nucleobase nucleobase_char = match nucleobase_char with
    | 'A' -> A
    | 'T' -> T
    | 'C' -> C
    | 'G' -> G
    | _ -> None
  in {
    phosphate = "phosphate";
    deoxyribose = "deoxyribose";
    nucleobase = convert_nucleobase nucleobase
  }

let generate_helix n =
  let rand_char rand_nb =
    let char_pool = ['A';'T';'C';'G']
    in
    let rec at nth count lst = match lst with
      | [] -> '_'
      | head :: tail -> if count = nth then head else
          at nth (count + 1) tail
    in
    at rand_nb 0 char_pool
  in
  let rec loop count max acc=
    if count >= 0 && count < max then
      let rand_nb = Random.int(4)
      in
      loop (count + 1) max ((generate_nucleotides (rand_char rand_nb)) :: acc)
    else
      acc
  in
  loop 0 n []


let helix_to_string helix =
  let convert_nucleobase nucleobase = match nucleobase with
    | A -> "A"
    | T -> "T"
    | C -> "C"
    | G -> "G"
    | _ -> "_"
  in
  let rec loop lst str = match lst with
    | [] -> (str ^ "\n")
    | head :: tail -> loop tail (str ^ (convert_nucleobase head.nucleobase))
  in
  loop helix ""

let complementary_helix helix =
  let rev lst =
      let rec loop acc = function
        | [] -> acc
        | head::tail-> loop (head::acc) tail in
      loop [] lst
  in
  let complement nucl = match nucl.nucleobase with
    | A -> 'T'
    | T -> 'A'
    | C -> 'G'
    | G -> 'C'
    | _ -> '_'
  in
  let rec loop lst acc = match lst with
    | [] -> acc
    | head :: tail -> loop tail (generate_nucleotides (complement head) :: acc)
  in
  rev (loop helix [])

let main() =
  let helix = generate_helix 10 in
  print_string (helix_to_string helix);
  print_string (helix_to_string (complementary_helix helix));

  let helix = generate_helix 30 in
  print_string (helix_to_string helix);
  print_string (helix_to_string (complementary_helix helix))

let () = main()
