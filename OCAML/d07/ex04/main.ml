let main() =
  let dalek_army = new Army.army in
  dalek_army#add (new Dalek.dalek);
  dalek_army#add (new Dalek.dalek);
  dalek_army#add (new Dalek.dalek);
  dalek_army#remove;

  let doctor_army = new Army.army in
  doctor_army#add (new Doctor.doctor "who1" 20 (new People.people "sidekick1"));
  doctor_army#add (new Doctor.doctor "who2" 20 (new People.people "sidekick2"));
  doctor_army#add (new Doctor.doctor "who3" 20 (new People.people "sidekick3"));
  doctor_army#remove;
  doctor_army#remove;
  doctor_army#remove;
  doctor_army#remove


let () = main()
