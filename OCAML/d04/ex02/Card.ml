module Color =
struct
  type t = Spade | Heart | Diamond | Club

  let all = [Spade;Heart;Diamond;Club]

  let toString t = match t with
    | Spade -> "S"
    | Heart -> "H"
    | Diamond -> "D"
    | Club -> "C"

  let toStringVerbose t = match t with
    | Spade -> "Spade"
    | Heart -> "Heart"
    | Diamond -> "Diamond"
    | Club -> "Club"
end

module Value =
struct
  type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10 | Jack | Queen | King | As

  let all = [T2;T3;T4;T5;T6;T7;T8;T9;T10;Jack;Queen;King;As]

  let toInt t = match t with
    | T2 -> 1
    | T3 -> 2
    | T4 -> 3
    | T5 -> 4
    | T6 -> 5
    | T7 -> 6
    | T8 -> 7
    | T9 -> 8
    | T10 -> 9
    | Jack -> 10
    | Queen -> 11
    | King -> 12
    | As -> 13

  let toString t = match t with
    | T2 -> "2"
    | T3 -> "3"
    | T4 -> "4"
    | T5 -> "5"
    | T6 -> "6"
    | T7 -> "7"
    | T8 -> "8"
    | T9 -> "9"
    | T10 -> "10"
    | Jack -> "J"
    | Queen -> "Q"
    | King -> "K"
    | As -> "A"

  let toStringVerbose t = match t with
    | T2 -> "2"
    | T3 -> "3"
    | T4 -> "4"
    | T5 -> "5"
    | T6 -> "6"
    | T7 -> "7"
    | T8 -> "8"
    | T9 -> "9"
    | T10 -> "10"
    | Jack -> "Jack"
    | Queen -> "Queen"
    | King -> "King"
    | As -> "As"

  let next t =
    let fromInt t = match t with
      | 1 -> T2
      | 2 ->  T3
      | 3 -> T4
      | 4 -> T5
      | 5 -> T6
      | 6 -> T7
      | 7 -> T8
      | 8 -> T9
      | 9 -> T10
      | 10 -> Jack
      | 11 -> Queen
      | 12 -> King
      | 13 -> As
      | _ -> T2
    in
    if (toInt t < 13) then
      fromInt ((toInt t) + 1)
    else
      invalid_arg "can't call next on As"

  let previous t =
    let fromInt t = match t with
      | 1 -> T2
      | 2 ->  T3
      | 3 -> T4
      | 4 -> T5
      | 5 -> T6
      | 6 -> T7
      | 7 -> T8
      | 8 -> T9
      | 9 -> T10
      | 10 -> Jack
      | 11 -> Queen
      | 12 -> King
      | 13 -> As
      | _ -> T2
    in
    if ((toInt t) > 1) then
      fromInt ((toInt t) - 1)
    else
      invalid_arg "can't call previous on T2"
end

type t = (Value.t * Color.t)

let newCard value color =
  (value, color)

let allSpades =
  [(Value.T2,Color.Spade);(Value.T3,Color.Spade);(Value.T4,Color.Spade);(Value.T5,Color.Spade);(Value.T6,Color.Spade);
  (Value.T7,Color.Spade);(Value.T8,Color.Spade);(Value.T9,Color.Spade);(Value.T10,Color.Spade);(Value.Jack,Color.Spade);
  (Value.Queen,Color.Spade);(Value.King,Color.Spade);(Value.As,Color.Spade);]
let allHearts =
  [(Value.T2,Color.Heart);(Value.T3,Color.Heart);(Value.T4,Color.Heart);(Value.T5,Color.Heart);(Value.T6,Color.Heart);
  (Value.T7,Color.Heart);(Value.T8,Color.Heart);(Value.T9,Color.Heart);(Value.T10,Color.Heart);(Value.Jack,Color.Heart);
  (Value.Queen,Color.Heart);(Value.King,Color.Heart);(Value.As,Color.Heart);]
