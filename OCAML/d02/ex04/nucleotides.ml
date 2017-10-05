type phosphate = string
type deoxyribose = string
type nucleobase = A | T | C | G | None

type nucleotide = {
  phosphate : phosphate;
  deoxyribose : deoxyribose;
  nucleobase : nucleobase
}

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

let main() =
  let print_nucleotides nucleotide =
    let convert_nucleobase nucleobase = match nucleobase with
      | A -> "A"
      | T -> "T"
      | C -> "C"
      | G -> "G"
      | _ -> "_"
    in
    print_endline nucleotide.phosphate;
    print_endline nucleotide.deoxyribose;
    print_endline (convert_nucleobase nucleotide.nucleobase)
  in
  print_nucleotides (generate_nucleotides 'T')

let () = main()
