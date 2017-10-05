let gray n =
  let rec gray_rec prefix n =
    if n = 0 then
      begin
        print_string prefix;
        print_char ' '
      end
    else
      begin
        gray_rec (prefix ^ "0") (n - 1);
        yarg_rec (prefix ^ "1") (n - 1)
      end
  and yarg_rec prefix n =
    if n = 0 then
      begin
        print_string prefix;
        print_char ' '
      end
    else
      begin
        gray_rec (prefix ^ "1") (n - 1);
        yarg_rec (prefix ^ "0") (n - 1)
      end
  in gray_rec "" n;
  print_char '\n'

let main() =
  gray 1;
  gray 2;
  gray 3;
  gray 4

let () = main()
