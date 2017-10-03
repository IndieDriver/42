let repeat_x nb =
    if nb <= -1 then
        "Error"
    else
        begin
        let rec loop n str=
            if n < 0 then str
            else
                let accstr = str ^ "x" in
                loop ((n - 1) accstr)
        in
        loop nb ""
    end

let main() =
    repeat_x (-1);
    repeat_x 0;
    repeat_x 1;
    repeat_x 2;
    repeat_x 5

let () = main()