let allDiamonds =
  [(Value.T2,Color.Diamond);(Value.T3,Color.Diamond);(Value.T4,Color.Diamond);(Value.T5,Color.Diamond);(Value.T6,Color.Diamond);
  (Value.T7,Color.Diamond);(Value.T8,Color.Diamond);(Value.T9,Color.Diamond);(Value.T10,Color.Diamond);(Value.Jack,Color.Diamond);
  (Value.Queen,Color.Diamond);(Value.King,Color.Diamond);(Value.As,Color.Diamond);]
let allClubs =
  [(Value.T2,Color.Club);(Value.T3,Color.Club);(Value.T4,Color.Club);(Value.T5,Color.Club);(Value.T6,Color.Club);
  (Value.T7,Color.Club);(Value.T8,Color.Club);(Value.T9,Color.Club);(Value.T10,Color.Club);(Value.Jack,Color.Club);
  (Value.Queen,Color.Club);(Value.King,Color.Club);(Value.As,Color.Club);]


let all =
  [(Value.T2,Color.Spade);(Value.T3,Color.Spade);(Value.T4,Color.Spade);(Value.T5,Color.Spade);(Value.T6,Color.Spade);
  (Value.T7,Color.Spade);(Value.T8,Color.Spade);(Value.T9,Color.Spade);(Value.T10,Color.Spade);(Value.Jack,Color.Spade);
  (Value.Queen,Color.Spade);(Value.King,Color.Spade);(Value.As,Color.Spade);
  (Value.T2,Color.Heart);(Value.T3,Color.Heart);(Value.T4,Color.Heart);(Value.T5,Color.Heart);(Value.T6,Color.Heart);
  (Value.T7,Color.Heart);(Value.T8,Color.Heart);(Value.T9,Color.Heart);(Value.T10,Color.Heart);(Value.Jack,Color.Heart);
  (Value.Queen,Color.Heart);(Value.King,Color.Heart);(Value.As,Color.Heart);
  (Value.T2,Color.Diamond);(Value.T3,Color.Diamond);(Value.T4,Color.Diamond);(Value.T5,Color.Diamond);(Value.T6,Color.Diamond);
  (Value.T7,Color.Diamond);(Value.T8,Color.Diamond);(Value.T9,Color.Diamond);(Value.T10,Color.Diamond);(Value.Jack,Color.Diamond);
  (Value.Queen,Color.Diamond);(Value.King,Color.Diamond);(Value.As,Color.Diamond);
  (Value.T2,Color.Club);(Value.T3,Color.Club);(Value.T4,Color.Club);(Value.T5,Color.Club);(Value.T6,Color.Club);
  (Value.T7,Color.Club);(Value.T8,Color.Club);(Value.T9,Color.Club);(Value.T10,Color.Club);(Value.Jack,Color.Club);
  (Value.Queen,Color.Club);(Value.King,Color.Club);(Value.As,Color.Club);]

let getValue (value , _) =
  value

let getColor (_ , color) =
  color

let toString (value, color) =
  ((Value.toString value) ^ (Color.toString color))

let toStringVerbose (value, color) =
  Printf.sprintf "Card(%s, %s)" (Value.toStringVerbose value)
  (Color.toStringVerbose color)

let compare (value1, _) (value2, _) =
  if (Value.toInt value1) < (Value.toInt value2) then -1
  else if (Value.toInt value1) > (Value.toInt value2) then 1
  else 0

let max (value1, color1) (value2, color2) =
  if ((Value.toInt value1) >= (Value.toInt value2)) then
    (value1, color1)
  else
    (value2, color2)

let min (value1, color1) (value2, color2) =
  if ((Value.toInt value1) <= (Value.toInt value2)) then
    (value1, color1)
  else
    (value2, color2)

let best lst =
  if List.length lst = 0 then
    invalid_arg "empty list"
  else
    List.fold_left max (List.hd lst) lst

let isOf (_, tcolor) color =
  if ((Color.toString tcolor) = (Color.toString color)) then
    true
  else
    false

let isSpade (_, color) =
  if color = Color.Spade then
    true
  else
    false

let isHeart (_, color) =
  if color = Color.Heart then
    true
  else
    false

let isDiamond (_, color) =
  if color = Color.Diamond then
    true
  else
    false

let isClub (_, color) =
  if color = Color.Club then
    true
  else
    false
