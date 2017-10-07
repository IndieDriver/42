type ft_ref

let return reference =
  {mutable contents = reference}

let get ref =
