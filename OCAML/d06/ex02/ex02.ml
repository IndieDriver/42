
module type PAIR = sig val pair : (int * int) end
module type VAL = sig val x : int end

module type MAKEPROJECTION =
  functor (Val : VAL) -> PAIR

module MakeFst : MAKEPROJECTION =
  functor (Val : VAL) ->
    struct
      let pair = (Val.x, Val.x)
    end

module Val : VAL =
  struct
    let x = 42
  end
(* FIX ME !!! *)

module Pair : PAIR = struct let pair = ( 21, 42 ) end
module Fst : VAL = MakeFst (Pair)
module Snd : VAL = MakeSnd (Pair)
let () = Printf.printf "Fst.x = %d, Snd.x = %d\n" Fst.x Snd.x
